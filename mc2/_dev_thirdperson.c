/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Tally */
/* Script Code Snippets: PlusIce */
/* Third Person Cheat */

init()
{
	if( !level.mc2_devmode ) return;

	level.mc2_thirdperson = cvardef( "mc2_thirdperson", 1, 0, 1, "int" );
	
	if( !level.mc2_thirdperson ) return;

	ThirdPerson();
}
ThirdPerson()
{
	if( level.thirdperson )
	{
		self setClientCvar("cg_thirdperson", "1");
		self setClientCvar( "cg_thirdpersonangle", level.thirdperson_angle );
		self setClientCvar( "cg_thirdpersonrange", level.thirdperson_range );
	}
	else
	{
		self setClientCvar("cg_thirdperson", "0");
		self setClientCvar( "cg_thirdpersonangle", "180");
		self setClientCvar( "cg_thirdpersonrange", "120");
	}

}