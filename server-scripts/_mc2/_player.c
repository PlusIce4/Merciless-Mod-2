/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_painsounds;
#include _mc2\_forceto;

StartGameType()
{
	//flags
	_mc2\_levelflags::InitPlayer_Flags();
	
	//sprint
	//if(getcvarint("scr_" + self.pers["pClass"] + "_speed") < 1)
		self.maxspeed = getcvar("g_speed");
	//else
	//	self.maxspeed = getcvarint("scr_" + self.pers["pClass"] + "_speed");
	
	//bots
	thread _mc2\_bots::init();
	thread _mc2\_bots::addTestClients();

	//SpawnProtection int
	_mc2\_protect::init();
	
	_mc2\_mc2_init::init();
	_mc2\pb::pb_init();

	thread _mc2\_mc2_classes::init();
	thread _mc2\_mc2_classes::MonitorClasses();
		
//	_mc2\_mortars::init(); //update later
	_mc2\_artillery::init();
	_mc2\_mc2_special::init(); //Eliminate later
	// Sprinting
	thread _mc2\_sprinting::init();  // Added by bell
	_mc2\_healthpacks::init();

  	thread _mc2\_protect::nozombie(); 
  		
	thread _mc2\_bannerimage::banner_image("gfx/hud/logo_mc1.tga", 179,45,15,-5);
}
PlayerConnect()
{



}
PlayerDisconnect()
{


}
spawnPlayer()
{
	//Spawn Protection
	_mc2\_protect::ProtectSpawnPlayer();

	if(isdefined(game["german_soldiertype"]) && (game["german_soldiertype"] == "winterlight"||game["german_soldiertype"] == "winterdark")
	||isdefined(game["russian_soldiertype"]) && (game["russian_soldiertype"] == "padded"||game["russian_soldiertype"] == "coats")&&level.scr_coldbreath==1)
		self thread _mc2\_coldbreath::breath();
			

	//Skins
	self thread _mc2\_playermodels::checkAttachment_head();
	self thread _mc2\_playermodels::checkAttachment_hat();
	
	self thread _mc2\_buttonusage::checkStance();
	self thread _mc2\_buttonusage::check_adsbutton();

	//deadbody handling
	//self thread _mc2\_mc2_gore::check_nade();
	self thread _mc2\_mc2_gore::body_shooting();	

	_mc2\_mc2_hud::hud();

	//Reset some HUD Elems
	_mc2\_clearhud::resetHUD();

	self _mc2\_sprinting::RunOnSpawn(); // Added by bell

	//Wait until player dies
	self waittill("TimeToDie", attacker);
	
	_mc2\_sprinting::CleanupKilled(); // Added by bell

	//Clean up HUD Elems
	_mc2\_clearhud::hud_playerdeath();

	//Obitsys
	_mc2\_obitsys::ObitSpawnPlayer(attacker);
}
spawnSpectator()
{
	self _mc2\_clearhud::resetHUD();
	self _mc2\_clearhud::hud_playerdeath();
	if(isDefined(self.sprot))
		self.sprot destroy();

}
PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	if(isdefined(self.burned)&&self.burned==1||sMeansOfDeath == "MOD_UNKNOWN"||sMeansOfDeath == "MOD_FALLING"||isDefined(self.protected))return;

	if (!isDefined(vPoint))
		vPoint = self.origin + (0,0,11);

	if(isDefined(self.scr) && self.health - iDamage > 0 )
		self thread _doSounds("pain",sMeansOfDeath);

	if (isPlayer(eAttacker) && sMeansOfDeath != "MOD_FALLING" && level.scr_bloodyscreen)
	{
		if(sMeansOfDeath == "MOD_MELEE" || distance(eAttacker.origin , self.origin ) <= 48 )
			eAttacker thread _mc2\_mc2_gore::Splatter_View();

		if(level.scr_showhit )
			eAttacker thread _mc2\_mc2_gore::showhit();
	}
	if(sHitLoc == "head" || shitLoc=="none" || sHitLoc=="helmet")
	{
		if(level.scr_bloodyscreen && (!isDefined(self.thrown)))
			self thread _mc2\_mc2_gore::Splatter_View();
	}
	if(level.scr_extragore && sMeansOfDeath != "MOD_GRENADE" && sMeansOfDeath != "MOD_GRENADE_SPLASH")
	{
		if(level.bloodfx==0)return;
		else if(level.bloodfx==1)
		{
			switch (randomint(3))
			{
				case 0:	playfx(level._effect["hit_extra1_mc"],vPoint,vDir);break;		
				case 1: playfx(level._effect["hit_extra2_mc"],vPoint,vDir);break;
				case 2: playfx(level._effect["hit_extra3_mc"],vPoint,vDir);break;
			}
		}
		else
		{
			switch (randomint(3))
			{
				case 0:	playfx(level._effect["hit_extra1"],vPoint,vDir);break;		
				case 1: playfx(level._effect["hit_extra2"],vPoint,vDir);break;
				case 2: playfx(level._effect["hit_extra3"],vPoint,vDir);break;
			}
		}
	}
	
	if(sHitLoc == "right_hand"|| sHitLoc == "left_hand" || sHitLoc == "gun" || sHitLoc == "right_arm_lower" || sHitLoc == "left_arm_lower")
	{		
		if ( isAlive(self) && level.scr_dropweaponhit > randomint(99))
			self dropItem(self getcurrentweapon());
	}
	if(level.realism && sHitLoc == "left_leg_upper" || sHitLoc == "right_leg_upper" || sHitLoc == "left_leg_lower" || sHitLoc == "right_leg_lower" || sHitLoc == "left_foot" || sHitLoc == "right_foot")
	{
		if(self.stance==2)
			forceto("crouch");
		else if(self.stance==1)
			forceto("prone");
	}
	
	if(sHitLoc == "head"|| sHitLoc=="helmet")
	{	

		if( self.health - iDamage < 1  &&  (iDamage >= level.scr_decap_min) && sMeansOfDeath != "MOD_MELEE" )
		{
			}
			else		
			if(self.decaped != 1 )
			{
					self thread _doSounds("death",sMeansOfDeath);						
			}		
	}
	
	if(sHitLoc == "none")
	{			
		if(sMeansOfDeath == "MOD_PROJECTILE" || sMeansOfDeath == "MOD_PROJECTILE_SPLASH" || sMeansOfDeath == "MOD_GRENADE" || sMeansOfDeath == "MOD_GRENADE_SPLASH" || sMeansOfDeath == "MOD_EXPLOSIVE")
		{
			if(self.health - iDamage < 1)
			{
				if(isDefined(eInflictor))
				{
					if(distance(eInflictor.origin,self.origin)<=100)
					{
					}
					else if(distance(eInflictor.origin,self.origin)>100)
					{
						if( (iDamage >= level.scr_decap_min) && (level.scr_decap_chance >= randomint(100)) && (sMeansOfDeath != "MOD_MELEE") && (!isDefined(self.thrown)) )
						{
						}
						else
						{
								self thread _doSounds("death",sMeansOfDeath);
						}
					}
				}
			}
		}
	}
}
PostPlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	//Gas Nade
	self thread _mc2\_gasnade::GasPlayerDamage(vPoint, eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, level.mustardgas, vDir, sHitLoc, psOffsetTime);

	//flame nade
	self thread _mc2\_flamenade::FlamePlayerDamage(vPoint, eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, level.flamenade, vDir, sHitLoc, psOffsetTime);

	//helmet pop
	thread _mc2\_helmetpop::HelmetPlayerDamage(sHitLoc, sMeansOfDeath, self.helm, vPoint, self.curhat, iDamage, "death", org, ch, vDir, model);

}
PlayerKilled(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration)
{
	
	if(self.sessionteam == "spectator")
		return;

	if(isPlayer(attacker))
	{
		if(attacker == self) // killed himself
		{
		}
		else
		{

			if(level.awe_teamplay && self.pers["team"] == attacker.pers["team"]) // killed by a friendly
			{
				attacker _mc2\_teamkilling::TeamKill();
			}
			else		// killed by an enemy
			{
			}
		}
	}
	else // If you weren't killed by a player, you were in the wrong place at the wrong time
	{
	}
		
	// Drop health
	_mc2\_healthpacks::dropHealth();

	//Bloodpools
	_mc2\_bloodpools::BloodPlayerKilled(self.burned, self.origin);

	//PlayerBurn
	_mc2\_playerburn::BurnPlayerKilled(self.burned, sWeapon);

}
endMap()
{
	//remove bots
	thread _mc2\_bots::removeTestClients();

}