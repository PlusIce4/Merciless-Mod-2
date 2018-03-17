/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
//keep cvardef OFF so bots work in listen mode

init()
{

	if(getcvar("scr_testclients") == "")
		setcvar("scr_testclients","0");
		

	level.scr_testclients = getcvarint ("scr_testclients");

}
addTestClients()
{
	wait 5;

	for(;;)
	{
		if(getCvarInt("scr_testclients") > 0)
			break;
		wait 1;
	}

	testclients = getCvarInt("scr_testclients");
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
removeTestClients() //check to see if this works
{
	wait 5;

	for(;;)
	{
		if(getCvarInt("scr_testclients") > 0)
			break;
		wait 1;
	}

	testclients = getCvarInt("scr_testclients");
	for(i = 0; i < testclients; i--)
	{
		ent[i] = addtestclient();

		if(i & 1)
			team = "axis";
		else
			team = "allies";
		
		ent[i] delete();
	}
}