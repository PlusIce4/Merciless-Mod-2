/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

_doSounds(kind,sMOD)
{
	self endon("TimeToDie");
	self endon ("disconnect");
	if (sMOD != "MOD_EXPLOSIVE"&& !isDefined(self.scr))
	{
		self.scr = 1;
		if(level.scr_painsounds > randomint(100))
		{
			if(kind == "death")
				self playsound(self.deathsound);
			else
				self playsound(self.painsound);
		}
		self.scr = undefined;
	}
}
scream(t)
{

	self endon("TimeToDie");
	self.scr = 1;
	if( randomint(100) > 40 || t == "mc" || t == "fc" || t == "p" || t == "h")
	{
		if(t == "f")
			self playsound("nikita_scream");
		else if(t == "m")
			self playsound("mc_scream");
		else if(t == "mc")
			self playsound("mchoke");
		else if(t == "fc")
			self playsound("fchoke");
		else if(t == "p")
			self playsound("puker");
		else if(t == "h")
			self playsound("heave");
		else if(t == "n")
			self playsound("pain");
	}
	else
	{
		self playsound (self.painsound);
	}
	wait 2;
	if(isAlive(self))
		self.scr = undefined;
}