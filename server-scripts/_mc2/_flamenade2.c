/**************************************************************************
MERCILESS MOD 2 V3.4+
Developed by PlusIce (current), Merciless Mod Team (previous work)
See credits.txt for complete works cited
**************************************************************************/

#include _mc2\_cd;
#include _mc2\_painsounds;

PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	if(isDefined(sWeapon) && sMeansOfDeath != "MOD_MELEE" && sWeapon == "fire_mp"||sWeapon == "axisfire_mp")
	{
		if (!isDefined(vPoint))
			vPoint = self.origin + (0,0,11);
		if(isDefined(level.cocktail) && level.cocktail == vPoint)
			return;
		level.cocktail = vPoint;
		level thread MonitorCocktail(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, level.cocktail, vDir, sHitLoc, psOffsetTime);
			return;		
	}
}	
GetFlameNadeType()
{
	sWeapon = undefined;
	if( self.pers["team"] == "allies" )
		sWeapon = "fire_mp";
	else
		sWeapon = "axisfire_mp";
		
	return sWeapon;
}
/* ----------------------------------------------------- 
   CREATE THE AREA EFFECT 
   AND DAMAGE FOR THE COCKTAIL 
   eAttacker = owner of damage 
   vPoint = cocktail explosion coords 
---------------------------------------------------- */ 
MonitorCocktail(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime) 
{ 	
	self endon("TimeToDie");
	self endon("disconnect");

	//PLAY EFFECT FOR 12 SECONDS 
	burntime = 13;     

	for(j = 0;j < burntime ;j++) 
	{ 
		//LOOP THROUGH PLAYERS AND DETERMINE WHO IS IN RANGE 
		players = getentarray("player", "classname"); 
		for(i=0;i<players.size;i++) 
		{ 
			dst = distance(vPoint, players[i].origin); 
			if( dst > 240 || players[i].sessionstate != "playing" || !isAlive(players[i]) ) 
				continue; 

			if(dst < 240 )
			{
				iDamage = int(45 * (1 - (dst / 240)));
			}
			if(dst <= 140 )
				players[i] thread Burn(13);
				

			if(dst > 140 )
				players[i] thread Burn(5);

			sMeansOfDeath = "MOD_UNKNOWN";
			sWeapon = GetFlameNadeType();
			iDFlags = 1; 
			if(iDamage < players[i].health )
			{
				if(!isDefined(players[i].scr))
					players[i] thread scream("m");
				players[i].health = players[i].health - iDamage;
			} 
			else
			{
				if(iDamage < players[i].health)
				{
					if(randomint(100) > 70)
						players[i] playsound(players[i].painsounds);

					players[i].health = players[i].health - iDamage;
				} 
				else
				{
					players[i] finishPlayerDamage(eAttacker, eAttacker, iDamage , iDFlags , sMeansOfDeath , sWeapon , (players[i].origin + (0,0,-300)), vDir, sHitLoc,psOffsetTime);
				}
			}
		} 
		wait(1); 
	} 
}

PlayerBurn()
{
	self endon("TimeToDie");
	self endon("disconnect");

	if(isDefined(self.isonfire))
		return;	

	self shellshock("mc_mustard", 1);
	self.isonfire = 1;
	tag="pelvis";
	
	for(i =0;i<13;i++)
	{
		switch(randomint(15))
		{
		case 0: tag = "j_hip_le";break;
		case 1: tag = "j_hip_ri";break;
		case 2: tag = "j_knee_le";break;
		case 3: tag = "j_ankle_ri";break;
		case 4: tag = "j_knee_ri";break;
		case 5: tag = "pelvis";break;
		case 6:	tag = "j_wrist_ri";break;
		case 7: tag = "j_head";break;
		case 8:tag = "j_shoulder_le";break;
		case 9:tag = "j_shoulder_ri";break;
		case 10:tag = "j_elbow_le";break;
		case 11: tag = "j_elbow_ri";break;
		case 12: tag = "j_wrist_le";break;	
		}
		if(isDefined(self))
		{
			playfxontag(level._effect["playerburn2"], self, tag);
			playfxontag(level._effect["playerburn"], self, "pelvis");
		}
		wait .25;
	}
		if(isAlive(self))
		self.isonfire = undefined;
}
Burn(burntime)
{
	self endon("TimeToDie");
	self endon("disconnect");

	if(isDefined(self.isonfire))
		return;	

	self.isonfire = 1;
	tag="j_spine1";
	
	for(i =0;i<burntime;i++)
	{
		switch(randomint(13))
		{
		case 0: tag = "j_hip_le";break;
		case 1: tag = "j_hip_ri";break;
		case 2: tag = "j_knee_le";break;
		case 3: tag = "j_ankle_ri";break;
		case 4: tag = "j_knee_ri";break;
		case 5: tag = "j_spine1";break;
		case 6:	tag = "j_wrist_ri";break;
		case 7: tag = "j_head";break;
		case 8:tag = "j_shoulder_le";break;
		case 9:tag = "j_shoulder_ri";break;
		case 10:tag = "j_elbow_le";break;
		case 11: tag = "j_elbow_ri";break;
		case 12: tag = "j_wrist_le";break;	
		}
		if(burntime==5)
		{
			if(isDefined(self))
				self thread burnfx(tag, level._effect["playerburn2"], .1);
		}
		else
		{
			if(isDefined(self))
			{
				playfxontag(level._effect["playerburn2"], self, tag);
				playfxontag(level._effect["playerburn"], self, "j_spine1");
			}		
		}
		wait .25;
	}
		if(isAlive(self))
		self.isonfire = undefined;
}
burnfx(tag, fxName, loopTime)
{
	self endon("TimeToDie");
	self endon("disconnect");
	while(isdefined(self)&&isdefined(self.isonfire))
	{
		playfxOnTag (fxName, self, tag);
		wait (loopTime);
	}
}