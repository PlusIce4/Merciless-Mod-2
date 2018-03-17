/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

ObitSpawnPlayer(attacker)
{
// If the person killed had a killing spree, 
// then notify the players that it has been ended
//	if(self.killspree > 5 && isPlayer(attacker) && isAlive(attacker))			
//		iprintln(attacker.name + " ^7put and end to " + self.name + "'s ^7 killing spree!");	

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