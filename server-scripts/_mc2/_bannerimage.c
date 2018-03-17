/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

banner_image(shader, scalex, scaley, x, y)
{
	if(level.scr_merciless2_logo ==0) return;

	logo = newHudElem();
	logo setShader(shader, scalex, scaley);
	logo.y = y;
	logo.x = x;
	logo.alignX = "right";
	logo.alignY = "top";
	logo.horzAlign = "right";
	logo.vertAlign = "top";
}