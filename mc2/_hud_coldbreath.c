/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell */
/* Script Code Snippets: */
/* HUD Coldbreath Script */

#include mc2\_utils_cvardef;

init()
{
	// Cold breath
	level.mc2_coldbreath		= cvardef("mc2_cold_breath", 0, 0, 1, "int");

	if(!level.mc2_coldbreath || !level.mc2_wintermap) return;

	// Load breath fx
	level.mc2_breathfx = loadfx ("fx/misc/cold_breath.efx");
}

RunOnSpawn()
{
	if(!level.mc2_coldbreath || !level.mc2_wintermap) return;

	self thread breath_fx();
}

breath_fx()
{
	self endon("mc2_killthreads");

	wait (2 + randomint(3));

	while(isalive(self) && self.sessionstate == "playing")
	{
		playfxontag (level.mc2_breathfx, self, "J_Head");
		wait randomfloatrange(1.5,3.5);
	}
}

