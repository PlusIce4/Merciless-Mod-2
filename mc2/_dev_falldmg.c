/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell */
/* Script Code Snippets: */
/* Fall Damage */

#include mc2\_utils_cvardef;

init()
{
	level.mc2_falldamage = cvardef("mc2_falldamage", 0, 0, 1, "int");
	if(!level.mc2_falldamage) return;

	level.mc2_minfallheight = cvardef("mc2_minfallheight",256,1,1000,"int");
	level.mc2_maxfallheight = cvardef("mc2_maxfallheight",480,level.mc2_minfallheight,1000,"int");

	setcvar("bg_fallDamageMinHeight", level.mc2_minfallheight);
	setcvar("bg_fallDamageMaxHeight", level.mc2_maxfallheight); 
} 