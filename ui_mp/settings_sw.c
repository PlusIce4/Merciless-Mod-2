#include "ui_mp/menudef.h"

#define GLOBAL_TEXTSCALE	0.25
#define ORIGIN_SETTINGS		5 33

{
	menuDef 
	{
		name			"settings_sw"
		fullscreen		0
		rect			5 102 361 278	
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			1
		border			0
		onEsc  
		{
			open main;
			close createserver;
		}

		itemDef
		{
			visible			1
			rect			0 0 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_SCORE_LIMIT_TEAM_POINTS"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_sw_scorelimit"
			maxChars		4
			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			visible			1
			rect			0 15 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_TIME_LIMIT"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_sw_timelimit"
			maxChars		4
			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			visible			1
			rect			0 30 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_ROUND_LIMIT"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_sw_roundlimit"
			maxChars		2
			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			visible			1
			rect			0 45 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_ROUND_LENGTH"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_sw_roundlength"
			maxChars		1
			mouseEnter		{ play "mouse_over" }
		}

		itemDef
		{
			visible			1
			rect			0 60 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_GRACE_PERIOD"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_sw_graceperiod"
			maxChars		2
			mouseEnter		{ play "mouse_over" }
		}
		
		itemDef
		{
			visible			1
			rect			0 75 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_FRIENDLY_INDICATORS"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_drawfriend"
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			visible			1
			rect			0 90 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_FRIENDLY_FIRE"
			dvar			"scr_friendlyfire"
			dvarFloatList		{ "@MENU_OFF" 0 "@MENU_ON" 1 "@MENU_REFLECT" 2 "@MENU_SHARED" 3 }
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			visible			1
			rect			0 105 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_KILLCAM"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_killcam"
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			visible			1
			rect			0 120 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_AUTOBALANCE_TEAMS"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_teambalance"
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			visible			1
			rect			0 135 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_ALLOW_VOTING"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"g_allowvote"
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}

		itemDef
		{
			visible			1
			rect			0 150 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_ALLOW_ENEMY_SPECTATING"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_spectateenemy"
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}
		
		itemDef
		{
			visible			1
			rect			0 165 OPTIONS_CONTROL_SIZE
			origin			ORIGIN_SETTINGS
			forecolor		OPTIONS_CONTROL_FORECOLOR
			backcolor		OPTIONS_CONTROL_BACKCOLOR       
			style			WINDOW_STYLE_FILLED
			textfont		UI_FONT_NORMAL
			type			9
			text			"@MENU_ALLOW_FREE_SPECTATING"
			textalign		ITEM_ALIGN_RIGHT
			textalignx		OPTIONS_CONTROL_XALIGN 
			textaligny		OPTIONS_CONTROL_YALIGN
			textscale		GLOBAL_TEXTSCALE
			dvar			"scr_freelook"
			mouseEnter		{ play "mouse_over" }
			action			{ play "mouse_click" }
		}


	}
}
