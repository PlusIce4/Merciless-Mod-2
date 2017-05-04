/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell, Tally */
/* Script Code Snippets:  */
/* Spawn Related Utils */


createExtraSpawnpoint( classname, origin, yaw )
{
	spawnpoint = spawn( "script_origin", origin );
	spawnpoint.angles = (0,yaw,0);
	
	if( !isdefined( level.extraSpawnpoints ) )
		level.extraSpawnpoints = [];
		
	if( !isdefined( level.extraSpawnpoints[classname] ) )
		level.extraSpawnpoints[classname] = [];
		
	level.extraSpawnpoints[classname][ level.extraSpawnpoints[classname].size ] = spawnpoint;
}
getGroundpoint( entity )
{
	trace = bullettrace( entity.origin+(0,0,10), entity.origin + (0,0,-2000), false, entity );
	groundpoint = trace["position"];
	
	finalz = groundpoint[2];
	
	for( angleCounter = 0; angleCounter < 10; angleCounter++ )
	{
		angle = angleCounter / 10.0 * 360.0;
			
		pos = entity.origin + (cos( angle ), sin( angle ), 0);
			
		trace = bullettrace( pos+(0,0,10), pos + (0,0,-2000), false, entity );
		hitpos = trace["position"];
			
		if( hitpos[2] > finalz && hitpos[2] < groundpoint[2] + 15 )
			finalz = hitpos[2];
	}
	
	return( groundpoint[0], groundpoint[1], finalz );
}
getSpawnPointsArray()
{
	array = [];

	switch( level.gametype )
	{
		case "tdm":
		case "hq":
		case "dom":
		case "tdef":
		case "kconf":
		case "re":
			array = AddToSpawnArray( array, "mp_tdm_spawn" );
			break;

		case "ctf":
			array = AddToSpawnArray( array, "mp_ctf_spawn_allies" );
			array = AddToSpawnArray( array, "mp_ctf_spawn_axis" );
			break;
		
		case "sd":
			array = AddToSpawnArray( array, "mp_sd_spawn_attacker" );
			array = AddToSpawnArray( array, "mp_sd_spawn_defender" );
			break;
		
		default:
			array = AddToSpawnArray( array, "mp_" + level.gametype + "_spawn" );
			break;
		
	}

	return( array );
}

AddToSpawnArray( array, spawnname )
{
	spawnpoints = maps\mp\gametypes\_spawnlogic::getSpawnpointArray( spawnname );
	for( i = 0; i < spawnpoints.size; i++ )
		array[array.size] = spawnpoints[i];

	return( array );
}
spawnSpectator(origin, angles)
{
	self notify("spawned");
	self notify("end_respawn");

	resettimeout();

	// Stop shellshock and rumble
	self stopShellshock();
	self stoprumble("damage_heavy");

	self.sessionstate = "spectator";
	self.spectatorclient = -1;
	self.archivetime = 0;
	self.psoffsettime = 0;
	self.friendlydamage = undefined;

	if(self.pers["team"] == "spectator")
		self.statusicon = "";

	maps\mp\gametypes\_spectating::setSpectatePermissions();
	
	if(isDefined(origin) && isDefined(angles))
		self spawn(origin, angles);
	else
	{
         	spawnpointname = "mp_global_intermission";
		spawnpoints = getentarray(spawnpointname, "classname");
		spawnpoint = maps\mp\gametypes\_spawnlogic::getSpawnpoint_Random(spawnpoints);
	
		if(isDefined(spawnpoint))
			self spawn(spawnpoint.origin, spawnpoint.angles);
		else
			maps\mp\_utility::error("NO " + spawnpointname + " SPAWNPOINTS IN MAP");
	}
}
FindGround(position)
{
//	trace=bulletTrace(position+(0,0,10),position+(0,0,-1200),false,undefined);
	trace=bulletTrace(position+(0,0,10),position+(0,0,-10000),false,undefined);
	ground=trace["position"];
	return ground;
}

FindPlayArea()
{
	// Get all spawnpoints
	spawnpoints = [];
	temp = getentarray("mp_dm_spawn", "classname");
	if(temp.size)
		for(i=0;i<temp.size;i++)
			spawnpoints[spawnpoints.size] = temp[i];

	temp = getentarray("mp_tdm_spawn", "classname");
	if(temp.size)
		for(i=0;i<temp.size;i++)
			spawnpoints[spawnpoints.size] = temp[i];

	temp = getentarray("mp_sd_spawn_attacker", "classname");
	if(temp.size)
		for(i=0;i<temp.size;i++)
			spawnpoints[spawnpoints.size] = temp[i];

	temp = getentarray("mp_sd_spawn_defender", "classname");
	if(temp.size)
		for(i=0;i<temp.size;i++)
			spawnpoints[spawnpoints.size] = temp[i];

	temp = getentarray("mp_ctf_spawn_allied", "classname");
	if(temp.size)
		for(i=0;i<temp.size;i++)
			spawnpoints[spawnpoints.size] = temp[i];

	temp = getentarray("mp_ctf_spawn_axis", "classname");
	if(temp.size)
		for(i=0;i<temp.size;i++)
			spawnpoints[spawnpoints.size] = temp[i];

	// Initialize
	iMaxX = spawnpoints[0].origin[0];
	iMinX = iMaxX;
	iMaxY = spawnpoints[0].origin[1];
	iMinY = iMaxY;
	iMaxZ = spawnpoints[0].origin[2];
	iMinZ = iMaxZ;

	// Loop through the rest
	for(i = 1; i < spawnpoints.size; i++)
	{
		// Find max values
		if (spawnpoints[i].origin[0]>iMaxX)
			iMaxX = spawnpoints[i].origin[0];

		if (spawnpoints[i].origin[1]>iMaxY)
			iMaxY = spawnpoints[i].origin[1];

		if (spawnpoints[i].origin[2]>iMaxZ)
			iMaxZ = spawnpoints[i].origin[2];

		// Find min values
		if (spawnpoints[i].origin[0]<iMinX)
			iMinX = spawnpoints[i].origin[0];

		if (spawnpoints[i].origin[1]<iMinY)
			iMinY = spawnpoints[i].origin[1];

		if (spawnpoints[i].origin[2]<iMinZ)
			iMinZ = spawnpoints[i].origin[2];
	}

	level.mc2_playAreaMin = (iMinX,iMinY,iMinZ);
	level.mc2_playAreaMax = (iMaxX,iMaxY,iMaxZ);
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
	
	if(level.mc2_debug)
	{
		// Spawn stukas to mark center and corners that we got from the entities.
		stuka1 = spawn_model("xmodel/vehicle_stuka_flying","stuka1",(iX,iY,iMaxZ),(0,90,0));
		stuka11 = spawn_model("xmodel/vehicle_stuka_flying","stuka11",(iX,iY,iMaxZ - 200),(0,90,0));
		stuka12 = spawn_model("xmodel/vehicle_stuka_flying","stuka12",(iX,iY,iMaxZ - 400),(0,90,0));
		stuka4 = spawn_model("xmodel/vehicle_stuka_flying","stuka4",(iMaxX,iMaxY,iMaxZ),(0,90,0));
		stuka5 = spawn_model("xmodel/vehicle_stuka_flying","stuka5",(iMinX,iMinY,iMaxZ),(0,90,0));
		stuka6 = spawn_model("xmodel/vehicle_stuka_flying","stuka6",(iMaxX,iMinY,iMaxZ),(0,90,0));
		stuka7 = spawn_model("xmodel/vehicle_stuka_flying","stuka7",(iMinX,iMaxY,iMaxZ),(0,90,0));
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
	if(level.mc2_debug)
	{
		// Spawn stukas to mark the corner we got from bulletTracing
		stuka14 = spawn_model("xmodel/vehicle_stuka_flying","stuka14",(iMaxX,iMaxY,iMaxZ-200),(0,90,0));
		stuka15 = spawn_model("xmodel/vehicle_stuka_flying","stuka15",(iMinX,iMinY,iMaxZ-200),(0,90,0));
		stuka16 = spawn_model("xmodel/vehicle_stuka_flying","stuka16",(iMaxX,iMinY,iMaxZ-200),(0,90,0));
		stuka17 = spawn_model("xmodel/vehicle_stuka_flying","stuka17",(iMinX,iMaxY,iMaxZ-200),(0,90,0));
	}
	level.mc2_vMax = (iMaxX, iMaxY, iMaxZ);
	level.mc2_vMin = (iMinX, iMinY, iMinZ);
}	