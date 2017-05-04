/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Updated on JAN 2016 by PlusIce
Merciless Gore Mod removed
FIXED
-------------------------------------------*/
main()
{
	if(isdefined(self.pers["pClass"]))
	{
	switch(self.pers["pClass"])
	{
		case "medic":
			self.bodymodel="xmodel/playerbody_german_winterlight_medic";
			self.headModel="xmodel/head_german_winter_jon";
			self.hatModel="xmodel/helmet_medic_winter";
			break;
		case "engineer":
		case "soldier":
		case "sniper":
		case "support":
		default:
			self.bodymodel="xmodel/playerbody_german_winterdark";
			self.headModel="xmodel/head_german_winter_jon";
			self.hatModel="xmodel/helmet_german_winter_jon";
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
	self setViewmodel("xmodel/viewmodel_hands_german_winter");
}

precache()
{
	precacheModel("xmodel/playerbody_german_winterdark");
	precacheModel("xmodel/playerbody_german_winterlight_medic");
	precacheModel("xmodel/helmet_medic_winter");
	precacheModel("xmodel/helmet_medic_winter_burn");
	precacheModel("xmodel/helmet_german_winter_dark");
	precacheModel("xmodel/head_german_winter_jon");
	precacheModel("xmodel/helmet_german_winter_jon");
	precacheModel("xmodel/head_german_normandy_christoph");
	precacheModel("xmodel/head_german_normandy_ericp");
	precacheModel("xmodel/viewmodel_hands_german_winter");
}