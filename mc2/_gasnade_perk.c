/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: PlusIce, Merciless Mod Team, */
/* Script Code Snippets: */
/* Gas Grenade Perk */


#include mc2\_utils_cvardef;
#include mc2\_utils_realism;
#include mc2\_utils_voiceovers;

init()
{
	if( !level.mc2_gasnades ) return;
	if( level.mc2_scrim ) return;
	
	//Enabled or Disabled
	level.mc2_gasnades 			= cvardef("mc2_gasnades",1,0,1,"int");

	level.mc2_gastime 			= cvardef("mc2_gastime",10,0,999,"int");

	precacheShellShock("mc_mustard");
	precacheShellShock("mc_default");
	precacheShellShock("mc_hit3");	
}
defineGasNade()
{
	sWeapon = undefined;
	if( self.pers["team"] == "allies" )
		sWeapon = "am_gas_mp";
	else
		sWeapon = "ax_gas_mp";
		
	return sWeapon;
}
Callback_PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	if(self.sessionteam == "spectator") return;
	if(isdefined(self.protected))return; //fix this line
	if(isDefined(sWeapon) && sWeapon == "ax_gas_mp"||sWeapon == "am_gas_mp")
	{
			if(sWeapon == "am_gas_mp" && sMeansOfDeath != "MOD_MELEE")
			{
				if (!isDefined(vPoint))
					vPoint = self.origin + (0,0,11);
				if(isDefined(level.mustardgas) && level.mustardgas == vPoint)
					return;
				level.mustardgas = vPoint;
				level thread MonitorMustardGas(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, level.mustardgas, vDir, sHitLoc, psOffsetTime);
				return;
			}
			else if(sWeapon == "ax_gas_mp" && sMeansOfDeath != "MOD_MELEE")
			{
				if (!isDefined(vPoint))
				vPoint = self.origin + (0,0,11);
				if(isDefined(level.mustardgas) && level.mustardgas == vPoint)
				return;
				level.mustardgas = vPoint;
				level thread MonitorMustardGas(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, level.mustardgas, vDir, sHitLoc, psOffsetTime);
				return;

			}
	}

}
shockFX(sLOC, sWPN, sDMG , sMOD)
{		
	if(getCvarint("scr_shellshock") < 1 )
		return;
	if (sMOD != "MOD_EXPLOSIVE")
	{

		if(sDMG > 100)
			sDMG = 100;

		switch(sLOC)		
		{		
		case "head": case "neck": case "helmet":
			type = "mc_default";
			break;	
		case "torso_lower":
			type = "mc_mustard";
			break;
		case "torso_upper": 
			type = "mc_hit3";
			break;
		case "none":
			type = "mc_hit3";
			break;
		default: 
			type = "mc_mustard";
		}
		/*if(sLOC == "head" || sLOC == "none")
		{
			if(sDMG > 100)
				self viewkick(96, self.origin);
			else if(sDMG > 75 && sDMG <= 100)
				self viewkick(40,self.origin);
			else if(sDMG > 50 && sDMG <= 75)
				self viewkick(20,self.origin);
			else 
				self viewkick(5,self.origin);
		}*/
		self shellshock(type, (sDMG * .025) );
		wait(sDMG * .025);
	}
}
MonitorMustardGas(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{ 
	self endon("TimeToDie");
	self endon("disconnect");
	//PLAY EFFECT FOR 15 SECONDS 
	gastime = getCvarInt( "mc2_gastime" );     
	for(j = 0;j <= gastime;j++) 
	{ 
		//LOOP THROUGH PLAYERS AND DETERMINE WHO IS IN RANGE 
		players = getentarray("player", "classname"); 
		for(i=0;i<players.size;i++) 
		{ 
			dst = distance(vPoint, players[i].origin); 

			//AREA WHICH PLAYER WILL BE AFFECTED EXPANDS 
			//ALONG WITH THE GAS/SMOKE (~2ft per sec)

			if( dst > 200 + (j * 20) || players[i].sessionstate != "playing" || !isAlive(players[i]) ) 
				continue; 
			//DAMAGE THE PLAYER

			pcnt = 200 + (j * 20);
			if(dst > pcnt * .75 ) 					// 0-25% dmg
				iDamage = randomint(5);
			else if(dst > pcnt * .5 && dst < pcnt * .75) 	// 25-50 % dmg
				iDamage = 15 + randomint(5);
			else if(dst > pcnt *.25 && dst < pcnt * .5) 	// 59-75% dmg
				iDamage = 30 + randomint(5);
			else if(dst < pcnt * .25)				// 100% dmg
				iDamage = 45 + randomint(5);

			//vDir = undefined; 
			//SET THE MOD 
			sMeansOfDeath = "MOD_UNKNOWN"; 
			// SET THE WEAPON TO "NONE" SO THE DAMAGE CALLBACK 
			// DOESNT PICK IT BACK UP AND RESTART THE THREAD 
			sWeapon = self defineGasNade();
			iDFlags = 1; 

			players[i] thread GasPlayer(eAttacker, eAttacker, iDamage, iDFlags , sMeansOfDeath , sWeapon, vPoint , undefined,"none",psOffsetTime); 
		} 
		wait(1); 
	}    
} 

/* ----------------------------------------------------- 
   CAUSE THE DAMAGE & EFFECT 
   eAttacker = owner of damage 
   vPoint = mustard gas grenade coords 

   TODO: 

      -make a custom HUD shader to go along with 
      the custom shellshock. 
---------------------------------------------------- */ 
GasPlayer(eAttacker, eAttacker, iDamage, iDFlags , sMeansOfDeath , sWeapon, vPoint , vDir, sHitLoc,psOffsetTime) 
{ 
	self endon("TimeToDie");
	self endon("disconnect");
	len=undefined;
	if(!isDefined(self.gassed)) 
	{
		if(iDamage <= 5)
			len = .25*2;
		else if(iDamage >=5 && iDamage < 10)
			len = .45*2;
		else if(iDamage >= 10 && iDamage < 15)
			len = .75*2;
		else if(iDamage >= 15)
			len = 1*2; //4
		self shellshock("mc_mustard",len);
		self.gassed = 1;
	}
	
	if(!isDefined(self.puked) && randomint(100) > 70) //30% chance to puke
	{
		playfxontag (level._effect["puke"], self, "j_Head");
		forceto("crouch");
		if(!isDefined(self.scr))
		{
			if(!isDefined(self.scr) )
				self thread scream("p");
			self.puked = 1;
		}
	}
	else
	{
		if(randomint(100)>70)
		{
			if(!isDefined(self.scr))
				self thread scream("h");
		}
		else
		{
			if(!isDefined(self.scr))
				self scream("mc");
		}
	}
	
	if(self.health - iDamage <= 0)
		self finishPlayerDamage(eAttacker, eAttacker, 5 , iDFlags , sMeansOfDeath , sWeapon , (self.origin + (0,0,-300)), vDir, sHitLoc,psOffsetTime);
	else
		self.health = self.health -iDamage;
	
	if(isAlive(self))
	{ 
		if(isDefined(self.gassed))
			return;		
		self.gassed = undefined; 
	}

}
