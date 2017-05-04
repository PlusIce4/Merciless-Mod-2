/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Merciless Mod 2 Bot System */

#include mc2\_utils_cvardef;

init()
{
	if( !level.mc2_devmode ) return;
		
	level.mc2_testclients = cvardef( "mc2_testclients", 0, 0, 64, "int" );

	if( !level.mc2_testclients ) return;
	
	addTestClients();
}
addTestClients()
{
	wait 5;

	for(;;)
	{
		if(level.mc2_testclients<=1)
			break;
		wait 1;
	}

	testclients = cvardef( "mc2_testclients", 0, 0, 64, "int" );
	for(i = 0; i < testclients; i++)
	{
		ent[i] = addtestclient();

		if(i & 1)
			team = "axis";
		else
			team = "allies";
		
		ent[i] thread TestClient(team);
	}
}

TestClient(team)
{
	while(!isdefined(self.pers["team"]))
		wait .05;

	self notify("menuresponse", game["menu_team"], team);
	wait 0.5;

	if(team == "allies")
	{
		self notify("menuresponse", game["menu_weapon_allies"], "soldier");
		self.pers["pClass"] = "soldier";
		wait 0.5;
		switch(game["allies"])
		{
		case "american":
			self notify("menuresponse", game["menu_weapon_allies_soldier"],"m1carbine_mp");
			break;

		case "british":
			self notify("menuresponse", game["menu_weapon_allies_soldier"],"enfield_mp");
			break;

		case "russian":
			self notify("menuresponse", game["menu_weapon_allies_soldier"],"mosin_nagant_mp");
			break;
		}
		
		wait 0.5;
	}
	else if(team == "axis")
	{
		self notify("menuresponse", game["menu_weapon_axis"], "soldier");
		self.pers["pClass"] = "soldier";
		wait 0.5;
		self notify("menuresponse", game["menu_weapon_axis_soldier"],"mp40_mp");
		wait 0.5;
	}
}
