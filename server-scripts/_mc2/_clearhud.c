/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
//Clean up HUD Elements

resetHUD()
{
	if (isDefined(self.Painscreen))
		self.Painscreen destroy();
	if (isDefined(self.Painscreen2))
		self.Painscreen2 destroy();
	if (isDefined(self.bloodyscreen))
		self.bloodyscreen destroy();
	if (isDefined(self.bloodyscreen1))
		self.bloodyscreen1 destroy();
	if (isDefined(self.bloodyscreen2))
		self.bloodyscreen2 destroy();		
}
hud_playerdeath()
{
	if(isDefined(self.mortaricon))
		self.mortaricon destroy();

	if(isDefined(self.mortarcharge))
		self.mortarcharge destroy();

	if(isDefined(self.healicon))
		self.healicon = undefined;
	if(isdefined(self.hitblip))
		self.hitblip destroy();

	if (isDefined(self.Painscreen))
		self.Painscreen destroy();

	if (isDefined(self.Painscreen2))
		self.Painscreen2 destroy();
	if(isDefined(self.hlth))
		self.hlth destroy();
	if(isDefined(self.wpn_back))
		self.wpn_back destroy();
	if(isDefined(self.health_back))
		self.health_back destroy();
	if(isDefined(self.healthicon))
		self.healthicon destroy();
	if(isDefined(self.ammo_clip))
		self.ammo_clip destroy();
	if(isDefined(self.ammo))
		self.ammo destroy();
	if(isDefined(self.slash))
		self.slash destroy();
	if(isDefined(self.sprint_back))
		self.sprint_back destroy();
	if(isDefined(self.sprint_back2))
		self.sprint_back2 destroy();
	if(isDefined(self.sprint_bar))
		self.sprint_bar destroy();
		
	if(isDefined(self.turret_indicator)) 
		self.turret_indicator destroy();

	if(isdefined(self.heatbar))		
		self.heatbar destroy();
	if(isdefined(self.heatbar_back))	
		self.heatbar_back destroy();
	if(isdefined(self.info_text))	
		self.info_text destroy();
}