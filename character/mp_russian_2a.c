/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Updated on July 2015 by PlusIce
Merciless Gore Mod removed
Russian Coats
-------------------------------------------*/
main()
{
	if(isdefined(self.pers["pClass"]))
	{
		switch(self.pers["pClass"])
		{
			case "medic":
				self.bodymodel="xmodel/playerbody_russian_medic";
				self.headmodel="xmodel/head_russian_winter_datien";
				self.hatModel ="xmodel/helmet_russian_medic";
				break;
			case "engineer":
			case "soldier":
			case "sniper":
			case "support":
			default:
				self.bodyModel="xmodel/playerbody_russian_coat03";
				self.headmodel="xmodel/head_russian_winter_jesse";
				self.hatModel ="xmodel/helmet_russian_trench_c_hat";
				break;
		}
	}

	zahl=randomint(6);
	if(zahl==0)zahl=1;

	self.painsound="generic_pain_russian_"+zahl;
	self.deathsound="generic_death_russian_"+zahl;
	self.bleedpain = "generic_pain_russian_"+zahl;
	self.nationality = game["allies"];
	self.body_gib="xmodel/blood_chunk2";
	self setModel(self.bodyModel);
	self attach(self.headmodel,"",true);
	self attach(self.hatModel,"",true);
	self setViewmodel("xmodel/viewmodel_hands_russian");
}

precache()
{
	precacheModel("xmodel/playerbody_russian_medic");
	precacheModel("xmodel/head_russian_winter_datien");
	precacheModel("xmodel/helmet_russian_medic");
	precacheModel("xmodel/playerbody_russian_coat03");	
	precacheModel("xmodel/head_russian_winter_jesse");
	precacheModel("xmodel/helmet_russian_trench_c_hat");
	precacheModel("xmodel/viewmodel_hands_russian");
	precacheModel("xmodel/blood_chunk2");
}