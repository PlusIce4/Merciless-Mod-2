/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_playermodels; 

init()
{
	//CVARS
	if(getcvar("scr_spawnprotect") == "")
		setcvar("scr_spawnprotect","1");	
		
	level.scr_spawnprotect= getcvarint("scr_spawnprotect");
	
	//Levels
	level._sprottext = (&"Spawn Protected: ^3");	

}
ProtectSpawnPlayer()
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
nozombie()
{
	for(;;)
	{
		wait .05;
		player = getentarray("player", "classname");
		for(i = 0; i < player.size; i++)
		{
			h=player[i].health;	
			if(h<0)
			{
				player[i].suicide=1;
				player[i] suicide();
				break;
			}
		}
	}
}