/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell */
/* Script Code Snippets: PlusIce */
/* Head Popping */

#include mc2\_utils_cvardef;
#include mc2\_utils_origins;

init()
{
	if(!level.mc2_realism) return;
	
	// Pop helmet
	level.mc2_pophelmet 		= cvardef("mc2_pophelmet", 50, 0, 100, "int");

	// head popping controls
	level.mc2_pophead			= cvardef("mc2_pophead", 0, 0, 100, "int");
	level.mc2_popheadbullet		= cvardef("mc2_pophead_bullet", 1, 0, 1, "int");
	level.mc2_popheadmelee		= cvardef("mc2_pophead_melee", 1, 0, 1, "int");
	level.mc2_popheadexplosion	= cvardef("mc2_pophead_explosion", 1, 0, 1, "int");

	// Set up object queues
	if(level.mc2_pophead)
	{
		level.mc2_objectQ["head"] = [];
		level.mc2_objectQcurrent["head"] = 0;
		level.mc2_objectQsize["head"] = 4;
	}
	if(level.mc2_pophelmet)
	{
		level.mc2_objectQ["helmet"] = [];
		level.mc2_objectQcurrent["helmet"] = 0;
		level.mc2_objectQsize["helmet"] = 8;
	}

	// Flesh hit effect used by bouncing heads
	if(level.mc2_pophead)
		level.mc2_popheadfx = loadfx("fx/impacts/flesh_hit.efx");
}

CleanupKilled()
{
	self.mc2_helmetpopped = false;
	self.mc2_headpopped = false;
}

popHelmet( damageDir, damage)
{
	self.mc2_helmetpopped = true;

	if(!isdefined(self.hatModel))
		return;

	self detach( self.hatModel , "");

	if(isPlayer(self))
	{
		switch(self.mc2_stance)
		{
			case 2:
				helmetoffset = (0,0,15);
				break;
			case 1:
				helmetoffset = (0,0,44);
				break;
			default:
				helmetoffset = (0,0,64);
				break;
		}
	}
	else
		helmetoffset = (0,0,15);

//	iprintln("hatModel:" + self.hatModel);
	switch(self.hatModel)
	{
		case "xmodel/helmet_russian_trench_a_hat":
		case "xmodel/helmet_russian_trench_b_hat":
		case "xmodel/helmet_russian_trench_c_hat":
		case "xmodel/helmet_russian_padded_a":
			bounce = 0.2;
			impactsound = undefined;
			break;
		default:
			bounce = 0.7;
			impactsound = "helmet_bounce_";
			break;
	}		

	rotation = (randomFloat(540), randomFloat(540), randomFloat(540));
	offset = (0,0,3);
	radius = 6;
	velocity = maps\mp\_utility::vectorScale(damageDir, (damage/20 + randomFloat(5)) ) + (0,0,(damage/20 + randomFloat(5)) );

	helmet = spawn("script_model", self.origin + helmetoffset );
	helmet setmodel( self.hatModel );
	helmet.angles = self.angles;
	helmet.targetname = "popped helmet";
	helmet thread bounceObject(rotation, velocity, offset, (0,0,0), radius, bounce, impactsound, undefined, "helmet");
}

popHead( damageDir, damage)
{
	self.mc2_headpopped = true;

	if(!self.mc2_helmetpopped)
		self popHelmet( damageDir, damage );

	if(!isdefined(self.mc2_headmodel))
		return;

	self detach( self.mc2_headmodel , "");
	playfxontag (level.mc2_popheadfx,self,"J_Neck");

	if(isPlayer(self))
	{
		switch(self.mc2_stance)
		{
			case 2:
				headoffset = (0,0,16);
				break;
			case 1:
				headoffset = (0,0,45);
				break;
			default:
				headoffset = (0,0,65);
				break;
		}
	}
	else
		headoffset = (0,0,16);
	
	rotation = (randomFloat(540), randomFloat(540), randomFloat(540));
	offset = (-2,0,-13);
	radius = 6;

	velocity = maps\mp\_utility::vectorScale(damageDir, (damage/20 + randomFloat(5)) ) + (0,0,(damage/20 + randomFloat(5)) );

	head = spawn("script_model", self.origin + headoffset );
	head setmodel( self.mc2_headmodel );
	head.angles = self.angles;
	head thread bounceObject(rotation, velocity, offset, (-90,0,-90), radius, 0.75, "Land_", level.mc2_popheadfx, "head");
}

delayedbloodfx()
{
	x = 2 + randomint(4);
	for(i=0;i<x;i++)
	{
		wait 0.25 + randomfloat(i);
		if(isdefined(self))
			playfxontag (level.mc2_popheadfx,self,"J_Neck");
	}

/*	x = 15 + randomint(10);
	if(isdefined(level.mc2_bleedingfx))
	{
		for(i=0;i<x && isdefined(self);i++)
		{
			s = 0;
			for(k = 0 ; k < 3 ; k++ )
			{
				p = (randomInt(2) *.1) + (randomInt(5) * .01);
				if(isdefined(self))
					playfxontag(level.mc2_bleedingfx, self ,"J_Neck" );
				wait p;
				s = s + p;
			}
			wait (.75 - s);
		}
	}*/
}
