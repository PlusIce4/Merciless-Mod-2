/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Tally, Bell */
/* Script Code Snippets: Merciless Mod Team */
/* Origin Script such as groundpos, spawnmodel, positions ect. */


/****************************************************************************************************************

	sort a list of entities with ".origin" properties in ascending order by their distance from the "startpoint"
	"points" is the array to be sorted
	"startpoint" (or the closest point to it) is the first entity in the returned list
	"maxdist" is the farthest distance allowed in the returned list
	"mindist" is the nearest distance to be allowed in the returned list
	
******************************************************************************************************************/
sortByDist( points, startpoint, maxdist, mindist )
{
	if( !isdefined( points ) )
		return undefined;
	if( !isdefineD( startpoint ) )
		return undefined;

	if( !isdefined( mindist ) )
		mindist = -1000000;
	if( !isdefined( maxdist ) )
		maxdist = 1000000; // almost 16 miles, should cover everything.

	sortedpoints = [];

	max = points.size-1;
	for(i = 0; i < max; i++)
	{
		nextdist = 1000000;
		next = undefined;

		for( j = 0; j < points.size; j++ )
		{
			thisdist = distance( startpoint.origin, points[j].origin );
			if( thisdist <= nextdist && thisdist <= maxdist && thisdist >= mindist )
			{
				next = j;
				nextdist = thisdist;
			}
		}

		if( !isdefined( next ) )
			break; // didn't find one that fit the range, stop trying

		sortedpoints[i] = points[next];

		// shorten the list, fewer compares
		points[next] = points[points.size-1]; // replace the closest point with the end of the list
		points[points.size-1] = undefined; // cut off the end of the list
	}

	sortedpoints[sortedpoints.size] = points[0]; // the last point in the list

	return( sortedpoints );
}
GetStance()
{
	trace = bulletTrace( self.origin, self.origin + ( 0, 0, 80 ), false, undefined );
	top = trace["position"] + ( 0, 0, -1); //find the ceiling, if it's lower than 80

	bottom = self.origin + ( 0, 0, -12 );
	forwardangle = maps\mp\_utility::vectorScale( anglesToForward( self.angles ), 12 );

	leftangle = ( -1 * forwardangle[1], forwardangle[0], 0 );//a lateral vector

	//now do traces at different sample points
	//there are 9 sample points, forming a 3x3 grid centered on player's origin
	//and oriented with the player facing forward
	trace = bulletTrace( top + forwardangle, bottom + forwardangle, true, undefined );
	height1 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top - forwardangle, bottom - forwardangle, true, undefined );
	height2 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top + leftangle, bottom + leftangle, true, undefined );
	height3 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top - leftangle, bottom - leftangle, true, undefined );
	height4 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top + leftangle + forwardangle, bottom + leftangle + forwardangle, true, undefined );
	height5 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top - leftangle + forwardangle, bottom - leftangle + forwardangle, true, undefined );
	height6 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top + leftangle - forwardangle, bottom + leftangle - forwardangle, true, undefined );
	height7 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top - leftangle - forwardangle, bottom - leftangle - forwardangle, true, undefined );
	height8 = trace["position"][2] - self.origin[2];

	trace = bulletTrace( top, bottom, true, undefined );
	height9 = trace["position"][2] - self.origin[2];

	//find the maximum of the height samples
	heighta = getMax( height1, height2, height3, height4 );
	heightb = getMax( height5, height6, height7, height8 );
	maxheight = getMax( heighta, heightb, height9, 0 );

	//categorize stance based on height
	if( maxheight < 33 )
		stance = "prone";
	else if( maxheight < 52 )
		stance = "crouch";
	else
		stance = "stand";

	return( stance );
}

getMax( a, b, c, d )
{
	if( a > b )
		ab = a;
	else
		ab = b;
		
	if( c > d )
		cd = c;
	else
		cd = d;
		
	if( ab > cd )
		m = ab;
	else
		m = cd;
		
	return m;
}

spawn_model( model, name, origin, angles )
{
	if( !isdefined( model ) || !isdefined( name ) || !isdefined( origin ) )
		return undefined;

	if( !isdefined( angles ) )
		angles = (0,0,0);

	spawn = spawn( "script_model", (0,0,0) );
	spawn.origin = origin;
	spawn setmodel( model );
	spawn.targetname = name;
	spawn.angles = angles;

	return( spawn );
}

putinQ(type)
{
	index = level.objectQcurrent[type];

	level.objectQcurrent[type]++;
	if(level.objectQcurrent[type] >= level.objectQsize[type])
		level.objectQcurrent[type] = 0;

	if(isDefined(level.objectQ[type][index]))
	{
		level.objectQ[type][index] notify("bounceobject");
		level.objectQ[type][index] notify("healthpack");
		level.objectQ[type][index] notify("medcrate");
		level.objectQ[type][index] notify("ammocrate");

		wait .05; //Let thread die
		if(isDefined(level.objectQ[type][index].anchor))
		{
			level.objectQ[type][index] unlink();
			level.objectQ[type][index].anchor delete();
		}
		level.objectQ[type][index] delete();
	}
	
	level.objectQ[type][index] = self;
}

spawn_weapon( name, targetname, origin, angles, spawnflag )
{
	newname = "weapon_" + name;
	ent = spawn( newname, origin, spawnflag );
	ent setModel( getModelName( name ) );
	ent.targetname = targetname;
	ent.angles = angles;
}
addobj( name, origin, angles )
{
   ent = spawn( "trigger_radius", origin, 0, 48, 148 );
   ent.targetname = name;
   ent.angles = angles;
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
// bounceObject
//
// rotation		(pitch, yaw, roll) degrees/seconds
// velocity		start velocity
// offset		offset between the origin of the object and the desired rotation origin.
// angles		angles offset between anchor and object
// radius		radius between rotation origin and object surfce
// falloff		velocity falloff for each bounce 0 = no bounce, 1 = bounce forever
// bouncesound	soundalias played at bounching
// bouncefx		effect to play on bounce
//

bounceObject(vRotation, vVelocity, vOffset, angles, radius, falloff, bouncesound, bouncefx, objecttype,stopcount)
{	
	level endon("disconnect");
	self endon("bounceobject");

	if(isdefined(objecttype))
		self thread putinQ(objecttype);

	// Hide until everthing is setup
	self hide();

	// Setup default values
	if(!isdefined(vRotation))	vRotation = (0,0,0);
	pitch = vRotation[0]*0.05;	// Pitch/frame
	yaw	= vRotation[1]*0.05;	// Yaw/frame
	roll	= vRotation[2]*0.05;	// Roll/frame

	if(!isdefined(vVelocity))	vVelocity = (0,0,0);
	if(!isdefined(vOffset))		vOffset = (0,0,0);
	if(!isdefined(falloff))		falloff = 0.5;

	// Spawn anchor (the object that we will rotate)
	self.anchor = spawn("script_origin", self.origin );
	self.anchor.angles = self.angles;

	// Link to anchor
	self linkto( self.anchor, "", vOffset, angles );
	self show();

	wait .05;	// Let it happen

	if(isdefined(level.mc2_gravity))
		gravity = level.mc2_gravity;
	else
		gravity = 100;

	// Set gravity
	vGravity = (0,0,-0.02 * gravity);

	stopme = 0;
	notrace = 5;	// Avoid bullettrace for the first number of frames
	// Drop with gravity
	for(;;)
	{
		// Let gravity do, what gravity do best
		vVelocity +=vGravity;
		
		if(!isDefined(self.anchor)) return;
		
		// Get destination origin
		neworigin = self.anchor.origin + vVelocity;

		// Check for impact, check for entities but not myself.
		if(!notrace)
		{
//			trace=bulletTrace(self.anchor.origin,neworigin,true,self); 
			trace=bulletTrace(self.anchor.origin,neworigin,false,undefined); 
			if(trace["fraction"] != 1)	// Hit something
			{
				// Place object at impact point - radius
				distance = distance(self.anchor.origin,trace["position"]);
				if(distance)
				{
					fraction = (distance - radius) / distance;
					delta = trace["position"] - self.anchor.origin;
					delta2 = maps\mp\_utility::vectorScale(delta,fraction);
					neworigin = self.anchor.origin + delta2;
				}
				else
					neworigin = self.anchor.origin;

				// Play sound if defined
				if(isdefined(bouncesound)) self.anchor playSound(bouncesound + trace["surfacetype"]);	

				// Test if we are hitting ground and if it's time to stop bouncing
				if(vVelocity[2] <= 0 && vVelocity[2] > -10) stopme++;
				if(stopme==stopcount)
				{
					stopme=0;
					// Set origin to impactpoint	
					self.anchor.origin = neworigin;
					wait .05;
					// Delete anchor to save gamestate size
					self unlink();
					self.anchor delete();
					return;
				}
				// Play effect if defined and it's a hard hit
				if(isdefined(bouncefx) && length(vVelocity) > 20) playfx(bouncefx,trace["position"]);

				// Decrease speed for each bounce.
				vSpeed = length(vVelocity) * falloff;

				// Calculate new direction (Thanks to Hellspawn this is finally done correctly)
				vNormal = trace["normal"];
				vDir = maps\mp\_utility::vectorScale(vectorNormalize( vVelocity ),-1);
				vNewDir = ( maps\mp\_utility::vectorScale(maps\mp\_utility::vectorScale(vNormal,2),vectorDot( vDir, vNormal )) ) - vDir;

				// Scale vector
				vVelocity = maps\mp\_utility::vectorScale(vNewDir, vSpeed);
	
				// Add a small random distortion
				vVelocity += (randomFloat(1)-0.5,randomFloat(1)-0.5,randomFloat(1)-0.5);
			}
		}
		else
			notrace--;

		if(!isDefined(self.anchor)) return;
		self.anchor.origin = neworigin;

		// Rotate pitch
		a0 = self.anchor.angles[0] + pitch;
		while(a0<0) a0 += 360;
		while(a0>359) a0 -=360;

		// Rotate yaw
		a1 = self.anchor.angles[1] + yaw;
		while(a1<0) a1 += 360;
		while(a1>359) a1 -=360;

		// Rotate roll
		a2 = self.anchor.angles[2] + roll;
		while(a2<0) a2 += 360;
		while(a2>359) a2 -=360;
		self.anchor.angles = (a0,a1,a2);
		
		// Wait one frame
		wait .05;
	}
}
addobj( name, origin, angles )
{
   ent = spawn( "trigger_radius", origin, 0, 48, 148 );
   ent.targetname = name;
   ent.angles = angles;
}

getcoords( dvar )
{
	array = StrTok( dvar, "," );

	coords = ( int( array[0] ), int( array[1] ), int( array[2] )-60 );

	return( coords );
}