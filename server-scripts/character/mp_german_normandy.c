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
				self.bodymodel="xmodel/german_medic";
				self.headmodel = "xmodel/head_german_normandy_eric";
				self.hatModel = "xmodel/helmet_german_medic";
				break;
			case "engineer":
			case "soldier":
			case "sniper":
			case "support":
			default:
				self.bodyModel="xmodel/playerbody_german_normandy01";
				self.headmodel = codescripts\character::randomElement(head());
				self.hatModel = "xmodel/helmet_german_normandy";
				break;
		}
	}	
	zahl=randomint(3);
	if(zahl==0)zahl=1;

	self.painsound="generic_pain_german_"+zahl;
	self.deathsound="generic_death_german_"+zahl;
	self.bleedpain = "gbleedpain";
	self.nationality=game["axis"];

	self setModel(self.bodyModel);
	self attach(self.headmodel,"",true);
	self attach(self.hatModel,"",true);
	self setViewmodel("xmodel/viewmodel_hands_german");

}

precache()
{
	precacheModel("xmodel/german_medic");
	precacheModel("xmodel/helmet_german_medic");
	precacheModel("xmodel/playerbody_german_normandy01");
	precacheModel("xmodel/helmet_german_normandy");
	precacheModel("xmodel/viewmodel_hands_german");
	codescripts\character::precacheModelArray(head());
	precacheModel("xmodel/head_german_normandy_eric");
}

head()
{
	a[0] = "xmodel/head_german_normandy_christoph";
	a[1] = "xmodel/head_german_normandy_ericp";
	return a;
}