/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Orb System */

#include mc2\_utils_cvardef;

init()
{
	if( level.mc2_hardcore ) return;

	level.mc2_orbsys 			= cvardef("mc2_orbsys",1,0,1,"int");
	if(!level.mc2_orbsys) return;
	
	spawnPlayer();
}
spawnPlayer()
{
	if(!level.mc2_orbsys) return;
	
	if( isplayer(attacker) && isAlive(attacker))
	{
		
		if ( (attacker != self) && (getcvar("g_gametype") != "dm") && (attacker.team != self.team) )
		{
			attacker.killspree++;
		}
		if ( (attacker != self) && (getcvar("g_gametype") == "dm")  )
		{
			attacker.killspree++;
		}
	
		rn = randomint(16);
	
		if(attacker != self && isDefined(attacker.team) && isDefined(self.team) && attacker.team != self.team )
		{
			if (attacker.killspree == 2 || attacker.killspree == 3)
			{
				if(attacker.killspree == 3)
					iprintln(attacker.name + &"^7is on a roll with ^1" + attacker.killspree + &"^7 kills!"); //enable again
				rn = randomint(10);
			}
			if (attacker.killspree == 4 || attacker.killspree == 5)
			{
				if(attacker.killspree == 5)
					iprintln(attacker.name + " ^7is on a killing spree with ^1" + attacker.killspree + " ^7 kills!"); //enable again
				rn = randomint(8);
			}
			if (attacker.killspree > 5 && attacker.killspree < 10)
			{	
				if(attacker.killspree == 10)
					iprintln(attacker.name + " ^7is on fire with ^1" + attacker.killspree + " ^7 kills!"); //enable again
				rn = randomint(5);
			}
			if (attacker.killspree >= 10)
			{	
				if(attacker.killspree == 15)
					iprintln(attacker.name + " ^7is unstoppable with ^1" + attacker.killspree + "^7 kills!"); //enable again
				if(attacker.killspree == 20)
					iprintln(attacker.name + " ^7is dominating with ^1" + attacker.killspree + "^7 kills!"); //enable again
				rn = randomint(5);
			}	
		}
	}
}