/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: PlusIce, iNAK' */
/* Script Code Snippets:*/
/* Medkit Perk */

#include mc2\_utils_cvardef;
#include mc2\_utils_origin;

init()
{
	level.mc2_medkits		= cvardef("mc2_medkits", 1, 0, 1, "int"); // On or Off
	level.mc2_medkit_count		= cvardef("mc2_medkit_count", 1, 0, 1, "int"); //max medkits per person
	level.mc2_medkit_limit	= cvardef("mc2_medkit_limit", 10, 0, 10, "int"); //max medkits at time on map
	level.mc2_medkit_timer = cvardef("mc2_medkit_timer", 60, 0, 120, "int"); //Count Down in Seconds to delete
	level.mc2_medkit_replenish = cvardef("mc2_medkit_replenish", 30, 0, 120, "int"); //Count Down from deleted medkit to replenishing time
	

	//load Monitors
	self thread monitorHotKey();
	self thread monitorHUD();

	//Load Call backs
	self thread connectPlayer();

}
monitorHotKey()
{
	if( !level.mc2_medkits ) return;
	
	self endon( "disconnect" );

	for( ;; )
	{
		self waittill( "menuresponse", menu, response );
		
		if( response == "nbutton" )
		{
			if( level.mc2.medkit_count ) && ( level.mc2_medkit_limit)
			{
				self thread mc2\_medkits_main::DropMedkit();
			}	
			if( !level.mc2.medkit_count ) && ( level.mc2_medkit_replant)
			{	
				self thread mc2\_medkits_perk::replantMedkit();
			}
			if( !level.mc2.medkit_count ) && ( !level.mc2_medkit_replant)
			{
				self iprintlnbold( "You Have No Medkits and Reached Replant Limit!" );
			}
			if( level.mc2_medkit_count) && ( !level.mc2.medkit_limit)
			{
				self iprintlnBold( "Max Number of Medkits on Map Reached );	
			
			}
			else
				self iprintlnBold( "This feature is disabled" );	
			
		}
	}

}
startHealth()
{
	self endon("delete_medkit");
		
	for(;;)
	{
		players = getentarray("player", "classname");
		for(i=0;i<players.size;i++)
		{	
			if(isAlive(players[i]) && distancesquared(players[i].origin,medkit.origin)<15000) 
			{
				if(players[i].health < players[i].maxhealth)
				{
					if(players[i].health<80)
						players[i].health+=20;
					else
						players[i].health+=int(players[i].maxhealth-players[i].health);
				
//					if(players[i]!=self.owner)
//						self.owner thread maps\mp\gametypes\_gametype::points(50);
					
//					players[i] thread medkitOverlay();
				}
			}
		}
		wait 1;
	}
}
startTimer()
{
	if(self.pers["pClass"]!="medic")
		return;
		
	self endon("delete_medkit");
	
	time = getCvarInt( "mc2_medkit_timer" );
	
	for(;;)
	{
		time--;
		
		if(time<=0)
		self thread deletemedkit();
			
		wait 1;
	}
}
startReplenish()
{
	if(self.pers["pClass"]!="medic")
		return;
		
	self endon("delete_medkit");
	
	delay = getCvarInt( "mc2_medkit_replenish" );
	
	for(;;)
	{
		delay--;
		
		if(delay<=0)
		self thread deletemedkit();
		self.mc2_medkit_count++;
		self iprintlnbold( "You have Earned Back Your Medkit!" );
			
		wait 1;
	}

}
monitorHUD()
{
	if(self.pers["pClass"]!="medic" || !self.mc2_medkit_count)
		return;
		
	if ( level.mc2_hardcore ) return;
	
	if (!isdefined(self.medkitcounticon))
	{
		self.medkitcounticon = newClientHudElem(self);	
		self.medkitcounticon.alignX = "left";
		self.medkitcounticon.alignY = "top";
		self.medkitcounticon.x = 534; //590
		self.medkitcounticon.y = 398-5; //414
	//	self.medkitcounticon.alpha = 1;
		self.medkitcounticon SetShader("gfx/custom/hud@mediccharge.tga", 20, 20);			
	}					
	if (!isdefined(self.medkitcountammo))
	{
		self.medkitcountammo = newClientHudElem(self);	
		self.medkitcountammo.alignX = "left";
		self.medkitcountammo.alignY = "top";
		self.medkitcountammo.x = 549;
		self.medkitcountammo.y = 401;
		self.medkitcountammo.fontscale = 1;
	//	self.medkitcountammo.color = (.5,.5,0);
		self.medkitcountammo setValue(self.mc2_medkit_count);
	}

}
/* Call Backs */

connectPlayer()
{
	for(;;)
	{
		level waittill("connecting", player);
		player thread spawnPlayer();
		player thread PlayerKilled();
		player thread spawnSpectator();
		player thread disconnect();

	}
}

spawnPlayer()
{
	self endon("disconnect");
	
	
	for(;;)
	{
		self waittill("spawned_player");
	}
}
PlayerKilled()
{
	self endon("disconnect");
	
	for(;;)
	{
		self waittill("killed_player");
		self notify("delete_medkit");
		self thread deletemedkit();
		if (isDefined(self.medkitcounticon))
			self.medkitcounticon destroy();
		if (isDefined(self.medkitcountammo))
			self.medkitcountammo destroy();
	}
}
spawnSpectator()
{
	self endon("disconnect");
	
	for(;;)
	{
		self waittill("joined_spectators");
		self notify("delete_medkit");
		self thread deletemedkit();
		if (isDefined(self.medkitcounticon))
			self.medkitcounticon destroy();
		if (isDefined(self.medkitcountammo))
			self.medkitcountammo destroy();
	}
}
disconnect()
{
	self waittill("disconnect");
	self notify("delete_medkit");
	self thread deletemedkit();
}
GetMedkitType()
{
	medcrate = undefined;
	if( self.pers["team"] == "allies" )
		medcrate = "xmodel/allied_medkit1";
	else
		medcrate = "xmodel/axis_medkit1";
		
	return medcrate;
}
DropMedkit()
{
/*
	if ( !level.mc2_medkit_limit)
	{
		self iprintlnbold( "Maxmium Medkit Limit on Map Reached!" );
		return;
	}
*/	
	
	medkit = spawn( "script_model", (0,0,0) );
//	medkit = spawnstruct();
	medkit.origin = origin;
	medkit setmodel( medcrate );
	self.landmine.minetype = medcrate;
	medkit.targetname = medkits;
	medkit.angles = angles;
	
	medcrate = GetMedkitType();
	
	self.mc2_medkit_count--;
	self.mc2_medkit_limit--;
	
	self thread StartTimer();
	self thread StartHealth();
}
deleteMedkit()
{
	self notify("delete_medkit");
	self delete();
	self.mc2_medkit_limit++;
	self startReplenish();
}
replantMedkit()
{
	self notify("delete_medkit");
	self delete();
	self.mc2_medkit_count++;
	self iprintlnbold( "You Have Retaken Your Medkit!" );
}