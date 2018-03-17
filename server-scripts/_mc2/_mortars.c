/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
//tx bell

init()
{
	if(getcvar("scr_mortar") == "")
		setcvar("scr_mortar","4");
	if(getcvar("scr_mortar_quake") == "")
		setcvar("scr_mortar_quake","1");
	if(getcvar("scr_mortar_random") == "")
		setcvar("scr_mortar_random","0");
	if(getcvar("scr_mortar_safety") == "")
		setcvar("scr_mortar_safety","1");
	if(getcvar("scr_mortar_delay_min") == "")
		setcvar("scr_mortar_delay_min","20");
	if(getcvar("scr_mortar_delay_max") == "")
		setcvar("scr_mortar_delay_max","60");

	FindMapDimensions();
	// turn on ambient mortars
	level.mortar = getcvarint("scr_mortar");

	if(!level.mortar) 
		return;

	// quake?
	level.mortar_quake = getcvarint("scr_mortar_quake");
	// random?
	level.mortar_random 	= getcvarint("scr_mortar_random");
	// make them safe for players
	level.mortar_safety 	= getcvarint("scr_mortar_safety");
	// minimum delay between mortars
	level.mortar_delay_min 	= getcvarint("scr_mortar_delay_min");
	// maximum delay between mortars
	level.mortar_delay_max 	= getcvarint("scr_mortar_delay_max");

	// Setup mortar model
	level.mortarmodel = "xmodel/vehicle_halftrack_rockets_shell";

	// Set up mortar sounds
	level.mortars = [];
	level.mortars[level.mortars.size]["incoming"] = "mortar_incoming2";
	level.mortars[level.mortars.size-1]["delay"] = 0.65;
	level.mortars[level.mortars.size]["incoming"] = "mortar_incoming1";
	level.mortars[level.mortars.size-1]["delay"] = 1.05;
	level.mortars[level.mortars.size]["incoming"] = "mortar_incoming3";
	level.mortars[level.mortars.size-1]["delay"] = 1.5;
	level.mortars[level.mortars.size]["incoming"] = "mortar_incoming4";
	level.mortars[level.mortars.size-1]["delay"] = 2.1;
	level.mortars[level.mortars.size]["incoming"] = "mortar_incoming5";
	level.mortars[level.mortars.size-1]["delay"] = 3.0;

	// load effects
	level.mortarfx["sand"] 	= loadfx("fx/explosions/mortarExp_beach.efx");
	level.mortarfx["snow"]	= loadfx("fx/explosions/large_snow_explode1.efx");
//Don't think there are any water on the stock maps	level.mortarfx["water"]	= loadfx("fx/explosions/mortarExp_water.efx");
	level.mortarfx["concrete"]= loadfx("fx/explosions/mortarExp_concrete.efx");
	level.mortarfx["dirt"] 	= loadfx("fx/explosions/mortarExp_dirt.efx");
	level.mortarfx["generic"] = loadfx("fx/explosions/mortarExp_mud.efx");
	level.mortarfx["grass"] 	= loadfx("fx/explosions/artilleryExp_grass.efx");

	// Precache model
	precacheModel(level.mortarmodel);
	
	thread StartThreads();
}

StartThreads()
{
	// Start mortar threads
	for(i = 0; i < level.mortar; i++)
		thread incoming();
}

incoming()
{
	maxz = level.vMax[2];	

	surfaces = [];
	surfaces[surfaces.size] = "concrete";
	surfaces[surfaces.size] = "dirt";
	surfaces[surfaces.size] = "generic";
	surfaces[surfaces.size] = "grass";
	surfaces[surfaces.size] = "sand";

	// Init some local variables
	endorigin = (0,0,0);
	m = 0;
	pc = 0;
	x = 0;
	y = 0;
	trace = [];
	surface = "generic";

	// Do an endless loop
	for(;;)
	{
		// Get a random delay
		range = int(level.mortar_delay_max - level.mortar_delay_min);
		delay = randomInt(range);
		delay = level.mortar_delay_min + delay;

		wait delay;

		// Spawn mortar model
		mortar = spawn("script_model", (0,0,0));
		mortar setModel(level.mortarmodel);
		mortar hide();	// Hide it until we need it


		// Get a random mortar incoming sound
		m = randomInt(level.mortars.size);

		// Random strength
		pc = randomInt(100);

		// Get it's damage range
		range = int(200 + pc*360*0.01);

		// Make sure loop is run at least once
		distance = -1;

		// Loop until we find a safe spot if safety is 1
		while(distance < (level.mortar_safety * range * 2))
		{

			// Get all alive players
			players = [];
			level.allplayers = getentarray("player", "classname");
			for(i=0;i<level.allplayers.size;i++)
				if(isdefined(level.allplayers[i]))
					if(level.allplayers[i].sessionstate == "playing")
						players[players.size] = level.allplayers[i];
	
			// Find a random target if there is any alive players
			if(!level.mortar_random && players.size)
			{
				// Get a random player
				p = randomInt(players.size);
				// Get a random angle			
				angle = (0,randomInt(360),0);
				// Convert to vector
				vector = anglesToForward(angle);
				// Scale vector differently depending on safety
				variance = maps\mp\_utility::vectorScale(vector, range*level.mortar_safety*2 + randomInt(range*3) );
				// Set mortar origin;
				endorigin = players[p].origin + variance;
			}
			else	// Use a random impact point
			{
				x = level.vMin[0] + randomInt(int(level.vMax[0]-level.vMin[0]));
				y = level.vMin[1] + randomInt(int(level.vMax[1]-level.vMin[1]));
				z = level.vMin[2];
				endorigin = (x,y,z);
			}

			// find the impact point
			trace = bulletTrace((endorigin[0],endorigin[1],maxz),(endorigin[0],endorigin[1],level.vMin[2]), false, undefined);
			endorigin = trace["position"];

			// Check if any other player is within range
			if(level.mortar_safety && players.size)
			{
				bplayers = sortByDist(players, mortar);
				distance = distance(endorigin, bplayers[0].origin);
			}
			else	// No safety on = end loop
				break;

			wait 0.2;  // in case it has to loop a lot because of safety
		}

		// Get surfacetype
		surface = trace["surfacetype"];

		// Start point for mortar
		startpoint = ( (endorigin[0] - 200 + randomInt(400)) , (endorigin[1] - 200 + randomInt(400)) ,maxz);

		mortar.origin = startpoint;

		wait .05;

		// play the incoming sound
		mortar playsound(level.mortars[m]["incoming"]);

		falltime = .5;

		// wait for it to hit
		wait level.mortars[m]["delay"] - 0.05 - falltime;

		// Show visible mortar object
		mortar.angles = vectortoangles(vectornormalize(mortar.origin - startpoint));
		mortar show();
		wait .05;

		// Move visible mortar
		mortar moveto(endorigin, falltime);

		// wait for it to hit
		wait falltime;

		if(!isdefined(level.mortarfx[surface]))
		{
		//	if(level.wintermap)
		//		surface = "snow";
		//	else
				surface = surfaces[randomInt(surfaces.size)];
		}

		playfx(level.mortarfx[surface], endorigin);

		// Play explosion sound
		mortar playsound("mortar_explosion" + (randomInt(5) + 1));

		// Hide visible mortar
		mortar hide();

		// just to be extra safe, since a player MIGHT move in range during the "incoming" sound
		if(!level.mortar_safety)
		{
			// do the damage
			max = 200 + 200*pc*0.01;
			min = 10;
			radiusDamage(endorigin + (0,0,12), range, max, min);
		}

		if(level.mortar_quake)
		{
			// rock their world
			strength = 0.5 + 0.5 * pc * 0.01;
			length = 1 + 3*pc*0.01;
			range = int(600 + 600*pc*0.01);
			earthquake(strength, length, endorigin, range); 
		}
		// Loop through bodies
		//ent=getentarray();
		//for(i=0;i<ent.size;i++)
		//{
		//	dst=distance(self.origin,ent[i].origin);
		//	if(dst<250&&ent[i].classname=="noclass")
		//		self body_boom(ent[i]);
		//}
		body = getentarray("body","targetname");
		for(i=0;i<body.size;i++)
		{
			dst=distance(mortar.origin,body[i].origin);
			if(dst<250&&isdefined(body)&&body[i].targetname=="body")
			{
				if(50>=randomint(100))
					self _mc2\_artillery::body_boom(body[i]);
			}
		}
		mortar delete();
	}
}
FindMapDimensions()
{
	// Get entities
	entitytypes = getentarray();

	// Initialize
	iMaxX = entitytypes[0].origin[0];
	iMinX = iMaxX;
	iMaxY = entitytypes[0].origin[1];
	iMinY = iMaxY;
	iMaxZ = entitytypes[0].origin[2];
	iMinZ = iMaxZ;

	// Loop through the rest
	for(i = 1; i < entitytypes.size; i++)
	{
		// Find max values
		if (entitytypes[i].origin[0]>iMaxX)
			iMaxX = entitytypes[i].origin[0];

		if (entitytypes[i].origin[1]>iMaxY)
			iMaxY = entitytypes[i].origin[1];

		if (entitytypes[i].origin[2]>iMaxZ)
			iMaxZ = entitytypes[i].origin[2];

		// Find min values
		if (entitytypes[i].origin[0]<iMinX)
			iMinX = entitytypes[i].origin[0];

		if (entitytypes[i].origin[1]<iMinY)
			iMinY = entitytypes[i].origin[1];

		if (entitytypes[i].origin[2]<iMinZ)
			iMinZ = entitytypes[i].origin[2];
	}

	// Get middle of map
	iX = int((iMaxX + iMinX)/2);
	iY = int((iMaxY + iMinY)/2);
	iZ = int((iMaxZ + iMinZ)/2);

      // Find iMaxZ
	iTraceend = iZ;
	iTracelength = 50000;
	iTracestart = iTraceend + iTracelength;
	trace = bulletTrace((iX,iY,iTracestart),(iX,iY,iTraceend), false, undefined);
	if(trace["fraction"] != 1)
	{
		iMaxZ = iTracestart - (iTracelength * trace["fraction"]) - 100;
	} 

	// Find iMaxX
	iTraceend = iX;
	iTracelength = 100000;
	iTracestart = iTraceend + iTracelength;
	trace = bulletTrace((iTracestart,iY,iZ),(iTraceend,iY,iZ), false, undefined);
	if(trace["fraction"] != 1)
	{
		iMaxX = iTracestart - (iTracelength * trace["fraction"]) - 100;
	} 
	
	// Find iMaxY
	iTraceend = iY;
	iTracelength = 100000;
	iTracestart = iTraceend + iTracelength;
	trace = bulletTrace((iX,iTracestart,iZ),(iX,iTraceend,iZ), false, undefined);
	if(trace["fraction"] != 1)
	{
		iMaxY = iTracestart - (iTracelength * trace["fraction"]) - 100;
	} 

	// Find iMinX
	iTraceend = iX;
	iTracelength = 100000;
	iTracestart = iTraceend - iTracelength;
	trace = bulletTrace((iTracestart,iY,iZ),(iTraceend,iY,iZ), false, undefined);
	if(trace["fraction"] != 1)
	{
		iMinX = iTracestart + (iTracelength * trace["fraction"]) + 100;
	} 
	
	// Find iMinY
	iTraceend = iY;
	iTracelength = 100000;
	iTracestart = iTraceend - iTracelength;
	trace = bulletTrace((iX,iTracestart,iZ),(iX,iTraceend,iZ), false, undefined);
	if(trace["fraction"] != 1)
	{
		iMinY = iTracestart + (iTracelength * trace["fraction"]) + 100;
	} 

	// Find iMinZ
	iTraceend = iZ;
	iTracelength = 50000;
	iTracestart = iTraceend - iTracelength;
	trace = bulletTrace((iX,iY,iTracestart),(iX,iY,iTraceend), false, undefined);
	if(trace["fraction"] != 1)
	{
		iMinZ = iTracestart + (iTracelength * trace["fraction"]) + 100;
	} 
	level.vMax = (iMaxX, iMaxY, iMaxZ);
	level.vMin = (iMinX, iMinY, iMinZ);
}

/*-------------------------------------------
 sort a list of entities with ".origin" properties in ascending order by their distance from the "startpoint"
 "points" is the array to be sorted
 "startpoint" (or the closest point to it) is the first entity in the returned list
 "maxdist" is the farthest distance allowed in the returned list
 "mindist" is the nearest distance to be allowed in the returned list
-------------------------------------------*/
sortByDist(points, startpoint, maxdist, mindist)
{
	if(!isdefined(points))
		return undefined;
	if(!isdefineD(startpoint))
		return undefined;

	if(!isdefined(mindist))
		mindist = -1000000;
	if(!isdefined(maxdist))
		maxdist = 1000000; // almost 16 miles, should cover everything.

	sortedpoints = [];

	max = points.size-1;
	for(i = 0; i < max; i++)
	{
		nextdist = 1000000;
		next = undefined;

		for(j = 0; j < points.size; j++)
		{
			thisdist = distance(startpoint.origin, points[j].origin);
			if(thisdist <= nextdist && thisdist <= maxdist && thisdist >= mindist)
			{
				next = j;
				nextdist = thisdist;
			}
		}

		if(!isdefined(next))
			break; // didn't find one that fit the range, stop trying

		sortedpoints[i] = points[next];

		// shorten the list, fewer compares
		points[next] = points[points.size-1]; // replace the closest point with the end of the list
		points[points.size-1] = undefined; // cut off the end of the list
	}

	sortedpoints[sortedpoints.size] = points[0]; // the last point in the list

	return sortedpoints;
}