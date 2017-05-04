/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
class system specials
-------------------------------------------*/
init()
{	
	precacheShader("gfx/custom/hud@explosivepack.tga");
	precacheShader("inventory_tnt_small");
	precacheShader("gfx/custom/hud@lg_health.tga");
	precacheShader("gfx/custom/hud@mediccharge.tga");
	precacheShader("gfx/custom/hud@mine_warning.tga");
	precacheShader("gfx/custom/hud@landmine.tga");
	precacheShader("gfx/custom/hud@tellermine.tga");
	precacheShader("gfx/custom/hud@tellermine_diffuse.tga");
	precacheShader("gfx/custom/hud@landmine_diffuse.tga");
	precacheShader("gfx/custom/icon_ammo.tga");
	
	game["status_soldier_axis"]="gfx/custom/icon_ammo.tga";
	game["status_medic_axis"]="gfx/custom/hud@mediccharge.tga";
	game["status_sniper_axis"]="gfx/icons/hud@artillery.tga";
	game["status_engineer_axis"]="gfx/custom/hud@explosivepack.tga";
	game["status_support_axis"]="gfx/custom/hud@tellermine.tga";

	game["status_soldier_allies"]=game["status_soldier_axis"];
	game["status_medic_allies"]=game["status_medic_axis"];
	game["status_sniper_allies"]=game["status_sniper_axis"];
	game["status_engineer_allies"]="inventory_tnt_small";
	game["status_support_allies"]="gfx/custom/hud@landmine.tga";

///	precacheStatusIcon(game["status_soldier_axis"]);
///	precacheStatusIcon(game["status_medic_axis"]);
///	precacheStatusIcon(game["status_sniper_axis"]);
///	precacheStatusIcon(game["status_engineer_axis"]);
///	precacheStatusIcon(game["status_support_axis"]);
///	precacheStatusIcon(game["status_engineer_allies"]);
///	precacheStatusIcon(game["status_support_allies"]);

	precacheItem("axis_mine_mp");
	precacheItem("allies_mine_mp");
	precacheItem("item_health_large");
//	precacheItem("ammocrate");
//	precacheItem("medcrate");

	precacheModel("xmodel/landmine");
	precacheModel("xmodel/tellermine");
	precacheModel("xmodel/ammobox1");
	precacheModel("xmodel/axis_ammobox1");
	precacheModel("xmodel/allied_medkit1");
	precacheModel("xmodel/axis_medkit1");
	
	//functions
//	game["medcrate"] = ::medic_dropMedcrate;
//	game["AMMOCRATE"] = ::DropAmmocrate;


	//MedCrate
	level.objectQ["medkit"] = [];
	level.objectQcurrent["medkit"] = 0;
	level.objectQsize["medkit"] = 16;
	precacheItem("medkit");
	
	//AmmoCrate
	level.objectQ["ammocrate"] = [];
	level.objectQcurrent["ammocrate"] = 0;
	level.objectQsize["ammocrate"] = 16;

//	precacheString(&"medcrate");
	precacheString(&"MC2_MINE_PLACED");
	precacheString(&"MC2_MINE_DIFFUSED");
	precacheString(&"MC2_NO_AMMO_NEEDED"); 
	precacheString(&"MC2_SCORE_HEAL");
	precacheString(&"MC2_SCORE_SUPPLY");
	precacheString(&"MC2_SCORE_MINE_DIFFUSED");

	level.medic_healthpack = [];
	level.medic_healthpack_count = 0;
	
	level.medkit = [];
	level.medkit_count = 0;
	

	level.objused["medic"] = [];
	level.objused["engineer"] = [];
	for (i=0;i<16;i++)
	{
		level.objused["medic"][i] = false;
		level.objused["engineer"][i] = false;
	}
	
	level thread _mc2_connectPlayer();
}
_mc2_connectPlayer()
{
	for(;;)
	{
		level waittill("connecting", player);
		player thread _mc2_spawnPlayer();
		player thread _mc2_PlayerKilled();
		player thread _mc2_spawnSpectator();
		player thread _mc2_disconnect();

	}
}

_mc2_spawnPlayer()
{
	self endon("disconnect");
	
	for(;;)
	{
		self waittill("spawned_player");
		self.pers["wpn"]=self.pers["weapon"];
		self.calledM=undefined;
		self.calledE=undefined;
		self options();
		class();
	}
}
_mc2_PlayerKilled()
{
	self endon("disconnect");
	
	for(;;)
	{
		self waittill("killed_player");
		self notify("end_special");
		self mine_delete();
		self check_delete_objective();
		if (isDefined(self.hlthpackicon))
			self.hlthpackicon destroy();
		if (isDefined(self.hlthpackammo))
			self.hlthpackammo destroy();
		if (isDefined(self.medkitcounticon))
			self.medkitcounticon destroy();
		if (isDefined(self.medkitcountammo))
			self.medkitcountammo destroy();
		if (isDefined(self.mineicon))
			self.mineicon destroy();
		if (isDefined(self.mineammo))
			self.mineammo destroy();
		if(isDefined(self.minewarning))
			self.minewarning destroy();
		if(isDefined(self.minedisarm))
			self.minedisarm destroy();
		if(isDefined(self.diffuse))
			self.diffuse destroy();
		if(isDefined(self.diffuse_back))
			self.diffuse_back destroy();
	}
}
_mc2_spawnSpectator()
{
	self endon("disconnect");
	
	for(;;)
	{
		self waittill("joined_spectators");
		self notify("end_special");
		self check_delete_objective();
		if (isDefined(self.hlthpackicon))
			self.hlthpackicon destroy();
		if (isDefined(self.hlthpackammo))
			self.hlthpackammo destroy();
		if (isDefined(self.medkitcounticon))
			self.medkitcounticon destroy();
		if (isDefined(self.medkitcountammo))
			self.medkitcountammo destroy();
			self.tnt_icon destroy();
		if (isDefined(self.mineicon))
			self.mineicon destroy();
		if (isDefined(self.mineammo))
			self.mineammo destroy();
		if(isDefined(self.minewarning))
			self.minewarning destroy();
		if(isDefined(self.minedisarm))
			self.minedisarm destroy();
		if(isDefined(self.diffuse))
			self.diffuse destroy();
		if(isDefined(self.diffuse_back))
			self.diffuse_back destroy();
		if (isDefined(self.chargeicon))
			self.chargeicon destroy();
	}
}
_mc2_disconnect()
{
	self waittill("disconnect");
	self notify("end_special");
	self mine_delete();
	self check_delete_objective();
}
class()
{
	if(isdefined(self.pers["pClass"]))
	{
		switch(self.pers["pClass"])
		{
			case "medic":
			    self.isHoldingMedkit=undefined;	
				self.medkitcount=1;
				self.ishealing=undefined;
				self.mediccharge=2000;
				self.hashlthpacks=3;
				self.healpoints = 0;
				self.mine_planted=undefined;
				self.diffusepoints=5;
				self.hasmine=1;
//				self.medcrate=1; //xmodel/axis_medkit1
				self.packmine="xmodel/tellermine";
				icon="gfx/custom/hud@tellermine.tga";
				icon_x=32;
				icon_y=32;
				x=605+5;
				self thread medic_recharge();

				if (!isdefined(self.hlthpackicon))
				{
					self.hlthpackicon = newClientHudElem(self);	
					self.hlthpackicon.alignX = "left";
					self.hlthpackicon.alignY = "top";
					self.hlthpackicon.x = 590-25;
					self.hlthpackicon.y = 414;
				//	self.hlthpackicon.alpha = 1;
					self.hlthpackicon SetShader("gfx/custom/hud@lg_health.tga", 20, 20);			
				}					
				if (!isdefined(self.hlthpackammo))
				{
					self.hlthpackammo = newClientHudElem(self);	
					self.hlthpackammo.alignX = "left";
					self.hlthpackammo.alignY = "top";
					self.hlthpackammo.x = 605-25;
					self.hlthpackammo.y = 421;
					self.hlthpackammo.fontscale = 1;
				//	self.hlthpackammo.color = (.5,.5,0);
					self.hlthpackammo setValue(self.hashlthpacks);
				}
				if (!isdefined(self.medkitcounticon))
				{
					self.medkitcounticon = newClientHudElem(self);	
					self.medkitcounticon.alignX = "left";
					self.medkitcounticon.alignY = "top";
					self.medkitcounticon.x = 534; //590
					self.medkitcounticon.y = 398-5; //414
				//	self.medkitcounticon.alpha = 1;
					self.medkitcounticon SetShader("gfx/custom/hud@mediccharge.tga", 20, 20);			
				}					
				if (!isdefined(self.medkitcountammo))
				{
					self.medkitcountammo = newClientHudElem(self);	
					self.medkitcountammo.alignX = "left";
					self.medkitcountammo.alignY = "top";
					self.medkitcountammo.x = 549;
					self.medkitcountammo.y = 401;
					self.medkitcountammo.fontscale = 1;
				//	self.medkitcountammo.color = (.5,.5,0);
					self.medkitcountammo setValue(self.medkitcount);
				}
				if(self.pers["team"]=="allies")
				{					
					self.packmine="xmodel/landmine";
					icon="gfx/custom/hud@landmine.tga";
					icon_x=25;
					icon_y=25;
					x=605;
				}
				if (!isdefined(self.mineicon))
				{
					self.mineicon = newClientHudElem(self);	
					self.mineicon.alignX = "left";
					self.mineicon.alignY = "top";
					self.mineicon.x = 590;
					self.mineicon.y = 414-5;
				//	self.mineicon.alpha = 1;
					self.mineicon SetShader(icon, icon_x, icon_y);			
				}					
				if (!isdefined(self.mineammo))
				{
					self.mineammo = newClientHudElem(self);	
					self.mineammo.alignX = "left";
					self.mineammo.alignY = "top";
					self.mineammo.x = x;
					self.mineammo.y = 421;
					self.mineammo.fontscale = 1;
				//	self.mineammo.color = (.5,.5,0);
					self.mineammo setValue(self.hasmine);
				}
				self thread mine_watch();
				break;
			case "soldier":
				self.mine_planted=undefined;
				self.diffusepoints=5;
				self.hasmine=1;
				self.packmine="xmodel/tellermine";
				icon="gfx/custom/hud@tellermine.tga";
				icon_x=32;
				icon_y=32;
				x=605+5;
				if(self.pers["team"]=="allies")
				{					
					self.packmine="xmodel/landmine";
					icon="gfx/custom/hud@landmine.tga";
					icon_x=25;
					icon_y=25;
					x=605;
				}
				if (!isdefined(self.mineicon))
				{
					self.mineicon = newClientHudElem(self);	
					self.mineicon.alignX = "left";
					self.mineicon.alignY = "top";
					self.mineicon.x = 590;
					self.mineicon.y = 414-5;
				//	self.mineicon.alpha = 1;
					self.mineicon SetShader(icon, icon_x, icon_y);			
				}					
				if (!isdefined(self.mineammo))
				{
					self.mineammo = newClientHudElem(self);	
					self.mineammo.alignX = "left";
					self.mineammo.alignY = "top";
					self.mineammo.x = x;
					self.mineammo.y = 421;
					self.mineammo.fontscale = 1;
				//	self.mineammo.color = (.5,.5,0);
					self.mineammo setValue(self.hasmine);
				}
				self thread mine_watch();
				break;	
//Officer	
			case "engineer":				
				self.mine_planted=undefined;
				self.diffusepoints=5;
				self.hasmine=1;
				self.packmine="xmodel/tellermine";
				icon="gfx/custom/hud@tellermine.tga";
				icon_x=32;
				icon_y=32;
				x=605+5;
				if(self.pers["team"]=="allies")
				{					
					self.packmine="xmodel/landmine";
					icon="gfx/custom/hud@landmine.tga";
					icon_x=25;
					icon_y=25;
					x=605;
				}
				if (!isdefined(self.mineicon))
				{
					self.mineicon = newClientHudElem(self);	
					self.mineicon.alignX = "left";
					self.mineicon.alignY = "top";
					self.mineicon.x = 590;
					self.mineicon.y = 414-5;
				//	self.mineicon.alpha = 1;
					self.mineicon SetShader(icon, icon_x, icon_y);			
				}					
				if (!isdefined(self.mineammo))
				{
					self.mineammo = newClientHudElem(self);	
					self.mineammo.alignX = "left";
					self.mineammo.alignY = "top";
					self.mineammo.x = x;
					self.mineammo.y = 421;
					self.mineammo.fontscale = 1;
				//	self.mineammo.color = (.5,.5,0);
					self.mineammo setValue(self.hasmine);
				}
				self thread mine_watch();
				break;				
				
			case "support":
				self.ammoboxcount=1;
				self.isHoldingAmmo=undefined;
				self.isReArming=undefined;
				self.ammocrate="xmodel/axis_ammobox1";
//				self.ammocrate.healthavailable=undefined;
				self.rearmpoints=0;
				self.hasammocrate=1;	
				self.supply=undefined;
				self.supportcharge=100;
				self.supplypoints=0;
				self.mine_planted=undefined;
				self.diffusepoints=0;
				self.hasmine=1;
				self.packmine="xmodel/tellermine";
				icon="gfx/custom/hud@tellermine.tga";
				icon_x=32;
				icon_y=32;
				x=605+5;
				if(self.pers["team"]=="allies")
				{					
					self.packmine="xmodel/landmine";
					icon="gfx/custom/hud@landmine.tga";
					self.ammocrate="xmodels/ammobox1";
					icon_x=25;
					icon_y=25;
					x=605;
				}
				if (!isdefined(self.mineicon))
				{
					self.mineicon = newClientHudElem(self);	
					self.mineicon.alignX = "left";
					self.mineicon.alignY = "top";
					self.mineicon.x = 590;
					self.mineicon.y = 414-5;
				//	self.mineicon.alpha = 1;
					self.mineicon SetShader(icon, icon_x, icon_y);			
				}					
				if (!isdefined(self.mineammo))
				{
					self.mineammo = newClientHudElem(self);	
					self.mineammo.alignX = "left";
					self.mineammo.alignY = "top";
					self.mineammo.x = x;
					self.mineammo.y = 421;
					self.mineammo.fontscale = 1;
				//	self.mineammo.color = (.5,.5,0);
					self.mineammo setValue(self.hasmine);
				}
				if (!isdefined(self.chargeicon))
				{
					self.chargeicon = newClientHudElem(self);	
					self.chargeicon.alignX = "left";
					self.chargeicon.alignY = "top";
					self.chargeicon.x = 534;
					self.chargeicon.y = 398-5;
				//	self.chargeicon.alpha = 1;
					self.chargeicon SetShader("gfx/custom/icon_ammo.tga", 20, 20);			
				}					
				if (!isdefined(self.ammoboxcount))
				{
					self.ammoboxcount = newClientHudElem(self);	
					self.ammoboxcount.alignX = "left";
					self.ammoboxcount.alignY = "top";
					self.ammoboxcount.x = 549;
					self.ammoboxcount.y = 401;
					self.ammoboxcount.fontscale = 1;
				//	self.ammoboxcount.color = (.5,.5,0);
					self.ammoboxcount setValue(self.ammoboxcount);
				}
				self thread mine_watch();
				break;
				
			case "sniper":
				self.mine_planted=undefined;
				self.diffusepoints=5;
				self.hasmine=1;
				self.packmine="xmodel/tellermine";
				icon="gfx/custom/hud@tellermine.tga";
				icon_x=32;
				icon_y=32;
				x=605+5;
				if(self.pers["team"]=="allies")
				{					
					self.packmine="xmodel/landmine";
					icon="gfx/custom/hud@landmine.tga";
					icon_x=25;
					icon_y=25;
					x=605;
				}
				if (!isdefined(self.mineicon))
				{
					self.mineicon = newClientHudElem(self);	
					self.mineicon.alignX = "left";
					self.mineicon.alignY = "top";
					self.mineicon.x = 590;
					self.mineicon.y = 414-5;
				//	self.mineicon.alpha = 1;
					self.mineicon SetShader(icon, icon_x, icon_y);			
				}					
				if (!isdefined(self.mineammo))
				{
					self.mineammo = newClientHudElem(self);	
					self.mineammo.alignX = "left";
					self.mineammo.alignY = "top";
					self.mineammo.x = x;
					self.mineammo.y = 421;
					self.mineammo.fontscale = 1;
				//	self.mineammo.color = (.5,.5,0);
					self.mineammo setValue(self.hasmine);
				}
				
			self thread mine_watch();
			
			default:
				/*players = getentarray("player","classname");
				if(players.size > 0)
				{
					for(i = 0;i<players.size;i++)
					{
					/*	if( (isDefined(players[i].pers["pClass"])) && (players[i].pers["pClass"] != "medic") && (players[i].pers["team"] == self.pers["team"]) )
						{
							players[i] iprintln("^1" + self.name + " ^1 NEEDS A MEDIC!");
							if(!isdefined(self.calledM))
							{
								players[i] make_obj_marker("medic",self,"gfx/custom/hud@mediccharge.tga");
							}
							self.calledM=true;
						//	objective_add(self.clientid, "current", players[i].origin, "gfx/custom/hud@mediccharge.tga");
						//	objective_position(self.clientid, self.origin);
						}
						if( (isDefined(players[i].pers["pClass"])) && (players[i].pers["pClass"] != "support") && (players[i].pers["team"] == self.pers["team"]) )
						{
							players[i] iprintln("^1" + self.name + " ^1 IS REQUESTING AMMO");
							if(!isdefined(self.calledE))
								players[i] make_obj_marker("support",self,"gfx/custom/icon_ammo.tga");
							self.calledE=true;
						}
					}
				}*/
				break;
		}
	}
}
update(name,a,b)
{
	if(isdefined(name))
	{
		name setValue(a);
		if(b)
		{
			if(a<=25)
				name.color=(1,0,0);
			else
				name.color=(1,1,1);
		}
		else
		{
			if(a<=1)
				name.color=(1,0,0);
			else
				name.color=(1,1,1);	
		}
	}
}
special_effect()
{
	if(!isalive(self))return;
	if(isdefined(self.pers["pClass"]))
	{
		switch(self.pers["pClass"])
		{
			case "medic":
				self minesetup();
				break;
			case "engineer":
				self minesetup();
				break;
			case "support":
				self minesetup();
				break;
			case "sniper":
				self minesetup();
				break;
			case "soldier":
				self minesetup();
				break;
			default:
				break;
		}
	}
}

dropweapon()
{
	if(level.scr_ss_drop==0)return;
	current = self getcurrentweapon();
	if(current != "none" && current != level.awe_sprintweapon)
		self dropItem(self getcurrentweapon());
}
call_medic()
{
	if(self.pers["pClass"] == "medic")
	{
//		if(self.mediccharge>0)
//			self thread medic_healself();
		
		if(self.hashlthpacks>0)
		{
			medic_dropHealth();
			self.hashlthpacks--;
			update(self.hlthpackammo,self.hashlthpacks,false);
		}	
		self.calledM=undefined;
		self medic_call_delete();
	}
	if(self.pers["pClass"] == "support")
	{
		if(self.supportcharge>0)
		{
			self support_rearm();
			iprintln("You have rearmed your ammo!");
//			self.supportcharge-=25;
		}
		else
		{
			iprintln("You can't rearm!");
		}
	}
	else
	{
		self playsound(self.nationality + "_medic");

		players = getentarray("player","classname");
		if(players.size > 0)
		{
			for(i = 0;i<players.size;i++)
			{
				if( (isDefined(players[i].pers["pClass"])) && (players[i].pers["pClass"] != "medic") && (players[i].pers["team"] == self.pers["team"]) )
				{
					players[i] iprintln("^1" + self.name + " ^1 NEEDS A MEDIC!");
					if(!isdefined(self.calledM)&&(!isdefined(self.calledE)))
						players[i] make_obj_marker("medic",self,"gfx/custom/hud@mediccharge.tga");
					self.calledM=true;
				}
			}
		}
		self pingplayer();
	}
}	
options()
{
	self endon("TimeToDie");
	self endon("disconnect");
	
	player = "";
	players = getentarray("player", "classname");
	thread dude_think();

	for(i = 0; i < players.size; i++) //what is this?
	{
		if(isPlayer(players[i]) &&(players[i].team==players[i].pers["team"]) && isDefined(players[i].objnum))
		{
			players[i] thread dude_think(players[i]);
		}
	}
}
medic_call_delete()
{
	if(isDefined(self.objnum))
		objective_delete(self.objnum);
}
medic()
{
	player = getentarray("player", "classname");
	for(i=0;i<player.size;i++)
	{
		dst = distance(self.origin , player[i].origin);
		if(dst<= 48)
		{
			player[i] check_delete_objective(self.pers["class"]);

			if(player[i].pers["team"] == self.team && (!isDefined(player[i].ishealing)) && player[i].health < 100&&(isdefined(player[i].pers["pClass"])&&player[i].pers["pClass"]!="medic")&&self.mediccharge>0 )
			{
				self.ishealing = 1;
				self.mediccharge-=level.scr_medic_heal;
				if(self.mediccharge<0)
					self.mediccharge=0;
				player[i].health+=level.scr_medic_heal;
				if(player[i].health>100)
					player[i].health=100;
				update(self.medkitcountammo,self.mediccharge,true);
				if((getCvar("g_gametype")!="dm"))
				{
					self.healpoints+=10;
					if(self.healpoints>50)
					{
						self.score ++;
						self iprintln(&"MC2_SCORE_HEAL");
						self.healpoints = 0;
					}
				}
			}
		}
	}
	if(!isdefined(self.ishealing))
	{
		if(self.hashlthpacks>0)
		{
			medic_dropHealth();
			self.hashlthpacks--;
			update(self.hlthpackammo,self.hashlthpacks,false);
		}
	}
	self.ishealing=undefined;
}
medic_dropHealth(alive)
{		
	if(isDefined(level.medic_healthpack[level.medic_healthpack_count]))
		level.medic_healthpack[level.medic_healthpack_count] delete();

	range = 48;
	forward = anglesToForward(self.angles);
	forward = maps\mp\_utility::vectorScale(forward, range);	

	level.medic_healthpack[level.medic_healthpack_count] = spawn("item_health_large", (self.origin + (0, 0 , 20) + forward));
	level.medic_healthpack[level.medic_healthpack_count].angles = (0, randomint(360), 0);

	level.medic_healthpack_count++;
	
	if(level.medic_healthpack_count >= 16)
		level.medic_healthpack_count = 0;
}
medic_healself()
{
	self endon("disconnect");
	self endon("TimeToDie");
	self.ishealing = 1;
	h = self.health;	
	for(i = 0;i < (100 - h) ;i++)
	{
		if(self.health < 100)
		{
			self.health += 1;
			self.mediccharge-=1;
			update(self.medkitcountammo,self.mediccharge,true);
		}
		else
			break;
		wait .2;
	}
	self.ishealing = undefined;
}
medic_recharge()
{
	self endon("disconnect");
	self endon("TimeToDie");
	
	for(;;)
	{
		wait 1;
		if(!isdefined(self.ishealing)&&self.mediccharge<100)
		{
			self.mediccharge+=1;
			update(self.medkitcountammo,self.mediccharge,true);
			if(self.mediccharge>100)
				self.mediccharge=100;
		}
	}
}
deletePlacedEntity(entity)
{
	entities = getentarray(entity, "classname");
	for(i = 0; i < entities.size; i++)
	{
		//println("DELETED: ", entities[i].classname);
		entities[i] delete();
	}
}
//******************************************************************************
//******************************************************************************
// Bloodlust - make all users of landmines use the same functions
// Each class doesn't need it's own identical landmine functions...
mine_think() //distance increased from 36 to 42
{
	wait 1.25;
	wastripped = false;
	
	while(!isdefined(self.isblown))
	{
		players = getentarray("player", "classname");
		for(j = 0; j < players.size; j++)
		{
			if(isAlive(players[j]) && isdefined(players[j].pers["team"]) && players[j].pers["team"] != "spectator" && players[j].sessionstate == "playing" )
			{
				if(!isdefined(self))
					break;
					
				dst = distance(players[j].origin,self.origin);
				
				if(isAlive(players[j]) && dst < 42 /*&& players[j].pers["team"] != players[j].pers["team"]*/ )
				{
					if((players[j].pers["team"] == self.team) && (level.scr_mine_teamkill==0))
						return;

					self playsound ("minefield_click");
					
					wait(.5);
					wait(randomFloat(.5));
					
					if(!isdefined(self))
						break;
						
					self.isblown = 1;
					wastripped = true;
				}		
			}
		}
		wait 0.1;
	}

	if(wastripped)
		self mine_dmg(self.owner);
}

mine_watch()
{	
	self endon("disconnect");
	self endon("TimeToDie");

	while(isDefined(self))
	{
		self.mine2disarm = undefined;
		mines = getentarray("mine","targetname");
		
		if(mines.size > 0)
		{	
			show_warning = undefined;
			show_disarm = undefined;
			barsize=20;
			diffusesize=100;
			
			for(i = 0; i < mines.size; i++)
			{	
				mine = mines[i];
				dst=distance(self.origin, mine.origin);
				
				if(dst < 240 && dst>100)
				{
						show_warning= "1";
						break;
				}
				
				if(dst<=100)
				{
					show_disarm = "1";
					
					if(isDefined(self.mine2disarm) && self.mine2disarm != mine)
						self.mine2disarm = mine;
					else if(!isDefined(self.mine2disarm))
						self.mine2disarm = mine;
						
					if(mine.team=="axis")
					{
						if(isDefined(self.minedisarm))
							self.minedisarm setshader("gfx/custom/hud@tellermine_diffuse.tga",32,32);
					}
					else if(mine.team=="allies")
					{
						if(isDefined(self.minedisarm))
							self.minedisarm setshader("gfx/custom/hud@landmine_diffuse.tga",25,25);
					}
					
					//****************************************************************************
					// Bloodlust - give everyone a chance to defuse the landmines
					if(self.stance<2)
					{
						while(self usebuttonpressed())
						{
							wait .05;
							diffusesize--;
							diffusesize2 = diffusesize/100;
							diffusesize3 = int((diffusesize2)* 20);
	
							if(diffusesize3 < 1)
								diffusesize3 = 1;
	
							if(isDefined(self.diffuse))
								self.diffuse setShader("gfx/hud/hud@health_bar.tga", 3, diffusesize3);
						
							if(diffusesize < 10)
							{
								chance = randomInt(100);								
//								self iprintlnbold("Defuse chance is: " + chance + "%");
								
								if(isDefined(self) && isDefined(self.pers["pClass"]) && isAlive(self) && self.sessionstate == "playing")
								{
									if((self.pers["pClass"] != "engineer" && chance <= 60) || (self.pers["pClass"] == "engineer" && chance <=80))
									{
										self mine_defuse();
										break;
									}
									else
									{
										self iprintln("You failed to properly defuse the landmine!");
										self.mine2disarm mine_dmg(self.mine2disarm.owner);
										break;
									}
								}
							}
						}
					} //****************************************************************************
				}
			}
			
			if( isdefined(show_warning) )
			{
				if(!isDefined(self.minewarning))
				{
					self.minewarning = newClientHudElem(self);
					self.minewarning.alignX = "left";
					self.minewarning.alignY = "top";
					self.minewarning.x = 590-20;//142
					self.minewarning.y = 411-40;//434
					self.minewarning.alpha = 1;
					self.minewarning setshader("gfx/custom/hud@mine_warning.tga",40,40);
				}	
			}

			if(isdefined(show_disarm))
			{
				if(!isDefined(self.minedisarm) && isDefined(self.mine2disarm) && self.mine2disarm getentitynumber() )
				{
					self.minedisarm = newclientHudElem(self);
					self.minedisarm.alignx = "left";
					self.minedisarm.aligny = "top";
					self.minedisarm.x = 590-32;
					self.minedisarm.y = 414-5;
					self.minedisarm.alpha = 1;
				
					self.diffuse_back = newClientHudElem(self);
					self.diffuse_back setShader("gfx/hud/hud@health_back.tga", 5,barsize+2);
					self.diffuse_back.alignX = "left";
					self.diffuse_back.alignY = "top";
					self.diffuse_back.x = 590-32;
					self.diffuse_back.y = 411;

					self.diffuse = newClientHudElem(self);
					self.diffuse setShader("gfx/hud/hud@health_bar.tga",3,barsize);
					self.diffuse.color = ( 0, 1, 0);
					self.diffuse.alignX = "left";
					self.diffuse.alignY = "bottom";
					self.diffuse.x = 590-32+1;
					self.diffuse.y = 411+20+1;
					self.diffuse.alpha = 0.6;
				}
				
				if(!isdefined(self.mine2disarm))
					show_disarm = undefined;
			}

			if(!isDefined(show_warning) )
			{
				if(isDefined(self.minewarning))
					self.minewarning destroy();
			}
			
			if(!isDefined(show_disarm) && isDefined(self.minedisarm))
			{
				self.mine2disarm = undefined;
				if(isDefined(self.minedisarm))
					self.minedisarm destroy();
				if(isDefined(self.diffuse_back))
					self.diffuse_back destroy();
				if(isDefined(self.diffuse))
					self.diffuse destroy();
			}
		}
		else
		{
			if(isDefined(self.mine2disarm))
			{
				if(isDefined(self.mine2disarm.owner.minedisarm))
					self.mine2disarm.owner.minedisarm destroy();
				if(isDefined(self.mine2disarm.owner.diffuse_back))
					self.mine2disarm.owner.diffuse_back destroy();
				if(isDefined(self.mine2disarm.owner.diffuse))
					self.mine2disarm.owner.diffuse destroy();
					
				self.mine2disarm.isblown = true;
				self.mine2disarm delete();
				self.mine2disarm = undefined;
			}
			
			if(isDefined(self.minedisarm))
				self.minedisarm destroy();

		}
		wait (.05);
				
	}
}

mine_defuse()
{
	if(isDefined(self.mine2disarm))
	{
		self.mine2disarm.isblown = true;

		if(isDefined(self.mine2disarm.owner.minedisarm))
			self.mine2disarm.owner.minedisarm destroy();
		if(isDefined(self.mine2disarm.owner.diffuse_back))
			self.mine2disarm.owner.diffuse_back destroy();
		if(isDefined(self.mine2disarm.owner.diffuse))
			self.mine2disarm.owner.diffuse destroy();
			
		if(isdefined(self.mine2disarm.owner.team))
		{
			if((getCvar("g_gametype")!="dm"))
			{
				if(self.mine2disarm.owner.team==self.pers["team"])
				{
					self.hasmine++;
					update(self.mineammo,self.hasmine,false);
				}
				else
				{
					self.score ++;
					self iprintln(&"MC2_SCORE_MINE_DIFFUSED");
				}
			}
			else
			{
				if(self.mine2disarm.owner.team==self.pers["team"])
				{
					self.hasmine++;
					update(self.mineammo,self.hasmine,false);
				}			
			}
		}
		
		self.mine2disarm delete();
		wait(.05);
		self iprintln(&"MC2_MINE_DIFFUSED");
	}
}

mine_dmg(eAttacker)
{
	self hide();

	playfx(level._effect["mine_boom"],self.origin);	
	self playSound("explo_mine");

	// Rock their world
	earthquake(2, 3, self.origin, 100);

	// Loop through players
	players = getentarray("player", "classname");
	for(i=0;i<players.size;i++)
	{
		// Check that player is in range
		dst = distance(self.origin,players[i].origin);
		if(dst>180|| players[i].sessionstate != "playing" || !isAlive(players[i]))
			continue;

		percent = (180-dst)/180;
		iDamage = 10 + (450 - 10)*percent;

		traceorigin = players[i].origin + (0,0,32);

		trace = bullettrace(self.origin, traceorigin, true, self);

		if(isdefined(trace["entity"]) && trace["entity"] != players[i])
			iDamage = iDamage * .7;
		else if(!isdefined(trace["entity"]))
			iDamage = iDamage * .3;

		vDir = vectorNormalize(traceorigin - (self.origin ));
		iDamage = int(iDamage);
		
		players[i] thread [[level.callbackPlayerDamage]]( eAttacker, eAttacker, iDamage, 1, "MOD_EXPLOSIVE", eAttacker.pers["team"]+"_mine_mp", undefined, vDir, "none",0);
	}

	body = getentarray("body","targetname");
	for(i=0;i<body.size;i++)
	{
		dst=distance(self.origin,body[i].origin);
		if(dst<250&&isdefined(body)&&body[i].targetname=="body")
		{
			if(30>=randomint(100))
				self _mc2\_artillery::body_boom(body[i]);
		}
	}
	self delete();
}

mine_delete()
{
	if(isdefined(self.mine))
	{
		for(k=0;k<self.mine.size;k++)
		{
			if(isdefined(self.mine[k]))
				self.mine[k] delete();
		}

		self.mine = undefined;
	}
}
//******************************************************************************
//******************************************************************************
make_obj_marker(class,dude,icon)
{
	self endon("TimeToDie");

	objnum = GetNextObjNum(class);
	dude.objnum = objnum;
	objective_add(objnum, "current", dude.origin, icon);
	objective_team(objnum,dude.pers["team"]);
	self thread dude_think(dude);
}
dude_think(dude)
{
	self endon("TimeToDie");
	self endon("disconnect");
	
	while((isPlayer(dude)) && (isAlive(dude)))
	{
		wait .05;
		objective_position(dude.objnum, dude.origin);
	}
}
GetNextObjNum(class)
{
	for (i=0;i<16;i++)
	{
		if (level.objused[class][i] == true)
			continue;
		
		level.objused[class][i] = true;
		return ( i + 1 );
	}
	return -1;
}
check_delete_objective(class)
{
	//objnum = ((self getEntityNumber()) + 1);
	if (isdefined (self.objnum))
	{
		objective_delete(self.objnum);
		level.objused[(self.objnum - 1)] = false;
		self.objnum = undefined;
		if(class=="medic")
			self.calledM=undefined;
		else if(class=="engineer")
			self.calledE=undefined;
	}
}	
minesetup() //for medic, engineer, solder and support
{
	offset = maps\mp\_utility::vectorScale(anglestoforward(self.angles), 40 ) + (0,0,32);
	// Find ground
	origin = _mc2\_healthpacks::FindGround(self.origin + offset);
	
	model = self.packmine;
	
	if(self.hasmine > 0)
	{
		self.hasmine--;
		update(self.mineammo,self.hasmine,false);

		if(!isdefined(self.mine))
			self.mine = [];


		self.mine[self.mine.size] = spawn("script_model", origin);
		self.mine[self.mine.size -1] setModel(model);
		self.mine[self.mine.size -1].targetname="mine";
		self.mine[self.mine.size -1] playSound("explo_plant_no_tick");
		self.mine[self.mine.size -1].owner=self;
		self.mine[self.mine.size -1].health=100;
		self.mine[self.mine.size -1].team = self.pers["team"];
		self.mine[self.mine.size -1] thread mine_think();
		
		self iprintln(&"MC2_MINE_PLACED");
	}
}
//---------------------------------------------------------------------------------//
//Give Support Rearm abilities
//--------------------------------------------------------------------------------//
call_support()
{
	if(self.pers["pClass"] == "support")
	{
	 if(self.pers["team"] == "axis")
	  { 
	  self _mc2\_ammobox_axis::main();
	  self support_call_delete();
	  self.calledE=undefined;
	  }
	  else if(self.pers["team"] == "allies")
	  {
	  self _mc2\_ammobox_allied::main();
	  self support_call_delete();
	  self.calledE=undefined;
	  }
	}
	if(self.pers["pClass"] == "medic")
	{
	  if(self.pers["team"] == "axis")
	  {
		self _mc2\_medkit_axis::main();
		self.calledE=undefined;
	  }
	  else if(self.pers["team"] == "allies")
	  {
		self _mc2\_medkit_allied::main();
		self.calledE=undefined;
	  }
	} 
	else
	{	
		if(self.nationality!="russian")
			self playsound(self.nationality + "_needammo");

		players = getentarray("player","classname");
		if(players.size > 0)
		{
			for(i = 0;i<players.size;i++)
			{
				if( (isDefined(players[i].pers["pClass"])) && (players[i].pers["pClass"] != "support") && (players[i].pers["team"] == self.pers["team"]) )
				{
					players[i] iprintln("^1" + self.name + " ^1 IS REQUESTING AMMO");
				}
				
			}
		}
		self pingplayer();
	}
}
support_call_delete()
{
	if(isDefined(self.objnum))
		objective_delete(self.objnum);
}
support_rearm()
{
	if(self.pers["class"]!="support" || !self.supportcharge)
		return;
		
//	if(isDefined(self.ammoboxcount))
//		return;
				
		wpn=self getcurrentWeapon();
		slotwpn = self getweaponslotweapon("primaryb");
		wpnslot = "primary";
		if(wpn==slotwpn)
		  wpnslot = "primaryb";
		ammo_clip = self getweaponslotclipammo(wpnslot);
		ammo = self getweaponslotammo(wpnslot);
		self.ammo_clip setValue(ammo_clip);
		self.ammo setValue(ammo);
		
		self GiveMaxAmmo(wpnslot);
		self GiveMaxAmmo(slotwpn);
		self.supportcharge-=25;
}	
supportInit()
{
	origin = self.origin+(0,0,54);
	dir=anglesToForward(self getplayerangles());
	velocity = maps\mp\_utility::vectorScale(dir, (80/20 + randomFloat(5)) ) + (0,0,(150/20 + randomFloat(5)));
	model=self.packtnt;
	pos=_mc2\_artillery::GetTargetedPos(100);

	player = getentarray("player", "classname");
	for(i=0;i<player.size;i++)
	{
		{
			dst = distance(self.origin , player[i].origin);
			if(dst<= 48)
			{
				if(player[i].pers["team"] == self.team && (!isDefined(player[i].supply)) &&(isdefined(player[i].pers["pClass"])&&player[i].pers["pClass"]!="engineer") )
				{
					if(self.supportcharge>0)
					//player[i] support_ammosupply();
						self support_ammosupply(player[i]);
			}	}	
		}
	}
	self.supply=undefined;
}
support_ammosupply(other)
{
	other.supply=1;	
	weapontype = other getcurrentweapon();
	weaponname = maps\mp\gametypes\_weapons::getWeaponName(weapontype);
	clip_size = maps\mp\gametypes\_weapons::fullclipsize(weapontype);
	ammount = other getweaponslotammo("primary");
	maxammo = maps\mp\gametypes\_weapons::GetGunAmmo(weapontype) - clip_size ;
	if ( maxammo > ammount )
	{
		self.supportcharge-=clip_size;
		if(self.supportcharge<0)
			self.supportcharge=0;
		update(self.ammoboxcount,self.supportcharge,true); 

		ammount = other getweaponslotammo("primary");
		other setWeaponSlotAmmo("primary", ammount + clip_size );
//		other playlocalsound("weap_raise");
		
		if((getCvar("g_gametype")!="dm"))
		{
			self.supplypoints+=10;
			if(self.supplypoints>50)
			{
				self.score ++;
				self iprintln(&"MC2_SCORE_SUPPLY");
				self.supplypoints = 0;
			}
		}
	}
	else
		other iprintln(&"MC2_NO_AMMO_NEEDED");
	other.supply=undefined;
}
support_recharge()
{
	self endon("disconnect");
	self endon("TimeToDie");
	
	for(;;)
	{
		wait 1;
		if(!isdefined(self.supply)&&self.supportcharge<100)
		{
			self.supportcharge+=5;
			update(self.ammoboxcount,self.supportcharge,true);
			if(self.supportcharge>100)
				self.supportcharge=100;
		}
	}
}