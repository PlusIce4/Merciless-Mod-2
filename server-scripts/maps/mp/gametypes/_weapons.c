/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ ||
---------------------------
(www.mercilessmod.com)
----------------------
Class special weapons balanced
Mid July 2015
renamed weapons a bit
-------------------------------------------*/

#include maps\mp\_utility;
init()
{
	switch(game["allies"])
	{
	case "american":
		precacheItem("frag_grenade_american_mp");
		precacheItem("smoke_grenade_american_mp");
		precacheItem("colt_mp");
		precacheItem("m1carbine_mp");
		precacheItem("m1garand_mp");
		precacheItem("thompson_mp");
		precacheItem("bar_mp");
		precacheItem("springfield_mp");
		precacheItem("greasegun_mp");
		precacheItem("shotgun_mp");
		precacheItem("m1903_mp");
		precacheItem("scoped_garand_mp");
		precacheItem("alliedgas_mp");
		precacheItem("fire_mp");
		precacheItem("tnt_mp");
		precacheItem("mb30cal_mp");

		break;

	case "british":
		precacheItem("frag_grenade_british_mp");
		precacheItem("smoke_grenade_british_mp");
		precacheItem("webley_mp");
		precacheItem("enfield_mp");
		precacheItem("sten_mp");
		precacheItem("bren_mp");
		precacheItem("enfield_scope_mp");
		precacheItem("m1garand_mp");
		precacheItem("thompson_mp");
		precacheItem("shotgun_mp");
		precacheItem("scoped_garand_mp");
		precacheItem("m1903_mp");
		precacheItem("springfield_mp");
		precacheItem("m1carbine_mp");
		precacheItem("alliedgas_mp");
		precacheItem("fire_mp");
		precacheItem("tnt_mp");
		precacheItem("mb30cal_mp");

		break;

	case "russian":
		precacheItem("frag_grenade_russian_mp");
		precacheItem("smoke_grenade_russian_mp");
		precacheItem("TT30_mp");
		precacheItem("mosin_nagant_mp");
		precacheItem("SVT40_mp");
		precacheItem("PPS42_mp");
		precacheItem("ppsh_mp");
		precacheItem("ppsh41_mp");
		precacheItem("mosin_nagant_sniper_mp");
		precacheItem("shotgun_mp");
		precacheItem("scoped_svt_mp");
		precacheItem("alliedgas_mp");
		precacheItem("fire_mp");
		precacheItem("tnt_mp");
		precacheItem("mb30cal_mp");

		break;
	}

	precacheItem("frag_grenade_german_mp");
	precacheItem("smoke_grenade_german_mp");
	precacheItem("luger_mp");
	precacheItem("kar98k_mp");
	precacheItem("g43_mp");
	precacheItem("mp40_mp");
	precacheItem("mp44_mp");
	precacheItem("kar98k_sniper_mp");
	precacheItem("g43_sniper_mp");
	precacheItem("shotgun_mp");
	precacheItem("mb42_mp");
	precacheItem("axisgas_mp");
	precacheItem("axisfire_mp");
	precacheItem("sixpack_mp");




	precacheItem("binoculars_mp");

	level.weaponnames = [];
	level.weaponnames[0] = "greasegun_mp";
	level.weaponnames[1] = "m1carbine_mp";
	level.weaponnames[2] = "m1garand_mp";
	level.weaponnames[3] = "springfield_mp";
	level.weaponnames[4] = "thompson_mp";
	level.weaponnames[5] = "bar_mp";
	level.weaponnames[6] = "sten_mp";
	level.weaponnames[7] = "enfield_mp";
	level.weaponnames[8] = "enfield_scope_mp";
	level.weaponnames[9] = "bren_mp";
	level.weaponnames[10] = "PPS42_mp";
	level.weaponnames[11] = "mosin_nagant_mp";
	level.weaponnames[12] = "SVT40_mp";
	level.weaponnames[13] = "mosin_nagant_sniper_mp";
	level.weaponnames[14] = "ppsh_mp";
	level.weaponnames[15] = "mp40_mp";
	level.weaponnames[16] = "kar98k_mp";
	level.weaponnames[17] = "g43_mp";
	level.weaponnames[18] = "kar98k_sniper_mp";
	level.weaponnames[19] = "mp44_mp";
	level.weaponnames[20] = "shotgun_mp";
	level.weaponnames[21] = "fraggrenade";
	level.weaponnames[22] = "smokegrenade";
	level.weaponnames[23] = "extragrenade";
	level.weaponnames[24] = "mg42";
	level.weaponnames[25] = "mg30cal";
	level.weaponnames[26] = "g43_sniper_mp";
	level.weaponnames[27] = "m1903_mp";
	level.weaponnames[28] = "scoped_garand_mp";
	level.weaponnames[29] = "ppsh41_mp";
	level.weaponnames[30] = "scoped_svt_mp";
	level.weaponnames[31] = "gasgrenade";
	level.weaponnames[32] = "biggrenade";
	level.weaponnames[33] = "mb30cal_mp";
	level.weaponnames[34] = "mb42_mp";



	level.weapons = [];
	level.weapons["greasegun_mp"] = spawnstruct();
	level.weapons["greasegun_mp"].server_allowcvar = "scr_allow_greasegun";
	level.weapons["greasegun_mp"].client_allowcvar = "ui_allow_greasegun";
	level.weapons["greasegun_mp"].allow_default = 1;

	level.weapons["m1carbine_mp"] = spawnstruct();
	level.weapons["m1carbine_mp"].server_allowcvar = "scr_allow_m1carbine";
	level.weapons["m1carbine_mp"].client_allowcvar = "ui_allow_m1carbine";
	level.weapons["m1carbine_mp"].allow_default = 1;

	level.weapons["m1garand_mp"] = spawnstruct();
	level.weapons["m1garand_mp"].server_allowcvar = "scr_allow_m1garand";
	level.weapons["m1garand_mp"].client_allowcvar = "ui_allow_m1garand";
	level.weapons["m1garand_mp"].allow_default = 1;

	level.weapons["springfield_mp"] = spawnstruct();
	level.weapons["springfield_mp"].server_allowcvar = "scr_allow_springfield";
	level.weapons["springfield_mp"].client_allowcvar = "ui_allow_springfield";
	level.weapons["springfield_mp"].allow_default = 1;

	level.weapons["thompson_mp"] = spawnstruct();
	level.weapons["thompson_mp"].server_allowcvar = "scr_allow_thompson";
	level.weapons["thompson_mp"].client_allowcvar = "ui_allow_thompson";
	level.weapons["thompson_mp"].allow_default = 1;

	level.weapons["bar_mp"] = spawnstruct();
	level.weapons["bar_mp"].server_allowcvar = "scr_allow_bar";
	level.weapons["bar_mp"].client_allowcvar = "ui_allow_bar";
	level.weapons["bar_mp"].allow_default = 1;

	level.weapons["sten_mp"] = spawnstruct();
	level.weapons["sten_mp"].server_allowcvar = "scr_allow_sten";
	level.weapons["sten_mp"].client_allowcvar = "ui_allow_sten";
	level.weapons["sten_mp"].allow_default = 1;

	level.weapons["enfield_mp"] = spawnstruct();
	level.weapons["enfield_mp"].server_allowcvar = "scr_allow_enfield";
	level.weapons["enfield_mp"].client_allowcvar = "ui_allow_enfield";
	level.weapons["enfield_mp"].allow_default = 1;

	level.weapons["enfield_scope_mp"] = spawnstruct();
	level.weapons["enfield_scope_mp"].server_allowcvar = "scr_allow_enfieldsniper";
	level.weapons["enfield_scope_mp"].client_allowcvar = "ui_allow_enfieldsniper";
	level.weapons["enfield_scope_mp"].allow_default = 1;

	level.weapons["bren_mp"] = spawnstruct();
	level.weapons["bren_mp"].server_allowcvar = "scr_allow_bren";
	level.weapons["bren_mp"].client_allowcvar = "ui_allow_bren";
	level.weapons["bren_mp"].allow_default = 1;

	level.weapons["PPS42_mp"] = spawnstruct();
	level.weapons["PPS42_mp"].server_allowcvar = "scr_allow_pps42";
	level.weapons["PPS42_mp"].client_allowcvar = "ui_allow_pps42";
	level.weapons["PPS42_mp"].allow_default = 1;

	level.weapons["mosin_nagant_mp"] = spawnstruct();
	level.weapons["mosin_nagant_mp"].server_allowcvar = "scr_allow_nagant";
	level.weapons["mosin_nagant_mp"].client_allowcvar = "ui_allow_nagant";
	level.weapons["mosin_nagant_mp"].allow_default = 1;

	level.weapons["SVT40_mp"] = spawnstruct();
	level.weapons["SVT40_mp"].server_allowcvar = "scr_allow_svt40";
	level.weapons["SVT40_mp"].client_allowcvar = "ui_allow_svt40";
	level.weapons["SVT40_mp"].allow_default = 1;

	level.weapons["scoped_svt_mp"] = spawnstruct();
	level.weapons["scoped_svt_mp"].server_allowcvar = "scr_allow_scoped_svt";
	level.weapons["scoped_svt_mp"].client_allowcvar = "ui_allow_scoped_svt";
	level.weapons["scoped_svt_mp"].allow_default = 1;

	level.weapons["mosin_nagant_sniper_mp"] = spawnstruct();
	level.weapons["mosin_nagant_sniper_mp"].server_allowcvar = "scr_allow_nagantsniper";
	level.weapons["mosin_nagant_sniper_mp"].client_allowcvar = "ui_allow_nagantsniper";
	level.weapons["mosin_nagant_sniper_mp"].allow_default = 1;

	level.weapons["ppsh_mp"] = spawnstruct();
	level.weapons["ppsh_mp"].server_allowcvar = "scr_allow_ppsh";
	level.weapons["ppsh_mp"].client_allowcvar = "ui_allow_ppsh";
	level.weapons["ppsh_mp"].allow_default = 1;

	level.weapons["ppsh41_mp"] = spawnstruct();
	level.weapons["ppsh41_mp"].server_allowcvar = "scr_allow_ppsh41";
	level.weapons["ppsh41_mp"].client_allowcvar = "ui_allow_ppsh41";
	level.weapons["ppsh41_mp"].allow_default = 1;

	level.weapons["mp40_mp"] = spawnstruct();
	level.weapons["mp40_mp"].server_allowcvar = "scr_allow_mp40";
	level.weapons["mp40_mp"].client_allowcvar = "ui_allow_mp40";
	level.weapons["mp40_mp"].allow_default = 1;

	level.weapons["kar98k_mp"] = spawnstruct();
	level.weapons["kar98k_mp"].server_allowcvar = "scr_allow_kar98k";
	level.weapons["kar98k_mp"].client_allowcvar = "ui_allow_kar98k";
	level.weapons["kar98k_mp"].allow_default = 1;

	level.weapons["g43_mp"] = spawnstruct();
	level.weapons["g43_mp"].server_allowcvar = "scr_allow_g43";
	level.weapons["g43_mp"].client_allowcvar = "ui_allow_g43";
	level.weapons["g43_mp"].allow_default = 1;

	level.weapons["kar98k_sniper_mp"] = spawnstruct();
	level.weapons["kar98k_sniper_mp"].server_allowcvar = "scr_allow_kar98ksniper";
	level.weapons["kar98k_sniper_mp"].client_allowcvar = "ui_allow_kar98ksniper";
	level.weapons["kar98k_sniper_mp"].allow_default = 1;

	level.weapons["mp44_mp"] = spawnstruct();
	level.weapons["mp44_mp"].server_allowcvar = "scr_allow_mp44";
	level.weapons["mp44_mp"].client_allowcvar = "ui_allow_mp44";
	level.weapons["mp44_mp"].allow_default = 1;

	level.weapons["shotgun_mp"] = spawnstruct();
	level.weapons["shotgun_mp"].server_allowcvar = "scr_allow_shotgun";
	level.weapons["shotgun_mp"].client_allowcvar = "ui_allow_shotgun";
	level.weapons["shotgun_mp"].allow_default = 1;

	level.weapons["fraggrenade"] = spawnstruct();
	level.weapons["fraggrenade"].server_allowcvar = "scr_allow_fraggrenades";
	level.weapons["fraggrenade"].client_allowcvar = "ui_allow_fraggrenades";
	level.weapons["fraggrenade"].allow_default = 1;

	level.weapons["smokegrenade"] = spawnstruct();
	level.weapons["smokegrenade"].server_allowcvar = "scr_allow_smokegrenades";
	level.weapons["smokegrenade"].client_allowcvar = "ui_allow_smokegrenades";
	level.weapons["smokegrenade"].allow_default = 1;

	level.weapons["extragrenade"] = spawnstruct();
	level.weapons["extragrenade"].server_allowcvar = "scr_allow_extragrenades";
	level.weapons["extragrenade"].client_allowcvar = "ui_allow_extragrenades";
	level.weapons["extragrenade"].allow_default = 1;
	
	level.weapons["gasgrenade"] = spawnstruct();
	level.weapons["gasgrenade"].server_allowcvar = "scr_allow_gasgrenades";
	level.weapons["gasgrenade"].client_allowcvar = "ui_allow_gasgrenades";
	level.weapons["gasgrenade"].allow_default = 1;
	
	level.weapons["biggrenade"] = spawnstruct();
	level.weapons["biggrenade"].server_allowcvar = "scr_allow_biggrenades";
	level.weapons["biggrenade"].client_allowcvar = "ui_allow_biggrenades";
	level.weapons["biggrenade"].allow_default = 1;

	level.weapons["mb30cal_mp"] = spawnstruct();
	level.weapons["mb30cal_mp"].server_allowcvar = "scr_allow_browning";
	level.weapons["mb30cal_mp"].client_allowcvar = "ui_allow_browning";
	level.weapons["mb30cal_mp"].allow_default = 1;

	level.weapons["mb42_mp"] = spawnstruct();
	level.weapons["mb42_mp"].server_allowcvar = "scr_allow_mb42";
	level.weapons["mb42_mp"].client_allowcvar = "ui_allow_mb42";
	level.weapons["mb42_mp"].allow_default = 1;

	level.weapons["mg42"] = spawnstruct();
	level.weapons["mg42"].server_allowcvar = "scr_allow_mgsupport";
	level.weapons["mg42"].client_allowcvar = "ui_allow_mgsupport";
	level.weapons["mg42"].allow_default = 1;

	level.weapons["mg30cal"] = spawnstruct();
	level.weapons["mg30cal"].server_allowcvar = "scr_allow_mgsupport";
	level.weapons["mg30cal"].client_allowcvar = "ui_allow_mgsupport";
	level.weapons["mg30cal"].allow_default = 1;
	

	level.weapons["g43_sniper_mp"] = spawnstruct();
	level.weapons["g43_sniper_mp"].server_allowcvar = "scr_allow_g43sniper";
	level.weapons["g43_sniper_mp"].client_allowcvar = "ui_allow_g43sniper";
	level.weapons["g43_sniper_mp"].allow_default = 1;

	level.weapons["m1903_mp"] = spawnstruct();
	level.weapons["m1903_mp"].server_allowcvar = "scr_allow_m1903";
	level.weapons["m1903_mp"].client_allowcvar = "ui_allow_m1903";
	level.weapons["m1903_mp"].allow_default = 1;

	level.weapons["scoped_garand_mp"] = spawnstruct();
	level.weapons["scoped_garand_mp"].server_allowcvar = "scr_allow_scoped_garand";
	level.weapons["scoped_garand_mp"].client_allowcvar = "ui_allow_scoped_garand";
	level.weapons["scoped_garand_mp"].allow_default = 1;

	for(i = 0; i < level.weaponnames.size; i++)
	{
		weaponname = level.weaponnames[i];

		if(getCvar(level.weapons[weaponname].server_allowcvar) == "")
		{
			level.weapons[weaponname].allow = level.weapons[weaponname].allow_default;
			setCvar(level.weapons[weaponname].server_allowcvar, level.weapons[weaponname].allow);
		}
		else
			level.weapons[weaponname].allow = getCvarInt(level.weapons[weaponname].server_allowcvar);
	}

	level thread deleteRestrictedWeapons();
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

		player.usedweapons = false;

		player thread updateAllAllowedSingleClient();
		player thread onPlayerSpawned();
	}
}

onPlayerSpawned()
{
	self endon("disconnect");

	for(;;)
	{
		self waittill("spawned_player");

		self thread watchWeaponUsage();
	}
}

deleteRestrictedWeapons()
{
	for(i = 0; i < level.weaponnames.size; i++)
	{
		weaponname = level.weaponnames[i];

		//if(level.weapons[weaponname].allow != 1)
			//deletePlacedEntity(level.weapons[weaponname].radiant_name);
	}

	// Need to not automatically give these to players if I allow restricting them
	// colt_mp
	// webley_mp
	// TT30_mp
	// luger_mp
	// fraggrenade_mp
	// mk1britishfrag_mp
	// rgd-33russianfrag_mp
	// stielhandgranate_mp
}

givePistol()
{
	weapon2 = self getweaponslotweapon("primaryb");
	if(weapon2 == "none")
	{
		if(self.pers["team"] == "allies")
		{
			switch(game["allies"])
			{
			case "american":
				pistoltype = "colt_mp";
				break;

			case "british":
				pistoltype = "webley_mp";
				break;

			default:
				assert(game["allies"] == "russian");
				pistoltype = "TT30_mp";
				break;
			}
		}
		else
		{
			assert(self.pers["team"] == "axis");
			switch(game["axis"])
			{
			default:
				assert(game["axis"] == "german");
				pistoltype = "luger_mp";
				break;
			}
		}

		self takeWeapon("colt_mp");
		self takeWeapon("webley_mp");
		self takeWeapon("TT30_mp");
		self takeWeapon("luger_mp");

		//self giveWeapon(pistoltype);
		self setWeaponSlotWeapon("primaryb", pistoltype);
		self giveMaxAmmo(pistoltype);
	}
}

giveGrenades()
{
	if(self.pers["team"] == "allies")
	{
		switch(game["allies"])
		{
		case "american":
			grenadetype = "frag_grenade_american_mp";
			smokegrenadetype = "smoke_grenade_american_mp";
			extragrenadetype = "fire_mp";
			gasgrenadetype = "alliedgas_mp";
			biggrenadetype = "tnt_mp";
			break;

		case "british":
			grenadetype = "frag_grenade_british_mp";
			smokegrenadetype = "smoke_grenade_british_mp";
			extragrenadetype = "fire_mp";
			gasgrenadetype = "alliedgas_mp";
			biggrenadetype = "tnt_mp";
			break;

		default:
			assert(game["allies"] == "russian");
			grenadetype = "frag_grenade_russian_mp";
			smokegrenadetype = "smoke_grenade_russian_mp";
			extragrenadetype = "fire_mp";
			gasgrenadetype = "alliedgas_mp";
			biggrenadetype = "tnt_mp";
			break;
		}
	}
	else
	{
		assert(self.pers["team"] == "axis");
		switch(game["axis"])
		{
		default:
			assert(game["axis"] == "german");
			grenadetype = "frag_grenade_german_mp";
			smokegrenadetype = "smoke_grenade_german_mp";
			gasgrenadetype = "axisgas_mp";
			extragrenadetype = "axisfire_mp";
			biggrenadetype = "sixpack_mp";
			break;
		}
	}

	self takeWeapon("frag_grenade_american_mp");
	self takeWeapon("frag_grenade_british_mp");
	self takeWeapon("frag_grenade_russian_mp");
	self takeWeapon("frag_grenade_german_mp");
	self takeWeapon("smoke_grenade_american_mp");
	self takeWeapon("smoke_grenade_british_mp");
	self takeWeapon("smoke_grenade_russian_mp");
	self takeWeapon("smoke_grenade_german_mp");
	self takeWeapon("fire_mp");
	self takeWeapon("axisfire_mp");
	self takeWeapon("alliedgas_mp");
	self takeWeapon("axisgas_mp");
	self takeWeapon("tnt_mp");
	self takeWeapon("sixpack_mp");



	if(getcvarint("scr_allow_fraggrenades"))
	{
		fraggrenadecount = getClassBasedGrenadeCount(self.pers["pClass"]);
		if(fraggrenadecount)
		{
			self giveWeapon(grenadetype);
			self setWeaponClipAmmo(grenadetype, fraggrenadecount);
		}
	}

	if(getcvarint("scr_allow_smokegrenades"))
	{
		smokegrenadecount = getClassBasedSmokeGrenadeCount(self.pers["pClass"]);
		if(smokegrenadecount)
		{
			self giveWeapon(smokegrenadetype);
			self setWeaponClipAmmo(smokegrenadetype, smokegrenadecount);
		}
	}
	if(getcvarint("scr_allow_extragrenades"))
	{
		extragrenadecount = getClassBasedExtraGrenadeCount(self.pers["pClass"]);
		if(extragrenadecount)
		{
			self giveWeapon(extragrenadetype);
			self setWeaponClipAmmo(extragrenadetype, extragrenadecount);
			}
		}
		if(getcvarint("scr_allow_gasgrenades"))
		{
			gasgrenadecount = getClassBasedGasGrenadeCount(self.pers["pClass"]);
			if(gasgrenadecount)
			{
				self giveWeapon(gasgrenadetype);
				self setWeaponClipAmmo(gasgrenadetype, gasgrenadecount);
			}
	}		
	if(getcvarint("scr_allow_biggrenades")) //check spacing with braces
		{
			biggrenadecount = getClassBasedBigGrenadeCount(self.pers["pClass"]);
			if(biggrenadecount)
			{
				self giveWeapon(biggrenadetype);
				self setWeaponClipAmmo(biggrenadetype, biggrenadecount);
			}			
	}
	self switchtooffhand(grenadetype);
}

giveBinoculars()
{
	if( (isDefined(self.pers["pClass"])) && (self.pers["pClass"] == "sniper") || (self.pers["pClass"] == "engineer"))
		self giveWeapon("binoculars_mp");
}

dropWeapon()
{
	current = self getcurrentweapon();
///// Changed by AWE /////
	if(current != "none" && current != level.awe_sprintweapon)
//////////////////////////
	{
		weapon1 = self getweaponslotweapon("primary");
		weapon2 = self getweaponslotweapon("primaryb");

		if(current == weapon1)
			currentslot = "primary";
		else
		{
			assert(current == weapon2);
			currentslot = "primaryb";
		}

		clipsize = self getweaponslotclipammo(currentslot);
		reservesize = self getweaponslotammo(currentslot);

		if(clipsize || reservesize)
			self dropItem(current);
	}
}

dropOffhand()
{
	current = self getcurrentoffhand();
	if(current != "none")
	{
		ammosize = self getammocount(current);

		if(ammosize)
			self dropItem(current);
	}
}
getClassBasedGrenadeCount(class)
{
	switch(class)
	{
		case "sniper":
		case "support":	
			return 1;
		case "soldier":
		case "engineer":	
			return 2;
		case "medic":
		default:
			return 0;
	}
}
getClassBasedSmokeGrenadeCount(class)
{
	switch(class)
	{
		case "sniper":
			return 1;
		case "soldier":
			return 2;
		case "medic":	
		case "engineer":
		case "support":
		default:
			return 0;
	}
}
getClassBasedExtraGrenadeCount(class)
{
	switch(class)
	{
		case "support":
			return 1;
		case "medic":
		case "sniper":
		case "engineer":
		case "soldier":
		default:
			return 0;
		}	
}
getClassBasedGasGrenadeCount(class)
{
		switch(class)
		{
			case "engineer":
				return 2;
			case "medic":
			case "sniper":
			case "soldier":
			case "support":
			default:
				return 0;
		}	
}
getClassBasedBigGrenadeCount(class)
{
		switch(class)
		{
			case "medic":
				return 1;
			case "engineer":
			case "sniper":
			case "soldier":
			case "support":
			default:
				return 0;
		}	
}

getFragGrenadeCount()
{
	if(self.pers["team"] == "allies")
		grenadetype = "frag_grenade_" + game["allies"] + "_mp";
	else
	{
		assert(self.pers["team"] == "axis");
		grenadetype = "frag_grenade_" + game["axis"] + "_mp";
	}

	count = self getammocount(grenadetype);
	return count;
}

getSmokeGrenadeCount()
{
	if(self.pers["team"] == "allies")
		grenadetype = "smoke_grenade_" + game["allies"] + "_mp";
	else
	{
		assert(self.pers["team"] == "axis");
		grenadetype = "smoke_grenade_" + game["axis"] + "_mp";
	}

	count = self getammocount(grenadetype);
	return count;
}

getExtraGrenadeCount()
{
	if(self.pers["team"] == "allies")
		grenadetype = "fire_mp";
	else
	{
		assert(self.pers["team"] == "axis");
		grenadetype = "axisfire_mp";
	}

	count = self getammocount(grenadetype);
	return count;
}

getGasGrenadeCount()
{
	if(self.pers["team"] == "allies")
		grenadetype = "alliedgas_mp";
	else
	{
		assert(self.pers["team"] == "axis");
		grenadetype = "axisgas_mp";
	}

	count = self getammocount(grenadetype);
	return count;	
}
getBigGrenadeCount()
{
	if(self.pers["team"] == "allies")
		grenadetype = "tnt_mp";
	else
	{
		assert(self.pers["team"] == "axis");
		grenadetype = "sixpack_mp";
	}

	count = self getammocount(grenadetype);
	return count;	
}
isPistol(weapon)
{
	switch(weapon)
	{
	case "colt_mp":
	case "webley_mp":
	case "luger_mp":
	case "TT30_mp":
		return true;
	default:
		return false;
	}
}

isMainWeapon(weapon)
{
	// Include any main weapons that can be picked up

	switch(weapon)
	{
	case "mb30cal_mp":
	case "mb42_mp":
	case "greasegun_mp":
	case "m1carbine_mp":
	case "m1garand_mp":
	case "thompson_mp":
	case "bar_mp":
	case "springfield_mp":
	case "m1903_mp":
	case "sten_mp":
	case "enfield_mp":
	case "bren_mp":
	case "enfield_scope_mp":
	case "mosin_nagant_mp":
	case "SVT40_mp":
	case "PPS42_mp":
	case "ppsh_mp":
	case "ppsh41_mp":
	case "mosin_nagant_sniper_mp":
	case "scoped_svt_mp":
	case "kar98k_mp":
	case "g43_mp":
	case "mp40_mp":
	case "mp44_mp":
	case "kar98k_sniper_mp":
	case "shotgun_mp":
//	case "mb30cal_mp":
//	case "mb42_mp":
		return true;
	default:
		return false;
	}
}

restrictWeaponByServerCvars(response)
{
	switch(response)
	{
	// American
	case "mb30cal_mp":
		if(!getcvarint("scr_allow_browning"))
		{
			//self iprintln(&"Browning_is_restricted");
			response = "restricted";
		}
		break;
	
	
	case "m1carbine_mp":
		if(!getcvarint("scr_allow_m1carbine"))
		{
			//self iprintln(&"MP_M1A1_CARBINE_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "m1garand_mp":
		if(!getcvarint("scr_allow_m1garand"))
		{
			//self iprintln(&"MP_M1_GARAND_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "thompson_mp":
		if(!getcvarint("scr_allow_thompson"))
		{
			//self iprintln(&"MP_THOMPSON_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "bar_mp":
		if(!getcvarint("scr_allow_bar"))
		{
			//self iprintln(&"MP_BAR_IS_A_RESTRICTED_WEAPON");
			response = "restricted";
		}
		break;

	case "springfield_mp":
		if(!getcvarint("scr_allow_springfield"))
		{
			//self iprintln(&"MP_SPRINGFIELD_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "greasegun_mp":
		if(!getcvarint("scr_allow_greasegun"))
		{
			//self iprintln(&"MP_GREASEGUN_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "shotgun_mp":
		if(!getcvarint("scr_allow_shotgun"))
		{
			//self iprintln(&"MP_SHOTGUN_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

		case "m1903_mp":
				if(!getcvarint("scr_allow_m1903"))
				{
					//self iprintln(&"MP_SPRINGFIELD_IS_A_RESTRICTED");
					response = "restricted";
				}
		break;
		case "scoped_garand_mp":
						if(!getcvarint("scr_allow_scoped_garand"))
						{
							//self iprintln(&"MP_M1_GARAND_IS_A_RESTRICTED");
							response = "restricted";
						}
		break;
	// British
	case "enfield_mp":
		if(!getcvarint("scr_allow_enfield"))
		{
			//self iprintln(&"MP_LEEENFIELD_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;


	case "sten_mp":
		if(!getcvarint("scr_allow_sten"))
		{
			//self iprintln(&"MP_STEN_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "bren_mp":
		if(!getcvarint("scr_allow_bren"))
		{
			//self iprintln(&"MP_BREN_LMG_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "enfield_scope_mp":
		if(!getcvarint("scr_allow_enfieldsniper"))
		{
			//self iprintln(&"MP_BREN_LMG_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	// Russian
	case "mosin_nagant_mp":
		if(!getcvarint("scr_allow_nagant"))
		{
			//self iprintln(&"MP_MOSINNAGANT_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "SVT40_mp":
		if(!getcvarint("scr_allow_svt40"))
		{
			//self iprintln(&"MP_MOSINNAGANT_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "PPS42_mp":
		if(!getcvarint("scr_allow_pps42"))
		{
			//self iprintln(&"MP_PPSH_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "ppsh_mp":
		if(!getcvarint("scr_allow_ppsh"))
		{
			//self iprintln(&"MP_PPSH_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "ppsh41_mp":
		if(!getcvarint("scr_allow_ppsh41"))
		{
			//self iprintln(&"MP_PPSH_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "mosin_nagant_sniper_mp":
		if(!getcvarint("scr_allow_nagantsniper"))
		{
			//self iprintln(&"MP_SCOPED_MOSINNAGANT_IS");
			response = "restricted";
		}
		break;
	case "scoped_svt_mp":
		if(!getcvarint("scr_allow_scoped_svt"))
		{
			//self iprintln(&"MP_SCOPED_MOSINNAGANT_IS");
			response = "restricted";
		}
		break;

	// German
	case "mb42_mp":
		if(!getcvarint("scr_allow_mb42"))
		{
			//self iprintln(&"MP_KAR98K_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;
		
	case "kar98k_mp":
		if(!getcvarint("scr_allow_kar98k"))
		{
			//self iprintln(&"MP_KAR98K_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "g43_mp":
		if(!getcvarint("scr_allow_g43"))
		{
			//self iprintln(&"MP_KAR98K_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "mp40_mp":
		if(!getcvarint("scr_allow_mp40"))
		{
			//self iprintln(&"MP_MP40_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "mp44_mp":
		if(!getcvarint("scr_allow_mp44"))
		{
			//self iprintln(&"MP_MP44_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "kar98k_sniper_mp":
		if(!getcvarint("scr_allow_kar98ksniper"))
		{
			//self iprintln(&"MP_SCOPED_KAR98K_IS_A_RESTRICTED");
			response = "restricted";
		}
		break;

	case "fraggrenade":
		if(!getcvarint("scr_allow_fraggrenades"))
		{
			//self iprintln("Frag grenades are restricted");
			response = "restricted";
		}
		break;

	case "smokegrenade":
		if(!getcvarint("scr_allow_smokegrenades"))
		{
			//self iprintln("Smoke grenades are restricted");
			response = "restricted";
		}
		break;
	case "extragrenade":
		if(!getcvarint("scr_allow_extragrenades"))
		{
			//self iprintln("Extra grenades are restricted");
			response = "restricted";
		}
	case "gasgrenade":
			if(!getcvarint("scr_allow_gasgrenades"))
			{
				//self iprintln("Gas grenades are restricted");
				response = "restricted";		
			}
		break;
	
	case "biggrenade":
			if(!getcvarint("scr_allow_biggrenades"))
			{
				//self iprintln("Big grenades are restricted");
				response = "restricted";		
			}
		break;

	case "mg42_mp":
		if(!getcvarint("scr_allow_mgsupport"))
		{
			//self iprintln("MGS are restricted");
			response = "restricted";
		}
		break;
	case "mg30cal_mp":
		if(!getcvarint("scr_allow_mgsupport"))
		{
			//self iprintln("MGS are restricted");
			response = "restricted";
		}
		break;
	case "g43_sniper_mp":
		if(!getcvarint("scr_allow_g43sniper"))
		{
			//self iprintln("G43 Snipers are restricted");
			response = "restricted";
		}
		break;	
	default:
		//self iprintln(&"MP_UNKNOWN_WEAPON_SELECTED");
		response = "restricted";
		break;
	}
	return response;
}

// TODO: This doesn't handle offhands
watchWeaponUsage()
{
	self endon("spawned_player");
	self endon("disconnect");

	self.usedweapons = false;

	self thread watchOffhandUsage();

	while(self attackButtonPressed() && !self.usedweapons)
		wait .05;

	while(!(self attackButtonPressed()) && !self.usedweapons)
		wait .05;

	self.usedweapons = true;
}

watchOffhandUsage()
{
	self endon("spawned_player");
	self endon("disconnect");

	current = self getcurrentoffhand();
	if(current != "none")
		ammosize = self getammocount(current);
	else
		ammosize = 0;

	oldcurrent = current;
	oldammosize = ammosize;

	while(oldcurrent == current && oldammosize == ammosize && !self.usedweapons)
	{
		current = self getcurrentoffhand();
		if(current != "none")	ammosize = self getammocount(current);
		wait .05;
	}

	self.usedweapons = true;
}
getWeaponName(weapon)
{
	switch(weapon)
	{
	// American
	case "m1carbine_mp":
		weaponname = &"WEAPON_M1A1CARBINE";
		break;

	case "m1garand_mp":
		weaponname = &"WEAPON_M1GARAND";
		break;

	case "thompson_mp":
		weaponname = &"WEAPON_THOMPSON";
		break;

	case "bar_mp":
		weaponname = &"WEAPON_BAR";
		break;

	case "springfield_mp":
		weaponname = &"WEAPON_SPRINGFIELD";
		break;

	case "greasegun_mp":
		weaponname = &"WEAPON_GREASEGUN";
		break;

	case "shotgun_mp":
		weaponname = &"WEAPON_SHOTGUN";
		break;

//	case "30cal_mp":
//		weaponname = &"PI_WEAPON_MP_30CAL";
//		break;

//	case "m1903_mp":
//		weaponname = &"WEAPON_SPRINGFIELD";
//		break;

//	case "scoped_garand_mp":
//		weaponname = &"WEAPON_M1GARAND";
//		break;


	// British
	case "enfield_mp":
		weaponname = &"WEAPON_LEEENFIELD";
		break;

	case "sten_mp":
		weaponname = &"WEAPON_STEN";
		break;

	case "bren_mp":
		weaponname = &"WEAPON_BREN";
		break;

	case "enfield_scope_mp":
		weaponname = &"WEAPON_SCOPEDLEEENFIELD";
		break;

	// Russian
	case "mosin_nagant_mp":
		weaponname = &"WEAPON_MOSINNAGANT";
		break;

	case "SVT40_mp":
		weaponname = &"WEAPON_SVT40";
		break;

	case "PPS42_mp":
		weaponname = &"WEAPON_PPS42";
		break;

	case "ppsh_mp":
		weaponname = &"WEAPON_PPSH";
		break;

	case "ppsh41_mp":
		weaponname = &"WEAPON_PPSH41";
		break;

	case "mosin_nagant_sniper_mp":
		weaponname = &"WEAPON_SCOPEDMOSINNAGANT";
		break;

	//German
	case "kar98k_mp":
		weaponname = &"WEAPON_KAR98K";
		break;

	case "g43_mp":
		weaponname = &"WEAPON_G43";
		break;

	case "mp40_mp":
		weaponname = &"WEAPON_MP40";
		break;

	case "mp44_mp":
		weaponname = &"WEAPON_MP44";
		break;

	case "kar98k_sniper_mp":
		weaponname = &"WEAPON_SCOPEDKAR98K";
		break;
		
	case "mb30cal_mp":
		weaponname = "WPN_30CAL";
		break;
	case "mb42_mp":
		weaponname = "WPN_MG42";
		break;
		
	case "g43_sniper_mp":
		weaponname = &"WEAPON_SCOPEDG43";
		break;
		
	default:
		weaponname = &"WEAPON_UNKNOWNWEAPON";
		break;
	}

	return weaponname;
}

useAn(weapon)
{
	switch(weapon)
	{
	case "m1carbine_mp":
	case "m1garand_mp":
	case "mp40_mp":
	case "mp44_mp":
	case "shotgun_mp":
		result = true;
		break;

	default:
		result = false;
		break;
	}

	return result;
}

updateAllowed()
{
	for(i = 0; i < level.weaponnames.size; i++)
	{
		weaponname = level.weaponnames[i];

		cvarvalue = getCvarInt(level.weapons[weaponname].server_allowcvar);
		if(level.weapons[weaponname].allow != cvarvalue)
		{
			level.weapons[weaponname].allow = cvarvalue;

			thread updateAllowedAllClients(weaponname);
		}
	}
}

updateAllowedAllClients(weaponname)
{
	players = getentarray("player", "classname");
	for(i = 0; i < players.size; i++)
		players[i] updateAllowedSingleClient(weaponname);
}

updateAllowedSingleClient(weaponname)
{
	self setClientCvar(level.weapons[weaponname].client_allowcvar, level.weapons[weaponname].allow);
}


updateAllAllowedSingleClient()
{
	for(i = 0; i < level.weaponnames.size; i++)
	{
		weaponname = level.weaponnames[i];
		self updateAllowedSingleClient(weaponname);
	}
}


GetGunAmmo(weapon)
{
	clip_count = 4;

	clip_size = fullclipsize(weapon);

	switch(weapon)
	{
		// projectile weapons need to have default ammo returned for the original
		// game types

		//American Weapons
		case "thompson_mp":
		case "greasegun_mp":
		case "bar_mp":
		case "mb30cal_mp":
		//British Weapons
		case "sten_mp":
		case "bren_mp":
		//Russian Weapons
		case "ppsh_mp":
		case "ppsh41_mp":
		//German Weapons
		case "mp40_mp":
		case "mp44_mp":

		return clip_count * clip_size;

		// Semi-automatic rifles get 1 extra clip
		//American Weapons
		case "m1carbine_mp":
		case "m1garand_mp":
		case "scoped_garand_mp":
		//Russian Weapons
		case "svt40_mp":
		case "scoped_svt_mp":
		//German Weapons
		case "gewehr43_mp":

		return (clip_count + 1) * clip_size;

		// Bolt action rifles get 2 extra clips
		//American Weapons
		case "springfield_mp":
		case "m1903_mp":
		//British Weapons
		case "enfield_mp":
		//Russian Weapons
		case "mosin_nagant_mp":
		case "mosin_nagant_sniper_mp":
		//German Weapons
		case "kar98k_mp":
		case "kar98k_sniper_mp":

		return (clip_count + 2) * clip_size;

		default:
		   	return 0;
		}

	return 0;
}
fullclipsize(weapon)
{
	switch(weapon)
	{
		case "springfield_mp":
		case "kar98k_mp":
		case "kar98k_sniper_mp":
		case "mosin_nagant_mp":
		case "mosin_nagant_sniper_mp":
		case "m1903_mp":
		case "scoped_garand_mp":
			return 5;

		case "webley_mp":
		case "shotgun_mp":
			return 6;

		case "colt_mp":
			return 7;

		case "enfield_mp":
		case "enfield_scope_mp":
		case "luger_mp":
		case "tt30_mp":
		case "m1garand_mp":
			return 8;

		case "g43_mp":
		case "g43_sniper_mp":
		case "svt40_mp":
		case "scoped_svt_mp":
			return 10;

		case "m1carbine_mp":
			return 15;

		case "thompson_mp":
		case "bar_mp":
			return 20;

		case "bren_mp":
		case "mp44_mp":
			return 30;

		case "mp40_mp":
		case "sten_mp":
		case "greasegun_mp":
			return 32;

		case "pps42_mp":
		case "ppsh41_mp":
			return 35;

		case "ppsh_mp":
			return 71;
		
		case "mb42_mp":
		case "mb30cal_mp":
			return 50;

		default:
		   	return 0;

		}	
		
	return 0;
}