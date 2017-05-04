/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Menus */

/* Note: Removed Quick Specials due to Script Runtime Errors */
/* Note: Check to see if player dies on class switch */

init()
{
	if(getcvar("scr_autospeconly") == "")
		setcvar("scr_autospeconly", "0");
	level.scr_autospeconly = getcvarint("scr_autospeconly");
	
	game["menu_ingame"] = "ingame";
	if(level.scr_autospeconly==0)
		game["menu_team"] = "team_" + game["allies"] + game["axis"];
	else
		game["menu_team"] = "team_" + game["allies"] + game["axis"]+"2";
	game["menu_weapon_allies"] = "weapon_" + game["allies"];
	game["menu_weapon_axis"] = "weapon_" + game["axis"];

	//[Merciless2]///////////////////////////////
	// define
	game["menu_weapon_allies_soldier"] = "weapon_" + game["allies"]+ "_soldier";
	game["menu_weapon_allies_sniper"] = "weapon_" + game["allies"]+ "_sniper";
	game["menu_weapon_allies_medic"] = "weapon_" + game["allies"]+ "_medic";
	game["menu_weapon_allies_engineer"] = "weapon_" + game["allies"]+ "_engineer";
	game["menu_weapon_allies_support"] = "weapon_" + game["allies"]+ "_support";
	game["menu_weapon_axis_soldier"] = "weapon_" + game["axis"]+ "_soldier";
	game["menu_weapon_axis_sniper"] = "weapon_" + game["axis"]+ "_sniper";
	game["menu_weapon_axis_medic"] = "weapon_" + game["axis"]+ "_medic";
	game["menu_weapon_axis_engineer"] = "weapon_" + game["axis"]+ "_engineer";
	game["menu_weapon_axis_support"] = "weapon_" + game["axis"]+ "_support";

	// precache
	precacheMenu(game["menu_weapon_allies_soldier"]);
	precacheMenu(game["menu_weapon_allies_sniper"]);
	precacheMenu(game["menu_weapon_allies_medic"]);
	precacheMenu(game["menu_weapon_allies_engineer"]);
	precacheMenu(game["menu_weapon_allies_support"]);
	precacheMenu(game["menu_weapon_axis_soldier"]);
	precacheMenu(game["menu_weapon_axis_sniper"]);
	precacheMenu(game["menu_weapon_axis_medic"]);
	precacheMenu(game["menu_weapon_axis_engineer"]);
	precacheMenu(game["menu_weapon_axis_support"]);
	/////////////////////////////////////////////
	precacheMenu(game["menu_ingame"]);
	precacheMenu(game["menu_team"]);
	precacheMenu(game["menu_weapon_allies"]);
	precacheMenu(game["menu_weapon_axis"]);

	if(!level.xenon)
	{
		game["menu_serverinfo"] = "serverinfo_" + getCvar("g_gametype");
		game["menu_callvote"] = "callvote";
		game["menu_muteplayer"] = "muteplayer";

		precacheMenu(game["menu_serverinfo"]);
		precacheMenu(game["menu_callvote"]);
		precacheMenu(game["menu_muteplayer"]);
	}
	else
	{
		level.splitscreen = isSplitScreen();
		if(level.splitscreen)
		{
			game["menu_team"] += "_splitscreen";
			game["menu_weapon_allies"] += "_splitscreen";
			game["menu_weapon_axis"] += "_splitscreen";
			game["menu_ingame_onteam"] = "ingame_onteam_splitscreen";
			game["menu_ingame_spectator"] = "ingame_spectator_splitscreen";

			precacheMenu(game["menu_team"]);
			precacheMenu(game["menu_weapon_allies"]);
			precacheMenu(game["menu_weapon_axis"]);
			precacheMenu(game["menu_ingame_onteam"]);
			precacheMenu(game["menu_ingame_spectator"]);
		}
	}



	level thread onPlayerConnect();
}

onPlayerConnect()
{
	for(;;)
	{
		level waittill("connecting", player);
		player thread onMenuResponse();
	}
}

onMenuResponse()
{
	//while(isDefined(self))
	for(;;)
	{
		self waittill("menuresponse", menu, response);
		//iprintln("^6", response);

		if(response == "back")
		{
			self closeMenu();
			self closeInGameMenu();

			if(menu == game["menu_team"])
			{
				if(level.splitscreen)
				{
					if(self.pers["team"] == "spectator")
						self openMenu(game["menu_ingame_spectator"]);
					else
						self openMenu(game["menu_ingame_onteam"]);
				}
				else
					self openMenu(game["menu_ingame"]);
			}
			else if(menu == game["menu_weapon_allies"] || menu == game["menu_weapon_axis"])
				self openMenu(game["menu_team"]);
			else if(menu == game["menu_weapon_allies_soldier"]
				||menu == game["menu_weapon_allies_sniper"]
				||menu == game["menu_weapon_allies_medic"]
				||menu == game["menu_weapon_allies_engineer"]
				||menu == game["menu_weapon_allies_support"]
				||menu == game["menu_weapon_axis_soldier"]
				||menu == game["menu_weapon_axis_sniper"]
				||menu == game["menu_weapon_axis_medic"]
				||menu == game["menu_weapon_axis_engineer"]
				||menu == game["menu_weapon_axis_support"])
			{
				self openMenu(game["menu_team"]);
			}
			continue;
		}
		if(response == "back2")
		{
			self closeMenu();
			self closeInGameMenu();

			if(menu == game["menu_weapon_allies_soldier"]
				||menu == game["menu_weapon_allies_sniper"]
				||menu == game["menu_weapon_allies_medic"]
				||menu == game["menu_weapon_allies_engineer"]
				||menu == game["menu_weapon_allies_support"])
			{
				self openMenu(game["menu_weapon_allies"]);
			}
			else if(menu == game["menu_weapon_axis_soldier"]
				||menu == game["menu_weapon_axis_sniper"]
				||menu == game["menu_weapon_axis_medic"]
				||menu == game["menu_weapon_axis_engineer"]
				||menu == game["menu_weapon_axis_support"])
			{
				self openMenu(game["menu_weapon_axis"]);
			}
			continue;
		}

		if(response == "endgame")
		{
			if(level.splitscreen)
			{
				level thread [[level.endgameconfirmed]]();
			}
			else if (level.xenon)
			{
				endparty();
				level thread [[level.endgameconfirmed]]();
			}
				
			continue;
		}

		if(response == "endround")
		{
			level thread [[level.endgameconfirmed]]();
			continue;
		}


		if(menu == game["menu_ingame"] || (level.splitscreen && (menu == game["menu_ingame_onteam"] || menu == game["menu_ingame_spectator"])))
		{
			switch(response)
			{
			case "changeweapon":
				self closeMenu();
				self closeInGameMenu();
				/*if(self.pers["team"] == "allies")
					self openMenu(game["menu_weapon_allies"]);
				else if(self.pers["team"] == "axis")
					self openMenu(game["menu_weapon_axis"]);
				*/
				if(self.pers["team"] == "allies" || self.pers["team"] == "axis")
				{
					if(!isdefined(self.pers["pClass"]))continue;
					switch(self.pers["pClass"])
					{
						case "soldier":self openMenu(game["menu_weapon_" + self.pers["team"] + "_soldier"]);break;
						case "sniper":self openMenu(game["menu_weapon_" + self.pers["team"] + "_sniper"]);break;
						case "medic":self openMenu(game["menu_weapon_" + self.pers["team"] + "_medic"]);break;
						case "engineer":self openMenu(game["menu_weapon_" + self.pers["team"] + "_engineer"]);break;
						case "support":self openMenu(game["menu_weapon_" + self.pers["team"] + "_support"]);break;
					}
				}
				break;
				
			case "changeclass":
				self closeMenu();
				self closeInGameMenu();
				if(self.pers["team"] == "allies")

					self openMenu(game["menu_weapon_allies"]);
				else if(self.pers["team"] == "axis")
					self openMenu(game["menu_weapon_axis"]);
				break;

			case "changeteam":
				self closeMenu();
				self closeInGameMenu();
				self openMenu(game["menu_team"]);
				break;

			case "muteplayer":
				if(!level.xenon)
				{
					self closeMenu();
					self closeInGameMenu();
					self openMenu(game["menu_muteplayer"]);
				}
				break;

			case "callvote":
				if(!level.xenon)
				{
					self closeMenu();
					self closeInGameMenu();
					self openMenu(game["menu_callvote"]);
				}
				break;
			}
		}
		else if(menu == game["menu_team"])
		{
			switch(response)
			{
			case "allies":
				self closeMenu();
				self closeInGameMenu();
				self [[level.allies]]();
				break;

			case "axis":
				self closeMenu();
				self closeInGameMenu();
				self [[level.axis]]();
				break;

			case "autoassign":
				self closeMenu();
				self closeInGameMenu();
				self [[level.autoassign]]();
				break;

			case "spectator":
				self closeMenu();
				self closeInGameMenu();
				self [[level.spectator]]();
				break;
			}
		}
		else if(menu == game["menu_weapon_allies"] || menu == game["menu_weapon_axis"])
		{
			self closeMenu();
			self closeInGameMenu();
			if(mc2\_class_classes::CheckClassAvailablility(response) == "unavailable")
			{
			//	self iprintlnbold("The Class You Selected Is Unavailable");
				wait(1);
				self openmenu(menu);				
				continue;
			}
			if( (isDefined(self.pers["pClass"])) && (self.pers["pClass"] != "none") && (response != self.pers["pClass"]) )
			{
				self suicide();
				self.pers["weapon"] = undefined;
				self.pers["savedmodel"] = undefined;
				self notify("end_respawn");
			}
			/*if(response==self.pers["pClass"])
				continue;
			if(isalive(self))
			{
				self.switching_teams = undefined;
				self suicide();
			}	
			self.pers["weapon"] = undefined;
			self.pers["savedmodel"] = undefined;*/
			self.pers["pClass"] = response;	
			
			if(self.pers["team"] == "allies" || self.pers["team"] == "axis")
			{
				
				switch(response)
				{
					case "soldier":self openMenu(game["menu_weapon_" + self.pers["team"] + "_soldier"]);break;
					case "sniper":self openMenu(game["menu_weapon_" + self.pers["team"] + "_sniper"]);break;
					case "medic":self openMenu(game["menu_weapon_" + self.pers["team"] + "_medic"]);break;
					case "engineer":self openMenu(game["menu_weapon_" + self.pers["team"] + "_engineer"]);break;
					case "support":self openMenu(game["menu_weapon_" + self.pers["team"] + "_support"]);break;
				}
			}
		}
		else if(menu == game["menu_weapon_allies_soldier"]
			|| menu == game["menu_weapon_allies_sniper"]
			||menu == game["menu_weapon_allies_medic"]
			|| menu == game["menu_weapon_allies_engineer"]
			||menu == game["menu_weapon_allies_support"]
			||menu == game["menu_weapon_axis_soldier"]
			|| menu == game["menu_weapon_axis_sniper"]
			||menu == game["menu_weapon_axis_medic"]
			|| menu == game["menu_weapon_axis_engineer"]
			||menu == game["menu_weapon_axis_support"])

		{
			self closeMenu();
			self closeInGameMenu();
			self [[level.weapon]](response);
		}
		else if(!level.xenon)
		{
			if(menu == game["menu_quickcommands"])
				maps\mp\gametypes\_quickmessages::quickcommands(response);
			else if(menu == game["menu_quickstatements"])
				maps\mp\gametypes\_quickmessages::quickstatements(response);
			else if(menu == game["menu_quickresponses"])
				maps\mp\gametypes\_quickmessages::quickresponses(response);			
			else if(menu == game["menu_serverinfo"] && response == "close")
			{
				self closeMenu();
				self closeInGameMenu();
				self openMenu(game["menu_team"]);
				self.pers["skipserverinfo"] = true;
			}
		}
	}
}