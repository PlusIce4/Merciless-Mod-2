/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Tally */
/* Script Code Snippets:  */
/* Precache items*/

mc2PrecacheHeadIcon( headicon )
{
	if( !isdefined( level.precachedheadicons ) )
		level.precachedheadicons = [];

	if( isInArray( level.precachedheadicons, headicon ) ) return;
	level.precachedheadicons[ level.precachedheadicons.size ] = headicon;
	
	if( level.precachedheadicons.size > 12 ) return; // return if there is an attempt to precache more than 12 headicons
	
	precacheHeadIcon( headicon );
}

mc2PrecacheStatusIcon( statusicon )
{
	if( !isdefined( level.precachedstatusicon ) )
		level.precachedstatusicon = [];

	if( isInArray( level.precachedstatusicon, statusicon ) ) return;
	level.precachedstatusicon[ level.precachedstatusicon.size ] = statusicon;
	
	if( level.precachedstatusicon.size > 8 ) return; // return if there is an attempt to precahce more than 8 statusicons
	
	precacheStatusIcon( statusicon );
}

mc2PrecacheShader( shader )
{
	if( !isdefined( level.precachedshaders ) )
		level.precachedshaders = [];

	if( isInArray( level.precachedshaders, shader ) ) return;
	level.precachedshaders[ level.precachedshaders.size ] = shader;
	
	precacheShader( shader );
}

mc2PrecacheModel( model )
{
	if( !isdefined( level.precachedmodels ) )
		level.precachedmodels = [];

	if( isInArray( level.precachedmodels, model ) ) return;
	level.precachedmodels[ level.precachedmodels.size ] = model;
	
	precacheModel( model );
}

mc2PrecacheItem( item )
{
	if( !isdefined( level.precacheditems ) )
		level.precacheditems = [];

	if( isInArray( level.precacheditems, item ) ) return;
	level.precacheditems[ level.precacheditems.size ] = item;
	
	precacheItem( item );
}

mc2PrecacheString( element )
{
	if( !isdefined( level.precachedstrings ) )
		level.precachedstrings = [];

	if( isInArray( level.precachedstrings, element )) return;
	level.precachedstrings[ level.precachedstrings.size ] = element;
	
	precacheString( element );
}

isInArray( array, element )
{
	if( !isdefined( array ) || !array.size )
		return false;

	for( i=0; i < array.size; i++ )
	{
		if( array[i] == element )
			return true;
	}

	return false;
}