/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

breath()
{
	self endon ("TimeToDie");
	self endon ("killed_player");
	self endon ("disconnect");
	wait (2 + randomint(3));
	while(isdefined(self)&&isalive(self) && self.sessionstate == "playing")
	{
		playfxOnTag ( level._effect["breath"], self, "TAG_EYE" );
		wait randomfloatrange(1.5,3.5);
	}
	
}


