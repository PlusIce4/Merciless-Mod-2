/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

/*-------------------------------------------
Check the stance
code by Matthias Lorenz
-------------------------------------------*/
checkStance()
{
	self endon("disconnect");
	self endon("TimeToDie");

	while(1) 
	{	
		wait 0.25;	
		trace 	= bulletTrace( self.origin + ( 20, 0, 60 ), self.origin + ( -20, 0, 60 ), true, undefined );
		trace2 	= bulletTrace( self.origin + ( 20, 0, 40 ), self.origin + ( -20, 0, 40 ), true, undefined );
		stance = 2;
		if(trace["fraction"] == 1) 
			stance = 1;
		if(trace2["fraction"] == 1) 
			stance = 0;
		self.stance = stance;
	}
}

check_adsbutton()
{
	self.key["adsButtonPressed"] = false;
	self endon("disconnect");
	self endon("TimeToDie");
	while(1)
	{
		if(self playerads() < .85)
		{
			self.key["adsButtonPressed"] = false;
		}
		else
		{
			self.key["adsButtonPressed"] = true;
		}
		wait .05;
	}
}
check_usebutton()
{
	self.key["useButtonPressed"] = undefined; //or false
	self endon("disconnect");
	self endon("TimeToDie");	
}