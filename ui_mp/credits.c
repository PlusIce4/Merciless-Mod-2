#include "ui_mp/menudef.h"

{
\\ SETUP MENU \\

	menuDef {
    	name "credits_menu"
    	visible 0
    	fullscreen 0
	rect OPTIONS_WINDOW_POS OPTIONS_WINDOW_SIZE
    	focusColor UI_FOCUS_COLOR
    	style 1
    	border 1
	onOpen
	{ 
		hide grpfinish ;
		hide accept;
		uiScript loadMods
	}
	onEsc
	{
		close mods_menu ; 
		open main 
	}
		itemDef {
			name window
			group grpSystembutton
			rect 100 0 450 350	
			style WINDOW_STYLE_SHADER
			//border 1
			//bordercolor .5 .5 .5 .5
			background "mtl_credits"
			forecolor 1 1 1 0.925
			//backcolor 0 0 0 0.85
			visible 1
			decoration
		}
	}
}

