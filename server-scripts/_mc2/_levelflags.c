/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

InitPlayer_Flags()
{
	self.team = self.pers["team"];
	self.killspree = 0;
	self.decaped = 0;
	self.bleed = 11;
	self.isonfire = undefined;
	self.isKnockedOut = undefined;
	self.puked = undefined;
	self.gassed = undefined; 
	self.burned = undefined;
	self.flamed = undefined;
	self.thrown = undefined;
	self.scr = undefined;
	self.hand_dmg=undefined;
	self.legdmg = undefined;
	self.helm=0;
	self.spltr=0;
	self.weg=0;
	self.dmg=0;
	self.verwundet=0;
	self.suicide=undefined;
}
