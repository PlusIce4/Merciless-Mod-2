/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell */
/* Script Code Snippets: */
/* Anti-TeamKilling Script */

#include mc2\_utils_cvardef;

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
		self thread mc2\_util::PunishMe(level.mc2_teamkillmethod, "teamkilling");
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
