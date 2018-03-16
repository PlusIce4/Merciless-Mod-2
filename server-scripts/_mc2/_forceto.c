/**************************************************************************
MERCILESS MOD 2 V3.4+
Developed by PlusIce (current), Merciless Mod Team (previous work)
See credits.txt for complete works cited
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