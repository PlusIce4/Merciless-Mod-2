/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_playermodels;

main()
{
	if(isdefined(self.pers["pClass"]))
	{
		switch(self.pers["pClass"])
		{
			case "medic":
				self.bodymodel="xmodel/playerbody_russian_medic";
				self.headmodel="xmodel/head_russian_winter_alex";
				self.hatModel ="xmodel/helmet_russian_medic";
				break;
			case "engineer":
			case "soldier":
			case "sniper":
			case "support":
			default:
				self.bodymodel="xmodel/playerbody_russian_padded01";
				self.headmodel="xmodel/head_russian_winter_alex";
				self.hatModel ="xmodel/helmet_russian_padded_a";
				break;
		}
	}
	zahl=randomint(6);
	if(zahl==0)zahl=1;

	self.painsound="generic_pain_russian_"+zahl;
	self.deathsound="generic_death_russian_"+zahl;
	self.bleedpain = "generic_pain_russian_"+zahl;
	self.nationality = game["allies"];
	self setModel(self.bodyModel);
	self attach(self.headmodel,"",true);
	self attach(self.hatModel,"",true);
	self setViewmodel("xmodel/viewmodel_hands_russian");
}

precache()
{
	precacheModel("xmodel/playerbody_russian_padded01");
	precacheModel("xmodel/playerbody_russian_medic");
	precacheModel("xmodel/head_russian_winter_alex");
	precacheModel("xmodel/helmet_russian_medic");
	precacheModel("xmodel/helmet_russian_padded_a);
	precacheModel("xmodel/viewmodel_hands_russian");
}