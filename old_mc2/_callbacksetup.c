//	Callback Setup
//	This script provides the hooks from code into script for the gametype callback functions.

//=============================================================================
// Code Callback functions

/*================
Called by code after the level's main script function has run.
================*/
CodeCallback_StartGameType()
{
	// If the gametype has not beed started, run the startup
	if(!isDefined(level.gametypestarted) || !level.gametypestarted)
	{
		[[level.callbackStartGameType]]();

		level.gametypestarted = true; // so we know that the gametype has been started up
	}
}

/*================
Called when a player begins connecting to the server.
Called again for every map change or tournement restart.

Return undefined if the client should be allowed, otherwise return
a string with the reason for denial.

Otherwise, the client will be sent the current gamestate
and will eventually get to ClientBegin.

firstTime will be qtrue the very first time a client connects
to the server machine, but qfalse on map changes and tournement
restarts.
================*/
CodeCallback_PlayerConnect()
{
	self endon("disconnect");
	[[level.callbackPlayerConnect]]();
}

/*================
Called when a player drops from the server.
Will not be called between levels.
self is the player that is disconnecting.
================*/
CodeCallback_PlayerDisconnect()
{
	self notify("disconnect");
	self notify("TimeToDie");
	[[level.callbackPlayerDisconnect]]();
}

/*================
Called when a player has taken damage.
self is the player that took damage.
================*/
vectorMultiply (vec, dif)
{
	if(!isdefined(vec))return;
	vec = (vec[0] * dif, vec[1] * dif, vec[2] * dif);
	return vec;
}
CodeCallback_PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, timeOffset)
{
	self endon("disconnect");
	if(!isDefined(self.protected))
	{
		if(_mc2\_mc2_gore::WeaponType(sWeapon)=="rifle2"||_mc2\_mc2_gore::WeaponType(sWeapon)=="turret")
		{
			if(self.weg==0)
				self.weg=1;
		}
		else
		{
			if(self.weg==0)
				self.weg=2;
		}
		/*---------------------------------------
		BLOODFX
		----------------------------------------*/
		direction=vDir;
		//vDir2=int(-1*vDir);
		vDir2=vectorMultiply (vDir, -1);
//		vDir3=self.angles;
		if(_mc2\_mc2_gore::WeaponType(sWeapon)!="extranades")
		{
			if(sMeansOfDeath == "MOD_MELEE" || (isdefined(eAttacker)&&distance(eAttacker.origin , self.origin ) <= 48) )
			{
				if(isdefined(vdir2))
					direction=vDir2;				

			}
			if(_mc2\_mc2_gore::WeaponType(sWeapon)!="boom")
			{
				if(sMeansOfDeath != "MOD_FALLING")
				{
					if(level.bloodfx!=0)
					{
						if(isdefined(vdir2))
							playfx(level._effect["bloodimpact"],vpoint,vDir2);
					}
					if(level.bloodfx==0)
						playfx(level._effect["hit_flesh_org"],vpoint,direction);
					else if(level.bloodfx==1)
						playfx(level._effect["hit_flesh_mc"],vpoint,direction);
					else	
						playfx(level._effect["hit_flesh_mc2"],vpoint,direction);

					if(sMeansOfDeath != "MOD_MELEE")
						_mc2\_mc2_gore::bloodFX(sWeapon,sHitLoc);
				}
			}
		}
		self _mc2\_mc2_models::do_dmg_skins();
		/*---------------------------------------
		HIT LOCATION DAMAGE MODIFIER
		----------------------------------------*/
		hit = HitLoc(sHitLoc);
		if(sMeansOfDeath == "MOD_MELEE")
			iDamage = 15;
		else
			if (isDefined(hit) && hit != "none")
			{
				if(getcvar("scr_" + hit) != "")
					iDamage = int(iDamage * (getcvarint("scr_" + hit) * .01));
			}

		/*---------------------------------------
		TEAM DAMAGE
		----------------------------------------*/
		if(  isPlayer(eAttacker) && isPlayer(self) && isDefined(eAttacker.pers["team"]) && isDefined(self.pers["team"]) && eAttacker.pers["team"] == self.pers["team"] )
		{
			self.teamdamage = 1;	
		}
		else
		{
			self.teamdamage = undefined;
		}	
	
		/*---------------------------------------
		SCREAMS WHEN WEAPON IS A FLAME WEAPON
		----------------------------------------*/
		if(!isDefined(self.scr) && sMeansOfDeath == "MOD_FLAME")
		{
				self thread _mc2\_mc2_util::scream("m");		
		}


		if(!isDefined(level.scr_tkpunish)) 
			level.scr_tkpunish = 0;

		if(!isDefined(iDamage))
			iDamage = 1;

		if(sWeapon != "fire_mp" &&  sWeapon != "axisgas_mp" && sWeapon != "axisfire_mp" && sWeapon !="alliedgas_mp" && sMeansOfDeath != "MOD_UNKNOWN") 
		{
			
// changed by bell since MOD_FALLING does not have an eAttacker but code below expects one
//			if(level.realism && ( (isPlayer(eAttacker) && isPlayer(self)) || sMeansOfDeath == "MOD_FALLING" )  )
			if(level.realism && isPlayer(eAttacker) && isPlayer(self))
			{
				if( ((level.friendlyfire == "0" || level.friendlyfire == "2" || level.friendlyfire == "3" ) && self.pers["team"] != eattacker.pers["team"] ) || (level.friendlyfire == "1") )
				{
					if(!isDefined(eAttacker.pers["tmdmg"]))
						eAttacker.pers["tmdmg"] = iDamage;
					if(isDefined(eAttacker.pers["tmdmg"]))
					{
						if(  (level.scr_tkpunish > 0  && eAttacker.pers["tmdmg"] + iDamage > level.scr_tkpunish ) || level.scr_tkpunish == 0)
						{
							switch(hit)
							{

							case "leg":
							case "foot":
							case "none":
								if(iDamage >= 80 && iDamage < 100 && hit != "none")
								{
									if(self.stance==2)
										_mc2\_mc2_util::forceto("crouch");
								}
								else if(iDamage < 80 && iDamage >= 50 && hit != "none") 
								{
									if(self.stance==2)
										_mc2\_mc2_util::forceto("crouch");
								}
								else if(iDamage >= 20 && iDamage < 50 && hit != "none")
								{
									_mc2\_mc2_util::forceto("prone");
								}
							//	if(!isDefined(self.legdmg) )
							//	{
							//		self.legdmg = 0;
							//		if(self.health - iDamage > 0 )
							//			self iprintln(level._legdmg);
							//	}
							//	self.legdmg += iDamage;
							//	if(self.legdmg > 150) self.legdmg = 150;
							//	if(self.legdmg < 160) self.maxspeed = 160 - self.legdmg;
							break;
							}
						}
					}
				}
			}
		}
		[[level.callbackPlayerDamage]](eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, timeOffset);
	}
}

/*================
Called when a player has been killed.
self is the player that was killed.
================*/
CodeCallback_PlayerKilled(eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, timeOffset, deathAnimDuration)
{
	self endon("disconnect");
	[[level.callbackPlayerKilled]](eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, timeOffset, deathAnimDuration);
}

//=============================================================================

/*================
Setup any misc callbacks stuff like defines and default callbacks
================*/
SetupCallbacks()
{
	SetDefaultCallbacks();
	
	// Set defined for damage flags used in the playerDamage callback
	level.iDFLAGS_RADIUS			= 1;
	level.iDFLAGS_NO_ARMOR			= 2;
	level.iDFLAGS_NO_KNOCKBACK		= 4;
	level.iDFLAGS_NO_TEAM_PROTECTION	= 8;
	level.iDFLAGS_NO_PROTECTION		= 16;
	level.iDFLAGS_PASSTHRU			= 32;
}

/*================
Called from the gametype script to store off the default callback functions.
This allows the callbacks to be overridden by level script, but not lost.
================*/
SetDefaultCallbacks()
{
	level.default_CallbackStartGameType = level.callbackStartGameType;
	level.default_CallbackPlayerConnect = level.callbackPlayerConnect;
	level.default_CallbackPlayerDisconnect = level.callbackPlayerDisconnect;
	level.default_CallbackPlayerDamage = level.callbackPlayerDamage;
	level.default_CallbackPlayerKilled = level.callbackPlayerKilled;
}

/*================
Called when a gametype is not supported.
================*/
AbortLevel()
{
	println("Aborting level - gametype is not supported");

	level.callbackStartGameType = ::callbackVoid;
	level.callbackPlayerConnect = ::callbackVoid;
	level.callbackPlayerDisconnect = ::callbackVoid;
	level.callbackPlayerDamage = ::callbackVoid;
	level.callbackPlayerKilled = ::callbackVoid;
	
	setcvar("g_gametype", "dm");

	exitLevel(false);
}

/*================
================*/
callbackVoid()
{
}

/*================
return the hit location for use with the location based damage modifiers
================*/
hitloc(sHitLoc)
{
	switch(sHitLoc)
	{
	case "right_hand":
	case "left_hand":
		return "hand";
	case "right_arm_upper":	
	case "right_arm_lower":	
	case "left_arm_upper":
	case "left_arm_lower":
		return "arm";
	case "head":
	case "helmet":
		return "head";
	case "neck":
		return "neck";
	case "right_foot":
	case "left_foot":
		return "foot";
	case "right_leg_lower":
	case "left_leg_lower":
	case "right_leg_upper":
	case "left_leg_upper":
		return "leg";
	case "torso_upper":
		return "torso_up";
	case "torso_lower":
		return "torso_dn";
	default:
		return "none";
	}
}
