/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Updated July 2015 by PlusIce
Removed Merciless Gore Mod
Ditched the unneeded braces
-------------------------------------------*/
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
	self.body_gib="xmodel/blood_chunk2"; //PlusIce: gibbing is unrealistic remove later

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
	precacheModel("xmodel/viewmodel_hands_cloth");
	precacheModel("xmodel/blood_chunk2");
}
body()
{
	a[0] = "xmodel/playerbody_american_normandy05";
	a[1] = "xmodel/playerbody_american_normandy03";
	return a;
}
head()
{
	a[0] = "xmodel/head_us_ranger_braeburn";
	a[1] = "xmodel/head_us_ranger_wolf";
	return a;
}
