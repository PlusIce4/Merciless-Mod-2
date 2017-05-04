




#include mc2\_utils_cvardef;
#include mc2\_utils_realism;
#include mc2\_utils_weapons;


init()
{
	level.mc2_realism 			= cvardef( "mc2_realism",1,0,1,"int" );
	level.mc2_bloodmode 			= cvardef( "mc2_bloodmode",1,0,1,"int" );
	level.mc2_hitblip 			= cvardef( "mc2_hitblip",1,0,1,"int" );
	level.mc2_neckbleed 			= cvardef( "mc2_neckbleed",1,0,1,"int" );
	level.mc2_bleed 			= cvardef( "mc2_bleed",11,0,999,"int" );

	
	self.team = self.pers["team"];
	self.killspree = 0;
	self.decaped = 0;
	self.bleed = getCvarInt( "mc2_bleed");
	self.isonfire = undefined;
	self.isKnockedOut = undefined;
	self.puked = undefined;
	self.gassed = undefined; 
	self.thrown = undefined;
	self.scr = undefined;
	self.hand_dmg=undefined;
	self.legdmg = undefined;
	self.helm=0;
	self.spltr=0;
	self.weg=0;
	self.dmg=0;
	self.verwundet=0;
	self.suicide=undefined;
	
	// BLOOD & GORE FX
	if(level.bloodfx<=1)
	{
		level._effect["bloodpools_body"]=loadfx("fx/effects/gore/blood_pool_big_mc.efx");
		level._effect["headpop1"]=loadfx("fx/effects/gore/headpop1.efx");
		level._effect["bloodspurt"]=loadfx("fx/effects/gore/neck_squirt_master_mc.efx");
//		level._effect["ChunkyDeath"] = loadfx("fx/effects/gore/chunky_hit_mc.efx");
		level._effect["hit_extra1_mc"]=loadfx("fx/effects/gore/hit_extra1_mc.efx");
		level._effect["hit_extra2_mc"]=loadfx("fx/effects/gore/hit_extra2_mc.efx");
		level._effect["hit_extra3_mc"]=loadfx("fx/effects/gore/hit_extra3_mc.efx");

		precacheShader("blood_stain_sml01");
		precacheShader("blood_stain_sml02");
		precacheShader("blood_stain_sml03");
		precacheShader("blood_stain_sml04");
		precacheShader("blood_stain_sml05");
		precacheShader("blood_stain_sml06");
		precacheShader("blood_stain_lrg01");
		precacheShader("blood_stain_lrg02");
		precacheShader("blood_stain_lrg03");
		precacheShader("blood_stain_big01");
		precacheShader("blood_stain_big02");
		precacheShader("blood_stain_big03");
	}
	if(level.bloodfx>=2)
	{
		level._effect["bloodpools_body"]=loadfx("fx/effects/gore/blood_pool_big.efx");
		level._effect["headpop1"]=loadfx("fx/effects/gore/headpop2.efx");
		level._effect["bloodspurt"]=loadfx("fx/effects/gore/neck_squirt_master.efx");
//		level._effect["ChunkyDeath"] = loadfx("fx/effects/gore/chunky_hit.efx");
		level._effect["hit_extra1"]=loadfx("fx/effects/gore/hit_extra1.efx");
		level._effect["hit_extra2"]=loadfx("fx/effects/gore/hit_extra2.efx");
		level._effect["hit_extra3"]=loadfx("fx/effects/gore/hit_extra3.efx");

		precacheShader("blood_stain_sml07");
		precacheShader("blood_stain_sml08");
		precacheShader("blood_stain_sml09");
		precacheShader("blood_stain_sml10");
		precacheShader("blood_stain_sml11");
		precacheShader("blood_stain_lrg04");
		precacheShader("blood_stain_lrg05");
		precacheShader("blood_stain_lrg06");
		precacheShader("blood_stain_big01");
		precacheShader("blood_stain_big02");
		precacheShader("blood_stain_big03");
	}
	level._effect["bleed"] = loadfx("fx/effects/gore/blood_drip_sm.efx");
	level._effect["bleed2"] = loadfx("fx/effects/gore/blood_drips2.efx");
	level._effect["blood_spray"] = loadfx("fx/effects/gore/blood_drips.efx");
	level._effect["brain_splat"] = loadfx("fx/effects/gore/brain_splat.efx");

	level._effect["bloodfx"]=loadfx("fx/effects/gore/bloodfx.efx");
	level._effect["bloodimpact"]=loadfx("fx/effects/gore/bloodimpact.efx");
	level._effect["hit_flesh_org"]=loadfx("fx/effects/gore/flesh_hit.efx");
	level._effect["hit_flesh_mc"]=loadfx("fx/effects/gore/hit_flesh_mc.efx");
	level._effect["hit_flesh_mc2"]=loadfx("fx/effects/gore/hit_flesh_mc2_mp.efx");
	level._effect["hit_pistol"]=loadfx("fx/effects/gore/hit_pistol.efx");
	level._effect["hit_bolt"]=loadfx("fx/effects/gore/hit_rifle.efx");
	level._effect["hit_semirifle"]=loadfx("fx/effects/gore/hit_rifle2.efx");
	level._effect["hit_scopedsemi"]=loadfx("fx/effects/gore/hit_rifle.efx");
	level._effect["hit_scopedbolt"]=loadfx("fx/effects/gore/hit_rifle2.efx");
	level._effect["hit_drum"]=loadfx("fx/effects/gore/hit_turret.efx");
	level._effect["hit_smg"]=loadfx("fx/effects/gore/hit_smg.efx");
	level._effect["hit_turret"]=loadfx("fx/effects/gore/hit_turret.efx");
	level._effect["hit_shotgun"]=loadfx("fx/effects/gore/hit_shotgun.efx");

	// GENERAL FX
	level._effect["playerburn"] = loadfx("fx/fire/character_torso_fire.efx");
	level._effect["playerburn2"] = loadfx("fx/fire/character_arm_fire.efx");
	level._effect["playersmoke"] = loadfx ("fx/smoke/bodysmoke.efx");
	level._effect["burnpool_body"]=loadfx("fx/effects/gore/burn_pool_sml.efx");
	level._effect["burn_stains"]=loadfx("fx/effects/gore/burn_stain.efx");

}
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
		else if(WeaponType(a)=="scopedbolt"||WeaponType(a)=="sniper_rifle")		
			playfxontag(level._effect["hit_scopedbolt"],self,getHitLocTag(b));
		else if(WeaponType(a)=="scopedsemi")
			playfxontag(level._effect["hit_scopedsemi"],self,getHitLocTag(b));
		else if(WeaponType(a)=="bolt"||WeaponType(a)=="sniper_rifle")		
			playfxontag(level._effect["hit_bolt"],self,getHitLocTag(b));
		else if(WeaponType(a)=="semirifle")
			playfxontag(level._effect["hit_semirifle"],self,getHitLocTag(b));
		else if(WeaponType(a)=="drum")
			playfxontag(level._effect["hit_drum"],self,getHitLocTag(b));				
		else if(WeaponType(a)=="smg")
			playfxontag(level._effect["hit_smg"],self,getHitLocTag(b));
		else if(WeaponType(a)=="turret")
			playfxontag(level._effect["hit_shotgun"],self,getHitLocTag(b));
		else if(WeaponType(a)=="shotgun")
			playfxontag(level._effect["hit_shotgun"],self,getHitLocTag(b));	
	}
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
	if( !level.mc2_bloodmode ) return;
	if( !level.mc2_neckbleed ) return;



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

	if(/*sMeansOfDeath == "MOD_FLAME" || self isInVehicle() ||*/ sMeansOfDeath == "MOD_UNKNOWN" || sWeapon == "am_fire_mp" || sWeapon == "ax_fire_mp" || sWeapon == "am_gas_mp" || sWeapon == "ax_gas_mp") 
		return;
	
	if( isdefined(self)&&self.health > 0  &&  !isDefined(self.thrown) )
	{	
		if(level.mc2.realism)
		{
			if(self.health <= 10)
			{
				if(!isDefined(self.isKnockedOut))
					self thread slowdeath(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc,psOffsetTime);
			}
			else
			{
				if(self.bleed<=11)
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
				if(self.bleed<=11)
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
	if( !level.mc2_realism ) return;

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
					self thread scream("n");
			}
			forceto("prone");
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
				forceto("prone");
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
CodeCallback_PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, timeOffset)
{
		/*---------------------------------------
		BLOODFX
		----------------------------------------*/
		direction=vDir;
		//vDir2=int(-1*vDir);
		vDir2=vectorMultiply (vDir, -1);
//		vDir3=self.angles;
		if(WeaponType(sWeapon)!="extranades")
		{
			if(sMeansOfDeath == "MOD_MELEE" || (isdefined(eAttacker)&&distance(eAttacker.origin , self.origin ) <= 48) )
			{
				if(isdefined(vdir2))
					direction=vDir2;				

			}
			if(WeaponType(sWeapon)!="boom")
			{
				if(sMeansOfDeath != "MOD_FALLING")
				{
					if(level.bloodfx!=0)
					{
						if(isdefined(vdir2))
							playfx(level._effect["bloodimpact"],vpoint,vDir2);
					}
					if(level.bloodfx==0)
						playfx(level._effect["hit_flesh_org"],vpoint,direction);
					else if(level.bloodfx==1)
						playfx(level._effect["hit_flesh_mc"],vpoint,direction);
					else	
						playfx(level._effect["hit_flesh_mc2"],vpoint,direction);

					if(sMeansOfDeath != "MOD_MELEE")
						bloodFX(sWeapon,sHitLoc);
				}
			}
		}
		/*---------------------------------------
		HIT LOCATION DAMAGE MODIFIER
		----------------------------------------*/
		hit = HitLoc(sHitLoc);
		if(sMeansOfDeath == "MOD_MELEE")
			iDamage = 15;
		else
			if (isDefined(hit) && hit != "none")
			{
				if(getcvar("scr_" + hit) != "")
					iDamage = int(iDamage * (getcvarint("scr_" + hit) * .01));
			}

}
