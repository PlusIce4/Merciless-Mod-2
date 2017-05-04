#include "ui_mp/menudef.h"

#define GLOBAL_TEXTSCALE	0.25
#define ORIGIN_SETTINGS		5 33

{
	menuDef 
	{
		name			"settings_sd"
		fullscreen		0
		rect			0 2 370 400	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0
		onEsc  
		{
			close createserver;
			close settings_sd;
		}
		itemDef 
		{
			name			heading_gametype
			text			"@MENU_GAME_TYPE_SETTINGS"
			textscale		.35
			group			grpControlbutton
			type			9
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

		itemDef
		{
			type			9
			text			"@MENU_SCORE_LIMIT_TEAM_POINTS"
			rect			0 0 1 13 
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
			type			9
			text			"@MENU_TIME_LIMIT"
			rect			0 15 1 13 
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
			type			9
			text			"@MENU_ROUND_LIMIT"
			rect			0 30 1 13 
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
			type			9
			text			"@MENU_ROUND_LENGTH"
			rect			0 45 1 13 
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
			type			9
			text			"@MENU_GRACE_PERIOD"
			rect			0 60 1 13 
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
			type			9
			text			" "
			dvar			"scr_sd_scorelimit"
			maxChars		4
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

			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			type			9
			text			" "
			dvar			"scr_sd_timelimit"
			maxChars		4
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

			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			type			9
			text			" "
			dvar			"scr_sd_roundlimit"
			maxChars		2
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

			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			type			9
			text			" "
			dvar			"scr_sd_roundlength"
			maxChars		4
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

			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			type			9
			text			" "
			dvar			"scr_sd_graceperiod"
			maxChars		2
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

			mouseEnter		{ play "mouse_over" }
		}

	}
}
