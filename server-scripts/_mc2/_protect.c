/**************************************************************************
MERCILESS MOD 2 V3.4+
Developed by PlusIce (current), Merciless Mod Team (previous work)
See credits.txt for complete works cited
**************************************************************************/

init()
{
	//CVARS
	if(getcvar("scr_spawnprotect") == "")
		setcvar("scr_spawnprotect","1");	
		
	level.scr_spawnprotect= getcvarint("scr_spawnprotect");
	
	//Levels
	level._sprottext = (&"Spawn Protected: ^3");	

}
spawnPlayer()
{
	if(level.scr_spawnprotect)
		self thread spawnprotect();

}
spawnprotect()
{
	
	self endon ("TimeToDie");
	self endon("killprotection");
	self endon ("killed_player");
	self endon ("disconnect");
	len = getcvarint("scr_spawnprotect_time");
	self.protected = 1;
	if(isdefined(self.protected)&&self.protected==1)
		iDamage=0;
	if(!isDefined(self.sprot))
	{
		self.sprot = newClientHudElem(self);
		self.sprot.x = 320;
		self.sprot.y = 340;
		self.sprot.alignX = "center";
		self.sprot.alignY = "middle";
		self.sprot.label = level._sprottext;
			
	}
	self thread watchWeaponUsage();
	for(i = 0; i < len ;i++)
	{
		self.sprot setvalue(len-i);
		wait 1;
	}
	self.protected = undefined;
	if(isDefined(self.sprot))
		self.sprot destroy();
	//self iprintlnbold("You Are No Longer Protected");
	self notify("killprotection");

}
watchWeaponUsage()
{
	self endon("TimeToDie");
	self endon("killprotection");
	self endon ("killed_player");
	self endon ("disconnect");
	while(isdefined(self)&&self attackButtonPressed())
		wait .05;

	while(isdefined(self)&&!(self attackButtonPressed()))
		wait .05;
	self.protected = undefined;
	if(isDefined(self.sprot))
		self.sprot destroy();

	//self iprintlnbold("You Are No Longer Protected");	
	self notify("killprotection");
}