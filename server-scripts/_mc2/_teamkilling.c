/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_cd;
#include _mc2\_punishments;

init()
{
	// Anti teamkilling
	level.mc2_teamkillmax		= cvardef("mc2_teamkill_max", 3, 0, 99, "int");

	if(!level.mc2_teamkillmax) return;

	level.mc2_teamkillwarn		= cvardef("mc2_teamkill_warn", 1, 0, 99, "int");
	level.mc2_teamkillmethod	= cvardef("mc2_teamkill_method", 3, 0, level.mc2_punishments+1, "int");
	level.mc2_teamkillreflect	= cvardef("mc2_teamkill_reflect", 1, 0, 1, "int");
	level.mc2_teamkillmsg 		= cvardef("mc2_teamkill_msg","^6Good damnit! ^7Learn the difference between ^4friend ^7and ^1foe ^7you bastard!.","","","string");
}
DontShoot() //warn players to stop friendly fire
{
	self playsound(self.nationality + "_Hold_Fire");
}
PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	// Stop damage from teamkiller
	if(level.mc2_teamplay && isPlayer(eAttacker) && (self != eAttacker) && (self.pers["team"] == eAttacker.pers["team"]))
	{
		if(eAttacker.pers["mc2_teamkiller"])
		{
			eAttacker.friendlydamage = true;
			iDamage = int(iDamage * .5);
			// Make sure at least one point of damage is done
			if(iDamage < 1)
				iDamage = 1;

			eAttacker finishPlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime);
			eAttacker.friendlydamage = undefined;

			friendly = true;

			iDamage = -1;
		}
	}

	return iDamage;

}

Cleanup()
{
	if(!isdefined(self.pers["mc2_teamkills"]))	self.pers["mc2_teamkills"] = 0;
	if(!isdefined(self.pers["mc2_teamkiller"]))	self.pers["mc2_teamkiller"] = false;
}

TeamKill()
{
	if (!level.mc2_teamkillmax)
		return;

	// Increase value
	self.pers["mc2_teamkills"]++;
	
	// Check if it reached or passed the max level
	if (self.pers["mc2_teamkills"]>=level.mc2_teamkillmax)
	{
		if(level.mc2_teamkillmethod)
			iprintln(self.name + " ^7has killed ^1" + self.pers["mc2_teamkills"] + " ^7teammate(s) and will be punished.");
		if(level.mc2_teamkillreflect)
			iprintln(self.name + " ^7has killed ^1" + self.pers["mc2_teamkills"] + " ^7teammate(s) and will reflect damage.");

		self iprintlnbold(level.mc2_teamkillmsg);
		self thread PunishMe(level.mc2_teamkillmethod, "teamkilling");
		self thread DontShoot();
		if(level.mc2_teamkillreflect)
			self.pers["mc2_teamkiller"] = true;
	}
	// Check if it reached or passed the warning level
	else if (self.pers["mc2_teamkills"]>=level.mc2_teamkillwarn)
	{
		if(level.mc2_teamkillmethod)
			self iprintlnbold(level.mc2_teamkillmax - self.pers["mc2_teamkills"] + " ^7more teamkill(s) and you will be ^1punished^7!");
		else if(level.mc2_teamkillreflect)
			self iprintlnbold(level.mc2_teamkillmax - self.pers["mc2_teamkills"] + " ^7more teamkill(s) and you will reflect damage!");
		else 
			self iprintlnbold(level.mc2_teamkillmax - self.pers["mc2_teamkills"] + " ^7more teamkill(s) and nothing will happen!");
	}
}
