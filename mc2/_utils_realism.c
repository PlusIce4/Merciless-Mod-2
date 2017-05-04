/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Tally, Bell, Merciless Mod Team */
/* Script Code Snippets: Matthias Lorenz */
/* Realism Utils: sHitLoc, viewshift, nozombie */

viewShift( severity, attacker )
{
	if( isPlayer( attacker ) && self.pers["team"] == attacker.pers["team"] )
		return;
		
  	if( !isDefined( severity ) || severity < 3 ) 
		severity = randomint(10)+5;
  	else 
		severity = int( severity );
		
  	if( severity > 45 ) 
		severity = 45;
		
  	pShift = randomint( severity );
  	yShift = randomint( severity );
	
  	self setPlayerAngles( self.angles + ( pShift, yShift, 0 ) );
}

DropOnHit( sHitLoc )
{
	
	if( isAlive( self ) )
	{	
		weap = self getCurrentWeapon();
		switch( sHitLoc )
		{
			case "right_hand":
			case "left_hand":
			if( level.droponhandhit != 0 && randomInt( 100 ) < level.droponarmhit ) self DropItem( weap );
			break;
			
			case "right_arm_lower":
			case "left_arm_lower":
			if( level.droponarmhit != 0 && randomInt( 100 ) < level.droponarmhit ) self DropItem( weap );
			break;
	
			case "right_foot":
			case "left_foot":
			if( level.triponfoothit && randomInt( 100 ) < level.triponfoothit ) self ExecClientCommand( "gocrouch" );
			break;

			case "right_leg_lower":
			case "left_leg_lower":
			if( level.triponleghit && randomInt( 100 ) < level.triponleghit ) self ExecClientCommand( "gocrouch" );
			break;
		}
	}
}
getHitLocTag(sHitLoc) //credits: Merciless Mod Team
{
	switch(sHitloc)
	{
		case "right_hand":
			return "j_wrist_ri";
		case "left_hand":
			return "j_wrist_le";	
		case "right_arm_upper":	
			return "j_shoulder_ri";
		case "left_arm_upper":
			return "j_shoulder_le";
		case "right_arm_lower":	
			return "j_elbow_ri";
		case "left_arm_lower":
			return "j_elbow_le";
		case "head":
			return "J_Head";
		case "neck":
			return "J_Neck";			
		case "right_foot":
			return "j_ankle_ri";
		case "left_foot":
			return "j_ankle_le";
		case "right_leg_lower":
			return "j_knee_ri";
		case "left_leg_lower":
			return "j_knee_le";
		case "right_leg_upper":
			return "j_hip_ri";					
		case "left_leg_upper":
			return "j_hip_le";
		case "torso_upper":
			switch(randomint(2))
			{
				case 0:
					return "J_Clavicle_RI";
				case 1:
					return "J_Clavicle_LE";
			}		
		case "torso_lower":
			switch(randomint(3))
			{
				case 0:
					return "J_Spine1";
				case 1:
					return "J_Spine2";
				case 2:
					return "J_Spine3";
			}
		case "none":
		default:
			return "J_MainRoot";
	}
}
nozombie() //credits: Merciless Mod Team
{
	for(;;)
	{
		wait .05;
		player = getentarray("player", "classname");
		for(i = 0; i < player.size; i++)
		{
			h=player[i].health;	
			if(h<0)
			{
				player[i].suicide=1;
				player[i] suicide();
				break;
			}
		}
	}
}
hitloc(sHitLoc)
{
	switch(sHitLoc)
	{
	case "right_hand":
	case "left_hand":
		return "hand";
	case "right_arm_upper":	
	case "right_arm_lower":	
	case "left_arm_upper":
	case "left_arm_lower":
		return "arm";
	case "head":
	case "helmet":
		return "head";
	case "neck":
		return "neck";
	case "right_foot":
	case "left_foot":
		return "foot";
	case "right_leg_lower":
	case "left_leg_lower":
	case "right_leg_upper":
	case "left_leg_upper":
		return "leg";
	case "torso_upper":
		return "torso_up";
	case "torso_lower":
		return "torso_dn";
	default:
		return "none";
	}
}
scream(t) //credits: Merciless Mod Team
{

	self endon("TimeToDie");
	self.scr = 1;
	if( randomint(100) > 40 || t == "mc" || t == "fc" || t == "p" || t == "h")
	{
		if(t == "f")
			self playsound("nikita_scream");
		else if(t == "m")
			self playsound("mc_scream");
		else if(t == "mc")
			self playsound("mchoke");
		else if(t == "fc")
			self playsound("fchoke");
		else if(t == "p")
			self playsound("puker");
		else if(t == "h")
			self playsound("heave");
		else if(t == "n")
			self playsound("pain");
	}
	else
	{
		self playsound (self.painsound);
	}
	wait 2;
	if(isAlive(self))
		self.scr = undefined;
}
forceto(a) //credits: Merciless Mod Team, Matthias Lorenz
{
	if(a=="stand")
	{
		self openmenunomouse("stand");
		wait .05;
		self closeMenu();	
	}
	else if(a=="crouch"||a=="duck")
	{
		self openmenunomouse("crouch");
		wait .05;
		self closeMenu();	
	}
	else
	{

		self openmenunomouse("prone");
		wait .05;
		self closeMenu();
	}
}