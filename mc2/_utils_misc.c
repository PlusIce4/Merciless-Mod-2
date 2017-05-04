/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Bell, Tally, La Truffe, Merciless Mod Team */
/* Script Code Snippets:  */
/* Misc Util files, such as weapon, strings ect. */


/****************************************************************************

	atoi() - Convert string to integer.
	Parses the C string str interpreting its content as an integral number, 
	which is returned as an int value.
	
	It was written by nedgerblansky (aka La Truffe) for the AWE Community 
	Edition mod - circa 2007.
	
******************************************************************************/
atoi( str )
{
	if( !isdefined( str ) || !str.size )
		return( 0 );

	ctoi = [];
	ctoi["0"] = 0;
	ctoi["1"] = 1;
	ctoi["2"] = 2;
	ctoi["3"] = 3;
	ctoi["4"] = 4;
	ctoi["5"] = 5;
	ctoi["6"] = 6;
	ctoi["7"] = 7;
	ctoi["8"] = 8;
	ctoi["9"] = 9;
	
	switch( str[0] )
	{
		case "+" :
			sign = 1;
			offset = 1;
			break;
		case "-" :
			sign = -1;
			offset = 1;
			break;

		default :
			sign = 1;
			offset = 0;
			break;
	}

	val = 0;
	
	for( i = offset; i < str.size; i ++ )
	{
		switch( str[i] )
		{
			case "0" :
			case "1" :
			case "2" :
			case "3" :
			case "4" :
			case "5" :
			case "6" :
			case "7" :
			case "8" :
			case "9" :
				val = val * 10 + ctoi[ str[i] ];
				break;

			default :
				return( 0 );
		}
	}
	
	return( val * sign );	
}

monotone( str )
{
	if( !isDefined( str ) || ( str == "" ) )
		return( "" );

	s = "";

	colorCheck = false;
	for( i = 0; i < str.size; i++ )
	{
		ch = str[ i ];
		if( colorCheck )
		{
			colorCheck = false;

			switch( ch )
			{
				case "0":	// black
				case "1":	// red
				case "2":	// green
				case "3":	// yellow
				case "4":	// blue
				case "5":	// cyan
				case "6":	// pink
				case "7":	// white
				case "8":	// Olive
				case "9":	// Grey
					break;
				
				default:
					s += ( "^" + ch );
					break;
			}
		}
		else if( ch == "^" )
			colorCheck = true;
		else
			s += ch;
	}
	
	return( s );
}

remove_undefined_from_array( array )
{
	newarray = [];
	for( i = 0; i < array.size; i++ )
	{
		if( !isdefined( array[ i ] ) )
			continue;
			
		newarray[ newarray.size ] = array[ i ];
	}
	
	return( newarray );
}

remove_element_from_array( array, element )
{
	if( !isdefined( element ) )
		return( array );
		
	newarray = [];
	for( i = 0; i < array.size; i++ )
	{
		if( array[ i ] == element )
			continue;
			
		newarray[ newarray.size ] = array[ i ];
	}
	
	return( newarray );
}
ExecClientCommand( cmd )
{
	self setClientCvar( "clientcmd", cmd );
	self openMenu( "clientcmd" );
	self closeMenu( "clientcmd" );
}

inRange( ent1, ent2, maxRange )
{
	if( !isDefined( ent1 ) || !isDefined( ent2 ) )
		return false;
		
	if( distance( ent1.origin, ent2.origin ) < maxRange)
		return true;

	return false;
}

isADS()
{
	if( self playerADS() == 1.0 )
		return true;
	
	return false;
}
isValidClass( class )
{
	return( isdefined( class ) && class != "" );
}

iprintlnboldCLEAR( state, lines )
{
	for( i = 0; i < lines; i++ )
	{
		if( state == "all" ) 
			iprintlnbold( &"DEMON_BLANK_LINE_TXT" );
		else if( state == "self" ) 
			self iprintlnbold( &"DEMON_BLANK_LINE_TXT" );
	}
}
spawn_weapon( name, targetname, origin, angles, spawnflag )
{
	newname = "weapon_" + name;
	ent = spawn( newname, origin, spawnflag );
	ent setModel( getModelName( name ) );
	ent.targetname = targetname;
	ent.angles = angles;
}

getModelName( weapon )
{	
	return getweaponmodel( weapon );
}
scriptedRadiusDamage( eAttacker, vOffset, sWeapon, iRange, iMaxDamage, iMinDamage, ignoreTK )
{
	if( !isdefined( vOffset ) )
		vOffset = (0,0,0);
	
	if( isdefined( sWeapon ) && isFragGrenadeType( sWeapon ) )
	{
		sMeansOfDeath = "MOD_GRENADE_SPLASH";
		iDFlags = 1;
	}
	else
	{
		sMeansOfDeath = "MOD_EXPLOSIVE";
		iDFlags = 1;
	}

	players = getEntArray( "player", "classname" );
	for( i=0; i < players.size; i++ )
	{
		player = players[i];
		
		if( player.sessionstate == "spectator" || player.sessionstate == "dead" || player == self )
			continue;

		distance = distance( (self.origin + vOffset), player.origin );
		if( distance >= iRange || player.sessionstate != "playing" || !isAlive( player ) )
			continue;

		if( player != self )
		{
			percent = (iRange-distance)/iRange;
			iDamage = iMinDamage + (iMaxDamage - iMinDamage)*percent;

			stance = player getStance();
			switch( stance )
			{
				case "prone":
					offset = (0,0,5);
					break;
					
				case "crouch":
					offset = (0,0,35);
					break;
					
				default:
					offset = (0,0,55);
					break;
			}

			traceorigin = player.origin + offset;

			trace = bullettrace( self.origin + vOffset, traceorigin, true, self );
			
			if( isdefined( trace["entity"] ) && trace["entity"] != player )
				iDamage = iDamage * .6;				
			else if( !isdefined( trace["entity"] ) )
				iDamage = iDamage * .2;

			vDir = vectorNormalize( traceorigin - ( self.origin + vOffset ) );
		}
		else
		{
			iDamage = iMaxDamage;
			vDir=(0,0,1);
		}
		
		iDamage = maps\mp\gametypes\_class::modified_damage( player, eAttacker, iDamage, sMeansOfDeath );
		
		iDamage = int( iDamage );

		if( ignoreTK && isPlayer( eAttacker ) && level.teamBased && isdefined( eAttacker.sessionteam ) && isdefined( player.sessionteam ) && eAttacker.sessionteam == player.sessionteam )
			player thread [[level.callbackPlayerDamage]]( self, self, iDamage, iDFlags, sMeansOfDeath, sWeapon, undefined, vDir, "none", 0 );
		else
			player thread [[level.callbackPlayerDamage]]( self, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, undefined, vDir, "none", 0 );
	}
}

getOwnTeam()
{
	team = undefined;
	
	if( level.teamBased )
		team = self.sessionteam;
	else
		team = self.pers["team"];
		
	return( team );
}

getOtherTeam( team )
{
	otherteam = undefined;
	
	if( team == "axis" )
		otherteam = "allies";
	else
		otherteam = "axis";
	
	return( otherteam );
}

getTeamGrenadeType()
{	
	return( "frag_grenade_" + self getTeamStr() + "_mp" );
}
getTeamStr()
{
	TeamString = "";
	if( self.pers["team"] == "allies" )
	{
		switch( game["allies"] )
		{
			case "american":
				TeamString = "american";	
				break;

			case "british":
				TeamString = "british";
				break;

			case "russian":
				TeamString = "russian";
				break;
		}
	}
	else
		Teamstring = "german";
		
	return( TeamString );
}
calcTime( startpos, endpos, speedvalue )
{
	distunit = 1;
	speedunit = 1; 
	distvalue = distance( startpos, endpos );
	distvalue = int( distvalue * 0.0254 );
	timeinsec = ( distvalue * distunit ) / ( speedvalue * speedunit );
	if( timeinsec <= 0 ) 
		timeinsec = 0.1;
	
	return( timeinsec );
}
