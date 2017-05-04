#include "ui_mp/menudef.h"

#define ORIGIN_TITLE		48 64
#define ORIGIN_CHOICE1		80 84
#define ORIGIN_CHOICE2		80 108
#define ORIGIN_CHOICE3		80 132
#define ORIGIN_CHOICE4		80 156

#define ORIGIN_TEAMIMAGE	300 140


//-[Merciless2]
#define ORIGIN_MENUWINDOW			96 96
#define ORIGIN_MENUTABS				96 64
{
	menuDef
	{
		name			"team_americangerman2"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc
		{
			close team_americangerman2;
		}
		onClose
		{
		//	hide autoassign_info;
		//	hide american_info;
		//	hide german_info;
		//	hide spectator_info;
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
//[Merciless2]///////////////////////////////
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
		/*itemDef
		{
			name			"american_info"
			visible			0
			rect			0 0 448 288
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@ingame_american_background.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}

		itemDef
		{
			name			"german_info"
			visible			0
			rect			0 0 448 288
			origin			ORIGIN_MENUWINDOW
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@ingame_german_background.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}*/
// WINDOW BANNER

		itemDef
		{
			name			"window_banner_text"
			visible			1
			rect			9 6 430 24
			origin			ORIGIN_MENUWINDOW
			text			"@MPUI_TEAMS"
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
				close team_americangerman;
				open main;
			}
			onFocus
			{
				play "mouse_over";
			}
		}
// TEAM BUTTON
		itemDef
		{
			name			"button_team"
			visible			1
			rect			89 0 90 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_press.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			text			"@MPUI_TEAMS"
			textfont		UI_FONT_BOLD
			textscale		.24
			textalignx		45
			textaligny		24
			textalign		ITEM_ALIGN_CENTER
			decoration
		}
// EMPTY BUTTON
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
/////////////////////////////////////////////
// MENU CHOICES
		execKey "1" { play "mouse_click"; scriptMenuResponse "autoassign" }
		execKey "2" { play "mouse_click"; scriptMenuResponse "spectator" }

		itemDef 
		{
			name			"button_autoassign"
			visible			1
			rect			16 46 60 60//16 200 160 22
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_AUTOASSIGN"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_joinauto"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "autoassign";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
		itemDef 
		{
			name			"button_autoassign"
			visible			1
			rect			16 46 60 60//16 200 160 22
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_AUTOASSIGN"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_joinauto"
			showDvar		{ "2" }
			onFocus
			{
				play "mouse_over";
			}
		}
		itemDef 
		{
			name			"button_spectate"
			visible			1
			rect			16 66 60 60//16 200 160 22
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_2_SPECTATE"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			action
			{
				play "mouse_click";
				scriptMenuResponse "spectator";
			}
			onFocus
			{
				play "mouse_over";
			}
			mouseEnter		{ show russian_info;}

		}
		//test
		itemDef
		{
			name			"russian_info"
			visible 		0
			//rect			-52 0 288 288
			rect			0 6 224 112
			origin			ORIGIN_TEAMIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_thompson"
		//	decoration
		
			mouseEnter
			{ 
			//	setitemcolor russian_info forecolor 1 1 1 1;
			//	transition russian_info 112 202 160 40 112 202 165 42.5 5 5
			//	transition russian_info -52 0 288 288 -52 0 284 285.5 5 5
				transition "russian_info" 300 140 224 112 300 140 229 114.5 5 5
			//enter/focus	
			//transition "NAME" originX originY rectXalign rectYalign originX originY rectXalign+5 rectYalign+2.5 5 5
			//exit
			//transition "NAME" originX originY rectXalign+5 rectYalign+2.5 originX originY rectXalign rectYalign 5 5
			}
			mouseExit
			{
			//	transition russian_info -52 0 284 285.5 -52 0 288 288 5 5
			//	transition russian_info 112 202 165 42.5 112 202 160 40 5 5
			//	setitemcolor russian_info forecolor .8 .8 .8 .5 ;
			transition russian_info 300 140 229 114.5 300 140 224 112 5 5
			}
		}
	}
}
