/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team, Bell */
/* Script Code Snippets: PlusIce */
/* Medbags */

/* Note: Check to see if it plants right */

#include mc2\_utils_cvardef;
#include mc2\_utils_origins;
#include mc2\_utils_spawn;

init()
{
	level.mc2_medbags		= cvardef("mc2_medbags", 1, 0, 1, "int");
	level.mc2_medbag_count = cvardef("mc2_medbag_count", 2, 0, 999, "int");
	level.mc2_medbag_limit = cvardef("mc2_medbag_limit", 999, 0, 999, "int");


	if(!level.mc2_medbags) 
		return;
		
	level.picked_health=(&"MC2_PICKED_HEALTH");
	precacheString(level.picked_health);
	precacheItem("item_health_small");
	precacheModel("xmodel/health_medium");

	// Set up object queue
	level.objectQ["healthpack"] = [];
	level.objectQcurrent["healthpack"] = 0;
	level.objectQsize["healthpack"] = 16;
	
	monitorHotKey();
}
monitorHotKey()
{
	if( !level.mc2_medbag ) return;
	
	self endon( "disconnect" );

	for( ;; )
	{
		self waittill( "menuresponse", menu, response );
		
		if( response == "mbutton" )
		{
			if( level.mc2.medbag_count ) && ( level.mc2_medbag_limit)
			{
				self thread dropHealth(alive);
			}	
			if( level.mc2_medbag_count) && ( !level.mc2.medbag_limit)
			{
				self iprintlnBold( "Max Number of Medbags on Map Reached );	
			
			}
			else
				self iprintlnBold( "This feature is disabled" );	
			
		}
	}

}
dropHealth(alive)
{	
	//Offset to land on ground	
	offset = -4;	

/* Delete Later
	// Use an offset if an alive player drops health
	if(isdefined(alive))
		offset = maps\mp\_utility::vectorScale(anglestoforward(self.angles), 40 ) + (0,0,32);
	else
		offset = maps\mp\_utility::vectorScale(anglestoforward(self.angles + (0,-90 + randomInt(2)*180,0)), 10 + randomInt(8) ) + (0,0,32);
*/
	
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
/* Load this if it doesn't plant right */
MedBagFindGround(position)
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
		level.mc2_allplayers = getentarray("player", "classname");
		// Loop through all players
		for(i=0;i<level.mc2_allplayers.size;i++)
		{
			// Check that player still exist
			if(isDefined(level.mc2_allplayers[i]))
				player = level.mc2_allplayers[i];
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
