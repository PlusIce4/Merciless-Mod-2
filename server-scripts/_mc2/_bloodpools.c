/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
//check this script?

BloodPlayerKilled(self.burned, self.origin)
{	
	wait 6;
	
	if(level.scr_bloodpools)
	{
		if(!isdefined(self.burned))
			{
			playfx (level._effect["bloodpools_body"], self.origin);
			}
	}
}
bloodpool(a)
{
	playfx(level._effect["bloodpools_body"],a.origin);
}

