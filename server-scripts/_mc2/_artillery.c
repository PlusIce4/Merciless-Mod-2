/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

init()
{
	// load effects
	level.mortarfx["sand"] 	= loadfx("fx/explosions/mortarExp_beach.efx");
	level.mortarfx["snow"]	= loadfx("fx/explosions/large_snow_explode1.efx");
//Don't think there are any water on the stock maps	level.mortarfx["water"]	= loadfx("fx/explosions/mortarExp_water.efx");
	level.mortarfx["concrete"]= loadfx("fx/explosions/mortarExp_concrete.efx");
	level.mortarfx["dirt"] 	= loadfx("fx/explosions/mortarExp_dirt.efx");
	level.mortarfx["generic"] = loadfx("fx/explosions/mortarExp_mud.efx");
	level.mortarfx["grass"] 	= loadfx("fx/explosions/artilleryExp_grass.efx");
	level thread onPlayerConnect(); 
}

onPlayerConnect()
{
	for(;;)
	{
		level waittill("connecting", player);
		player thread onPlayerSpawned();
		player thread onPlayerKilled();
		player thread onJoinedTeam();
		player thread onJoinedSpectators();
		player thread onPlayerDisconnect();
	}
}

onJoinedTeam()
{
	self endon("disconnect");

	for(;;)
	{
		self waittill("joined_team");
	}
}

onJoinedSpectators()
{
	self endon("disconnect");

	for(;;)
	{
		self waittill("joined_spectators");
		self notify("end artillery_WaitForUse");
	}
}

onPlayerSpawned()
{
	self endon("disconnect");
	
	for(;;)
	{
		self waittill("spawned_player");
		
		if(isdefined(self.pers["pClass"]))
		{
			switch(self.pers["pClass"])
			{
				case "engineer":
				if(level.scr_sniper_artillery==0)return;
				self.hasmortars = 0;
				self.chargingmortar = undefined;
				self thread _mc2\_artillery::counter();
				break;
				case "sniper":
				if(level.scr_sniper_artillery==0)return;
				self.hasmortars = 0;
				self.chargingmortar = undefined;
				self thread _mc2\_artillery::counter();
				break;
				case "medic":
				case "support":
				case "soldier":
				default:
					break;
			}
		}			
	}				
}	
onPlayerKilled()
{
	self endon("disconnect");

	for(;;)
	{
		self waittill("killed_player");
		self notify("end artillery_WaitForUse");
	}
}

onPlayerDisconnect()
{
	self waittill("disconnect");
	self notify("end artillery_WaitForUse");
}
/*------------------------------------------
Sniper artillery HUD counter
------------------------------------------*/
counter()
{

	self endon("TimeToDie");
	self endon("disconnect");

	for(;;)
	{
		if (!isdefined(self.mortaricon))
		{
			self.mortaricon = newClientHudElem(self);
			self.mortaricon.alignX = "left";
			self.mortaricon.alignY = "top";
			self.mortaricon.x = 534;
			self.mortaricon.y = 398-5;
		//	self.mortaricon.alpha = 1;
			self.mortaricon SetShader("gfx/hud/hud@fire_ready_shll.dds", 25, 20);
		}

		if (!isdefined(self.mortarcharge))
		{
			self.mortarcharge = newClientHudElem(self);
			self.mortarcharge.alignX = "left";
			self.mortarcharge.alignY = "top";
			self.mortarcharge.x = 549;
			self.mortarcharge.y = 401;
			self.mortarcharge.fontscale = 1;
			self.mortarcharge.color = (.5,.5,0);
			self.mortarcharge.alpha = .9;
		}
		if(self.hasmortars == 0 && !isDefined(self.chargingmortar) )
		{


			self thread Recharge("mortar");
			self.chargingmortar = 1;
		}
		break;
	}
}

/*------------------------------------------
Updates the sniper artillery HUD counter
------------------------------------------*/
Recharge(chargetype)
{

	self endon("TimeToDie");
	self endon("disconnect");

	self.mortaricon.alpha = 0;
	self.mortaricon fadeovertime(60);
	self.mortaricon.alpha = .5;
	self.mortaricon fadeovertime(30);
	self.mortaricon.alpha = 1;
	self.mortarcharge settimer(90);
	wait 90;
	self.hasmortars = 1;
	self.chargingmortar = undefined;
	if(isdefined(self.mortarcharge))
		self.mortarcharge destroy();
	if(self.hasmortars==1)
		self thread DispenseStrike();

}
/*------------------------------------------
thinks while player is alive and gives an
artillery strike after timed intervals
------------------------------------------*/
DispenseStrike()
{
	self endon("death");
	self endon("disconnect");

	// kill any currently running artillery_DispenseStrike functions
	self notify("end artillery_DispenseStrike");
	wait(0.1);
	self endon("end artillery_DispenseStrike");

	while (1)
	{
		if(self.hasmortars==0&&isDefined(self.chargingmortar))return;
		// let them know the artillery strike is available
		self iprintln(&"MC2_ARTILLERY_READY");

		self playLocalSound("ctf_touchown");

		//monitor for binocular fire
		self thread WaitForUse();

		// wait until they use artillery
		self waittill("artillery end");
	}
}
/*------------------------------------------
returns the target coords
of where the player is looking
------------------------------------------*/
GetTargetedPos(num)
{
	startOrigin = self getEye()+self getPlayerEyeOffset();
	forward = anglesToForward(self getplayerangles());
	forward = vector_scale( forward, num );
	endOrigin = startOrigin + forward;

	trace = bulletTrace( startOrigin, endOrigin, false, self );
	if ( trace["fraction"] == 1.0 || trace["surfacetype"] == "default")
		return ( undefined );
	else
		return ( trace["position"] );
}
getPlayerEyeOffset()
{
	self endon("disconnect");
	self endon("TimeToDie");

	offset = (0,0,18);

	if(self.stance == 1) offset = (0,0,2);
	if(self.stance == 0) offset = (0,0,-27);

	return offset;
}
vector_scale (vec, scale)
{
	vec = (vec[0] * scale, vec[1] * scale, vec[2] * scale);
	return vec;
}
/*------------------------------------------
waits for player to use binoculars
------------------------------------------*/
WaitForUse()
{
	self endon("end artillery_WaitForUse");
	self endon("disconnect");

	for (;;)
	{
		//wait til binoculars are in hand
		self waittill("binocular_enter");
		//check if use button pressed
		self thread WaitforBinocularFire();
		//self thread artillery_binocularhint_hud();
		wait .2;
	}

}
/*------------------------------------------
checks to see if player presses the use button
while looking through binoculars
------------------------------------------*/
WaitforBinocularFire()
{
	//kill dupes
	self notify("binocular_exit");
	wait(0.1);
	self endon("binocular_exit");
	self endon("artillery fired");
	self endon("disconnect");

	//wait for use button to be pressed
	while (1)
	{
		if (self useButtonPressed())
		{
			targetpos = GetTargetedPos(100000);
			if (isdefined(targetpos))
			{
				artillery = spawn("script_origin",targetpos);
				artillery thread FireBarrage(self);

				if(isDefined(self.mortaricon))
					self.mortaricon destroy();
				if(isDefined(self.mortarcharge))
					self.mortarcharge destroy();
				self.hasmortars=0;
				self.chargingmortar=undefined;
				self thread _mc2\_artillery::counter();

				//notify threads
				self notify("end artillery_WaitForUse");
				self notify ("artillery fired");

			}
		}
		wait .1;
	}
}
/*------------------------------------------
fire barrage at target
------------------------------------------*/
FireBarrage(owner)
{
	time = 4 ;
	while (time)
	{
		self thread FiringSound();
		wait (.5);
		time -= .5;
	}
	//create shell positions x 18
	barrageSize = 18;
	shellPositions = [];
	for ( index = 0; index < barrageSize; index++ )
		shellPositions[index] = CalcShellPos( self.origin );

	//reset delay
	self.artilleryGlobalDelay = 0;
	//fire shells
	for ( index = 0; index < barrageSize; index++ )
	{
		self thread FireShell( shellPositions[index] , owner);
	}
	//wait for all shells to explode
	shellImpacts = 0;
	while ( shellImpacts < barrageSize )
	{
		self waittill ( "artillery shell impact" );
		shellImpacts++;
	}
	//end
	owner notify ("artillery end");
	self delete();

}
/*------------------------------------------
fire shell
------------------------------------------*/
FireShell( shellPos , owner)
{
	shellEnt = spawn( "script_origin", shellPos );
	self.artilleryGlobalDelay += randomFloatRange( .5, 1.5 );

	wait ( self.artilleryGlobalDelay );

	wait (randomFloatRange( 1.5, 2.5));

	shellent playSound("artillery_incoming");
	wait (randomFloatRange( 1.5, 3));
	shellEnt ShellImpact( owner );
	shellEnt delete();

	self notify ( "artillery shell impact" );
}
/*------------------------------------------
returns a shell coord within 1000 units of target
------------------------------------------*/
CalcShellPos( targetPos )
{
	shellPos = undefined;
	iterations = 0;
	level.surface=undefined;
	while ( !isdefined (shellPos) && iterations < 5 )
	{
		shellPos = targetPos;
		angle = randomfloat( 360 );
		radius = randomfloat( 750 );//level.pctf_artillery_offset
		randomOffset = ( cos( angle ) * radius, sin( angle ) * radius, 0 );
		shellPos += randomOffset;
		startOrigin = shellPos + (0, 0, 512);
		endOrigin = shellPos + (0, 0, -2048);

		trace = bulletTrace( startOrigin, endOrigin, false, undefined );
		if ( trace["fraction"] < 1.0 )
			shellPos = trace["position"];
		else
			shellPos = undefined;

		// Get surfacetype
		surface = trace["surfacetype"];
		level.surface=surface;

		iterations++;
	}
	return ( shellPos );
}
/*------------------------------------------
play the fx and do teh damage
------------------------------------------*/
ShellImpact(eAttacker)
{
	surfaces = [];
	surfaces[surfaces.size] = "concrete";
	surfaces[surfaces.size] = "dirt";
	surfaces[surfaces.size] = "generic";
	surfaces[surfaces.size] = "grass";
	surfaces[surfaces.size] = "sand";

	if(!isdefined(level.mortarfx[level.surface]))
		level.surface = surfaces[randomInt(surfaces.size)];

	playfx(level.mortarfx[level.surface], self.origin);

	self playSound( "artillery_explosion");

	earthquake(0.25, 0.75, self.origin, 4096);

	sMeansOfDeath = "MOD_EXPLOSIVE";
	iDFlags = 1;
	irange = 384;
	imaxdamage = 384;
	imindamage = 10;

	// Loop through players
	players = getentarray("player", "classname");
	for(i=0;i<players.size;i++)
	{
		// Check that player is in range
		distance = distance((self.origin ), players[i].origin);
		if(distance>=irange || players[i].sessionstate != "playing" || !isAlive(players[i]) )
			continue;

		percent = (irange - distance)/irange;
		iDamage = imindamage + (imaxdamage - imindamage)*percent;

		traceorigin = players[i].origin + (0,0,32);

		trace = bullettrace(self.origin, traceorigin, true, self);

		if(isdefined(trace["entity"]) && trace["entity"] != players[i])
			iDamage = iDamage * .7;
		else if(!isdefined(trace["entity"]))
			iDamage = iDamage * .3;

		vDir = vectorNormalize(traceorigin - (self.origin ));

		iDamage = int(iDamage);
		if( isPlayer( eAttacker ))
			players[i] thread [[level.callbackPlayerDamage]]( eAttacker, eAttacker, iDamage, iDFlags, sMeansOfDeath, "artillery_mp", undefined, vDir, "none",0);

	}

	body = getentarray("body","targetname");
	for(i=0;i<body.size;i++)
	{
		dst=distance(self.origin,body[i].origin);
		if(dst<250&&isdefined(body)&&body[i].targetname=="body")
		{
			if(60>=randomint(100))
				self body_boom(body[i]);
		}
	}
}
/*------------------------------------------
play artillery firing sound to all players
------------------------------------------*/
FiringSound()
{
	players = getentarray("player", "classname");

	for(i = 0; i < players.size; i++)
		players[i] playLocalSound("artillery_fire");
}
/*-------------------------------------------
Gib those deads :)
-------------------------------------------*/
body_boom(body)
{
	while(isDefined(body))
	{
		if(!isDefined(body)) break;
		body playsound ("gib");
		switch(randomint(2))
		{
		case 0:
			playfx(level._effect["gib"],body.origin+(0,0,11));
		case 1:
			playfx(level._effect["gib2"],body.origin+(0,0,11));
		}
		body delete();
		break;
		wait .1;
	}
}
