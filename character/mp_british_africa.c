/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Updated July 2015 by PlusIce
Merciless Gore Mod Removed
Unneeded Braces gone
-------------------------------------------*/
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
	self.body_gib="xmodel/blood_chunk2";

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
	precacheModel("xmodel/blood_chunk2");
}

head()
{
	a[0] = "xmodel/head_british_paul";
	a[1] = "xmodel/head_british_chance";
	return a;
}