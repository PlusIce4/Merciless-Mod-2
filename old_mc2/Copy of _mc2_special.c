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
		if (isDefined(self.hlthchargeicon))
			self.hlthchargeicon destroy();
		if (isDefined(self.hlthchargeammo))
			self.hlthchargeammo destroy();
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
		if (isDefined(self.hlthchargeicon))
			self.hlthchargeicon destroy();
		if (isDefined(self.hlthchargeammo))
			self.hlthchargeammo destroy();
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
				self.medcrate=1; //xmodel/axis_medkit1
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
				if (!isdefined(self.hlthchargeicon))
				{
					self.hlthchargeicon = newClientHudElem(self);	
					self.hlthchargeicon.alignX = "left";
					self.hlthchargeicon.alignY = "top";
					self.hlthchargeicon.x = 590;
					self.hlthchargeicon.y = 414;
				//	self.hlthchargeicon.alpha = 1;
					self.hlthchargeicon SetShader("gfx/custom/hud@mediccharge.tga", 20, 20);			
				}					
				if (!isdefined(self.hlthchargeammo))
				{
					self.hlthchargeammo = newClientHudElem(self);	
					self.hlthchargeammo.alignX = "left";
					self.hlthchargeammo.alignY = "top";
					self.hlthchargeammo.x = 605-4;
					self.hlthchargeammo.y = 421;
					self.hlthchargeammo.fontscale = 1;
				//	self.hlthchargeammo.color = (.5,.5,0);
					self.hlthchargeammo setValue(self.mediccharge);
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
//			    self.mediccharge=2000;
//				self.ishealing=undefined;
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
				self.ammocrate="xmodel/axis_ammobox1";
				self.ammocrate.healthavailable=undefined;
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
					self.chargeicon.x = 590;
					self.chargeicon.y = 414;
				//	self.chargeicon.alpha = 1;
					self.chargeicon SetShader("gfx/custom/icon_ammo.tga", 20, 20);			
				}					
				if (!isdefined(self.chargeammo))
				{
					self.chargeammo = newClientHudElem(self);	
					self.chargeammo.alignX = "left";
					self.chargeammo.alignY = "top";
					self.chargeammo.x = 605-4;
					self.chargeammo.y = 421;
					self.chargeammo.fontscale = 1;
				//	self.chargeammo.color = (.5,.5,0);
					self.chargeammo setValue(self.supportcharge);
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
			self giveMaxAmmo(self.pers["weapon"]);
			self giveMaxAmmo(self.pers["pistol"]);
			self playlocalsound("weap_raise");
			iprintln("You have rearmed your ammo!");
			self.supportcharge-=25;
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
				update(self.hlthchargeammo,self.mediccharge,true);
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
medic_dropMedcrate(alive) //dead code
{		
//	self endon("spawned");
	
		if(self.hasmedcrate>0) //off for now
		{
			self.hasmedcrate--;
			update(self.medcrate,self.hasmedcrate,false);	
		}	
	plant = self maps\mp\_utility::getPlant();
	medcrate = spawn( "script_model", plant.origin );
	medcrate.angles = plant.angles;
	medcrate setModel("xmodel/allied_medkit1");
	self thread _mc2\_mc2_gore::putinQ("medcrate");
	self thread _mc2\_medkit::giveHealth();
	self thread _mc2\_medkit::timer();
	self iprintln("Medkit Planted!");
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
			update(self.hlthchargeammo,self.mediccharge,true);
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
			update(self.hlthchargeammo,self.mediccharge,true);
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
	self DeployCrateA();
	self support_call_delete();
	self.calledE=undefined;
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
				if( (isDefined(players[i].pers["pClass"])) && (players[i].pers["pClass"] == "medic") && (players[i].pers["team"] == self.pers["team"]) )
				{
	//			players[i] iprintln("^1" + self.name + " ^1 NEEDS A MEDIC!");
				if(!isdefined(self.calledM)&&(!isdefined(self.calledE)))
				players[i] make_obj_marker("medic",self.medkit,"gfx/custom/hud@mediccharge.tga");
				self _mc2\_medkit::main();
				self iprintln("Medkit Planted!");
				self.calledE=undefined;
				self.calledM=undefined;
				self support_call_delete();
//				objective_position(self.clientid, self.origin);
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
		update(self.chargeammo,self.supportcharge,true);

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
support_selfsupply() //redo
{
	self.supply-=1;	
	weapontype = self getcurrentweapon();
	weaponname = maps\mp\gametypes\_weapons::getWeaponName(weapontype);
	clip_size = maps\mp\gametypes\_weapons::fullclipsize(weapontype);
	ammount = self getweaponslotammo("primary");
	maxammo = maps\mp\gametypes\_weapons::GetGunAmmo(weapontype) - clip_size ;
	if ( maxammo > ammount )
	{
		self.supportcharge-=clip_size;
		if(self.supportcharge<0)
			self.supportcharge=0;
		update(self.chargeammo,self.supportcharge,true);

		ammount = self getweaponslotammo("primary");
		self setWeaponSlotAmmo("primary", ammount + clip_size );
		self playlocalsound("weap_raise");
		iprintln(&"You have rearmed your ammo!");
	}
	else if(!isdefined(self.supply)&&self.supportcharge<100)
		iprintln(&"MC2_NO_AMMO_NEEDED");
//	self.supply=undefined;
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
			update(self.chargeammo,self.supportcharge,true);
			if(self.supportcharge>100)
				self.supportcharge=100;
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------//
//Added Ammocrate code from Eggbeast
//Unused code for future usage
//-----------------------------------------------------------------------------------------------------------------------//
//--------------------------------------
//Drop the ammo crate on the ground where the player is standing
//--------------------------------------

DeployCrateA()
{	
		ammocrate = getentarray("ammocrate","targetname");
//		self.hudcrateA.color = (.5 ,.5, .5);
		offset = maps\mp\_utility::vectorScale(anglestoforward(self.angles), 40 ) + (0,0,32);
		// Find ground
		origin = _mc2\_healthpacks::FindGround(self.origin + offset);
		origin = self.origin+(0,0,54);
//		origin = FindGround(self.origin + offset);
		model = self.ammocrate;
		
		if(self.hasammocrate > 0)
		{
		self.hasammocrate--; //or self.ammocrate for ammocrate?
		update(self.ammocrate,self.hasammocrate,false);

		if(!isdefined(self.ammocrate))
			self.ammocrate = [];
			
//		ammocrate = spawn("script_model", origin);
//		ammocrate.angles = (0, randomint(360), 0);
		self.ammocrate[self.ammocrate.size] = spawn("script_model", origin);
		self.ammocrate[self.ammocrate.size] = spawn("ammocrate", origin);
		self.ammocrate[self.ammocrate.size -1] setModel(model);
		self.ammocrate[self.ammocrate.size -1].targetname="ammocrate";
		self.ammocrate[self.ammocrate.size -1] playSound("explo_plant_no_tick");
		self.ammocrate[self.ammocrate.size -1].owner=self;
		self.ammocrate[self.ammocrate.size -1].healthavailable=800;
		self.ammocrate[self.ammocrate.size -1].team = self.pers["team"];
		self.ammocrate[self.ammocrate.size -1].health=300;
//		self.ammocrate[self.ammocrate.size -1] settakedamage(true); 
		self.ammocrate[self.ammocrate.size -1] .team = self.pers["team"];
		self.ammocrate[self.ammocrate.size -1] thread AmmoCrateDamage();
		self.ammocrate[self.ammocrate.size -1] thread MonitorAmmocrate();

//		if(self.pers["team"] == "axis")
//			self.ammocrate setmodel ("xmodel/ammobox1");
//		else
//			self.ammocrate setmodel ("xmodel/axis_ammobox1");

		if(self.pers["team"] == "allies")
		{
			objective_add(12,"current" , self.origin , "gfx/custom/icon_ammo.tga");
			objective_team(12, self.pers["team"] , self.origin, "gfx/custom/icon_ammo.tga");
		}
		else
		{
			objective_add(13,"current" , self.origin , "gfx/custom/icon_ammo.tga");
			objective_team(13, self.pers["team"] , self.origin, "gfx/custom/icon_ammo.tga");
		}
	}
}


/*--------------------------------------

Monitor the Ammocrate for damage

--------------------------------------*/

AmmoCrateDamage()
{
	while(self.health>0)
	{
		self waittill ("damage", dmg, who, dir, point, mod, inflictor);
		self.health -= dmg;	
	}
	self.healthavailable = 0;
}

/*--------------------------------------

Monitor the Ammocrate for any teammates
who might be nearby

--------------------------------------*/
MonitorAmmoCrate()
{
	level endon("gameover");
	level endon("intermission");
	level endon("round_ended");
	level endon("map_ended");
	
	wait 5;

	while (self.healthavailable > 0 )
	{	
		support = 0;
		players = getentarray("player","classname");
		ammocrates = getentarray("ammocrate","targetname");

		if(players.size > 0)
		{
			for( i =0;i< players.size;i++)
			{
				if(isDefined(players[i].pers["team"]) && self.team == players[i].pers["team"])
				{
					if(isDefined(players[i].pers["pClass"]) && players[i].pers["pClass"] == "support")
						support += 1;
				}
			}
			if(support == 0)
				self.healthavailable = 0;			
		}
		
		players = getentarray("player", "classname");
		for(i = 0; i < players.size; i++)
		{
			if( isdefined(players[i].pers["team"]) && players[i].pers["team"] != "spectator" && players[i].sessionstate == "playing" && isalive(players[i]) )
			{	
				if( distance(players[i].origin, self.origin) <= 48 )
				{	
					if( players[i].pers["team"] == self.team )
					{
						players[i] thread RearmPlayer(self);
					}
				}
			}
		}
		wait (.5);
	}

	if(self.team == "allies")
	{
		level._alAmmoCrate = undefined;
		objective_delete(12);
	}
	else
	{
		level._axAmmoCrate = undefined;
		objective_delete(13);
	}
	playFX(level._effect["flame_blast"],self.origin);
	self playsound("mortar_explosion1");
//	radiusDamage(self.origin, 512, 300, 25);
	wait(0.05);
	if(isAlive(self.owner))
		self.owner.hudcrateA.color = (1, 1 ,1);
	self delete();
}


/*------------------------------------------

Re-arms a player by pressing USE near an Ammo crate

------------------------------------------*/
RearmPlayer(ammocrate)
{
	self endon("TimeToDie");
	level endon("boot");
	self endon("spawned");
	level endon("intermission");
	level endon("map_ended");

	if(isdefined(self.cratethreadrunning))
		return;

	self.cratethreadrunning = true;

	loop = true;

//	if(isDefined(self.classicon))
//		self.classicon destroy();

	while(loop && isalive(self) && (self.sessionstate == "playing")  && distance(self.origin, ammocrate.origin) <= 48 && self isOnGround() && ammocrate.healthavailable > 0 )
	{
//		//display text that they can rearm
//		if( !isdefined(level.barsize) )
//			level.barsize = 288; 
//		//display the message
		if(!isdefined(self.ramsge))
		{
			self.ramsge = newClientHudElem(self);
			self.ramsge.x = 320;
			self.ramsge.y = 375;
			self.ramsge.alignX = "center";
			self.ramsge.alignY = "middle";
			self.ramsge.alpha = 1;
			self.ramsge.fontScale = 1.0;
			self.ramsge setText(&"Hold down USE [\{+activate\}] key to rearm");
		}
	}
		//wait for use key to be held down
		if (self useButtonPressed())
		{
//			//show progress bar
//			if( !isdefined(level.barsize) )
//				level.barsize = 288; 
//
//			if(!isdefined(self.pbgrd))
//			{
//				self.pbgrd = newClientHudElem(self);
//				self.pbgrd.x = 320;
//				self.pbgrd.y = 360;
//				self.pbgrd.alignX = "center";
//				self.pbgrd.alignY = "middle";
//				self.pbgrd.alpha = 0.5;
//			}
//			self.pbgrd setShader("black", (level.barsize + 4), 12);		
//
//			if(!isdefined(self.pbgrdb))
//			{
//				self.pbgrdb = newClientHudElem(self);
//				self.pbgrdb.x = (320 - (level.barsize / 2.0));
//				self.pbgrdb.y = 360;
//				self.pbgrdb.alignX = "left";
//				self.pbgrdb.alignY = "middle";
//			}
//			self.pbgrdb setShader("white", 0, 8);
//			self.pbgrdb scaleOverTime(2.4, level.barsize, 8);
			self playsound("weap_bar_reload");
			self linkTo(ammocrate);
			self disableWeapon();
			self.progresstime = 0;

			while(isalive(self) && self useButtonPressed() && (self.progresstime < 4))
			{
				self.progresstime += 0.05;
				wait 0.05;
			}
//			if(isdefined(self.pbgrd))
//				self.pbgrd destroy();
//			if(isdefined(self.pbgrdb))
//				self.pbgrdb destroy();
			self unlink();
			self enableWeapon();

			if(self.progresstime >= 4)
			{
				self giveMaxAmmo(self.pers["weapon"]);
				self playlocalsound("weap_raise");
//				self.pers["w1"] = self getWeaponSlotWeapon("primary");
//				if(!isDefined(self.pers["w1"]))
//					return;
//				c_size = getfullclipammo(self.pers["w1"]);
//				ammount = self getweaponslotammo("primary");
//				maxammo = maps\mp\gametypes\_rank_gmi::GetGunAmmo(self.pers["w1"]) - c_size + 1 ;
//				if ( maxammo > ammount )
//				{
//					ammount = self getweaponslotammo("primary");
//					self setWeaponSlotAmmo("primary", maxammo );
//				}
//				wait 0.05;
//
//				self.pers["w2"] = self getWeaponSlotWeapon("primaryb");
//				if(!isDefined(self.pers["w2"]))
//					return;
//				c_size2 = getfullclipammo(self.pers["w2"]);
//				ammount = self getweaponslotammo("primaryb");
//				maxammo = maps\mp\gametypes\_rank_gmi::GetGunAmmo(self.pers["w2"]) - c_size2 + 1 ;
//				if ( maxammo > ammount )
//				{
//					ammount = self getweaponslotammo("primaryb");
//					self setWeaponSlotAmmo("primaryb", maxammo );
//				}
				wait (0.5);
//ditched this
//If they have none, let them have one grenade (based on shotgun returning 1)
//				ammount = self getweaponslotclipammo("grenade");
//				if ( ammount < 1)
//					self maps\mp\gametypes\_teams::giveGrenades("shotgun_mp");
//				wait (0.5);
			}
//TNT and mine reloads
				switch(self.pers["pClass"])
				{
				case "soldier":
					if(self.hasmines < 1)
					{
						self.hasmines = 1;
						self setclientcvar("cl_hasmines","1");
					}
					else
						self iprintln("How many Mines can one soldier carry?");
					wait 0.05;
					break;
		
				case "support":
					if(self.hasmines < 1)
					{
						self.hasmines = 1;
						self setclientcvar("cl_hasmines","1");
					}
					else
						self iprintln("How many Mines can one soldier carry?");
					wait 0.05;
					break;
		
				case "engineer":
					if(self.hasmines < 1)
					{
						self.hasmines = 1;
						self setclientcvar("cl_hasmines","1");
					}
					else
						self iprintln("How many Mines can one soldier carry?");
					wait 0.05;
					break;
				}
				self playlocalsound("weap_raise");
				level.iamreloading = undefined;

//				if(isdefined(self.ramsge))
//				{
//					self.ramsge destroy();
//					self.ramsge = undefined;
//				}
//				wait 5;
//				loop = false;
//			}
		}
		
//	if(isDefined(self.classicon))
//		self.classicon destroy();
//	if (!isdefined(self.classicon) )
//	{
//		self.classicon = newclientHudElem(self);
//		self.classicon.x = 592;
//		self.classicon.y = 425;
//		self.classicon.alpha = .5;
//
//		switch(self.pers["pClass"])
//		{
//			case "sniper": 	self.classicon setShader(game["hud_sniper"], 40, 40);break;
//			case "soldier": self.classicon setShader(game["hud_soldier"], 40, 40);break;
//			case "engineer":self.classicon setShader(game["hud_engineer"], 40, 40);break;
//			case "medic": 	self.classicon setShader(game["hud_medic"], 40, 40);break;
//			case "support": self.classicon setShader(game["hud_support"], 40, 40);break;		
//		}
//	}
//	wait 0.1;

//	if(isDefined(ammocrate.owner) && ammocrate.owner != self)
//	{
//		ammocrate.owner.rearmpoints +=10;
//		{
//			if(ammocrate.owner.rearmpoints >= 100)
//			{
//				ammocrate.owner iprintln("^3You Scored 1 Point For Rearming Teammates" );
//				ammocrate.owner.score++;
//				ammocrate.owner.rearmpoints = 0;
//			}
//		}
//	}
//	self.ammocrate.healthavailable=undefined;
	self.ammocrate.healthavailable-=100;
//	if(isdefined(self.pbgrd))
//		self.pbgrd destroy();
//	if(isdefined(self.pbgrdb))
//		self.pbgrdb destroy();
//	if(isdefined(self.ramsge))
//		self.ramsge destroy();
	level.iamreloading = undefined;
	self.ramsge = undefined;
	self.cratethreadrunning = undefined;
}
//--------------------------------------------------------------------------------------------------//
//Added MEDCRATE
//--------------------------------------------------------------------------------------------------//