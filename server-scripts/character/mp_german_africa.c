/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Updated on July 2015 by PlusIce
Merciless Gore Mod removed
Unneeded braces gone
-------------------------------------------*/
main()
{
	if(isdefined(self.pers["pClass"]))
	{
		switch(self.pers["pClass"])
		{
		case "medic":
			self.bodymodel="xmodel/german_medic_afrika";
			self.headModel="xmodel/head_german_afrca_eric";
			self.hatModel = "xmodel/helmet_german_medic_afrika";
			break;
		case "engineer":
		case "soldier":
		case "sniper":
		case "support":
		default:
			self.bodyModel="xmodel/playerbody_german_africa01";;
			self.headmodel = codescripts\character::randomElement(head());
			self.hatModel = "xmodel/helmet_german_africa";
			break;
		}
	}
	zahl=randomint(3);
	if(zahl==0)zahl=1;
	self.painsound="generic_pain_german_"+zahl;
	self.deathsound="generic_death_german_"+zahl;
	self.bleedpain = "gbleedpain";
	self.nationality=game["axis"];
	self.body_gib="xmodel/blood_chunk2";

	self setModel(self.bodyModel);
	self attach(self.headmodel,"",true);
	self attach(self.hatModel,"",true);
	self setViewmodel("xmodel/viewmodel_hands_british_bare");

}

precache()
{
	precacheModel("xmodel/german_medic_afrika");
	precacheModel("xmodel/helmet_german_medic_afrika");
	precacheModel("xmodel/playerbody_german_africa01");
	codescripts\character::precacheModelArray(head());
	
	precacheModel("xmodel/head_german_afrca_eric");
	precacheModel("xmodel/helmet_german_africa");
	precacheModel("xmodel/viewmodel_hands_british_bare");
	precacheModel("xmodel/blood_chunk2");
}

head()
{
	a[0] = "xmodel/head_german_afrca_christoph";
//	a[1] = "xmodel/head_german_afrca_josh";
	return a;
}