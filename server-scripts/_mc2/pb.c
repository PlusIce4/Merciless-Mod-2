/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

pb_init()
{
	level thread pb_onPlayerConnect();
}

pb_onPlayerConnect()
{
	for(;;)
	{
		level waittill("connecting", player);
		
		player setClientCvar("cg_errordecay","100");
		player setClientCvar("cg_fov","80");
		player setClientCvar("cg_hudDamageIconHeight","64");
		player setClientCvar("cg_hudDamageIconInScope","0");
		player setClientCvar("cg_hudDamageIconOffset","128");
		player setClientCvar("cg_hudDamageIconTime","2000");
		player setClientCvar("cg_hudDamageIconWidth","128");
		player setClientCvar("cg_hudObjectiveMaxRange","2048");
		player setClientCvar("cg_hudObjectiveMinAlpha","1");
		player setClientCvar("cg_hudObjectiveMinHeigth","-70");
		player setClientCvar("cg_thirdperson","0");
		player setClientCvar("fx_sort","1");

	}
}