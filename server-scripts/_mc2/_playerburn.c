/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

BurnPlayerKilled(self.burned, sWeapon)
{
	if(isdefined(self.burned)&&self.burned==1)
	{
		if(isdefined(sWeapon)&&sWeapon=="fire_mp")
			self thread BurnBody();
		else
			self thread BurnBody2();
	}

}
BurnBody()
{
	t = int(0.1);
	while(isdefined(self) && t < 3 )
	{
		playfx(level._effect["playerburn4"],self.origin + (-10 + randomInt(21),-10 + randomInt(21),-27) );
		delay = 0.1 + randomFloat(0.15);
		t += delay;
		wait delay;
	}
	for(i=0;i<2 && isdefined(self);i++)
	{
		playfx(level._effect["playerburn3"],self.origin);
		wait (0.35 + randomFloat(0.4));
	}
	if(isdefined(self))
	{
		maps\mp\_fx::loopfx("playersmoke", (self.origin), 1,(self.origin+(0,0,1)),undefined,undefined,20);
		wait 2;
		playfx (level._effect["burnpool_body"], self.origin);
	}
}
BurnBody2()
{
	t = int(0.1);
	while(isdefined(self) && t < 3 )
	{
		playfx(level._effect["playerburn"],self.origin + (-10 + randomInt(21),-10 + randomInt(21),-27) );
		delay = 0.1 + randomFloat(0.15);
		t += delay;
		wait delay;
	}
}