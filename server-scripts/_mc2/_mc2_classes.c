/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

#include maps\mp\_utility;
init()
{
	level.classnames = [];
	level.classnames[0] = "allied_soldier";
	level.classnames[1] = "allied_medic";
	level.classnames[2] = "allied_sniper";
	level.classnames[3] = "allied_engineer";
	level.classnames[4] = "allied_support";
	level.classnames[5] = "axis_soldier";
	level.classnames[6] = "axis_medic";
	level.classnames[7] = "axis_sniper";
	level.classnames[8] = "axis_engineer";
	level.classnames[9] = "axis_support";
	
	level.classes = [];
	level.classes["allied_soldier"] = spawnstruct();
	level.classes["allied_soldier"].server_allowcvar = "scr_allow_allied_soldier";
	level.classes["allied_soldier"].client_allowcvar = "ui_allow_allied_soldier";
	level.classes["allied_soldier"].allow_default = 1;
	level.classes["allied_medic"] = spawnstruct();
	level.classes["allied_medic"].server_allowcvar = "scr_allow_allied_medic";
	level.classes["allied_medic"].client_allowcvar = "ui_allow_allied_medic";
	level.classes["allied_medic"].allow_default = 1;
	level.classes["allied_sniper"] = spawnstruct();
	level.classes["allied_sniper"].server_allowcvar = "scr_allow_allied_sniper";
	level.classes["allied_sniper"].client_allowcvar = "ui_allow_allied_sniper";
	level.classes["allied_sniper"].allow_default = 1;
	level.classes["allied_engineer"] = spawnstruct();
	level.classes["allied_engineer"].server_allowcvar = "scr_allow_allied_engineer";
	level.classes["allied_engineer"].client_allowcvar = "ui_allow_allied_engineer";
	level.classes["allied_engineer"].allow_default = 1;
	level.classes["allied_support"] = spawnstruct();
	level.classes["allied_support"].server_allowcvar = "scr_allow_allied_support";
	level.classes["allied_support"].client_allowcvar = "ui_allow_allied_support";
	level.classes["allied_support"].allow_default = 1;
	level.classes["axis_soldier"] = spawnstruct();
	level.classes["axis_soldier"].server_allowcvar = "scr_allow_axis_soldier";
	level.classes["axis_soldier"].client_allowcvar = "ui_allow_axis_soldier";
	level.classes["axis_soldier"].allow_default = 1;
	level.classes["axis_medic"] = spawnstruct();
	level.classes["axis_medic"].server_allowcvar = "scr_allow_axis_medic";
	level.classes["axis_medic"].client_allowcvar = "ui_allow_axis_medic";
	level.classes["axis_medic"].allow_default = 1;
	level.classes["axis_sniper"] = spawnstruct();
	level.classes["axis_sniper"].server_allowcvar = "scr_allow_axis_sniper";
	level.classes["axis_sniper"].client_allowcvar = "ui_allow_axis_sniper";
	level.classes["axis_sniper"].allow_default = 1;
	level.classes["axis_engineer"] = spawnstruct();
	level.classes["axis_engineer"].server_allowcvar = "scr_allow_axis_engineer";
	level.classes["axis_engineer"].client_allowcvar = "ui_allow_axis_engineer";
	level.classes["axis_engineer"].allow_default = 1;
	level.classes["axis_support"] = spawnstruct();
	level.classes["axis_support"].server_allowcvar = "scr_allow_axis_support";
	level.classes["axis_support"].client_allowcvar = "ui_allow_axis_support";
	level.classes["axis_support"].allow_default = 1;
	
	for(i = 0; i < level.classnames.size; i++)
	{
		classname = level.classnames[i];

		if(getCvar(level.classes[classname].server_allowcvar) == "")
		{
			level.classes[classname].allow = level.classes[classname].allow_default;
			setcvar(level.classes[classname].server_allowcvar, level.classes[classname].allow);
		}
		else
			level.classes[classname].allow = getCvarInt(level.classes[classname].server_allowcvar);
	}

	level thread deleteRestrictedClass();
	level thread onPlayerConnect();

	for(;;)
	{
		updateAllowed();
		wait 5;
	}
}
onPlayerConnect()
{
	for(;;)
	{
		level waittill("connecting", player);
	
		player InitializeMenu();
		player thread updateAllAllowedSingleClient();
	}
}
deleteRestrictedClass()
{
	for(i = 0; i < level.classnames.size; i++)
	{
		classname = level.classnames[i];
	}
}
updateAllowed()
{
	for(i = 0; i < level.classnames.size; i++)
	{
		classname = level.classnames[i];

		cvarvalue = getCvarInt(level.classes[classname].server_allowcvar);
		if(level.classes[classname].allow != cvarvalue)
		{
			level.classes[classname].allow = cvarvalue;

			thread updateAllowedAllClients(classname);
		}
	}
}
updateAllowedAllClients(classname)
{
	players = getentarray("player", "classname");
	for(i = 0; i < players.size; i++)
		players[i] updateAllowedSingleClient(classname);
}
updateAllAllowedSingleClient()
{
	for(i = 0; i < level.classnames.size; i++)
	{
		classname = level.classnames[i];
		self updateAllowedSingleClient(classname);
	}
}
updateAllowedSingleClient(classname)
{
	self setclientcvar(level.classes[classname].client_allowcvar, level.classes[classname].allow);
}
/*-------------------------------------------
INITIALIZE PLAYER CLASS RATIOS

-this needs to be called when the gametype script
 starts
 -------------------------------------------*/
InitializeClasses()
{	
		// SOLDIERS
		if (getcvar("scr_soldier_ratio") == "" )
			setcvar ("scr_soldier_ratio","100");
		// MEDIC
		if (getcvar("scr_medic_ratio") == "" )
			setcvar ("scr_medic_ratio","20");
		// SNIPERS
		if (getcvar("scr_sniper_ratio") == "" )
			setcvar ("scr_sniper_ratio","20");
		// ENINEER
		if (getcvar("scr_engineer_ratio") == "" )
			setcvar ("scr_engineer_ratio","20");
		// SUPPORT
		if (getcvar("scr_support_ratio") == "" )
			setcvar ("scr_support_ratio","20");
	
		// RATIOS/LIMITS
		level.soldier_ratio = getcvarint("scr_soldier_ratio");
		level.medic_ratio = getcvarint("scr_medic_ratio");
		level.sniper_ratio = getcvarint("scr_sniper_ratio");
		level.engineer_ratio = getcvarint("scr_engineer_ratio");
		level.support_ratio = getcvarint("scr_support_ratio");
		Update_Classes();

}
/*-------------------------------------------
INITIALIZE THE PLAYERS MENU WHEN THEY CONNECT
-------------------------------------------*/
InitializeMenu()
{
	/*-----------------
	AXIS
	------------------*/
	self setclientcvar("ui_axis_soldier",  level.axis_soldier_count + " of " + level.axis_soldier_limit);
	if(level.axis_soldier_count >= level.axis_soldier_limit )
		self setclientcvar("ui_allow_axis_soldier","0");
	else
		self setclientcvar("ui_allow_axis_soldier","1");

	self setclientcvar("ui_axis_sniper", level.axis_sniper_count + " of " + level.axis_sniper_limit);
	if(level.axis_sniper_count >= level.axis_sniper_limit )
		self setclientcvar("ui_allow_axis_sniper","0");
	else
		self setclientcvar("ui_allow_axis_sniper","1");


	self setclientcvar("ui_axis_medic",  level.axis_medic_count + " of " + level.axis_medic_limit);
	if(level.axis_medic_count >= level.axis_medic_limit )
		self setclientcvar("ui_allow_axis_medic","0");
	else
		self setclientcvar("ui_allow_axis_medic","1");


	self setclientcvar("ui_axis_engineer",  level.axis_engineer_count + " of " + level.axis_engineer_limit);
	if(level.axis_engineer_count >= level.axis_engineer_limit )
		self setclientcvar("ui_allow_axis_engineer","0");
	else
		self setclientcvar("ui_allow_axis_engineer","1");

	self setclientcvar("ui_axis_support", level.axis_support_count + " of " + level.axis_support_limit);
	if(level.axis_support_count >= level.axis_support_limit)
		self setclientcvar("ui_allow_axis_support","0");
	else
		self setclientcvar("ui_allow_axis_support","1");

	/*-----------------
	 ALLIED
	------------------*/
	self setclientcvar("ui_allied_soldier", "^3" + level.allied_soldier_count + " of " + level.allied_soldier_limit);
	if(level.allied_soldier_count >= level.allied_soldier_limit)
		self setclientcvar("ui_allow_allied_soldier","0");
	else
		self setclientcvar("ui_allow_allied_soldier","1");

	self setclientcvar("ui_allied_medic",  level.allied_medic_count + " of " + level.allied_medic_limit);
	if(level.allied_medic_count >= level.allied_medic_limit)
		self setclientcvar("ui_allow_allied_medic","0");
	else
		self setclientcvar("ui_allow_allied_medic","1");

	self setclientcvar("ui_allied_sniper",  level.allied_sniper_count + " of " + level.allied_sniper_limit);
	if(level.allied_sniper_count >= level.allied_sniper_limit )
		self setclientcvar("ui_allow_allied_sniper","0");
	else
		self setclientcvar("ui_allow_allied_sniper","1");

	self setclientcvar("ui_allied_engineer",  level.allied_engineer_count + " of " + level.allied_engineer_limit);
	if(level.allied_engineer_count >= level.allied_engineer_limit)
		self setclientcvar("ui_allow_allied_engineer","0");
	else
		self setclientcvar("ui_allow_allied_engineer","1");

	self setclientcvar("ui_allied_support",  level.allied_support_count + " of " + level.allied_support_limit);
	if(level.allied_support_count >= level.allied_support_limit)
		self setclientcvar("ui_allow_allied_support","0");
	else
		self setclientcvar("ui_allow_allied_support","1");
}

MonitorClasses()
{
	for(;;)
	{		
		Update_Classes();
		wait .05;
	}
}

/*-------------------------------------------
UPDATE THE PLAYER CLASS LIMITS AND COUNTS
-------------------------------------------*/
Update_Classes()
{	
	// RESET COUNTERS
	al_sniper = 0;
	al_support = 0;
	al_medic = 0;
	al_soldier = 0;
	al_engineer = 0;
	ax_sniper = 0;
	ax_support = 0;
	ax_medic = 0;
	ax_soldier = 0;
	ax_engineer = 0;
	al_players = 0;
	ax_players =0;

	//LOOP THROUGH AND GET PLAYER COUNT AND CLASS 	
	players = getentarray("player", "classname");
	
	if(players.size)
	{
		for(i = 0; i < players.size; i++)
		{
			if(!isDefined(players[i].pers["pClass"]))
				players[i].pers["pClass"] = "none";

			if( isdefined(players[i].pers["team"]))
			{
				switch(players[i].pers["team"])
				{
				case "allies":
					al_players++;
					switch(players[i].pers["pClass"])
					{
						case "soldier": al_soldier++;break;
						case "medic": al_medic++;break;
						case "sniper": al_sniper++;break;
						case "engineer": al_engineer++;break;
						case "support": al_support++;break;
					}
					break;
				case "axis":
					ax_players++;
					switch(players[i].pers["pClass"])
					{
						case "soldier": ax_soldier++;break;
						case "medic": ax_medic++;break;
						case "sniper": ax_sniper++;break;
						case "engineer": ax_engineer++;break;
						case "support": ax_support++;break;
					}
					break;
				}
			}		
		}
	}
	
	//SET LEVEL VARIABLES
	/*-----------------
	 AXIS
	------------------*/

	//SOLDIER
	a = ax_players * (level.soldier_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	if(!isDefined(level.axis_soldier_limit))
	{
		level.axis_soldier_limit = int(a);
		level.axis_soldier_count = ax_soldier;
		UpdateMenu("axis_soldier");
	}
	else if(level.axis_soldier_limit != int(a) || level.axis_soldier_count != ax_soldier)
	{
		level.axis_soldier_limit = int(a);
		level.axis_soldier_count = ax_soldier;
		UpdateMenu("axis_soldier");
	}


	//MEDIC
	a = ax_players * (level.medic_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;

	if(!isDefined(level.axis_medic_limit))
	{
		level.axis_medic_limit = int(a);
		level.axis_medic_count = ax_medic;
		UpdateMenu("axis_medic");
	}

	else if(level.axis_medic_limit != int(a) || level.axis_medic_count != ax_medic)
	{
		level.axis_medic_limit = int(a);
		level.axis_medic_count = ax_medic;
		UpdateMenu("axis_medic");
	}

	//SNIPER
	a = ax_players * (level.sniper_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	
	if(!isDefined(level.axis_sniper_limit))
	{
		level.axis_sniper_limit = int(a);
		level.axis_sniper_count = ax_sniper;
		UpdateMenu("axis_sniper");
	}
	else if(level.axis_sniper_limit != int(a) || level.axis_sniper_count != ax_sniper)
	{
		level.axis_sniper_limit = int(a);
		level.axis_sniper_count = ax_sniper;
		UpdateMenu("axis_sniper");				
	}

	//ENGINEER
	a = ax_players * (level.engineer_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;

	if(!isDefined(level.axis_engineer_limit))
	{
		level.axis_engineer_limit = int(a);
		level.axis_engineer_count = ax_engineer;
		UpdateMenu("axis_engineer");
	}
	else if(level.axis_engineer_limit != int(a) || level.axis_engineer_count != ax_engineer)
	{
		level.axis_engineer_limit = int(a);
		level.axis_engineer_count = ax_engineer;
		UpdateMenu("axis_engineer");
	}
	
	//SUPPORT 
	a = ax_players * (level.support_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;

	if(!isDefined(level.axis_support_limit))
	{
		level.axis_support_limit = int(a);
		level.axis_support_count = ax_support;
		UpdateMenu("axis_support");
	}
	else if(level.axis_support_limit != int(a) || level.axis_support_count != ax_support )
	{
		level.axis_support_limit = int(a);
		level.axis_support_count = ax_support;
		UpdateMenu("axis_support");
	}

	/*-----------------
	 ALLIED
	------------------*/
				
	//SOLDIER
	a = al_players * (level.soldier_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	if(!isDefined(level.allied_soldier_limit))
	{
		level.allied_soldier_limit = int(a);
		level.allied_soldier_count = al_soldier;
		UpdateMenu("allied_soldier");
	
	}
	else if(level.allied_soldier_limit != int(a) || level.allied_soldier_count != al_soldier)
	{
		level.allied_soldier_limit = int(a);
		level.allied_soldier_count = al_soldier;
		UpdateMenu("allied_soldier");
	}
	//MEDIC
	a = al_players * (level.medic_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	if(!isDefined(level.allied_medic_limit))
	{
		level.allied_medic_limit = int(a);
		level.allied_medic_count = al_medic;
		UpdateMenu("allied_medic");
	}
	else if(level.allied_medic_limit != int(a) || level.allied_medic_count != al_medic)
	{
		level.allied_medic_limit = int(a);
		level.allied_medic_count = al_medic;
		UpdateMenu("allied_medic");
	}
	//SNIPER
	a = al_players * (level.sniper_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	if(!isDefined(level.allied_sniper_limit))
	{
		level.allied_sniper_limit = int(a);
		level.allied_sniper_count = al_sniper;
		UpdateMenu("allied_sniper");
	}
	else if(level.allied_sniper_limit != int(a) || level.allied_sniper_count != al_sniper)
	{
		level.allied_sniper_limit = int(a);
		level.allied_sniper_count = al_sniper;
		UpdateMenu("allied_sniper");
	}
	//ENGINEER
	a = al_players * (level.engineer_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	if(!isDefined(level.allied_engineer_limit))
	{
		level.allied_engineer_limit = int(a);
		level.allied_engineer_count = al_engineer;
		UpdateMenu("allied_engineer");
	}
	else if(level.allied_engineer_limit != int(a) || level.allied_engineer_count != al_engineer)
	{
		level.allied_engineer_limit = int(a);
		level.allied_engineer_count = al_engineer;
		UpdateMenu("allied_engineer");
	}

	//SUPPORT 
	a = al_players * (level.support_ratio * .1) * .1;
	if(a < 1 && a > 0) a = 1;
	if(!isDefined(level.allied_support_limit))
	{
		level.allied_support_limit = int(a);
		level.allied_support_count = al_support;
		UpdateMenu("allied_support");
	}
	else if(level.allied_support_limit != int(a) || level.allied_support_count != al_support)
	{
		level.allied_support_limit = int(a);
		level.allied_support_count = al_support;
		UpdateMenu("allied_support");
	}
	
}

/*-------------------------------------------
UPDATE THE PLAYER CLASS LIMITS

called from UpdateClasses()
-------------------------------------------*/
UpdateMenu(classtype)
{
	players = getentarray("player", "classname");
	for(i = 0; i < players.size; i++)
	{
		if(!isDefined(players[i].pers["pClass"]))
			players[i].pers["pClass"] = "none";
		
		switch(classtype)
		{
		/*-----------------
		 AXIS
		------------------*/
		case "axis_soldier":
			players[i] setclientcvar("ui_axis_soldier",  level.axis_soldier_count + " of " + level.axis_soldier_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "soldier")
				players[i] setclientcvar("ui_allow_axis_soldier","1");
			else
			{
				if(level.axis_soldier_count >= level.axis_soldier_limit )
					players[i] setclientcvar("ui_allow_axis_soldier","0");
				else
					players[i] setclientcvar("ui_allow_axis_soldier","1");
			}
			break;
		case "axis_medic":
			players[i] setclientcvar("ui_axis_medic",  level.axis_medic_count + " of " + level.axis_medic_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "medic")
				players[i] setclientcvar("ui_allow_axis_medic","1");
			else
			{
				if(level.axis_medic_count >= level.axis_medic_limit )
					players[i] setclientcvar("ui_allow_axis_medic","0");
				else
					players[i] setclientcvar("ui_allow_axis_medic","1");
			}
			break;
		case "axis_sniper":
			players[i] setclientcvar("ui_axis_sniper",  level.axis_sniper_count + " of " + level.axis_sniper_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "sniper")
				players[i] setclientcvar("ui_allow_axis_sniper","1");
			else
			{
				if(level.axis_sniper_count >= level.axis_sniper_limit )
					players[i] setclientcvar("ui_allow_axis_sniper","0");
				else
					players[i] setclientcvar("ui_allow_axis_sniper","1");
			}
			break;
		case "axis_engineer":
			players[i] setclientcvar("ui_axis_engineer",  level.axis_engineer_count + " of " + level.axis_engineer_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "engineer")
				players[i] setclientcvar("ui_allow_axis_engineer","1");
			else
			{
				if(level.axis_engineer_count >= level.axis_engineer_limit )
					players[i] setclientcvar("ui_allow_axis_engineer","0");
				else
					players[i] setclientcvar("ui_allow_axis_engineer","1");
			}
			break;
		case "axis_support":
			players[i] setclientcvar("ui_axis_support",  level.axis_support_count + " of " + level.axis_support_limit);
			
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "support")
				players[i] setclientcvar("ui_allow_axis_support","1");
			else
			{
				if(level.axis_support_count >= level.axis_support_limit)
					players[i] setclientcvar("ui_allow_axis_support","0");
				else
					players[i] setclientcvar("ui_allow_axis_support","1");
			}
			break;
		/*-----------------
		 ALLIED
		------------------*/
		case "allied_soldier":
			players[i] setclientcvar("ui_allied_soldier",  level.allied_soldier_count + " of " + level.allied_soldier_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "soldier")
				players[i] setclientcvar("ui_allow_allied_soldier","1");
			else
			{
				if(level.allied_soldier_count >= level.allied_soldier_limit)
					players[i] setclientcvar("ui_allow_allied_soldier","0");
				else
					players[i] setclientcvar("ui_allow_allied_soldier","1");
			}
			break;
		case "allied_medic":
			players[i] setclientcvar("ui_allied_medic",  level.allied_medic_count + " of " + level.allied_medic_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "medic")
				players[i] setclientcvar("ui_allow_allied_medic","1");
			else
			{
				if(level.allied_medic_count >= level.allied_medic_limit)
					players[i] setclientcvar("ui_allow_allied_medic","0");
				else
					players[i] setclientcvar("ui_allow_allied_medic","1");
			}
			break;
		case "allied_sniper":
			players[i] setclientcvar("ui_allied_sniper",  level.allied_sniper_count + " of " + level.allied_sniper_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "sniper")
				players[i] setclientcvar("ui_allow_allied_sniper","1");
			else
			{
				if(level.allied_sniper_count >= level.allied_sniper_limit )
					players[i] setclientcvar("ui_allow_allied_sniper","0");
				else
					players[i] setclientcvar("ui_allow_allied_sniper","1");
			}
			break;
		case "allied_engineer":
			players[i] setclientcvar("ui_allied_engineer",  level.allied_engineer_count + " of " + level.allied_engineer_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "engineer")
				players[i] setclientcvar("ui_allow_allied_engineer","1");
			else
			{
				if(level.allied_engineer_count >= level.allied_engineer_limit)
					players[i] setclientcvar("ui_allow_allied_engineer","0");
				else
					players[i] setclientcvar("ui_allow_allied_engineer","1");
			}
			break;
		case "allied_support":
			players[i] setclientcvar("ui_allied_support",  level.allied_support_count + " of " + level.allied_support_limit);
			if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "support")
				players[i] setclientcvar("ui_allow_allied_support","1");
			else
			{
				if(level.allied_support_count >= level.allied_support_limit)
					players[i] setclientcvar("ui_allow_allied_support","0");
				else
					players[i] setclientcvar("ui_allow_allied_support","1");
			}
			break;
		}
	}
}

CheckClassAvailablility(response)
{
	switch(self.pers["team"])
	{
	case "allies":		
		if(isDefined(self.pers["pClass"]) && self.pers["pClass"] == response)
			return response;

		switch(response)
		{
		case "soldier":
			if(level.allied_soldier_count >= level.allied_soldier_limit)
				return "unavailable";
			else
				return response;
			break;
		case "medic":
			if(level.allied_medic_count >= level.allied_medic_limit)
				return "unavailable";
			else
				return response;
			break;
		case "sniper":
			if(level.allied_sniper_count >= level.allied_sniper_limit) 
				return "unavailable";
			else
				return response;
			break;
		case "engineer":
			if(level.allied_engineer_count >= level.allied_engineer_limit) 
				return "unavailable";
			else
				return response;
			break;
		case "support":
			
			if(level.allied_support_count >= level.allied_support_limit) 
				return "unavailable";
			else
				return response;
			break;
		}		
		break;

	case "axis":
		if(isDefined(self.pers["pClass"]) && self.pers["pClass"] == response)
			return response;
		switch(response)
		{
		case "soldier":
			if(level.axis_soldier_count >= level.axis_soldier_limit)
				return "unavailable";
			else
				return response;
			break;
		case "medic":
			if(level.axis_medic_count >= level.axis_medic_limit)
				return "unavailable";
			else
				return response;
			break;
		case "sniper":
			if(level.axis_sniper_count >= level.axis_sniper_limit)
				return "unavailable";
			else
				return response;
			break;
		case "engineer":
			if(level.axis_engineer_count >= level.axis_engineer_limit)
				return "unavailable";
			else
				return response;
			break;
		case "support":
			if(level.axis_support_count >= level.axis_support_limit)
				return "unavailable";
			else
				return response;
			break;
		}		
		break;	
	}
}