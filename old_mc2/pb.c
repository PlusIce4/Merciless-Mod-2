/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------

-------------------------------------------*/
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