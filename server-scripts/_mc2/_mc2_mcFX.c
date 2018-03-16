/* -----------------------------------------------------
Edited by PlusIce
SHELLSHOCK OF VARIOUS TYPES
sLoc = hit location | determines type of shellshock
sWPN = NotUSed
sDMG = Damage Amount
sMOD = Means of Death 	
---------------------------------------------------- */
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

//Begin split
/* ----------------------------------------------------- 
   CREATE THE AREA EFFECT 
   AND DAMAGE FOR THE MUSTARD GAS 
   eAttacker = owner of damage 
   vPoint = mustard gas grenade coords 
---------------------------------------------------- */ 
AlliedMonitorMustardGas(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{ 
	self endon("TimeToDie");
	self endon("disconnect");
	//PLAY EFFECT FOR 15 SECONDS 
	gastime = 10;     
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
			sWeapon = "alliedgas_mp"; 
			iDFlags = 1; 

			players[i] thread AlliedGasPlayer(eAttacker, eAttacker, iDamage, iDFlags , sMeansOfDeath , sWeapon, vPoint , undefined,"none",psOffsetTime); 
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
AlliedGasPlayer(eAttacker, eAttacker, iDamage, iDFlags , sMeansOfDeath , sWeapon, vPoint , vDir, sHitLoc,psOffsetTime) 
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
		_mc2\_mc2_util::forceto("crouch");
		if(!isDefined(self.scr))
		{
			if(!isDefined(self.scr) )
				self thread _mc2\_mc2_util::scream("p");
			self.puked = 1;
		}
	}
	else
	{
		if(randomint(100)>70)
		{
			if(!isDefined(self.scr))
				self thread _mc2\_mc2_util::scream("h");
		}
		else
		{
			if(!isDefined(self.scr))
				self _mc2\_mc2_util::scream("mc");
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
/* ----------------------------------------------------- 
   CREATE THE AREA EFFECT 
   AND DAMAGE FOR THE COCKTAIL 
   eAttacker = owner of damage 
   vPoint = cocktail explosion coords 
---------------------------------------------------- */ 
AlliedMonitorCocktail(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime) 
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
				players[i] thread AlliedBurn(13);

			if(dst > 140 )
				players[i] thread AlliedBurn(5);

			sMeansOfDeath = "MOD_UNKNOWN";
			sWeapon = "fire_mp";
			iDFlags = 1; 
			if(iDamage < players[i].health )
			{
				if(!isDefined(players[i].scr))
					players[i] thread _mc2\_mc2_util::scream("m");
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

AlliedPlayerBurn()
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
AlliedBurn(burntime)
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
				self thread alliedburnfx(tag, level._effect["playerburn2"], .1);
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
alliedburnfx(tag, fxName, loopTime)
{
	self endon("TimeToDie");
	self endon("disconnect");
	while(isdefined(self)&&isdefined(self.isonfire))
	{
		playfxOnTag (fxName, self, tag);
		wait (loopTime);
	}
}
//Begin Axis Script
/* ----------------------------------------------------- 
   CREATE THE AREA EFFECT 
   AND DAMAGE FOR THE MUSTARD GAS 
   eAttacker = owner of damage 
   vPoint = mustard gas grenade coords 
---------------------------------------------------- */ 
AxisMonitorMustardGas(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{ 
	self endon("TimeToDie");
	self endon("disconnect");
	//PLAY EFFECT FOR 15 SECONDS 
	gastime = 10;     
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
			sWeapon = "axisgas_mp"; 
			iDFlags = 1; 

			players[i] thread AxisGasPlayer(eAttacker, eAttacker, iDamage, iDFlags , sMeansOfDeath , sWeapon, vPoint , undefined,"none",psOffsetTime); 
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
AxisGasPlayer(eAttacker, eAttacker, iDamage, iDFlags , sMeansOfDeath , sWeapon, vPoint , vDir, sHitLoc,psOffsetTime) 
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
		_mc2\_mc2_util::forceto("crouch");
		if(!isDefined(self.scr))
		{
			if(!isDefined(self.scr) )
				self thread _mc2\_mc2_util::scream("p");
			self.puked = 1;
		}
	}
	else
	{
		if(randomint(100)>70)
		{
			if(!isDefined(self.scr))
				self thread _mc2\_mc2_util::scream("h");
		}
		else
		{
			if(!isDefined(self.scr))
				self _mc2\_mc2_util::scream("mc");
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
/* ----------------------------------------------------- 
   CREATE THE AREA EFFECT 
   AND DAMAGE FOR THE COCKTAIL 
   eAttacker = owner of damage 
   vPoint = cocktail explosion coords 
---------------------------------------------------- */ 
AxisMonitorCocktail(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime) 
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
				players[i] thread BurnAxis(13);

			if(dst > 140 )
				players[i] thread BurnAxis(5);

			sMeansOfDeath = "MOD_UNKNOWN";
			sWeapon = "axisfire_mp";
			iDFlags = 1; 
			if(iDamage < players[i].health )
			{
				if(!isDefined(players[i].scr))
					players[i] thread _mc2\_mc2_util::scream("m");
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

PlayerBurnAxis()
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
BurnAxis(burntime)
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
				self thread axisburnfx(tag, level._effect["playerburn2"], .1);
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
axisburnfx(tag, fxName, loopTime)
{
	self endon("TimeToDie");
	self endon("disconnect");
	while(isdefined(self)&&isdefined(self.isonfire))
	{
		playfxOnTag (fxName, self, tag);
		wait (loopTime);
	}
}
//------------------------------------------------------------------------------------//
//Split code again to give payload artillery napalm effect
//------------------------------------------------------------------------------------//
NapalmMonitorCocktail(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime) 
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
				players[i] thread BurnNapalm(13);

			if(dst > 140 )
				players[i] thread BurnNapalm(5);

			sMeansOfDeath = "MOD_UNKNOWN";
			sWeapon = "payload_mp";
			iDFlags = 1; 
			if(iDamage < players[i].health )
			{
				if(!isDefined(players[i].scr))
					players[i] thread _mc2\_mc2_util::scream("m");
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

PlayerBurnNapalm()
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
BurnNapalm(burntime)
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
				self thread napalmburnfx(tag, level._effect["playerburn2"], .1);
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
napalmburnfx(tag, fxName, loopTime)
{
	self endon("TimeToDie");
	self endon("disconnect");
	while(isdefined(self)&&isdefined(self.isonfire))
	{
		playfxOnTag (fxName, self, tag);
		wait (loopTime);
	}
}