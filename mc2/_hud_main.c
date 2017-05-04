/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Main HUD Script */

/* Weapon Utils split off to own file */

#include mc2\_utils_weapon;

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
				
				self thread ammoClips();
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

*/ WeaponType and AmmoClips Called from _utils_weapon.gsc */

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