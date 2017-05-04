/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell */
/* Script Code Snippets: PlusIce */
/* Spawn Protection Script */

#include mc2\_utils_cvardef;

/*Note: Need to call the GrenadeType function later */
/*Note: Check myammo oldammo and other varibles later */

init()
{
	// Spawn protection
	level.mc2_spawnprotection	= cvardef("mc2_spawn_protection", 0, 0, 99, "int");

	if(!level.mc2_spawnprotection) return;

	level.mc2_spawnprotectionrange		= cvardef("mc2_spawn_protection_range", 50, 0, 10000, "int");
	level.mc2_spawnprotectionhud			= cvardef("mc2_spawn_protection_hud", 1, 0, 2, "int");
	level.mc2_spawnprotectionheadicon 		= cvardef("mc2_spawn_protection_headicon", 1, 0, 1, "int");
	level.mc2_spawnprotectiondropweapon 	= cvardef("mc2_spawn_protection_dropweapon",0,0,1,"int");
	level.mc2_spawnprotectiondisableweapon 	= cvardef("mc2_spawn_protection_disableweapon",0,0,1,"int");
	level.mc2_spawnprotectionpunish	= cvardef ("mc2_spawn_protection_punish", 0, 0, 3, "int");
  level.mc2_spawnprotectioninvisible = cvardef("mc2_spawn_protection_invisible", 0, 0, 1, "int");

	// Precache
	if(!isdefined(game["gamestarted"]))
	{
		precacheShader("gfx/hud/hud@health_cross.tga");
		precacheHeadIcon("gfx/hud/hud@spprot_cross.tga");
	}
}

CleanupKilled()
{
	self.mc2_invulnerable = false;
	if(isdefined(self.mc2_spawnprotection))	self.mc2_spawnprotection destroy();
}

RunOnSpawn()
{
	self thread SpawnProtection();
}

SpawnProtection()
{
	self endon("mc2_killthreads");
	if(!level.mc2_spawnprotection) return;

	while (isdefined (self.mc2_isparachuting))
		wait 0.05;

  if (level.mc2_spawnprotectioninvisible) self hide();

	if(level.mc2_teamplay)
		myteam = self.sessionteam;
	else
		myteam = self.pers["team"];
	if(myteam == "axis")
		otherteam = "allies";
	else
		otherteam = "axis";

	count = 0;
	startposition = self.origin;
	self iprintln(&"MC2_SPROT_ACT");

	if(level.mc2_spawnprotectiondisableweapon)
		self disableWeapon();

	// Set up HUD element
	if(level.mc2_spawnprotectionhud == 1)
	{
		self.mc2_spawnprotection = newClientHudElem(self);	
		self.mc2_spawnprotection.x = -120;
		self.mc2_spawnprotection.y = 410;
		self.mc2_spawnprotection.alpha = 0.65;
		self.mc2_spawnprotection.alignX = "center";
		self.mc2_spawnprotection.alignY = "middle";
		self.mc2_spawnprotection.horzAlign = "right";
		self.mc2_spawnprotection setShader("gfx/hud/hud@health_cross.tga",40,40);
	}

	if(level.mc2_spawnprotectionhud == 2)
	{
		self.mc2_spawnprotection = newClientHudElem(self);	
		self.mc2_spawnprotection.x = 320;
		self.mc2_spawnprotection.y = 240;
		self.mc2_spawnprotection.alpha = 0.4;
		self.mc2_spawnprotection.alignX = "center";
		self.mc2_spawnprotection.alignY = "middle";
		self.mc2_spawnprotection setShader("gfx/hud/hud@health_cross.tga",350,320);
	}
/* Redo later
	// Get grenade count
	myammo	= self getammocount(mc2\_util::GetGrenadeType(game[myteam]));
	otherammo 	= self getammocount(mc2\_util::GetGrenadeType(game[otherteam]));
	oldammo = myammo + otherammo;
*/	
	while(isAlive(self) && self.sessionstate=="playing" && count < (level.mc2_spawnprotection * 20) && !(self attackButtonPressed() || self meleeButtonPressed()) )
	{
	/* Redo later
		// Get grenade count
		myammo	= self getammocount(mc2\_util::GetGrenadeType(game[myteam]));
		otherammo 	= self getammocount(mc2\_util::GetGrenadeType(game[otherteam]));
		ammo = myammo + otherammo;
		// Has it decreased?
		if(ammo < oldammo)	// Stop protection on grenade usage
			break;
		// Save last value
		oldammo = ammo;
	*/
		self.mc2_invulnerable = true;

		if(level.mc2_spawnprotectionheadicon)
		{
			// Setup headicon
			self.headicon = "gfx/hud/hud@spprot_cross.tga";
			self.headiconteam = "none";
		}

		if(level.mc2_spawnprotectionrange)
		{
			// Check moved range
			distance = distance(startposition, self.origin);
			if(distance > level.mc2_spawnprotectionrange)
				count = level.mc2_spawnprotection * 20;
		}

		count++;

		wait 0.05;
	}

	if (level.mc2_spawnprotectioninvisible) self show();

	if(level.mc2_spawnprotectiondisableweapon)
		self enableWeapon();

	self.mc2_invulnerable = false;

	if(level.mc2_spawnprotectionheadicon)
	{
		if(level.mc2_teamplay && level.drawfriend)
		{
			if(myteam == "allies")
			{
				self.headicon = game["headicon_allies"];
				self.headiconteam = "allies";
			}
			else
			{
				self.headicon = game["headicon_axis"];
				self.headiconteam = "axis";
			}
		}
		else
		{
			self.headicon = "";
		}
	}

	if( isAlive(self) && self.sessionstate=="playing" )
	{
		self iprintln(&"MC2_SPROT_DEACT");

		// Fade HUD element
		if(isdefined(self.mc2_spawnprotection))
		{
			self.mc2_spawnprotection fadeOverTime (1); 
			self.mc2_spawnprotection.alpha = 0;
		}

		wait 1;
	}

	// Remove HUD element
	if(isdefined(self.mc2_spawnprotection))
		self.mc2_spawnprotection destroy();
}