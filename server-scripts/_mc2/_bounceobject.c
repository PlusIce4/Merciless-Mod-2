/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/


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