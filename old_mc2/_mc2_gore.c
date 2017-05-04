/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Updated on July 2015 by PlusIce
All functions for blood and gore effects 
-------------------------------------------*/
/*------------------------------------------
Adds enhanced blood effects to the game
------------------------------------------*/
bloodFX(a,b)
{
	if(level.bloodfx==0)
		playfxontag(level._effect["hit_flesh_org"],self,getHitLocTag(b));
	else if(level.bloodfx==1)
		playfxontag(level._effect["hit_flesh_mc"],self,getHitLocTag(b));
	else	
	{
		if(WeaponType(a)=="pistol")
			playfxontag(level._effect["hit_pistol"],self,getHitLocTag(b));
		else if(WeaponType(a)=="rifle"||WeaponType(a)=="sniper_rifle")
			playfxontag(level._effect["hit_rifle"],self,getHitLocTag(b));
		else if(WeaponType(a)=="rifle2")
			playfxontag(level._effect["hit_rifle2"],self,getHitLocTag(b));
		else if(WeaponType(a)=="smg")
			playfxontag(level._effect["hit_smg"],self,getHitLocTag(b));
		else if(WeaponType(a)=="turret")
			playfxontag(level._effect["hit_shotgun"],self,getHitLocTag(b));
		/*{
			switch(randomint(2))
			{
			case 0:playfxontag(level._effect["hit_turret"],self,getHitLocTag(b));
			case 1:playfxontag(level._effect["hit_shotgun"],self,getHitLocTag(b));
			}
		}*/
		else if(WeaponType(a)=="shotgun")
			playfxontag(level._effect["hit_shotgun"],self,getHitLocTag(b));
	}
}

/*------------------------------------------
Draw the blood pooling effect
------------------------------------------*/
bloodpool(a)
{
	playfx(level._effect["bloodpools_body"],a.origin);
}
/*------------------------------------------
Gib
------------------------------------------*/
gib(curhead,vDir) //removed from V3.4 Public Alpha
{

}
/*------------------------------------------
Pop off the players head
------------------------------------------*/
popHead()
{
}
/*------------------------------------------
Pop off the players helmet
------------------------------------------*/
popHelm(org,ch,vDir,model,iDamage)
{
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
/*------------------------------------------
Returns a weapon type
used for extra gore effects
------------------------------------------*/
WeaponType(sWeapon)
{
	switch(sWeapon)
	{
		//pistol
		case "colt_mp":
		case "luger_mp":
		case "tt30_mp":
		case "webley_mp":
			return "pistol";

		//rifles
		case "defaultweapon_mp":
		case "enfield_mp":
		case "g43_mp":
		case "kar98k_mp":
		case "m1carbine_mp":
		case "m1garand_mp":
		case "mosin_nagant_mp":
		case "svt40_mp":
			return "rifle";
			
		case "bar_mp":
		case "bren_mp":
		case "mp44_mp":
		case "ppsh_mp":
		case "_mg42_mp":
		case "_mg30cal_mp":
			return "rifle2";

		//sniper rifles
		case "springfield_mp":
		case "enfield_scope_mp":
		case "kar98k_sniper_mp":
		case "g43_sniper_mp":
		case "mosin_nagant_sniper_mp":
			return "sniper";
		//SMG
		case "mp40_mp":
		case "pps42_mp":
		case "sten_mp":
		case "thompson_mp":
		case "greasegun_mp":
			return "smg";	

		//MOUNTED
		case "30cal_prone_mp":
		case "30cal_stand_mp":
		case "30cal_duck_mp":
		case "mg30cal_mp":
		case "mg42_bipod_duck_mp":
		case "mg42_bipod_prone_mp":
		case "mg42_bipod_stand_mp":
		case "mg42_mp":
			return "turret";	

		//weapons that gib
		case "frag_grenade_german_mp":
		case "frag_grenade_american_mp":
		case "frag_grenade_british_mp":
		case "frag_grenade_russian_mp":
			return "boom";

		case "axisfire_mp":
		case "fire_mp":
		case "alliedgas_mp":
		case "axisgas_mp":
			return "specialnades";

		//die extrawurst	
		case "shotgun_mp":
			return "shotgun";
			
		case "mg42_fake_mp":
		//case "mg42_mp":
		case "mg30cal_fake_mp":
		//case "mg30cal_mp":
			return "fake";	

		default: 
			return "default";
	}
}
/*------------------------------------------
Get a tag based on the area of the body 
------------------------------------------*/
getHitLocTag(sHitLoc)
{
	switch(sHitloc)
	{
		case "right_hand":
			return "j_wrist_ri";
		case "left_hand":
			return "j_wrist_le";	
		case "right_arm_upper":	
			return "j_shoulder_ri";
		case "left_arm_upper":
			return "j_shoulder_le";
		case "right_arm_lower":	
			return "j_elbow_ri";
		case "left_arm_lower":
			return "j_elbow_le";
		case "head":
			return "J_Head";
		case "neck":
			return "J_Neck";			
		case "right_foot":
			return "j_ankle_ri";
		case "left_foot":
			return "j_ankle_le";
		case "right_leg_lower":
			return "j_knee_ri";
		case "left_leg_lower":
			return "j_knee_le";
		case "right_leg_upper":
			return "j_hip_ri";					
		case "left_leg_upper":
			return "j_hip_le";
		case "torso_upper":
			switch(randomint(2))
			{
				case 0:
					return "J_Clavicle_RI";
				case 1:
					return "J_Clavicle_LE";
			}		
		case "torso_lower":
			switch(randomint(3))
			{
				case 0:
					return "J_Spine1";
				case 1:
					return "J_Spine2";
				case 2:
					return "J_Spine3";
			}
		case "none":
		default:
			return "J_MainRoot";
	}
}
/*-------------------------------------------
The pain and death sounds
-------------------------------------------*/
_doSounds(kind,sMOD)
{
	self endon("TimeToDie");
	self endon ("disconnect");
	if (sMOD != "MOD_EXPLOSIVE"&& !isDefined(self.scr))
	{
		self.scr = 1;
		if(level.scr_painsounds > randomint(100))
		{
			if(kind == "death")
				self playsound(self.deathsound);
			else
				self playsound(self.painsound);
		}
		self.scr = undefined;
	}
}
/*-------------------------------------------
Blood splats on the players viewcam
-------------------------------------------*/
Splatter_View()
{

	self endon ("TimeToDie");
	self endon ("disconnect");

	if(!isDefined(self.bloodyscreen))
	{
		self.bloodyscreen = newClientHudElem(self);
		self.bloodyscreen1 = newClientHudElem(self);
		self.bloodyscreen2 = newClientHudElem(self);

		self.bloodyscreen.alignX = "left";
		self.bloodyscreen.alignY = "top";

		self.bloodyscreen1.alignX = "left";
		self.bloodyscreen1.alignY = "top";

		self.bloodyscreen2.alignX = "left";
		self.bloodyscreen2.alignY = "top";

		bs1 = (randomint(500));
		bs2 = (randomint(400));
		bs1a = (randomint(500));
		bs2a = (randomint(400));
		bs1b = (randomint(500));
		bs2b = (randomint(400));

		self.bloodyscreen.x = bs1;
		self.bloodyscreen.y = bs2;

		self.bloodyscreen1.x = bs1a;
		self.bloodyscreen1.y = bs2a;

		self.bloodyscreen2.x = bs1b;
		self.bloodyscreen2.y = bs2b;

		bs3 = randomint(32);
		bs3a = randomint(32);
		bs3b = randomint(32);
		self.bloodyscreen.color = (0.7,0,0);
		self.bloodyscreen1.color = (0.9,0,0);
		self.bloodyscreen2.color = (0.5,0,0);
		if(level.bloodfx<2)
		{
			self.bloodyscreen.color = (0.7,0,0);
			self.bloodyscreen1.color = (0.9,0,0);
			self.bloodyscreen2.color = (0.5,0,0);
		}
		else
		{
			self.bloodyscreen.color = (1,0,0);
			self.bloodyscreen1.color = (1,0,0);
			self.bloodyscreen2.color = (1,1,1);
		}
		self.bloodyscreen.alpha = .7;
		self.bloodyscreen1.alpha = .7;
		self.bloodyscreen2.alpha = .7;

		if(level.bloodfx<2)
		{
			self.bloodyscreen SetShader(codescripts\character::randomElement(splatters()),64 + bs3 , 64 + bs3);
			self.bloodyscreen1 SetShader(codescripts\character::randomElement(splatters()),64 + bs3a , 64 + bs3a);
			self.bloodyscreen2 SetShader(codescripts\character::randomElement(splatters()),128 + bs3b , 128 + bs3b);
		}
		else
		{
			self.bloodyscreen SetShader(codescripts\character::randomElement(splatters2()),64 + bs3 , 64 + bs3);
			self.bloodyscreen1 SetShader(codescripts\character::randomElement(splatters2()),64 + bs3a , 64 + bs3a);
			self.bloodyscreen2 SetShader(codescripts\character::randomElement(splatters2()),128 + bs3b , 128 + bs3b);
		}

		wait (4);
		self.bloodyscreen fadeOverTime (2); 
		self.bloodyscreen.alpha = 0;
		self.bloodyscreen1 fadeOverTime (2);
		self.bloodyscreen1.alpha = 0;
		self.bloodyscreen2 fadeOverTime (2);
		self.bloodyscreen2.alpha = 0;
		wait(2);
		self.bloodyscreen destroy();
		self.bloodyscreen1 destroy();
		self.bloodyscreen2 destroy();
	}
}
splatters()
{
	a[0] = "blood_stain_sml01";
	a[1] = "blood_stain_sml02";
	a[2] = "blood_stain_sml03";
	a[3] = "blood_stain_sml04";
	a[4] = "blood_stain_sml05";
	a[5] = "blood_stain_sml06";
	a[6] = "blood_stain_lrg01";
	a[7] = "blood_stain_lrg02";
	a[8] = "blood_stain_lrg03";
	a[9] = "blood_stain_big01";
	a[10] = "blood_stain_big02";
	a[11] = "blood_stain_big03";
	return a;
	
}
splatters2()
{
	a[0] = "blood_stain_sml07";
	a[1] = "blood_stain_sml08";
	a[2] = "blood_stain_sml09";
	a[3] = "blood_stain_sml10";
	a[4] = "blood_stain_sml11";
	a[5] = "blood_stain_lrg04";
	a[6] = "blood_stain_lrg05";
	a[7] = "blood_stain_lrg06";
	return a;
	
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
/*-------------------------------------------
The blood-squirting effects
when a player is decaptitated
-------------------------------------------*/
Neck_Bleed()
{

	for(k = 0 ; k < 60 ; k++ )
	{
		p = (randomint(2) * .05) + (randomint(5) * .01);
		if (K !=30&&isdefined(self))
			playfxontag(level._effect["bleed2"],self,"J_Neck");
		else if (K ==30&&isdefined(self))
			playfxontag(level._effect["bloodspurt"],self,"J_Neck");
		wait p;
		wait (.25 - p);
	}

}
PlayerPain(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime)
{

	if(/*sMeansOfDeath == "MOD_FLAME" || self isInVehicle() ||*/ sMeansOfDeath == "MOD_UNKNOWN" || sWeapon == "fire_mp" || sWeapon == "payload_mp" || sWeapon == "axisgas_mp"|| sWeapon == "axisfire_mp"|| sWeapon == "alliedgas_mp") 
		return;
	
	if( isdefined(self)&&self.health > 0  &&  !isDefined(self.thrown) )
	{	
		
		if(level.realism)
		{
			if(self.health <= 10)
			{
				if(!isDefined(self.isKnockedOut))
					self thread slowdeath(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime);
			}
			else
			{
				if (self.bleed == 11 && (getcvarint("scr_bleed") > 0))
					self thread DoBleedingPain(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime);
				if(!isDefined(self.Painscreen) && level.scr_painscreen)
					self thread DoPainScreen(iDamage,vDir,sMeansOfDeath);
			}
		}
		else
		{
			if(self.health <= 5)
			{
				if(!isDefined(self.isKnockedOut))
					self thread slowdeath(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime);
			}
			else
			{
				if (self.bleed == 11 && (getcvarint("scr_bleed") > 0))
					self thread DoBleedingPain(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime);
				if(!isDefined(self.Painscreen) && level.scr_painscreen)
					self thread DoPainScreen(iDamage,vDir,sMeansOfDeath);
			}
		}
	}
}	

/*-------------------------------------------
Cause the player to die slowly and fade his
screen to red
-------------------------------------------*/
SlowDeath(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime)
{

	if(isDefined(self.isKnockedOut))
		return;

	self endon("TimeToDie");
	self endon ("disconnect");
	self.isKnockedOut = 1;
	secs = randomint(8);
	if(secs == 0) 
		secs  = 3;
	h = self.health;
	medcry = 0;
	unctime = 0;
	if (isDefined(self.Painscreen2))
		self.Painscreen2 destroy();
	
	if (!isDefined(self.Painscreen2))
	{
		self.Painscreen2 = newClientHudElem(self);
		self.Painscreen2.alignX = "left";
		self.Painscreen2.alignY = "top";
		self.Painscreen2.x = 0;
		self.Painscreen2.y = 0;	
		self.Painscreen2.alpha = .05;
		self.Painscreen2 SetShader("gfx/hud/hud@redpain_tr.tga",640,480);
		self.Painscreen2 fadeovertime(secs);
		self.Painscreen2.alpha = .95;
	}
	while(isDefined(self.isKnockedOut) && unctime < (secs * 20) && isAlive(self) && self.health <= h )
	{
		self disableweapon();
		
		x2 = unctime % 30;
		x1 = unctime % 100;
		if(x1 == 1)
		{
			if(randomint(3) == 1)
				self shellshock("mc_mustard", 3);

			if(randomint(2) == 1 )
			{
				if(medcry < 2)
				{
					self playsound(self.nationality + "_medic");
					medcry++;
					self pingplayer();
				}
			}

		}
		if(x2 == 1)
		{
			
			self playlocalsound ("heartbeat");
			if(randomint(3) == 1)
			{
				if(!isDefined(self.scr))
					self thread _mc2\_mc2_util::scream("n");
			}
			_mc2\_mc2_util::forceto("prone");
		}
		wait (.05);
		unctime++;
	}
	if(self.health > h)
	{
		if (isDefined(self.Painscreen2))
			self.Painscreen2 destroy();
		self.isKnockedOut = undefined;
		self enableweapon();
	}
	else 
	{
		_doSounds("death",sMeansOfDeath);
		self.isKnockedOut = undefined;
		self finishPlayerDamage(eInflictor, eAttacker , 100 , iDFlags , sMeansOfDeath , sWeapon , (self.origin + (0,0,-300)), vDir, sHitLoc,psOffsetTime);		
	}
}
/*-------------------------------------------
Bleeding effect when player gets hit. 
-------------------------------------------*/
DoBleedingPain(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime)
{

	self endon ("TimeToDie");
	self endon ("disconnect");
	bLoc = getHitLocTag(sHitLoc);
	x = 11;

	for(self.bleed = 0 ; self.bleed < x ; self.bleed++)
	{
		
		self.health -- ;

		if (self.health <= 1 || self.bleed >= x)
		{
			if (self.health <= 1 )
			{
				_mc2\_mc2_util::forceto("prone");
				_doSounds("death",sMeansOfDeath);
				self finishPlayerDamage(eInflictor, eAttacker, 5 , iDFlags , sMeansOfDeath , sWeapon , (self.origin + (0,0,-300)), vDir, sHitLoc,psOffsetTime);//Kill the player
			}
			else
				self.bleed = 11;

			break;
		}
		
		if (self.health > 10)			
			self playlocalsound("heartbeat");
		else
			self playlocalsound("heartbeat_fast");		

		if (self.bleed == 3 || self.bleed == 5|| self.bleed == 7 || self.bleed == 9)
		{	
			if (randomint(3)==1)
				self playsound(self.bleedpain);
			else
				self playsound("brth");
		}

		s = 0;
		squirt = int(iDamage * .1) + 1;
		if (self.bleed > 0 && self.bleed <= squirt)
		{
			for(k = 0 ; k < 1 ; k++ )
			{
				p = (randomInt(2) *.1) + (randomInt(5) * .01);
				playfxontag (level._effect["blood_spray"], self ,bLoc );
				wait p;
				s = s + p;
			}
		}
		else
		{	
			for(k = 0 ; k < 1 ; k++ )
			{
				p = (randomInt(2) *.1) + (randomInt(5) * .01);
				playfxontag (level._effect["bleed"], self ,bLoc );
				wait p;
				s = s + p;
			}
		}
		wait (.75 - s);
	}
	self.bleed = 11;
}


/*-------------------------------------------
Pain flash on screen when hit
-------------------------------------------*/
DoPainScreen(iDamage,vDir,sMeansOfDeath)
{
	self endon("TimeToDie");
	self endon ("disconnect");

	if(!isDefined(vDir))
		vDir = self.origin;

	if (!isDefined(self.Painscreen))
	{
		self.Painscreen = newClientHudElem(self);
		self.Painscreen.alignX = "left";
		self.Painscreen.alignY = "top";
		self.Painscreen.x = 0;
		self.Painscreen.y = 0;	
		p = iDamage * .01;
		if (p > .8 ) 
			P = .8;
		self.Painscreen.alpha = p;
		t = self.Painscreen.alpha * .1;
		self.Painscreen SetShader("gfx/hud/hud@redpain_tr.tga",640,480);				
		wait ((p * 10) * .15 );
		if(isDefined(self.Painscreen))
		{
			self.Painscreen FadeOverTime(.25);
			self.Painscreen.alpha = 0;
		}
		wait(.25);
		if(isDefined(self.Painscreen))
			self.Painscreen destroy();

	}
}
/*-------------------------------------------
Throws a body through the air
Based on Bell's code for popping off helmets
-------------------------------------------*/
ThrowBody( vDir, damage,pnt)
{
	if(self.thrown==1)return;
	self.thrown = 1;
	if(damage > 175)
		damage = 175;

	if(isDefined(self.anchor))
		return;
	rotation = (randomFloat(40), randomFloat(40), randomFloat(40));
	offset = (0,0,0);
	radius = 0;	
	velocity = maps\mp\_utility::vectorScale(vDir, damage * .003) + (0 , 0 , damage * .003);
	self bounceObject(rotation, velocity, offset, (0,0,0), radius, .01, "bodyfall_flesh_large",level._effect["hit_rifle"],2);
}
/*-------------------------------------------
Borrowed from AWE
Code for burning effect played on 
dead bodies
-------------------------------------------*/
BurnBody()
{
	t = int(0.1);
	while(isdefined(self) && t < 3 )
	{
		playfx(level._effect["playerburn4"],self.origin + (-10 + randomInt(21),-10 + randomInt(21),-27) );
		delay = 0.1 + randomFloat(0.15);
		t += delay;
		wait delay;
	}
	for(i=0;i<2 && isdefined(self);i++)
	{
		playfx(level._effect["playerburn3"],self.origin);
		wait (0.35 + randomFloat(0.4));
	}
	if(isdefined(self))
	{
		maps\mp\_fx::loopfx("playersmoke", (self.origin), 1,(self.origin+(0,0,1)),undefined,undefined,20);
		wait 2;
		playfx (level._effect["burnpool_body"], self.origin);
	}
}
BurnBody2()
{
	t = int(0.1);
	while(isdefined(self) && t < 3 )
	{
		playfx(level._effect["playerburn"],self.origin + (-10 + randomInt(21),-10 + randomInt(21),-27) );
		delay = 0.1 + randomFloat(0.15);
		t += delay;
		wait delay;
	}
}
/*-------------------------------------------
deadbody shooting
-------------------------------------------*/
body_shooting() 
{
	self endon("disconnect");
	self endon("TimeToDie");

	for(;;)
	{         
		if(isAlive(self) && self.sessionstate == "playing") 
		{
			body = getentarray("body","targetname");
			for(j=0;j<body.size;j++)
			{
				if(distance(self.origin,body[j].origin) < 300)
				{
					y1 = (randomint(4));
					x1 = (randomint(20));
					y2 = (randomint(6));
					x2 = (randomint(25));

					// Blickkontakt?
					trace = bullettrace(body[j].origin,self.origin,false,undefined);																		
					if(trace["fraction"]==1)
					{
						// Nur wenn der Spieler den Toten anguckt
						//if(self CanSee(body[j])&&self attackButtonPressed())
						target_range = vectordot(anglestoforward(self getplayerangles()),anglestoforward(vectortoangles(vectornormalize((self getEye() + _mc2\_artillery::getPlayerEyeOffset()) - body[j].origin)))) * -1;
						if(target_range >= 0.97&&isdefined(self)&&self attackButtonPressed())
						{
							waffe=self getcurrentweapon();					
							if(waffe != "none")
							{
								slotwaffe = self getweaponslotweapon("primaryb");

								waffenslot = "primary";
								if(waffe==slotwaffe)
									waffenslot = "primaryb";

								//muni im clip
								clipsize = self getweaponslotclipammo(waffenslot);
								//clipammo = self getweaponslotammo(waffenslot);
								//muni imsgesamt
								ammosize = self getammocount(waffe);

								if(WeaponType(waffe)=="fake")break;

								if(WeaponType(waffe)=="pistol"||WeaponType(waffe)=="rifle"||WeaponType(waffe)=="sniper"||WeaponType(waffe)=="shotgun")
								{
									//schauen ob gehalten
									while(isdefined(self)&&self attackButtonPressed())
										wait 0.1;
									//wieder losgelassen
									while(isdefined(self)&&!(self attackButtonPressed()))
										wait 0.1;
								}

								if(ammosize!=0||clipsize!=0)
								{
									if(!isdefined(body[j]))break;
									//playfx (level._effect["hit_dead"], body[j].origin+(x1,y1,10));
									//playfx (level._effect["hit_dead"], body[j].origin+(x2,y2,10));
									//playfx (level._effect["hit_dead"], body[j].origin+(x1,y1,10));
									playfx (level._effect["hit_flesh_mc"], body[j].origin+(x1,y1,10));
									playfx (level._effect["hit_flesh_mc2"], body[j].origin+(x2,y2,10));
								}
							}
						}
					}
				}
			}
		}	
		wait .05;
	}
}
/*-------------------------------------------
kamikaze //Removed from V2.0
-------------------------------------------*/
kamikaze(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration)
{
	if(isdefined(self.suicide))return;
	rand = randomInt(100);	
	sMeansOfDeath = "MOD_EXPLOSIVE";
	iDFlags = 1;
	irange = int(200 + rand*360*0.01);
	imaxdamage = 200 + 200*rand*0.01;
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
		sWeapon=self getcurrentoffhand();
		players[i] thread [[level.callbackPlayerDamage]]( eInflictor, Attacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, undefined, vDir, "none",0);
	}
}