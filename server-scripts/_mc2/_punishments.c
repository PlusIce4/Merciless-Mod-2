/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_putinq;

PunishMe(iMethod, sReason)
{
	self endon("awe_killthreads");

	sMethodname = "";

	if(iMethod == 1)
		iMethod = 2 + randomInt(level.awe_punishments);

	switch (iMethod)
	{
		case 2:
			self suicide();
			sMethodname = "killed";
			break;

		case 3:
			wait 0.5;
			// explode 
			playfx(level._effect["bombexplosion"], self.origin);
			wait .05;
			self suicide();
			sMethodname = "blown up";
			break;
		
		case 4:
			// Drop a piano on the player
			level thread DropPiano(self);
			sMethodname = "crushed";
			break;

		case 5 :
			wait 1;
			kick (self getEntityNumber ());
			sMethodname = "kicked";
			break;

		case 6 :
			wait 1;
			self thread freezeMe (60);
			sMethodname = "frozen";
			break;

		default:
			break;
	}
	if(iMethod)
		iprintln(self.name + "^7 is being " + sMethodname + " ^7for " + sReason + "^7.");
}

freezeMe (duration)
{
	self endon ("awe_killthreads");
	self endon ("disconnect");
	self endon ("killed_player");
	
	self freezeControls (true);
	wait duration;
	self freezeControls (false);
}
DropPiano(victim)
{
	level endon("awe_killthreads");

	falltime = 2;
	yaw = victim.angles[1];
	offset = (-25 + randomInt(51), -25 + randomInt(51), 3000);
	piano = spawn("script_model", victim.origin + offset);
	piano setModel("xmodel/" + level.awe_crushmodels[randomInt(level.awe_crushmodels.size)]);
	piano.angles = (0,yaw,0);
	piano show();
	piano moveto(victim.origin, falltime);
	origin = victim.origin;

	deltayaw = -10 + randomInt(21);

	for(i=2;i<falltime*20;i++)
	{
		if(isDefined(victim) && isPlayer(victim) && isAlive(victim))
			victim setOrigin(origin);

		piano.angles = (0,yaw,0);
		yaw += deltayaw;
		wait .05;
	}
	if(isDefined(victim) && isPlayer(victim) && isAlive(victim))
	{
		victim setOrigin(origin);
		if (isPlayer (self))
			victim thread [[level.callbackPlayerDamage]] (self, self, victim.health * 2, 1, "MOD_EXPLOSIVE", "binoculars_mp", undefined, (0, 0, 0), "none", 0);
		else
			victim suicide();
	}
	wait 0.1;
	playfx(level._effect["awe_dustimpact"],origin);
	piano playsound("wood_door_shoulderhit");
	piano thread putinQ("piano");
	wait 45;
	if(isdefined(piano))
	{
//		playfx(level._effect["awe_dustimpact"],origin);
		piano moveto(origin + offset, falltime);
		wait falltime;
		if(isdefined(piano)) piano delete();
	}
}