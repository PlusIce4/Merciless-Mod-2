/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: PlusIce, Merciless Mod Team */
/* Script Code Snippets: */
/* Bloodpooling Script */

#include mc2\_utils_cvardef;
#include mc2\_utils_origins;

init()
{	
	if(!level.mc2_realism) return;

	level.mc2_bloodpooling	= cvardef("mc2_bloodpooling", 1, 0, 1, "int");
	level.mc2_bloodpooling_time = cvardef("mc2_bloodpooling_time", 10, 0, 1000, "float");

	if(!level.mc2_bloodpooling) return;
	
	bloodpool = spawn( "script_model", origin+(0,0,offset) );
	bloodpool setmodel("xmodel/axis_ammobox1");
//	bloodpool.angles = (0,angle-180,0);
	bloodpool.angles = self.angles;

	bloodpool.targetname="bloodpool";
	bloodpool.owner=self;
	
	range = distance( self.origin, origin ) + 120;
	
	bloopool linkto( self );
	bloodpool hide();


}
doBloodPool() //Called by other script
{
	if(!level.mc2_realism) return;
	if(!level.mc2_bloodpooling) return;

	self endon("TimeToDie");
	self endon("disconnect")
		
	bloodpool playfx (level._effect["bloodpools_body"], body.origin);

	self thread timer();

}
timer()
{
	self endon("delete_ammo");
	
	time = self.mc2_bloodpooling_time;
//	for(j = 0;j <= time;j++) 
	
	for(;;)
	{
		time--;
		
		if(time<=0)
		self thread deleteBloodpool();
			
		wait 1;
	}
}
deleteBloodpool()
{
	self notify("delete_bloodpool");
	self delete();
//	bloodpool delete (level._effect["bloodpools_body"]);

}

/*------------------------------------------
Pop off the players helmet
------------------------------------------*/

popHelm(org,ch,vDir,model,iDamage)
{
	if(self.helm==1)return;
	self notify("helm_wech");
	if (isDefined (org))
	{
		// If chance is not one, then get random number
		// based on value passed to function	
		if (ch != 1)
		{
			if (randomint(ch) != 1)
			{
				self.helm=0;
				return self.helm;
			}
		}
		if(!isdefined(model))return;
		self detach (model,"");

		rotation = (randomFloat(540), randomFloat(540), randomFloat(540)); 
		offset = (0,0,-6); 
		radius = 6;
		velocity = maps\mp\_utility::vectorScale(vDir, (iDamage/20 + randomFloat(5)) ) + (0,0,(iDamage/20 + randomFloat(5)) ); 
		helmet = spawn("script_model",org); 
		helmet setmodel( model );
		helmet.angles = self.angles;
		helmet thread bounceObject(rotation, velocity, offset, (-90,0,-90), radius, 0.7, undefined, undefined,"helmet",5);
	}
	self.helm=1;
}
/*--------------------------------------
Some code snippits from AWE that I modified
Thanks Bell :)
--------------------------------------*/
//
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

/*-------------------------------------------
HitBlip 
Based on code from AWE
-------------------------------------------*/
showhit()
{

	self endon("TimeToDie");
	self endon ("disconnect");

	if(isdefined(self.hitblip))
		self.hitblip destroy();

	self.hitblip = newClientHudElem(self);
	self.hitblip.alignX = "center";
	self.hitblip.alignY = "middle";
	self.hitblip.x = 320;
	self.hitblip.y = 240;
	self.hitblip.alpha = 0.5;
	self.hitblip setShader("gfx/hud/hud@fire_ready.tga", 32, 32);
	self.hitblip scaleOverTime(0.05, 64, 64);

	wait 0.15;

	if(isdefined(self.hitblip))
		self.hitblip destroy();
}
doBloodPools()
{
	self endon("TimeToDie");
	self endon("disconnect")
	//PLAY EFFECT FOR 15 SECONDS 
	bloopooltime = 10;     
	for(j = 0;j <= bloopooltime;j++) 
	{
	
		if(level.scr_bloodpools)
		{			
			if(isdefined(body))
			playfx (level._effect["bloodpools_body"], body.origin);
		}
	}

}