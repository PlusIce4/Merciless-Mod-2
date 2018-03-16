/*
USAGE OF "cvardef"
cvardef replaces the multiple lines of code used repeatedly in the setup areas of the script.
The function requires 5 parameters, and returns the set value of the specified cvar
Parameters:
	varname - The name of the variable, eg "scr_teambalance"

	vardefault - The default value for the variable.  
		Numbers do not require quotes, but strings do.  i.e.   10, "10", or "wave"

	min - The minimum value if the variable is an "int" or "float" type
		If there is no minimum, use "" as the parameter in the function call

	max - The maximum value if the variable is an "int" or "float" type
		If there is no maximum, use "" as the parameter in the function call

	type - The type of data to be contained in the vairable.
		"int" - integer value: 1, 2, 3, etc.
		"float" - floating point value: 1.0, 2.5, 10.384, etc.
		"string" - a character string: "wave", "player", "none", etc.
		
Ravir's cvardef, with modifications by Bell and Number7
*/
cvardef (varname, vardefault, min, max, type)
{
	mapname = getcvar("mapname");					// eg "mp_dawnville"

	if (isdefined (level.awe_gametype))
		gametype = level.awe_gametype;			// eg "tdm"
	else
		gametype = getcvar ("g_gametype");	// eg "tdm"

	both = gametype + "_" + mapname;			// eg "tdm_mp_dawnville"

	tempvar = varname + "_" + gametype;		// eg "scr_teambalance_tdm"
	if (getcvar (tempvar) != "") 						// if the gametype override is being used
		varname = tempvar; 										// use the gametype override instead of the standard variable

	tempvar = varname + "_" + mapname;		// eg "scr_teambalance_mp_dawnville"
	if (getcvar (tempvar) != "")						// if the map override is being used
		varname = tempvar;										// use the map override instead of the standard variable

	tempvar = varname + "_" + both;				// eg "scr_teambalance_tdm_mp_dawnville"
	if (getcvar (tempvar) != "")						// if the gametype+map override is being used
		varname = tempvar;										// use the gametype+map override instead of the standard variable

	// get the variable's definition
	switch(type)
	{
		case "int":
			if(getcvar(varname) == "")	// if the cvar is blank
				definition = vardefault;	// set the default
			else
				definition = getcvarint(varname);
			break;
		case "float":
			if(getcvar(varname) == "")	// if the cvar is blank
				definition = vardefault;	// set the default
			else
				definition = getcvarfloat(varname);
			break;
		case "string":
		default:
			if(getcvar(varname) == "")	// if the cvar is blank
				definition = vardefault;	// set the default
			else
				definition = getcvar(varname);
			break;
	}

	// if it's a number, with a minimum, that violates the parameter
	if((type == "int" || type == "float") && definition < min)
		definition = min;

	// if it's a number, with a maximum, that violates the parameter
	if((type == "int" || type == "float") && definition > max)
		definition = max;

	return definition;
}