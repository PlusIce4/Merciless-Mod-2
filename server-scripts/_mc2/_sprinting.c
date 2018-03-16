init()
{
	level.awe_sprintspeed = cvardef("awe_sprint_speed",2,1,3,"int");

	// Which sprint weapon to use?
	if(level.awe_sprintspeed == 1)
		level.awe_sprintweapon = "sprint_slow_mp";
	else if(level.awe_sprintspeed == 2)
		level.awe_sprintweapon = "sprint_med_mp";
	else 
		level.awe_sprintweapon = "sprint_fast_mp";
	

	// AWE Sprinting
	level.awe_sprint 			= cvardef("awe_sprint",1,0,3,"int");
	if(!level.awe_sprint) return;

	level.awe_sprinttime 		= cvardef("awe_sprint_time",3,1,999,"int") * 20;
	level.awe_sprintrecovertime	= cvardef("awe_sprint_recover_time",2,0,999,"int") * 20;
	level.awe_sprinthud 		= cvardef("awe_sprint_hud",1,0,2,"int");
	level.awe_sprinthudhint 	= cvardef("awe_sprint_hud_hint",1,0,1,"int");
	level.awe_sprintheavyflag 	= cvardef("awe_sprint_heavy_flag", 0, 0, 1, "int");

	// Precache
	if(!isdefined(game["gamestarted"]))
	{
		if(level.awe_sprintspeed)
			precacheItem(level.awe_sprintweapon);
		else
		{
			precacheItem("sprint_fast_mp");
			precacheItem("sprint_med_mp");
			precacheItem("sprint_slow_mp");
		}

		if(level.awe_sprinthud == 1)
		{
			precacheShader("gfx/hud/hud@health_back.tga");
			precacheShader("gfx/hud/hud@health_bar.tga");
		}

		if(level.awe_sprinthud == 2)
			precacheShader("white");

		if(level.awe_sprinthudhint)
			precacheString(&"^7Hold USE [{+activate}] to sprint");
	}
}

CleanupKilled()
{
	self.awe_sprinttime = 0;
	self.awe_sprinting = false;

	if(!level.awe_sprint) return;

	// Remove hud elements
	if(isdefined(self.awe_sprinthud))		self.awe_sprinthud destroy();
	if(isdefined(self.awe_sprinthud_back))	self.awe_sprinthud_back destroy();
	if(isdefined(self.awe_sprinthud_hint))	self.awe_sprinthud_hint destroy();
}

RunOnSpawn()
{
	self.awe_sprinttime = 0;	 // Added for MC
	self.awe_sprinting = false;	 // Added for MC

	self thread MonitorSprinting();
	self thread EverySecondThread(); // Added for MC
}

monitorsprinting()
{
	self endon("TimeToDie");  // Changed for MC
	self endon("disconnect");

	if(!level.awe_sprint)
		return;

	self.awe_oldprimary = self getWeaponSlotWeapon("primary");
	self.awe_oldprimary2 = self.awe_oldprimary;
	self.awe_oldammo = self getWeaponSlotAmmo("primary");
	self.awe_oldammo2= self.awe_oldammo;
	self.awe_oldclip = self getWeaponSlotClipAmmo("primary");
	self.awe_oldclip2= self.awe_oldclip;
	self.awe_oldcurrent = self getCurrentWeapon();
	self.awe_oldcurrent2 = self.awe_oldcurrent;

	playbreathsound = false;

	// Get maximum sprinttime from global variable
	self.awe_sprinttime = level.awe_sprinttime;
	// Clear recovertime
	recovertime = 0;
	// Setup sprint ammo
	ammo = 100;

	maxwidth = 83;
	y = 472;
	x = 547;

	if(level.awe_sprinthud == 1)
	{
		self.awe_sprinthud_back = newClientHudElem( self );
		self.awe_sprinthud_back setShader("gfx/hud/hud@health_back.tga", maxwidth + 2, 5);
		self.awe_sprinthud_back.alignX = "left";
		self.awe_sprinthud_back.alignY = "top";
		self.awe_sprinthud_back.x = x;
		self.awe_sprinthud_back.y = y;

		self.awe_sprinthud = newClientHudElem( self );
		self.awe_sprinthud setShader("gfx/hud/hud@health_bar.tga", maxwidth, 3);
		self.awe_sprinthud.color = ( 0, 0, 1);
		self.awe_sprinthud.alignX = "left";
		self.awe_sprinthud.alignY = "top";
		self.awe_sprinthud.x = x + 1;
		self.awe_sprinthud.y = y + 1;
	}

	if(level.awe_sprinthud == 2)
	{
		self.awe_sprinthud_back = newClientHudElem( self );
		self.awe_sprinthud_back setShader("white", maxwidth + 2, 5);
		self.awe_sprinthud_back.color = (0.85,0.85,0.85);
		self.awe_sprinthud_back.alignX = "left";
		self.awe_sprinthud_back.alignY = "top";
		self.awe_sprinthud_back.alpha = 0.95;
		self.awe_sprinthud_back.x = x;
		self.awe_sprinthud_back.y = y;

		self.awe_sprinthud = newClientHudElem( self );
		self.awe_sprinthud setShader("white", maxwidth, 3);
		self.awe_sprinthud.color = ( 0, 0, 1);
		self.awe_sprinthud.alignX = "left";
		self.awe_sprinthud.alignY = "top";
		self.awe_sprinthud.alpha = 0.65;
		self.awe_sprinthud.x = x + 1;
		self.awe_sprinthud.y = y + 1;
	}

	if(level.awe_sprinthudhint)
	{
		self.awe_sprinthud_hint = newClientHudElem( self );
		self.awe_sprinthud_hint setText(&"^7Hold USE [{+activate}] to sprint");
		self.awe_sprinthud_hint.alignX = "right";
		self.awe_sprinthud_hint.alignY = "top";
		self.awe_sprinthud_hint.fontScale = 0.8;
		self.awe_sprinthud_hint.x = x - 2;
		self.awe_sprinthud_hint.y = y - 2;
		self.awe_sprinthud_hint.alpha = 0;
	}

/*	//-[Merciless2]
	if (!isdefined(self.sprint_back))
	{
		self.sprint_back = newClientHudElem(self);
		self.sprint_back.x = -20;
		self.sprint_back.y = 340;
		self.sprint_back setShader("gfx/hud/hud@sprntback1.tga", 160, 160);
		
		self.sprint_back2 = newClientHudElem(self);
		self.sprint_back2.x = -20;
		self.sprint_back2.y = 340;
		self.sprint_back2 setShader("gfx/hud/hud@sprntback2.tga", 160, 160);
	}

	if (!isdefined(self.sprint_bar))
	{
		self.sprint_bar = newClientHudElem(self);
		self.sprint_bar.x = -20;
		self.sprint_bar.y = 500;
		self.sprint_bar.alignX = "left";
		self.sprint_bar.alignY = "bottom";
	//	self.sprint_bar.horzAlign = "fullscreen";
	//	self.sprint_bar.vertAlign = "fullscreen";
		self.sprint_bar.foreground = false;
		self.sprint_bar.sort = 2;
		self.sprint_bar setShader("gfx/hud/hud@sprint_bar.tga",160,160);
	}
*/
	while (isAlive(self) && self.sessionstate == "playing")
	{
		sprint = (level.awe_sprinttime-self.awe_sprinttime)/level.awe_sprinttime;
		
		if(level.awe_sprinthud)
		{
			if(!self.awe_sprinttime)
			{
				self.awe_sprinthud.color = ( 1.0, 0.0, 0.0);
			}
			else	
			{
				self.awe_sprinthud.color = ( sprint, 0, 1.0-sprint);
			}
		
			hud_width = int((1.0 - sprint) * maxwidth);
//			height=int((1.0-sprint)* 160); //-[Merciless2]
			
			if ( hud_width < 1 )
				hud_width = 1;
			
			if(level.awe_sprinthud == 1)
				self.awe_sprinthud setShader("gfx/hud/hud@health_back.tga", hud_width, 3);
			else
				self.awe_sprinthud setShader("white", hud_width, 3);
			
//			self.sprint_bar setShader("gfx/hud/hud@sprint_bar.tga", 160, height); //-[Merciless2]
		}

		oldorigin = self.origin;
		// Wait
		wait .05;

		// If nonexistant, return
		if(!isdefined(self))
			return;

		// If dead, break
		if(!isAlive(self))
			break;

		// If there is no origin then don't go on.
		if(!isdefined(self.origin))
			continue;

/*		// No sprinting if parchuting or under spawnprotection (with disabled weapon)
		if( (isdefined(self.awe_invulnerable) && level.awe_spawnprotectiondisableweapon) || isdefined(self.awe_isparachuting))
			continue;*/

		// Disable sprinting if we carry a flag in heavy flag mode
		if (level.awe_sprintheavyflag && isdefined(self.flagAttached))
			self.awe_sprinttime = 0;

		// Are we sprinting?
		if((oldorigin != self.origin || self.awe_pace) && self.awe_sprinttime>0 && self useButtonPressed() && level.awe_sprint>self.awe_stance)
		{
			// If not currently sprinting
			if(!self.awe_sprinting)
			{
				// Save old primary
				pw = self getWeaponSlotWeapon("primary");
				cw = self getCurrentWeapon();
				// If primary is not allready level.awe_sprintweapon
				if(pw != level.awe_sprintweapon)
				{
					// If current weapon is not "none"
					if(cw != "none")
					{
						//dont run with heavy weapons
						if(WeaponType(cw)=="mgs")continue;//-[Merciless2]

						// Save old primary
						self.awe_oldprimary = pw;
						self.awe_oldammo = self getWeaponSlotAmmo("primary");
						self.awe_oldclip = self getWeaponSlotClipAmmo("primary");

						// Save old current unless it is allready level.awe_sprintweapon
						if(cw != level.awe_sprintweapon)
							self.awe_oldcurrent = cw;
						else	// Else save primary as current
							self.awe_oldcurrent = pw;
					}
					else	// If cw is "none" then we likely unintenionally picked up a weapon when trying to sprint
					{
						// Check if any of the primaries have between the last 1-2 seconds
						if(pw != self.awe_oldprimary2)	// We've picked up a new primary by mistake
						{
							// Save the old primary in temporary varibles in case we need them
							oldprimary2 = self.awe_oldprimary2;
							oldammo2 = self.awe_oldammo2;
							oldclip2 = self.awe_oldclip2;
							oldcurrent2 = self.awe_oldprimary2;

							// Measure that the button is pressed for 0.5 second to make sure the player really want to sprint
							buttoncount = 0;
							while(self useButtonPressed() && buttoncount < 10)
							{
								buttoncount++;
								wait .05;
							}
							if(buttoncount<10)	// Seems this was just a normal weapon pickup
								continue;
							
							// Save the old primary instead if the new one
							self.awe_oldprimary = oldprimary2;
							self.awe_oldammo = oldammo2;
							self.awe_oldclip = oldclip2;
							self.awe_oldcurrent = oldprimary2;
						}
						else if(self getWeaponSlotWeapon("primaryb") != self.awe_oldprimaryb)	//We've picked up a new primaryb by mistake
						{
							// Save the old primary in temporary varibles in case we need them
							oldprimaryb = self.awe_oldprimaryb;
							oldammob = self.awe_oldammob;
							oldclipb = self.awe_oldclipb;

							// Measure that the button is pressed for 0.5 second to make sure the player really want to sprint
							buttoncount = 0;
							while(self useButtonPressed() && buttoncount < 10)
							{
								buttoncount++;
								wait .05;
							}
							if(buttoncount<10)	// Seems this was just a normal weapon pickup
								continue;

							// Restore the old primaryb
							self setWeaponSlotWeapon(	"primaryb",oldprimaryb);
							self setWeaponSlotAmmo(		"primaryb",oldammob);
							self setWeaponSlotClipAmmo(	"primaryb",oldclipb);

							// Save old primary
							self.awe_oldprimary = pw;
							self.awe_oldammo = self getWeaponSlotAmmo("primary");
							self.awe_oldclip = self getWeaponSlotClipAmmo("primary");

							// If we just switched primaryb then it must have been the current weapon
							self.awe_oldcurrent = oldprimaryb;
						}
						else	// Current weapon is "none" for unknown reason
						{
							// Save old primary
							self.awe_oldprimary = pw;
							self.awe_oldammo = self getWeaponSlotAmmo("primary");
							self.awe_oldclip = self getWeaponSlotClipAmmo("primary");
							self.awe_oldcurrent = pw;
						}
					}
				}

/*				if(level.awe_debug)
				{
					iprintln("oldprimary:" + self.awe_oldprimary);
					iprintln("oldcurrent:" + self.awe_oldcurrent);
					iprintln("cw:" + cw);
					iprintln("pw:" + pw);
				}*/

				// Set and select sprint weapon as primary
				self setWeaponSlotWeapon("primary", level.awe_sprintweapon);
				self switchToWeapon(level.awe_sprintweapon);
				self.awe_sprinting = true;
				playbreathsound = true;
				wait .05;
			}
			else
			{
				// Are we sprinting but weapon has been switched or picked up?
				cw = self getCurrentWeapon();
				pw = self getWeaponSlotWeapon("primary");
				// Picked up weapon by mistake?
				if(pw != level.awe_sprintweapon)
				{
					//Clean sweep the "world" for dropped potatoes
					deletePlacedEntity("weapon_" + level.awe_sprintweapon);

					// Set and select sprint weapon as primary
					self setWeaponSlotWeapon("primary", level.awe_sprintweapon);
					self switchToWeapon(level.awe_sprintweapon);
					wait .05;
				}
				else if(cw != level.awe_sprintweapon)	// Switched weapon while sprinting?
				{
					//Switch back to potato
					self switchToWeapon(level.awe_sprintweapon);
					wait .05;
				}
			}

			// Decrease available sprinttime
			self.awe_sprinttime--;
			// Update sprint ammo
			ammo = int(100 * (1.0 - sprint));
			self setWeaponSlotAmmo("primary",ammo);

		}
		else
		{
			// Did we just stop sprinting?
			if(self.awe_sprinting)
			{
/*				if(level.awe_debug)
				{
					iprintln("oldprimary2:" + self.awe_oldprimary);
					iprintln("oldcurrent2:" + self.awe_oldcurrent);
				}*/

				//Restore old primary and ammo
				self setWeaponSlotWeapon("primary", self.awe_oldprimary);
				self setWeaponSlotAmmo("primary", self.awe_oldammo);
				self setWeaponSlotClipAmmo("primary", self.awe_oldclip);
		
				// Make sure no sprint weapon has been picked up as primaryb (should never happen)
				if(self getWeaponSlotWeapon("primaryb") == level.awe_sprintweapon)
					self setWeaponSlotWeapon("primaryb", "none");

				//Restore old current
				if(self.awe_oldcurrent != "none")
					self switchToWeapon(self.awe_oldcurrent);
				else if(self.awe_oldprimary != "none")
					self switchToWeapon(self.awe_oldprimary); // Fallback

				// Get recover time from global variable
				recovertime = level.awe_sprintrecovertime;

				// Calculate recovertime of full sprinttime has not been used
				if(self.awe_sprinttime>0)
					recovertime = int(recovertime * sprint + 0.5);

				self.awe_sprinting = false;
				wait .05;
			}

			// Are we recovering?
			if(self.awe_sprinttime<(level.awe_sprinttime) && !(self useButtonPressed() && !isdefined(self.awe_plantbar) && !isdefined(self.awe_pickbar) ) )
			{
				// Don't increase sprinttime unless recovertime has passed
				if(recovertime>0)
				{
					recovertime--;
					if(playbreathsound)
					{
						if(!randomInt(6))
							self playLocalSound("breathing_better");
						playbreathsound = false;
					}
				}
				else
					self.awe_sprinttime++;
			}
		}
	}

	if(isdefined(self.awe_sprinthud)) self.awe_sprinthud destroy();
	if(isdefined(self.awe_sprinthud_back)) self.awe_sprinthud_back destroy();
	if(isdefined(self.awe_sprinthud_hint)) self.awe_sprinthud_hint destroy();
}

// Thread run on each player, every second (Added for MC2)
EverySecondThread()
{
	self endon("TimeToDie");
	self endon("disconnect");

	sprinthudvisible = false;
	self.awe_pace = 0;

	oldprimary = level.awe_sprintweapon;
	oldammo = 0;
	oldclip = 0;
	oldprimaryb = level.awe_sprintweapon;
	oldammob = 0;
	oldclipb = 0;

	// Avoid some undefined errors
	self.awe_oldprimary2 	= self getWeaponSlotWeapon("primary");
	self.awe_oldammo2 	= self getWeaponSlotAmmo("primary");
	self.awe_oldclip2 	= self getWeaponSlotClipAmmo("primary");
	self.awe_oldprimaryb = self getWeaponSlotWeapon("primaryb");
	self.awe_oldammob 	= self getWeaponSlotAmmo("primaryb");
	self.awe_oldclipb 	= self getWeaponSlotClipAmmo("primaryb");

	oldpos = self.origin;

	while( isPlayer(self) && isAlive(self) && self.sessionstate=="playing" )
	{
		delayed = 0;

		// Get the current weapon
		cw = self getCurrentWeapon();

		// Get the stance every second
		if(isdefined(self.stance))
			self.awe_stance = 2 - self.stance;
		else
			self.awe_stance = 0;

		// Show/Hide the sprint hint
		if(level.awe_sprint && level.awe_sprinthudhint)
		{
			if(!sprinthudvisible && self.awe_sprinttime && !self.awe_sprinting && self.awe_pace && level.awe_sprint>self.awe_stance)
			{
				if(isdefined(self.awe_sprinthud_hint))
				{
					self.awe_sprinthud_hint fadeOverTime (1); 
					self.awe_sprinthud_hint.alpha = 1;
					sprinthudvisible = true;
				}
			}
			else if(sprinthudvisible && (self.awe_sprinting || !self.awe_pace || level.awe_sprint<=self.awe_stance) )
			{
				{
					if(isdefined(self.awe_sprinthud_hint))
					{
						self.awe_sprinthud_hint fadeOverTime (1); 
						self.awe_sprinthud_hint.alpha = 0;
						sprinthudvisible = false;
					}
				}
			}
		}

		// Save old weapon data
		if(level.awe_sprint)
		{
			// Save 1 second old data
			if(oldprimary != level.awe_sprintweapon)
			{
				self.awe_oldprimary2 = oldprimary;
				self.awe_oldammo2 = oldammo;
				self.awe_oldclip2 = oldclip;
			}
			if(oldprimaryb != level.awe_sprintweapon)
			{
				self.awe_oldprimaryb = oldprimaryb;
				self.awe_oldammob = oldammob;
				self.awe_oldclipb = oldclipb;
			}
			
			// Save new dat
			oldprimary 	= self getWeaponSlotWeapon("primary");
			oldammo 	= self getWeaponSlotAmmo("primary");
			oldclip 	= self getWeaponSlotClipAmmo("primary");
			oldprimaryb = self getWeaponSlotWeapon("primaryb");
			oldammob 	= self getWeaponSlotAmmo("primaryb");
			oldclipb 	= self getWeaponSlotClipAmmo("primaryb");
		}

		// Calculate current speed
		wait 1;

		// If nonexistant, return
		if(!isdefined(self))
			return;

		// If dead, break
		if(!isAlive(self))
			break;

		// If there is no origin then don't go on.
		if(!isdefined(self.origin))
			continue;

		newpos = self.origin;

		if(isdefined(oldpos) && isdefined(newpos))
			speed = distance(oldpos,newpos);
		else
			speed = 0;

		oldpos = newpos;

		if (speed > 20)
			self.awe_pace = 1;
		else
			self.awe_pace = 0;
	}
}

/*
USAGE OF "cvardef"
cvardef replaces the multiple lines of code used repeatedly in the setup areas of the script.
The function requires 5 parameters, and returns the set value of the specified cvar
Parameters:
	varname - The name of the variable, i.e. "scr_teambalance", or "scr_dem_respawn"
		This function will automatically find map-sensitive overrides, i.e. "src_dem_respawn_mp_brecourt"

	vardefault - The default value for the variable.  
		Numbers do not require quotes, but strings do.  i.e.   10, "10", or "wave"

	min - The minimum value if the variable is an "int" or "float" type
		If there is no minimum, use "" as the parameter in the function call

	max - The maximum value if the variable is an "int" or "float" type
		If there is no maximum, use "" as the parameter in the function call

	type - The type of data to be contained in the vairable.
		"int" - integer value: 1, 2, 3, etc.
		"float" - floating point value: 1.0, 2.5, 10.384, etc.
		"string" - a character string: "wave", "player", "none", etc.
*/
cvardef(varname, vardefault, min, max, type)
{
	mapname = getcvar("mapname");		// "mp_dawnville", "mp_rocket", etc.

	if(isdefined(level.awe_gametype))
		gametype = level.awe_gametype;	// "tdm", "bel", etc.
	else
		gametype = getcvar("g_gametype");	// "tdm", "bel", etc.

	tempvar = varname + "_" + gametype;	// i.e., scr_teambalance becomes scr_teambalance_tdm
	if(getcvar(tempvar) != "") 		// if the gametype override is being used
		varname = tempvar; 		// use the gametype override instead of the standard variable

	tempvar = varname + "_" + mapname;	// i.e., scr_teambalance becomes scr_teambalance_mp_dawnville
	if(getcvar(tempvar) != "")		// if the map override is being used
		varname = tempvar;		// use the map override instead of the standard variable


	// get the variable's definition
	switch(type)
	{
		case "int":
			if(getcvar(varname) == "")		// if the cvar is blank
				definition = vardefault;	// set the default
			else
				definition = getcvarint(varname);
			break;
		case "float":
			if(getcvar(varname) == "")	// if the cvar is blank
				definition = vardefault;	// set the default
			else
				definition = getcvarfloat(varname);
			break;
		case "string":
		default:
			if(getcvar(varname) == "")		// if the cvar is blank
				definition = vardefault;	// set the default
			else
				definition = getcvar(varname);
			break;
	}

	// if it's a number, with a minimum, that violates the parameter
	if((type == "int" || type == "float") && definition < min)
		definition = min;

	// if it's a number, with a maximum, that violates the parameter
	if((type == "int" || type == "float") && definition > max)
		definition = max;

	return definition;
}

deletePlacedEntity(entity)
{
	entities = getentarray(entity, "classname");
	for(i = 0; i < entities.size; i++)
	{
		//println("DELETED: ", entities[i].classname);
		entities[i] delete();
	}
}

WeaponType(sWeapon)
{
	switch(sWeapon)
	{			
		case "mg42_fake_mp":
		case "_mg42_mp":
		case "mg30cal_fake_mp":
		case "_mg30cal_mp": 
			return "mgs";
		default:
			return"default";
	}
}