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
			self.bodymodel="xmodel/playerbody_american_medic";
			self.headmodel="xmodel/head_us_ranger_harry";	
			self.hatModel = "xmodel/helmet_us_ranger_medic_wells";
			break;
		case "engineer":
		case "soldier":
		case "sniper":
		case "support":
		default:
			self.bodyModel=codescripts\character::randomElement(body());
			self.headmodel = codescripts\character::randomElement(head());
			self.hatModel = "xmodel/helmet_us_ranger_generic";
			break;
		}
	}

	zahl=randomint(7);
	if(zahl==0)zahl=1;

	self.painsound="generic_pain_american_"+zahl;
	self.deathsound="generic_death_american_"+zahl;
	self.bleedpain = "cough_hack";
	self.nationality = game["allies"];

	self setModel(self.bodyModel);
	self attach(self.headmodel,"",true);
	self attach(self.hatModel,"",true);
	self setViewmodel("xmodel/viewmodel_hands_cloth");
}

precache()
{
	//medic
	precacheModel("xmodel/playerbody_american_medic");
	precacheModel("xmodel/helmet_us_ranger_medic_wells");
	codescripts\character::precacheModelArray(body());
	codescripts\character::precacheModelArray(head());
	precacheModel("xmodel/head_us_ranger_harry");
	precacheModel("xmodel/helmet_us_ranger_generic");
	precacheModel("xmodel/viewmodel_hands_cloth");;
}
body()
{
	a[0] = "xmodel/playerbody_american_normandy05";
	return a;
}
head()
{
	a[0] = "xmodel/head_us_ranger_braeburn";
	return a;
}
