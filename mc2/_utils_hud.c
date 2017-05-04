/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Tally */
/* Script Code Snippets: */
/* HUD Icon Utils*/

getGrenadeHud( Weapon, defuse )
{
	switch( Weapon )
	{
		case "frag_grenade_american_mp":
			if( isdefined( defuse ) )
				hudIcon = "hud_us_grenade_defuse";
			else
				hudIcon = "gfx/icons/hud@us_grenade_C.tga";
			break;

		case "frag_grenade_british_mp":
			if( isdefined( defuse ) )
				hudIcon = "hud_british_grenade_defuse";
			else
				hudIcon = "gfx/icons/hud@british_grenade_C.tga";
			break;

		case "frag_grenade_russian_mp":
			if( isdefined( defuse ) )
				hudIcon = "hud_russian_grenade_defuse";
			else
				hudIcon = "gfx/icons/hud@russian_grenade_C.tga";
			break;	

		default:
			if( isdefined( defuse ) )
				hudIcon = "hud_german_grenade_defuse";
			else
				hudIcon = "gfx/icons/hud@steilhandgrenate_C.tga";
			break;
	}
	
	return( hudIcon );
}

getLandMineHud( Weapon, defuse )
{
	hudIcon = undefined;
	switch( Weapon )
	{
		case "xmodel/landmine":
			if( isdefined( defuse ) )
				hudIcon = "hud_landmine_defuse";
			else
				hudIcon = "hud_landmine";
			break;
			
		default:
			if( isdefined( defuse ) )
				hudIcon = "hud_tellermine_defuse";
			else
				hudIcon = "hud_tellermine";
			break;
	}
	
	return( hudIcon );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// HUD ELEMENT METHODS ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// CLIENT ELEMENTS ///////////////////////////////////////////////////////

createClientHudElement( hud_element_name, x, y, xAlign, yAlign, horzAlign, vertAlign, foreground, shader, shader_width, shader_height, sort, alpha, color_r, color_g, color_b ) 
{
	if( !isDefined( self.hud ) ) self.hud = [];
	
	self deleteClientHudElementbyName( hud_element_name );

	hud 				= newClientHudElem( self );
	hud.name 			= hud_element_name;
	hud.x 				= x;
	hud.y 				= y;
	hud.alignX 			= xAlign;
	hud.alignY 			= yAlign;
	hud.horzAlign 		= horzAlign;
	hud.vertAlign 		= vertAlign;
	hud.foreground 		= foreground;
	hud.sort 			= sort;
	hud.alpha 			= alpha;
	hud.color 			= (color_r,color_g,color_b);
	hud setShader( shader, shader_width, shader_height );	
	
	self.hud[self.hud.size] = hud;
	
}

changeClientHudElementShaderByName( hud_element_name, shader, shader_width, shader_height ) 
{
	level.ShaderToUse = shader;
	
	if( isDefined( self.hud ) && self.hud.size > 0 ) 
	{
		for( i=0; i < self.hud.size; i++ ) 
		{
			if( isDefined( self.hud[i].name ) && self.hud[i].name == hud_element_name ) 
			{
 				if( isDefined( self.hud[i] ) ) self.hud[i] setShader( level.ShaderToUse, shader_width, shader_height );
				
				break;
			}
		}	
	}
}

ScaleClientHudElementShaderByName( hud_element_name, starttime, endtime, startsize1, startsize2, endsize1, endsize2 ) 
{
	if( isDefined( self.hud ) && self.hud.size > 0 ) 
	{
		for( i=0; i < self.hud.size; i++ ) 
		{
			if( isDefined( self.hud[i].name ) && self.hud[i].name == hud_element_name ) 
			{
				self.hud[i] ScaleOverTime( starttime, startsize1, startsize2 );
				self.hud[i] ScaleOverTime( endtime, endsize1, endsize2 );
			}
		}	
	}
}

deleteClientHudElementbyName( hud_element_name )
{
	if( isDefined( self.hud ) && self.hud.size > 0 ) 
	{
		for(i=0; i < self.hud.size; i++ ) 
		{
			if( isDefined( self.hud[i].name ) && self.hud[i].name == hud_element_name ) 
			{
				self.hud[i] destroy();
				self.hud[i].name = undefined;
			}
		}
		
		new_ar = [];
		
		for( i=0; i < self.hud.size; i++ ) 
		{
			if( isDefined( self.hud[i].name ) ) new_ar[new_ar.size] = self.hud[i];			
		}
		
		self.hud = new_ar;
	}
}

deleteClientHudElements() 
{
	if( isDefined( self.hud ) && self.hud.size > 0 ) 
	{
		for( i=0; i<self.hud.size; i++ ) 
		{
			if( isDefined( self.hud[i].name ) ) 
			{
				self.hud[i] destroy();
				self.hud[i].name = undefined;
			}
		}
	}
 
}

createClientHudTextElement( hud_text_name, x, y, xAlign, yAlign, horzAlign, vertAlign, foreground, sort, alpha, color_r, color_g, color_b, size, text ) 
{
	if( !isDefined( self.txt_hud ) ) self.txt_hud = [];
	
	self deleteHudTextElementbyName( hud_text_name );

	hud 			= newClientHudElem( self );
	hud.name 		= hud_text_name;
	hud.x 			= x;
	hud.y 			= y;
	hud.alignX 		= xAlign;
	hud.alignY 		= yAlign;
	hud.horzAlign 	= horzAlign;
	hud.vertAlign 	= vertAlign;
	hud.foreground 	= foreground;	
	hud.sort 		= sort;
	hud.color 		= ( color_r, color_g, color_b );
	hud.alpha 		= alpha;
	hud.fontScale 	= size;
	hud.font 		= "default";
	hud setText( text );
	
	self.txt_hud[self.txt_hud.size] = hud;
}

deleteClientHudTextElementbyName( hud_text_name )
{
	if( isDefined( self.txt_hud ) && self.txt_hud.size > 0 ) 
	{
		for(i=0; i<self.txt_hud.size; i++ ) 
		{
			if( isDefined( self.txt_hud[i].name ) && self.txt_hud[i].name == hud_text_name ) 
			{
				self.txt_hud[i] destroy();
				self.txt_hud[i].name = undefined;
			}
		}	

		new_ar = [];
		
		for( i=0; i < self.txt_hud.size; i++ ) 
		{
			if( isDefined( self.txt_hud[i].name ) ) new_ar[new_ar.size] = self.txt_hud[i];			
		}
		
		self.txt_hud = new_ar;	
	}
}

deleteClientTextElements() 
{
	if( isDefined( self.txt_hud ) && self.txt_hud.size > 0 ) 
	{
		for( i=0; i < self.txt_hud.size; i++ ) 
		{
			if( isDefined( self.txt_hud[i].name ) ) 
			{
				self.txt_hud[i] destroy();
				self.txt_hud[i].name = undefined;
			}
		}
	}
 
}

//////////////////////////////////////////// LEVEL ELEMENTS //////////////////////////////////////////////

createHudElement( hud_element_name, x, y, xAlign, yAlign, horzAlign, vertAlign, foreground, shader, shader_width, shader_height, sort, alpha, color_r, color_g, color_b ) 
{
	if( !isDefined( level.hud ) ) level.hud = [];

	hud					= newHudElem();
	hud.name 			= hud_element_name;
	hud.x 				= x;
	hud.y 				= y;
	hud.alignX 			= xAlign;
	hud.alignY 			= yAlign;
	hud.horzAlign 		= horzAlign;
	hud.vertAlign 		= vertAlign;
	hud.foreground 		= foreground;
	hud.sort 			= sort;
	hud.color 			= (color_r, color_g, color_b);
	hud.alpha 			= alpha;
	hud setShader( shader, shader_width, shader_height );
	
	level.hud[level.hud.size] = hud;
}

deleteHudElementByName( hud_element_name ) 
{
	if( isDefined( level.hud ) && level.hud.size > 0 ) 
	{
		for( i=0; i < level.hud.size; i++ ) 
		{
			if( isDefined( level.hud[i].name ) && level.hud[i].name == hud_element_name ) 
			{
				level.hud[i] destroy();
				level.hud[i].name = undefined;
			}
		}
		
		new_ar = [];
		
		for( i=0; i < level.hud.size; i++ ) 
		{
			if( isDefined( level.hud[i].name ) ) new_ar[new_ar.size] = level.hud[i];			
		}
		
		level.hud = new_ar;
	}
}

ScaleHudElementByName( hud_element_name, starttime, endtime, startsize1, startsize2, endsize1, endsize2 ) 
{
	if( isDefined( level.hud ) && level.hud.size > 0 ) 
	{
		for( j=0; j < level.hud.size; j++ ) 
		{
			if( isDefined( level.hud[j].name ) && level.hud[j].name == hud_element_name ) 
			{
				level.hud[j] ScaleOverTime( starttime, startsize1, startsize2 );
				level.hud[j] ScaleOverTime( endtime, endsize1, endsize2 );
			}
		}	
	}
}

createHudTextElement( hud_text_name, x, y, xAlign, yAlign, horzAlign, vertAlign, foreground, sort, alpha, color_r, color_g, color_b, size, text ) 
{
	if( !isDefined( level.txt_hud ) ) level.txt_hud = [];

	hud				= newHudElem();
	hud.name 		= hud_text_name;
	hud.x 			= x;
	hud.y 			= y;
	hud.alignX 		= xAlign;
	hud.alignY 		= yAlign;
	hud.horzAlign 	= horzAlign;
	hud.vertAlign 	= vertAlign;
	hud.foreground = foreground;	
	hud.sort 		= sort;
	hud.color 		= ( color_r, color_g, color_b );
	hud.alpha 		= alpha;
	hud.fontScale 	= size;
	hud.font 		= "default";
	hud setText( text );
	
	level.txt_hud[level.txt_hud.size] = hud;
}

deleteHudTextElementbyName( hud_text_name )
{
	if( isDefined( level.txt_hud ) && level.txt_hud.size > 0 ) 
	{
		for( i=0; i < level.txt_hud.size; i++ ) 
		{
			if( isDefined( level.txt_hud[i].name ) && level.txt_hud[i].name == hud_text_name ) 
			{
				level.txt_hud[i] destroy();
				level.txt_hud[i].name = undefined;
			}
		}

		new_ar = [];
		
		for( i=0; i < level.txt_hud.size; i++ ) 
		{
			if( isDefined( level.txt_hud[i].name ) ) new_ar[new_ar.size] = level.txt_hud[i];			
		}
		
		level.txt_hud = new_ar;	
	}
}