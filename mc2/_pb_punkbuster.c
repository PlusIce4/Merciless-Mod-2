/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* PunkBuster Cvar Script */
/* NOTE: Third Person MUST BE Disabled if PunkBuster is ON */

#include mc2\_utils_cvardef;

init()
{

	if( !level.mc2_devmode ) return;
		
	level.mc2_punkbuster = cvardef( "mc2_punkbuster", 1, 0, 1, "int" );

	if( !level.mc2_punkbuster ) return;

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