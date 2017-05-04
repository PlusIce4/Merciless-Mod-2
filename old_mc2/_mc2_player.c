/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
//Removed all gibbing
-------------------------------------------*/
/*------------------------------------------

Initializes the player and all attributes
Disabled decap chance from 100 to 0

------------------------------------------*/
_mc2_InitPlayer()
{
	self.team = self.pers["team"];
	self.killspree = 0;
	self.decaped = 0;
	self.bleed = 11;
	self.isonfire = undefined;
	self.isKnockedOut = undefined;
	self.puked = undefined;
	self.gassed = undefined; 
	self.thrown = undefined;
	self.scr = undefined;
	self.hand_dmg=undefined;
	self.legdmg = undefined;
	self.helm=0;
	self.spltr=0;
	self.weg=0;
	self.dmg=0;
	self.verwundet=0;
	self.suicide=undefined;

	//if(getcvarint("scr_" + self.pers["pClass"] + "_speed") < 1)
		self.maxspeed = getcvar("g_speed");
	//else
	//	self.maxspeed = getcvarint("scr_" + self.pers["pClass"] + "_speed");
}
_mc2_StartGameType()
{
	_mc2\_mc2_init::init();
	_mc2\pb::pb_init();

	thread _mc2\_mc2_classes::init();
	thread _mc2\_mc2_classes::MonitorClasses();
		
//	_mc2\_mortars::init(); //off for now
	_mc2\_artillery::init();
	//special action
	_mc2\_mc2_special::init();
	// Sprinting
	thread _mc2\_sprinting::init();  // Added by bell
	_mc2\_healthpacks::init();

  	thread _mc2\_mc2_util::nozombie(); //disable it?
  	if(level.scr_merciless2_logo!=0)
  		thread _mc2\_mc2_util::merciless2_logo("gfx/hud/logo_mc1.tga", 179,45,15,-5);
}
_mc2_spawnPlayer()
{
	if(level.scr_spawnprotect)
		self thread _mc2\_mc2_util::spawnprotect();

	if(isdefined(game["german_soldiertype"]) && (game["german_soldiertype"] == "winterlight"||game["german_soldiertype"] == "winterdark")
	||isdefined(game["russian_soldiertype"]) && (game["russian_soldiertype"] == "padded"||game["russian_soldiertype"] == "coats")&&level.scr_coldbreath==1)
		self thread _mc2\_mc2_util::breath();

	//Skins
	self thread _mc2\_mc2_models::checkAttachment_head();
	self thread _mc2\_mc2_models::checkAttachment_hat();
	
	self thread _mc2\_mc2_util::checkStance();
	self thread _mc2\_mc2_util::check_adsbutton();

	//deadbody handling
	//self thread _mc2\_mc2_gore::check_nade();
	self thread _mc2\_mc2_gore::body_shooting();	

	_mc2\_mc2_hud::hud();

	//Reset some HUD Elems
	_mc2\_mc2_util::resetHUD();

	self _mc2\_sprinting::RunOnSpawn(); // Added by bell

	//Wait until player dies
	self waittill("TimeToDie", attacker);
	
	_mc2\_sprinting::CleanupKilled(); // Added by bell

	//Clean up HUD Elems
	_mc2\_mc2_util::hud_playerdeath();

	//If the person killed had a killing spree, 
	//then notify the players that it has been ended
//	if(self.killspree > 5 && isPlayer(attacker) && isAlive(attacker))			
//		iprintln(attacker.name + " ^7put and end to " + self.name + "'s ^7 killing spree!");	

	if( isplayer(attacker) && isAlive(attacker))
	{
		
		if ( (attacker != self) && (getcvar("g_gametype") != "dm") && (attacker.team != self.team) )
		{
			attacker.killspree++;
		}
		if ( (attacker != self) && (getcvar("g_gametype") == "dm")  )
		{
			attacker.killspree++;
		}
	
		rn = randomint(16);
	
		if(attacker != self && isDefined(attacker.team) && isDefined(self.team) && attacker.team != self.team )
		{
			if (attacker.killspree == 2 || attacker.killspree == 3)
			{
				if(attacker.killspree == 3)
					iprintln(attacker.name + &"^7is on a roll with ^1" + attacker.killspree + &"^7 kills!"); //enable again
				rn = randomint(10);
			}
			if (attacker.killspree == 4 || attacker.killspree == 5)
			{
				if(attacker.killspree == 5)
					iprintln(attacker.name + " ^7is on a killing spree with ^1" + attacker.killspree + " ^7 kills!"); //enable again
				rn = randomint(8);
			}
			if (attacker.killspree > 5 && attacker.killspree < 10)
			{	
				if(attacker.killspree == 10)
					iprintln(attacker.name + " ^7is on fire with ^1" + attacker.killspree + " ^7 kills!"); //enable again
				rn = randomint(5);
			}
			if (attacker.killspree >= 10)
			{	
				if(attacker.killspree == 15)
					iprintln(attacker.name + " ^7is unstoppable with ^1" + attacker.killspree + "^7 kills!"); //enable again
				if(attacker.killspree == 20)
					iprintln(attacker.name + " ^7is dominating with ^1" + attacker.killspree + "^7 kills!"); //enable again
				rn = randomint(5);
			}	
		}
	}
}

_mc2_PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	if(isdefined(self.isonfire)&&self.isonfire==1||sMeansOfDeath == "MOD_UNKNOWN"||sMeansOfDeath == "MOD_FALLING"||isDefined(self.protected))return;

	if (!isDefined(vPoint))
		vPoint = self.origin + (0,0,11);

	if(isDefined(self.scr) && self.health - iDamage > 0 )
		self thread _mc2\_mc2_gore::_doSounds("pain",sMeansOfDeath);

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
			_mc2\_mc2_util::forceto("crouch");
		else if(self.stance==1)
			_mc2\_mc2_util::forceto("prone");
	}
	
	if(sHitLoc == "head"|| sHitLoc=="helmet")
	{	

		if( self.health - iDamage < 1  &&  (iDamage >= level.scr_decap_min) && sMeansOfDeath != "MOD_MELEE" )
		{
			}
			else		
			if(self.decaped != 1 )
			{
					self thread _mc2\_mc2_gore::_doSounds("death",sMeansOfDeath);						
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
								self thread _mc2\_mc2_gore::_doSounds("death",sMeansOfDeath);
						}
					}
				}
			}
		}
	}
}
_mc2_PlayerKilled(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration)
{
	// Drop health
	_mc2\_healthpacks::dropHealth();
	if((!isDefined(self.thrown)))
	{
		if(isdefined(self.isonfire)&&self.isonfire==1&&sWeapon=="fire_mp")
		{

		}
		if((!isdefined(self.isonfire)) && (self.gibbed==0) && (self.decaped==0)&&(!isdefined(self.switching_teams)))
		{
			}
		}
	}