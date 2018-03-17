/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

/*-------------------------------------------
Force to Prone
based on code by Matthias Lorenz
-------------------------------------------*/
forceto(a)
{
	if(a=="stand")
	{
		self openmenunomouse("stand");
		wait .05;
		self closeMenu();	
	}
	else if(a=="crouch"||a=="duck")
	{
		self openmenunomouse("crouch");
		wait .05;
		self closeMenu();	
	}
	else
	{

		self openmenunomouse("prone");
		wait .05;
		self closeMenu();
	}
}