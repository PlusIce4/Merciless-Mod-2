/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Weapon Utils */

ammoClips() 
{
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
			
		// Scoped Semi Rifles
	if(WeaponType(wpn)=="scopedsemi"&&ammo_clip<=2)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="scopedsemi"&&ammo_clip>2)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="scopesemi"&&ammo<=10)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="scopesemi"&&ammo>10)
		self.ammo.color = (1,1,1);	
					
		// Scoped Bolt Action
	if(WeaponType(wpn)=="scopedbolt"&&ammo_clip<=2)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="scopedbolt"&&ammo_clip>2)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="scopedbolt"&&ammo<=10)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="scopedbolt"&&ammo>10)
		self.ammo.color = (1,1,1);	
					
		// Semi Rifles
	if(WeaponType(wpn)=="semirifle"&&ammo_clip<=2)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="semirifle"&&ammo_clip>2)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="semirifle"&&ammo<=10)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="semirifle"&&ammo>10)
		self.ammo.color = (1,1,1);	

		//Bolt Action
	if(WeaponType(wpn)=="bolt"&&ammo_clip<=2)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="bolt"&&ammo_clip>2)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="bolt"&&ammo<=10)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="bolt"&&ammo>10)
		self.ammo.color = (1,1,1);

		// Mobile MGs
	if(WeaponType(wpn)=="mobile"&&ammo_clip<=2)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="mobile"&&ammo_clip>2)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="mobile"&&ammo<=10)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="mobile"&&ammo>10)
		self.ammo.color = (1,1,1);	
				
		//Sub Machine Gun
	if(WeaponType(wpn)=="smg"&&ammo_clip<=10)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="smg"&&ammo_clip>10)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="smg"&&ammo<=40)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="smg"&&ammo>40)
		self.ammo.color = (1,1,1);
					
		//Assault Rifle
	if(WeaponType(wpn)=="assault"&&ammo_clip<=10)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="assault"&&ammo_clip>10)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="assault"&&ammo<=40)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="assualt"&&ammo>40)
		self.ammo.color = (1,1,1);
					
		//Shotgun
	if(WeaponType(wpn)=="shotgun"&&ammo_clip<=3)
	self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="shotgun"&&ammo_clip>3)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="shotgun"&&ammo<=16)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="shotgun"&&ammo>16)
		self.ammo.color = (1,1,1);
		
	//Turret
	if(WeaponType(wpn)=="turret"&&ammo_clip<=5)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="turret"&&ammo_clip>5)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="turret"&&ammo<=30)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="turret"&&ammo>30)
		self.ammo.color = (1,1,1);	

	//Mounted Turret
	if(WeaponType(wpn)=="mgs"&&ammo_clip<=5)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="mgs"&&ammo_clip>5)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="mgs"&&ammo<=30)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="mgs"&&ammo>30)
		self.ammo.color = (1,1,1);		
		
/* Future Usage
	//Special: FG42, Scoped MP44, Short Scope Kar98k ect.
	if(WeaponType(wpn)=="special"&&ammo_clip<=5)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="special"&&ammo_clip>5)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="special"&&ammo<=30)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="special"&&ammo>30)
		self.ammo.color = (1,1,1);
		
	//drum: MP40-64, ThommyGun, PPSH Drum
	if(WeaponType(wpn)=="drum"&&ammo_clip<=5)
		self.ammo_clip.color = (1,0,0);
	else if (WeaponType(wpn)=="drum"&&ammo_clip>5)
		self.ammo_clip.color = (1,1,1);
	if(WeaponType(wpn)=="drum"&&ammo<=30)
		self.ammo.color = (1,0,0);
	else if (WeaponType(wpn)=="drum"&&ammo>30)
		self.ammo.color = (1,1,1);	
/*		
}
WeaponType(sWeapon)
{
	switch(sWeapon)
	{
		//Pistol
		case "colt_mp":
		case "luger_mp":
		case "tt30_mp":
		case "webley_mp":
			return "pistol";

		//Bolt Action
		case "defaultweapon_mp":
		case "enfield_mp":
		case "kar98k_mp":
		case "mosin_nagant_mp":
			return "bolt";
		
		//Semi Rifles
		case "g43_mp":
		case "svt40_mp":
		case "m1garand_mp":
		case "m1carbine_mp":
			return "semirifle";
		
		//Scoped Bolts
		case "springfield_mp":
		case "enfield_scope_mp":
		case "kar98k_sniper_mp":
		case "g43_sniper_mp":
		case "mosin_nagant_sniper_mp":
			return "scopedbolt";
		
		//Scoped Semi
		case "scoped_garand_mp":
		case "scoped_svt40_mp":
		case "scoped_g43_mp":
			return "scopedsemi";
		
			
		//SMG
		case "mp40_mp":
		case "pps42_mp":
		case "sten_mp":
		case "thompson_mp":
		case "greasegun_mp":
		case "ppsh_mp":
		case "ppsh41_mp":
		case "mg42_mp":
		case "mg30cal":
			return "smg";			
			
		//Assault
		case "bar_mp":
		case "bren_mp":
		case "mp44_mp":
			return "assault";
		
		// Mobile MGs
		case "mb42_mp":
		case "mb30cal_mp":
			return "mobile";
		
		//Deployable Turrets
		//Add back later
		case "mg42_mp":
		case "mg30cal_mp":	
			return "turret";
		
		//Mounted Turrets	
		case "mg42_fake_mp":
		case "_mg42_mp":
		case "mg30cal_fake_mp":
		case "_mg30cal_mp": 
			return "mgs";
			
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