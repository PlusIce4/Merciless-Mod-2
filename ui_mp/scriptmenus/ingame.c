#include "ui_mp/menudef.h"

#define ORIGIN_TITLE	48 64
#define ORIGIN_CHOICE1	80 84
#define ORIGIN_CHOICE2	80 108
#define ORIGIN_CHOICE3	80 132
#define ORIGIN_CHOICE4	80 156
#define ORIGIN_CHOICE5	80 180

//-[Merciless2]
#define ORIGIN_MENUWINDOW			96 96
#define ORIGIN_MENUTABS				96 64
{
	menuDef
	{
		name			"ingame"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc 
		{
			close ingame;
		}

		// Gradient
		itemDef
		{
			style			WINDOW_STYLE_SHADER
			//rect			-107 0 554 480
			rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN
			background		"gradient"
			visible			1
			decoration
		}

////////////////////////Merciless2
		itemDef
		{
			name			"window_background"
			visible			1
			rect			0 0 448 288
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@ingame_background.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}
// WINDOW BANNER

		itemDef
		{
			name			"window_banner_text"
			visible			1
			rect			9 6 430 24
			origin			ORIGIN_MENUWINDOW
			text			"@MENU_OPTIONS"
			textfont		UI_FONT_BOLD
			forecolor		1 1 1 .5
			textscale		.5
			textalignx		8
			textaligny		24
			textalign		ITEM_ALIGN_LEFT
			decoration
		}
// WINDOW LINES
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			3 0 2 283
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

		itemDef
		{
			name			"window_lines"
			visible			1
			rect			443 0 2 283
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

		itemDef
		{
			name			"window_lines"
			visible			1
			rect			3 283 442 2
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

		itemDef
		{
			name			"window_lines"
			visible			1
			rect			5 0 438 2
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

		itemDef
		{
			name			"window_lines"
			visible			1
			rect			5 34 438 1
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

// MAIN MENU BUTTON
		itemDef
		{
			name			"button_mainmenu"
			visible			1
			rect			0 0 89 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			type			ITEM_TYPE_BUTTON
			text			"@MENU_MAIN_MENU"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		45
			textaligny		24
			textalign		ITEM_ALIGN_CENTER
			action
			{
				play "mouse_click";
				close ingame;
				open main;
			}
			onFocus
			{
				play "mouse_over";					
			}
		}
// EMPTY BUTTON
		itemDef
		{
			name			"button_empty"
			visible			1
			rect			89 0 90 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}
		itemDef
		{
			name			"button_empty"
			visible			1
			rect			179 0 90 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}

		itemDef
		{
			name			"button_empty"
			visible			1
			rect			269 0 90 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}
		itemDef
		{
			name			"button_empty"
			visible			1
			rect			359 0 89 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}

////////////////////////
		
// MENU CHOICES
		execKey "1" { play "mouse_click"; scriptMenuResponse "changeweapon" }
		execKey "2" { play "mouse_click"; scriptMenuResponse "changeclass" }
		execKey "3" { play "mouse_click"; scriptMenuResponse "changeteam" }
		execKey "4" { play "mouse_click"; scriptMenuResponse "muteplayer" }
		execKey "5" { play "mouse_click"; scriptMenuResponse "callvote" }
		execKey "6" { play "mouse_click"; close ingame; open leavegame }
		
		itemDef
		{
			name			"button_changeweapon"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_CHANGE_WEAPON"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_weaponchange"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "changeweapon";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
		itemDef 
		{
			name			"button_changeweapon"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_CHANGE_WEAPON"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_weaponchange"
			hideDvar		{ "1" }
			decoration
		}
		itemDef
		{
			name			"button_changeclass"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_2_CHANGE_CLASS"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
		//	dvartest		"ui_allow_classchange"
		//	showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "changeclass";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
		/*itemDef 
		{
			name			"button_changeclass"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_2_CHANGE_CLASS"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_classchange"
			hideDvar		{ "1" }
			decoration
		}*/
		itemDef 
		{
			name			"button_changeteam"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_CHANGE_TEAM"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			action
			{
				play "mouse_click";
				scriptMenuResponse "changeteam";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
				
		itemDef 
		{
			name			"button_muteplayer"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_MUTE_PLAYERS"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			action
			{
				play "mouse_click";
				scriptMenuResponse "muteplayer";
			}
			onFocus
			{
				play "mouse_over";
			}
		}

		itemDef 
		{
			name			"button_callvote"
			visible			1
			rect			16 126 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_5_CALL_VOTE"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allowvote"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "callvote";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
		itemDef 
		{
			name			"button_callvote"
			visible			1
			rect			16 126 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_5_CALL_VOTE"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allowvote"
			hideDvar		{ "1" }
			decoration
		}

		itemDef 
		{
			name			"button_leavegame"
			
			visible			1
			rect			16 146 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_6_LEAVE_GAME"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			action
			{
				play "mouse_click";
				close ingame;
				open leavegame;
			}
			onFocus
			{
				play "mouse_over";
			}
		}
	}
	
	menuDef
	{
		name			"leavegame"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc 
		{
			close leavegame;
		}
		onOpen 
		{
		}
		onClose
		{
			setfocus button_no;
		}

		// Gradient
		itemDef
		{
			style			WINDOW_STYLE_SHADER
			//rect			-107 0 554 480
			rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN
			background		"gradient"
			visible			1
			decoration
		}

		#include "ui/bars.menu"

		itemDef
		{
			type			ITEM_TYPE_TEXT
			visible			1
			origin			ORIGIN_TITLE
			forecolor		1 1 1 1
			text			"@MPUI_LEAVE_GAME1"
			textfont		UI_FONT_NORMAL
			textscale		GLOBAL_HEADER_SIZE
			decoration
		}

// MENU CHOICES
		execKey "1" { play "mouse_click"; close leavegame; exec "disconnect" }
		execKey "2" { play "mouse_click"; close leavegame; }

		itemDef
		{
			name			"button_yes"
			visible			1
			rect			0 0 128 24
			origin			ORIGIN_CHOICE1
			forecolor		GLOBAL_UNFOCUSED_COLOR
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_YES"
			textfont		UI_FONT_NORMAL
			textscale		GLOBAL_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textaligny		20
			action
			{
				play "mouse_click";
				close leavegame;
				exec "disconnect";
			}
			onFocus
			{
				play "mouse_over";
			}
		}

		itemDef
		{
			name			"button_no"
			visible			1
			rect			0 0 128 24
			origin			ORIGIN_CHOICE2
			forecolor		GLOBAL_UNFOCUSED_COLOR
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_2_NO"
			textfont		UI_FONT_NORMAL
			textscale		GLOBAL_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textaligny		20
			action
			{
				play "mouse_click";
				close leavegame;
			}
			onFocus
			{
				play "mouse_over";
			}
		}

		itemDef 
		{
			#include "ui_mp/button_mainmenu.menu"

			action
			{
				play "mouse_click";
				close leavegame;
				open main;
			}
			onFocus
			{
				play "mouse_over";
			}
		}
	}
}
