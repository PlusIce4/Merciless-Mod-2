/**************************************************************************
MERCILESS MOD 2 V3.4+
Developed by PlusIce (current), Merciless Mod Team (previous work)
See credits.txt for complete works cited
**************************************************************************/
/* -----------------------------------------------------
SHELLSHOCK OF VARIOUS TYPES
sLoc = hit location | determines type of shellshock
sWPN = NotUSed
sDMG = Damage Amount
sMOD = Means of Death 	
---------------------------------------------------- */

#include _mc2\_cd;
#include _mc2\_forceto;
#include _mc2\_painsounds;


PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{

	//[Merciless2]///////////////////////////////
	if(isdefined(self.protected))return;
	if(isDefined(sWeapon) && sWeapon == "axisgas_mp"||sWeapon == "alliedgas_mp" && sMeansOfDeath != "MOD_MELEE")
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
GetGasNadeType()
{
	sWeapon = undefined;
	if( self.pers["team"] == "allies" )
		sWeapon = "alliedgas_mp";
	else
		sWeapon = "axisgas_mp";
		
	return sWeapon;
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
//Begin split
/* ----------------------------------------------------- 
   CREATE THE AREA EFFECT 
   AND DAMAGE FOR THE MUSTARD GAS 
   eAttacker = owner of damage 
   vPoint = mustard gas grenade coords 
---------------------------------------------------- */ 
MonitorMustardGas(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
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
			sWeapon = GetGasNadeType(); 
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