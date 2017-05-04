#include "ui_mp/menudef.h"

#define ORIGIN_SETTINGS		20 -15
#define HELP_ORIGIN		0 5
#define GLOBAL_TEXTSCALE	0.25
#define GLOBAL_TEXTSCALE3	0.25

{
	// Server Creation //
	menuDef 
	{
		name			"createserver"
		fullscreen		0    	
		rect			0 0 640 70	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0
		
		onEsc  
		{
			close createserver;
		}

		onOpen 
		{
			//setitemcolor backcolor 0 0 0 1 ;		 
			uiScript loadArenas ;	
			open createserver_buttons;
			open createserver_maps;	
			open createserver_serversettings;

			setdvar ui_background "background_american_w";
			setdvar ui_logo_show "1";
			setdvar ui_version_show "1";
			setdvar ui_separator_show "1";
			setdvar ui_background_gradient_show "1";
		}
		
		onClose
		{
			close settings_dm;
			close settings_tdm;
			close settings_sd;
			close settings_hq;
			close settings_hqt;
			close settings_ctf;
			close createserver_maps;
			close createserver_buttons;
			close createserver_serversettings;
			open main_text;
		}
#include "ui_mp/menu_background2.menu"
	itemDef
	{
		type			ITEM_TYPE_TEXT
		origin			35 64
		forecolor		1 1 1 1
		text			"@MENU_START_NEW_SERVER"
		textfont		UI_FONT_NORMAL
		textscale		HEADER_SIZE
		visible			1
		decoration
	}

	}
	menuDef
	{
		name			"createserver_opa"
		fullscreen		0    	
		rect			0 0 400 410	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0
		onOpen 
		{
			hide button_gametypesettings;
			show button_serversettings;
			show serversettings
		}

		onEsc  
		{
			close createserver;
		}

		






	}
	menuDef
	{
		name			"createserver_maps"
		fullscreen		0    	
		rect			404 137 200 280	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0

		onEsc  
		{
			close createserver;
		}
		itemDef 
		{
			name			mappreview
			style			0
			ownerdraw		UI_STARTMAPCINEMATIC
			rect			405 130 191 142
			border			0
			bordercolor		.5 .5 .5 .5
			origin			-404 -135
			visible			1
			decoration
		}

		// bottom left map selection border image

		itemDef 
		{
			name			maplist
			rect			404 271 192 130
			type			ITEM_TYPE_LISTBOX
			style			WINDOW_STYLE_FILLED
			elementwidth		119
			elementheight		20
			origin			-405 -135
			textfont		UI_FONT_NORMAL
			textscale		GLOBAL_TEXTSCALE
			elementtype		LISTBOX_TEXT
			feeder			FEEDER_ALLMAPS
			textstyle		6
			textaligny		-5
			border			1
			bordercolor		.5 .5 .5 .5
			forecolor		1 1 1 1
			backcolor		0 0 0 .6
			outlinecolor		.1 .1 .7 .5
			visible			1
			columns			1 2 190 25
			
			mouseEnter 
			{
				//fadein message_arena ;	
//				play "mouse_over";
			}
			mouseExit 
			{
				//fadeout message_arena ; 
				setitemcolor maplist bordercolor .5 .5 .5 .5
			} 
		}
}

	menuDef
	{
		name			"createserver_buttons"
		fullscreen		0    	
		rect			0 415 640 100	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0
		onOpen 
		{
			hide button_gametypesettings;
			show button_serversettings;
		}
		onEsc  
		{
			close createserver;
		}
		//	BACK AND NEXT BUTTONS	//

		itemDef 
		{
			name			back
			text			"@MENU_BACK"
			type			1
			style			UI_BUTTON_STYLE
			textstyle		UI_BUTTON_TEXT_STYLE
			rect			40 0 70 22 
			textfont		UI_FONT_NORMAL
			textalign		0
			border			UI_BUTTON_BORDER
			bordercolor		UI_BUTTON_BORDER_COLOR
			textscale		.35	
			textalignx		0
			textaligny		18
			forecolor		UI_BUTTON_TEXT_COLOR
			backcolor		UI_BUTTON_BACK_COLOR
			visible			1
			//border		1
			//bordercolor		1 1 1 1
			mouseEnter		{ setitemcolor back backcolor UI_BUTTON_BACK_COLOR_HOVER; play "mouse_over"; }
			mouseExit		{ setitemcolor back backcolor UI_BUTTON_BACK_COLOR }
			
			action 
			{
				play "mouse_click";
				close createserver;
			}	
		}
		itemDef 
		{
			name			button_serversettings
			//group			serversettings
			text			"@MENU_GAME_TYPE_SETTINGS"
			type			1
			textfont		UI_FONT_NORMAL
			textscale		.35
			style			UI_BUTTON_STYLE
			textstyle		UI_BUTTON_TEXT_STYLE
			//background		"ui_mp/assets/button_back.tga"
			rect			245 0 140 22
			textalign		0
			textalignx		0
			textaligny		18
			forecolor		UI_BUTTON_TEXT_COLOR
			backcolor		UI_BUTTON_BACK_COLOR 
			bordercolor		UI_BUTTON_BORDER_COLOR 
			border			UI_BUTTON_BORDER
			visible			1
			dvar			"ui_netGametypeName"
			action	
			{ 
				hide button_serversettings; 
				show button_gametypesettings; 
				close createserver_serversettings;
				openForGameType "settings_%s";
				play "mouse_click" ; 
			}
			mouseEnter		{ setitemcolor button_serversettings backcolor UI_BUTTON_BACK_COLOR_HOVER ; play "mouse_over"} 
			mouseExit		{ setitemcolor button_serversettings backcolor UI_BUTTON_BACK_COLOR } 
		}

		itemDef 
		{
			name			button_gametypesettings
			text			"@MENU_SERVER_SETTINGS"
			type			1
			textfont		UI_FONT_NORMAL
			textscale		.35
			style			UI_BUTTON_STYLE
			textstyle		UI_BUTTON_TEXT_STYLE
			rect			245 0 140 22
			textalign		0
			textalignx		0
			textaligny		18
			forecolor		UI_BUTTON_TEXT_COLOR
			backcolor		UI_BUTTON_BACK_COLOR 
			bordercolor		UI_BUTTON_BORDER_COLOR 
			border			UI_BUTTON_BORDER
			visible			1
			//action		{ play "mouse_click" ; close dm ; hide button_gametypesettings" ; show serversettings}
			mouseEnter		{ setitemcolor button_gametypesettings backcolor UI_BUTTON_BACK_COLOR_HOVER ; play "mouse_over"} 
			mouseExit		{ setitemcolor button_gametypesettings backcolor UI_BUTTON_BACK_COLOR} 
			dvar			"ui_netGametypeName"
			action 
			{
				//close settings_dm;
				closeForGameType "settings_%s";
				open createserver_serversettings;
				hide button_gametypesettings;
				show button_serversettings;

				play "mouse_click" ; 
			}	
		}
		
		//	next	//

		itemDef 
		{
			name			accept
			text			"@MENU_START"
			type			1
			textfont		UI_FONT_NORMAL
			style			UI_BUTTON_STYLE	
			textstyle		UI_BUTTON_TEXT_STYLE
			rect			550 0 70 22 
			textalign		0
			textscale		.35		
			textalignx		0
			textaligny		18
			border			UI_BUTTON_BORDER
			bordercolor		UI_BUTTON_BORDER_COLOR
			forecolor		UI_BUTTON_TEXT_COLOR
			backcolor		UI_BUTTON_BACK_COLOR
			visible			1
			//border		1
			//bordercolor		1 1 1 1
			mouseEnter		{ setitemcolor accept backcolor UI_BUTTON_BACK_COLOR_HOVER;play "mouse_over"; }
			mouseExit		{ setitemcolor accept backcolor UI_BUTTON_BACK_COLOR }
	
			action 
			{
				play "mouse_click";
				uiScript StartServer
			}	
		}
	}
	menuDef 
	{
		name			"createserver_serversettings"
		fullscreen		0
		rect			0 2 370 400	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0
		onEsc  
		{
			close createserver;
		}
		itemDef 
		{
			name			heading_server
			text			"@MENU_SERVER_SETTINGS"
			textscale		.35
			group			grpControlbutton
			type			ITEM_TYPE_BUTTON
			style			0
			rect			52.5 -15 120 10
			origin			OPTIONS_ITEM_ORIGIN
			textalign		1
			textalignx		75
			textaligny		10
			forecolor		0.75 0.75 0.75 1
			visible			1
			decoration 
		}
		//	SETTINGS	//

		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_BUTTON
			textfont		UI_FONT_NORMAL
			text			"@MENU_GAME_TYPE"
			rect			0 0 1 13 
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_ITEM_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1  
			decoration

		}
		itemDef 
		{
			name			expert
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_BUTTON
			text			"@MENU_SERVER_NAME"
			rect			0 15 1 13 
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_ITEM_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1  
			decoration

		}
		itemDef 
		{
			name			normal
			group			serversettings
			type			ITEM_TYPE_BUTTON
			textfont		UI_FONT_NORMAL
			text			"@MENU_DEDICATED"
			rect		0 30 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		// 	EXPERT	//	

		itemDef 
		{
			name			normal
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_BUTTON
			text			"@MENU_PURE"
			rect		0 45 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_BUTTON
			textfont		UI_FONT_NORMAL
			text			"@MENU_MAXIMUM_PLAYERS"
			rect		0 60 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef 
		{
			name			expert
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_BUTTON
			text			"@MENU_MINIMUM_PING"
			rect		0 75 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef 
		{
			name			expert
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_BUTTON
			text			"@MENU_MAXIMUM_PING"
			rect		0 90 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_BUTTON
			textfont		UI_FONT_NORMAL
			text			"@MENU_MAXIMUM_RATE"
			rect		0 105 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}
		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_BUTTON
			text			"@MENU_VOICE_CHAT"
			textfont		UI_FONT_NORMAL
			rect		0 120 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}
		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_BUTTON
			text			"@MENU_PASSWORD1"
			textfont		UI_FONT_NORMAL
			rect		0 135 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}
		itemDef
		{
			group			serversettings
			text			"@MENU_FRIENDLY_INDICATORS"
			type			ITEM_TYPE_BUTTON
			rect		0 150 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef
		{
			group			serversettings
			text			"@MENU_FRIENDLY_FIRE"
			type			ITEM_TYPE_BUTTON
			rect		0 165 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_BUTTON
			text			"@MENU_FORCE_RESPAWNING"
			rect		0 180 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_BUTTON
			text			"@MENU_KILLCAM"
			rect		0 195 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}

		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_BUTTON
			text			"@MENU_AUTOBALANCE_TEAMS"
			rect		0 210 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}
		
		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_BUTTON
			text			"@MENU_ALLOW_VOTING"
			rect		0 225 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration

		}
		itemDef
		{
			type			ITEM_TYPE_BUTTON
			text			"@MENU_ALLOW_ENEMY_SPECTATING"
			rect		0 240 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration
		}
		
		itemDef
		{
			type			ITEM_TYPE_BUTTON
			text			"@MENU_ALLOW_FREE_SPECTATING"
			rect		0 255 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration
		}

		itemDef
		{
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_PUNKBUSTERWITHCOLON"
			rect		0 270 1 13 
			origin OPTIONS_ITEM_ORIGIN
			textstyle	OPTIONS_ITEM_TEXT_STYLE
			textalign	OPTIONS_ITEM_ALIGN
			textalignx	OPTIONS_ITEM_ALIGN_X 
			textaligny	OPTIONS_ITEM_ALIGN_Y
			textscale	OPTIONS_CONTROL_TXTSCALE
			style		WINDOW_STYLE_FILLED
			backcolor	OPTIONS_CONTROL_BACKCOLOR
			forecolor	OPTIONS_CONTROL_FORECOLOR
			visible		1  
			decoration
		}





/* Actual Binds */






		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_MULTI
			origin			ORIGIN_SETTINGS
			textfont		UI_FONT_NORMAL
			text			" "
			//dvar			"g_subGameType"
			//dvarfloatlist		{ "Normal" 0 "Stopwatch" 1 "Capture Flag" 2 }
			ownerdraw		UI_NETGAMETYPE
			rect			0 0 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_game_type ; play "mouse_over"}
			mouseExit		{ hide message_game_type }
		}
		itemDef 
		{
			name			expert
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_EDITFIELD
			text			" "
			dvar			"sv_hostname"
			maxChars		32
			maxPaintChars		15
			rect			0 15 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_hostname ; play "mouse_over"}
			mouseExit		{ hide message_hostname }
		}
		itemDef 
		{
			name			normal
			group			serversettings
			type			ITEM_TYPE_MULTI
			textfont		UI_FONT_NORMAL
			text			" "
			// syntax for this is dvar name followed by a semicolan separated list of choices first choice equals 0
			// dedicated is a special dvar in that as soon as it is set, the game goes to console only so the ui catches this one specifically
			dvar			"ui_dedicated"
			dvarFloatList		{ "@MENU_NO" 0 "@MENU_LAN" 1 "@MENU_INTERNET" 2 }
			rect			0 30 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click" }
			mouseEnter		{ show message_dedicated ; play "mouse_over"}
			mouseExit		{ hide message_dedicated }
		}


		itemDef 
		{
			name			normal
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_YESNO
			text			" "
			dvar			"sv_pure"
			rect			0 45 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_pure_server ; play "mouse_over"}
			mouseExit		{ hide message_pure_server }
		}

		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_NUMERICFIELD
			textfont		UI_FONT_NORMAL
			text			" "
			dvar			"sv_maxclients"
			maxChars		3
			rect			0 60 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_maximum_players ; play "mouse_over"}
			mouseExit		{ hide message_maximum_players }
		}

		itemDef 
		{
			name			expert
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_NUMERICFIELD
			text			" "
			dvar			"sv_minping"
			maxChars		4
			rect			0 75 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_minimum_ping ; play "mouse_over"}
			mouseExit		{ hide message_minimum_ping }
		}

		itemDef 
		{
			name			expert
			group			serversettings
			textfont		UI_FONT_NORMAL
			type			ITEM_TYPE_NUMERICFIELD
			text			" "
			maxChars		4
			dvar			"sv_maxping"
			rect			0 90 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_maximum_ping ; play "mouse_over"}
			mouseExit		{ hide message_maximum_ping }
		}

		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_NUMERICFIELD
			textfont		UI_FONT_NORMAL
			text			" "
			maxChars		8
			dvar			"sv_maxrate"
			rect			0 105 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_max_rate ; play "mouse_over"}
			mouseExit		{ hide message_max_rate }
		}
		itemDef 
		{
			name			expert
			group			serversettings
			type			ITEM_TYPE_YESNO
			text			" "
			textfont		UI_FONT_NORMAL
			dvar			"sv_voice"
			rect			0 120 OPTIONS_BIND_SIZE
			maxChars		12
			maxPaintChars		12
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over"}
			action			{ play "mouse_click"; }
		}
		itemDef 
		{
			name			expert
			group			serversettings
			type			4
			text			" "
			textfont		UI_FONT_NORMAL
			dvar			"g_password"
			rect			0 135 OPTIONS_BIND_SIZE
			maxChars		12
			maxPaintChars		12
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			action			{ play "mouse_click"; }
			mouseEnter		{ show message_password ; play "mouse_over"}
			mouseExit		{ hide message_password } 
		}
		itemDef
		{
			group			serversettings
			text			" "
			type			ITEM_TYPE_YESNO
			rect			0 150 OPTIONS_BIND_SIZE
			dvar			"scr_drawfriend"
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			group			serversettings
			text			" "
			type			ITEM_TYPE_MULTI
			dvar			"scr_friendlyfire"
			dvarFloatList		{ "@MENU_OFF" 0 "@MENU_ON" 1 "@MENU_REFLECT" 2 "@MENU_SHARED" 3 }
			rect			0 165 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_YESNO
			text			" "
			dvar			"scr_forcerespawn"
			visible			1
			rect			0 180 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_YESNO
			text			" "
			dvar			"scr_killcam"
			rect			0 195 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_YESNO
			text			" "
			dvar			"scr_teambalance"
			rect			0 210 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}
		
		itemDef
		{
			group			serversettings
			type			ITEM_TYPE_YESNO
			text			" "
			dvar			"g_allowvote"
			rect			0 225 OPTIONS_BIND_SIZE
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}
		itemDef
		{
			type			ITEM_TYPE_YESNO
			text			" "
			rect			0 240 OPTIONS_BIND_SIZE
			dvar			"scr_spectateenemy"
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}
		
		itemDef
		{
			type			ITEM_TYPE_YESNO
			text			" "
			rect			0 255 OPTIONS_BIND_SIZE
			dvar			"scr_spectatefree"
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			type			ITEM_TYPE_YESNO
			text			" "
			rect			0 270 OPTIONS_BIND_SIZE
			dvar			"sv_punkbuster"
			origin			OPTIONS_ITEM_ORIGIN
			textstyle		OPTIONS_ITEM_TEXT_STYLE
			textalign		OPTIONS_ITEM_ALIGN
			textalignx		OPTIONS_BIND_ALIGN_X 
			textaligny		OPTIONS_ITEM_ALIGN_Y
			textscale		OPTIONS_CONTROL_TXTSCALE
			style			WINDOW_STYLE_FILLED
			backcolor		OPTIONS_CONTROL_BACKCOLOR
			forecolor		OPTIONS_CONTROL_FORECOLOR
			visible			1 
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}





	}



}
