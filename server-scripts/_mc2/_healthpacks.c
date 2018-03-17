/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_putinq;
#include _mc2\_cd;

init()
{
	level.awe_healthpacks		= cvardef("awe_healthpacks", 0, 0, 1, "int");

	if(!level.awe_healthpacks) 
		return;
		
	level.picked_health=(&"MC2_PICKED_HEALTH");
	precacheString(level.picked_health);
	precacheItem("item_health_small");
	precacheModel("xmodel/health_medium");

	// Set up object queue
	level.objectQ["healthpack"] = [];
	level.objectQcurrent["healthpack"] = 0;
	level.objectQsize["healthpack"] = 16;
}
dropHealth(alive)
{
	if(!level.awe_healthpacks) 
		return;

	// Use an offset if an alive player drops health
	if(isdefined(alive))
		offset = maps\mp\_utility::vectorScale(anglestoforward(self.angles), 40 ) + (0,0,32);
	else
		offset = maps\mp\_utility::vectorScale(anglestoforward(self.angles + (0,-90 + randomInt(2)*180,0)), 10 + randomInt(8) ) + (0,0,32);
	
	// Find ground
	origin = FindGround(self.origin + offset);

	// Randomize health
	diff=randomint(100);
	if(diff<=10)
	{
		healthpack = spawn("item_health_large", origin);
		healthpack.angles = (0, randomint(360), 0);
		healthpack thread putinQ("healthpack");	
	}
	else if(diff>10&&diff<=60)
	{
		// Spawn model
		healthpack = spawn("script_model", origin);
		healthpack setModel("xmodel/health_medium");
		healthpack thread healthpack_think(25);	
	}
	else if(diff>60)
	{
		healthpack = spawn("item_health_small", origin);
		healthpack.angles = (0, randomint(360), 0);
		healthpack thread putinQ("healthpack");	
	}
}
FindGround(position)
{
	trace=bulletTrace(position+(0,0,10),position+(0,0,-1200),false,undefined);
	ground=trace["position"];
	return ground;
}

healthpack_think(health)
{
	self endon("healthpack");

	self thread putinQ("healthpack");

	for(;;)
	{
		level.awe_allplayers = getentarray("player", "classname");
		// Loop through all players
		for(i=0;i<level.awe_allplayers.size;i++)
		{
			// Check that player still exist
			if(isDefined(level.awe_allplayers[i]))
				player = level.awe_allplayers[i];
			else
				continue;

			// Player? Alive? Playing? Wounded?
			if(!isPlayer(player) || !isAlive(player) || player.sessionstate != "playing" || player.health==100)
				continue;

			// Check that healthpack still exist
			if(!isdefined(self))
				return;
			
			// Within range?
			distance = distance(self.origin, player.origin);
			if(distance>=20)
				continue;

			// Wounded player in range, let him get some health
			newhealth = player.health + health;
			if(newhealth>100) newhealth = 100;
			player.health = newhealth;

			player iprintln(level.picked_health);

			// Play sound
			player  playsound("health_pickup_medium");

			// Delete healthpack
			self delete();

			// End this thread
			return;
		}
		wait .05;
	}
}
