/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

hud()
{
	back_wpn();
	self thread ammo();
	if(!level.healthregen)
	{
		//icon_health();
		back_health();
		self thread hlth();
	}
}

hlth() 
{
	self endon("disconnect");
	self endon("TimeToDie");
	if(!isDefined(self.hlth))
	{
		self.hlth = newClientHudElem(self);	
		self.hlth.x = 590;
		self.hlth.y = 452;
		self.hlth.fontScale = 1.3;
		//self.hlth.color = (0.9, 0.9, 0.6);
	}	 
	while(isDefined(self))
	{
		hlth=self.health;
		self.hlth setValue(hlth);
		if(hlth<=30)
			self.hlth.color=(1,0,0);
		else
			self.hlth.color=(1,1,1);
		wait .05;
	}
}
ammo()
{
	self endon("disconnect");
	self endon("TimeToDie");
	while(isDefined(self))
	{
		wpn=self getcurrentWeapon();
		if(wpn!="none"&&WeaponType(wpn)!="sprint")
		{
				if(isdefined(self.oo))	
					self.oo destroy();
				if(!isDefined(self.ammo_clip))
				{
					self.ammo_clip = newClientHudElem(self);	
					self.ammo_clip.x = 568.5;
					self.ammo_clip.y = 433;
					self.ammo_clip.fontScale = 1.3;
					//self.ammo_clip.color = (1, 1, 1);
				}
				if(!isDefined(self.ammo))
				{
					self.ammo = newClientHudElem(self);	
					self.ammo.x = 583.5;
					self.ammo.y = 433;
					self.ammo.fontScale = 1.3;
					//self.ammo.color = (0.9, 0.9, 0.6);
					self.ammo.label = (&"MP_SLASH");
				}
				/*if(!isDefined(self.slash))
				{
					self.slash = newClientHudElem(self);	
					self.slash.x = 583.25;
					self.slash.y = 433.5;
					//self.slash.color = (0.9, 0.9, 0.6);
					self.slash SetShader("gfx/icons/hud@iconslash.tga", 16, 16);
				}*/

				slotwpn = self getweaponslotweapon("primaryb");
				wpnslot = "primary";
				if(wpn==slotwpn)
					wpnslot = "primaryb";
				ammo_clip = self getweaponslotclipammo(wpnslot);
				ammo = self getweaponslotammo(wpnslot);
				self.ammo_clip setValue(ammo_clip);
				self.ammo setValue(ammo);

				//pistol
				if(WeaponType(wpn)=="pistol"&&ammo_clip<=2)
					self.ammo_clip.color = (1,0,0);
				else if (WeaponType(wpn)=="pistol"&&ammo_clip>2)
					self.ammo_clip.color = (1,1,1);				
				if(WeaponType(wpn)=="pistol"&&ammo<=8)
					self.ammo.color = (1,0,0);
				else if (WeaponType(wpn)=="pistol"&&ammo>8)
					self.ammo.color = (1,1,1);
///				//panzerfaust/schreck
///				if(WeaponType(wpn)=="boom"&&ammo_clip<=0)
///					self.ammo_clip.color = (1,0,0);
///				else if (WeaponType(wpn)=="boom"&&ammo_clip>0)
///					self.ammo_clip.color = (1,1,1);
///				if(WeaponType(wpn)=="boom"&&ammo<=1)
///					self.ammo.color = (1,0,0);
///				else if (WeaponType(wpn)=="boom"&&ammo>1)
///					self.ammo.color = (1,1,1);
				//rifles
				if(WeaponType(wpn)=="rifle"&&ammo_clip<=2)
					self.ammo_clip.color = (1,0,0);
				else if (WeaponType(wpn)=="rifle"&&ammo_clip>2)
					self.ammo_clip.color = (1,1,1);
				if(WeaponType(wpn)=="rifle"&&ammo<=10)
					self.ammo.color = (1,0,0);
				else if (WeaponType(wpn)=="rifle"&&ammo>10)
					self.ammo.color = (1,1,1);
				//smg
				if(WeaponType(wpn)=="smg"&&ammo_clip<=10)
					self.ammo_clip.color = (1,0,0);
				else if (WeaponType(wpn)=="smg"&&ammo_clip>10)
					self.ammo_clip.color = (1,1,1);
				if(WeaponType(wpn)=="smg"&&ammo<=40)
					self.ammo.color = (1,0,0);
				else if (WeaponType(wpn)=="smg"&&ammo>40)
					self.ammo.color = (1,1,1);
				//extrawurst
				if(WeaponType(wpn)=="shotgun"&&ammo_clip<=3)
					self.ammo_clip.color = (1,0,0);
				else if (WeaponType(wpn)=="shotgun"&&ammo_clip>3)
					self.ammo_clip.color = (1,1,1);
				if(WeaponType(wpn)=="shotgun"&&ammo<=16)
					self.ammo.color = (1,0,0);
				else if (WeaponType(wpn)=="shotgun"&&ammo>16)
					self.ammo.color = (1,1,1);
			
		}			
		wait (.05);
	}

}
back_wpn()
{
	if (!isdefined(self.wpn_back))
	{
		self.wpn_back = newClientHudElem(self);	
		self.wpn_back.alignX = "right";
		self.wpn_back.alignY = "top";
		self.wpn_back.x = 630;
		self.wpn_back.y = 410;
		//self.wpn_back.color = (0.9, 0.9, 0.6);
		self.wpn_back SetShader("gfx/icons/hud@icon_bullet.tga", 64, 64);
	}
}
icon_health()
{
	if (!isdefined(self.healthicon))
	{
		self.healthicon = newClientHudElem(self);
		self.healthicon.alignX = "right";
		self.healthicon.alignY = "top";
		self.healthicon.x = 628;
		self.healthicon.y = 454;
		//self.healthicon.color = (0.9, 0.9, 0.6);
		self.healthicon setShader("gfx/hud/hud@healthcros.tga", 12, 12);
	}
}

back_health()
{
	if (!isdefined(self.health_back))
	{
		self.health_back = newClientHudElem(self);
		self.health_back.alignX = "right";
		self.health_back.alignY = "top";
		self.health_back.x = 630;
		self.health_back.y = 428;
		self.health_back setShader("gfx/hud/hud@helth_back.tga", 64, 64);
	}
}

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
		//sniper rifles
		case "springfield_mp":
		case "enfield_scope_mp":
		case "kar98k_sniper_mp":
		case "g43_sniper_mp":
		case "mosin_nagant_sniper_mp":
			return "rifle";
			
		//SMG
		case "mp40_mp":
		case "pps42_mp":
		case "sten_mp":
		case "thompson_mp":
		case "greasegun_mp":
		case "bar_mp":
		case "bren_mp":
		case "mp44_mp":
		case "ppsh_mp":
		case "mg42_mp":
		case "mg30cal":
			return "smg";	

///	//weapons that gib
///		case "panzerfaust_mp":
///		case "panzerschreck_mp":
///			return "boom";

		//die extrawurst	
		case "shotgun_mp":
			return "shotgun";

		case "sprint_slow_mp":
		case "sprint_med_mp":
		case "sprint_fast_mp":
			return "sprint";
		default: 
			return "default";
	}
}

back_sprint()
{
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
}
//sprinten
bar_sprint()
{
	if (!isdefined(self.sprint_bar))
	{
		self.sprint_bar = newClientHudElem(self);
		self.sprint_bar.x = -20;
		self.sprint_bar.y = 500;
		self.sprint_bar.alignX = "left";
		self.sprint_bar.alignY = "bottom";
	//	self.sprint_bar.horzAlign = "fullscreen";
	//	self.sprint_bar.vertAlign = "fullscreen";
		//self.sprint_bar setShader("gfx/hud/hud@sprint_bar.tga",160,160);
		self.sprint_bar setShader("gfx/hud/hud@sprint_bar.tga",160,160);
	}
}
update_bar_sprint()
{
	while(1)
	{
		wait .05;
		
		sprint=160/level.sprint_time;
		height=int((sprint)* self.sprint_stamina);
		//self.sprint_bar setShader("gfx/hud/hud@sprint_bar.tga", 160, height);
		self.sprint_bar scaleOverTime(0.05,160,height);
	}
}