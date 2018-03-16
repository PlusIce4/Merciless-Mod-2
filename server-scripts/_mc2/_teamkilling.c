/**************************************************************************
MERCILESS MOD 2 V3.4+
Developed by PlusIce (current), Merciless Mod Team (previous work)
See credits.txt for complete works cited
**************************************************************************/

#include _mc2\_cd;
#include _mc2\_punishments;

init()
{
	// Anti teamkilling
	level.awe_teamkillmax		= cvardef("awe_teamkill_max", 3, 0, 99, "int");

	if(!level.awe_teamkillmax) return;

	level.awe_teamkillwarn		= cvardef("awe_teamkill_warn", 1, 0, 99, "int");
	level.awe_teamkillmethod	= cvardef("awe_teamkill_method", 3, 0, level.awe_punishments+1, "int");
	level.awe_teamkillreflect	= cvardef("awe_teamkill_reflect", 1, 0, 1, "int");
	level.awe_teamkillmsg 		= cvardef("awe_teamkill_msg","^6Good damnit! ^7Learn the difference between ^4friend ^7and ^1foe ^7you bastard!.","","","string");
}
PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	// Stop damage from teamkiller
	if(level.awe_teamplay && isPlayer(eAttacker) && (self != eAttacker) && (self.pers["team"] == eAttacker.pers["team"]))
	{
		if(eAttacker.pers["awe_teamkiller"])
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
	if(!isdefined(self.pers["awe_teamkills"]))	self.pers["awe_teamkills"] = 0;
	if(!isdefined(self.pers["awe_teamkiller"]))	self.pers["awe_teamkiller"] = false;
}

TeamKill()
{
	if (!level.awe_teamkillmax)
		return;

	// Increase value
	self.pers["awe_teamkills"]++;
	
	// Check if it reached or passed the max level
	if (self.pers["awe_teamkills"]>=level.awe_teamkillmax)
	{
		if(level.awe_teamkillmethod)
			iprintln(self.name + " ^7has killed ^1" + self.pers["awe_teamkills"] + " ^7teammate(s) and will be punished.");
		if(level.awe_teamkillreflect)
			iprintln(self.name + " ^7has killed ^1" + self.pers["awe_teamkills"] + " ^7teammate(s) and will reflect damage.");

		self iprintlnbold(level.awe_teamkillmsg);
		self thread PunishMe(level.awe_teamkillmethod, "teamkilling");
		if(level.awe_teamkillreflect)
			self.pers["awe_teamkiller"] = true;
	}
	// Check if it reached or passed the warning level
	else if (self.pers["awe_teamkills"]>=level.awe_teamkillwarn)
	{
		if(level.awe_teamkillmethod)
			self iprintlnbold(level.awe_teamkillmax - self.pers["awe_teamkills"] + " ^7more teamkill(s) and you will be ^1punished^7!");
		else if(level.awe_teamkillreflect)
			self iprintlnbold(level.awe_teamkillmax - self.pers["awe_teamkills"] + " ^7more teamkill(s) and you will reflect damage!");
		else 
			self iprintlnbold(level.awe_teamkillmax - self.pers["awe_teamkills"] + " ^7more teamkill(s) and nothing will happen!");
	}
}
