
BotStartGametype()
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
isBotName()
{
	if(self.name == self.pers["mc2_bot_name"])
		return true;
	else
		return false;
}