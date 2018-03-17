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
			self.bodymodel="xmodel/british_africa_medic";
			self.headmodel="xmodel/head_british_boon";
			self.hatModel = "xmodel/helmet_british_afrca_medic";
			break;
		case "engineer":
		case "soldier":
		case "sniper":
		case "support":
		default:
			self.bodyModel=codescripts\character::randomElement(xmodelalias\mp_body_british_africa::main());
			self.headmodel = codescripts\character::randomElement(head());
			self.hatModel = "xmodel/helmet_british_afrca";
			break;
		}
	}

	zahl=randomint(5);
	if(zahl==0)zahl=1;
	
	self.painsound="generic_pain_british_"+zahl;
	self.deathsound="generic_death_british_"+zahl;
	self.bleedpain = "generic_pain_british_"+zahl;
	self.nationality = game["allies"];

	self setModel(self.bodyModel);
	self attach(self.headmodel,"",true);
	self attach(self.hatModel,"",true);
	self setViewmodel("xmodel/viewmodel_hands_british_bare");
}

precache()
{
	precacheModel("xmodel/british_africa_medic");
	precacheModel("xmodel/helmet_british_afrca_medic");
	codescripts\character::precacheModelArray(xmodelalias\mp_body_british_africa::main());
	codescripts\character::precacheModelArray(head());
	precacheModel("xmodel/head_british_boon");	
	precacheModel("xmodel/helmet_british_afrca");
	precacheModel("xmodel/viewmodel_hands_british_bare");
}

head()
{
	a[0] = "xmodel/head_british_paul";
	a[1] = "xmodel/head_british_chance";
	return a;
}