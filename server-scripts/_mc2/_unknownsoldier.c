/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_cd;
#include _mc2\_teamkilling;

UnknownRunOnSpawn(self.isUnknown, "mc2_unknown_name", level.mc2_unknownrenamemsg, "name")
{


	// Handle the Unknown Soldiers
	if(self isUnknown())
	{
		// Rename Unknown Soldiers
		// Get names
		names = [];
		count = 0;
		name = cvardef("mc2_unknown_name" + count, "", "", "", "string");
		while(name != "")
		{
			names[names.size] = name;
			count++;
			name = cvardef("mc2_unknown_name" + count, "", "", "", "string");
		}
		if(names.size)
		{
			self.pers["mc2_unknown_name"] = names[randomInt(names.size)] + " " + randomInt(1000);
			self setClientCvar("name", self.pers["mc2_unknown_name"]);
			if(level.mc2_unknownrenamemsg != "none")
				self iprintlnbold(level.mc2_unknownrenamemsg);
		}

		// Make sure an unknown player can't do much damage
		if(level.mc2_unknownreflect)
			self.pers["mc2_teamkiller"] = true;
	}

}
isUnknown()
{
	if(self.name == self.pers["mc2_unknown_name"])
		return true;
	else
		return false;
}