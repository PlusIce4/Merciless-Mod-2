#include "ui_mp/menudef.h"

#define ORIGIN_TITLE				48 64
#define ORIGIN_CHOICE1				80 84
#define ORIGIN_CHOICE2				80 108
#define ORIGIN_CHOICE3				80 132
#define ORIGIN_CHOICE4				80 156
#define ORIGIN_CHOICE5				80 180
#define ORIGIN_CHOICE6				80 204
#define ORIGIN_CHOICE7				80 228
#define ORIGIN_CHOICE8				80 252

//#define ORIGIN_WEAPONIMAGE			296 84
//#define ORIGIN_WEAPONTEXT			296 220
//#define ORIGIN_WEAPONPROPERTIESTEXT	296 290
//#define ORIGIN_WEAPONACCURACY		395 277
//#define ORIGIN_WEAPONDAMAGE			395 301
//#define ORIGIN_WEAPONMOBILITY		395 325
//#define ORIGIN_GRENADESLOT1			296 144
//#define ORIGIN_GRENADESLOT2			312 144
//#define ORIGIN_GRENADESLOT3			328 144
//#define ORIGIN_GRENADESLOT0			290 144
//#define ORIGIN_GRENADESLOT4			346 144
//#define ORIGIN_GRENADESLOT5			362 144

//-[Merciless2]
#define ORIGIN_MENUTABS				96 64
#define ORIGIN_MENUWINDOW			96 96
#define ORIGIN_WEAPONIMAGE			296 116
#define ORIGIN_WEAPONTEXT			296 220
#define ORIGIN_WEAPONPROPERTIESTEXT		296 330
#define ORIGIN_WEAPONACCURACY			395 325
#define ORIGIN_WEAPONDAMAGE			395 335
#define ORIGIN_WEAPONMOBILITY			395 345
#define ORIGIN_GRENADESLOT1			296 176
#define ORIGIN_GRENADESLOT2			312 176
#define ORIGIN_GRENADESLOT3			328 176
#define ORIGIN_GRENADESLOT0			290 176
#define ORIGIN_GRENADESLOT4			346 176
#define ORIGIN_GRENADESLOT5			362 176
{
	menuDef
	{
		name			"weapon_german"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc 
		{
			close weapon_german;
		}
		onOpen 
		{
		}
		onClose
		{
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
			background		"gfx/custom/hud@ingame_german_background.tga"
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
			text			"@MC2_GERMAN_CLASS"
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
			rect			5 225 438 2
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
		//WPN
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			185 35 2 190
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
				close weapon_german;
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
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0.1 0.7975
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_TEAMS"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		45
			textaligny		24
			textalign		ITEM_ALIGN_CENTER
			action
			{
				play "mouse_click";
				scriptMenuResponse "back";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
// CLASS BUTTON
		itemDef
		{
			name			"button_class"
			visible			1
			rect			179 0 90 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_press.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			text			"@MC2_MENU_CLASS"
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
		execKey "1" { play "mouse_click"; scriptMenuResponse "soldier" }
		execKey "2" { play "mouse_click"; scriptMenuResponse "medic" }
		execKey "3" { play "mouse_click"; scriptMenuResponse "sniper" }
		execKey "4" { play "mouse_click"; scriptMenuResponse "engineer" }
		execKey "5" { play "mouse_click"; scriptMenuResponse "support" }

		/*------------------------------
		SOLDIER
		------------------------------*/
		itemDef 
		{
			name			"button_soldier"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_SOLDIER"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_soldier"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "soldier";
			}
			onFocus
			{
				//hide
				play "mouse_over";
				//show
			}
		}
		itemDef 
		{
			name			"button_soldier"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_SOLDIER"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_soldier"
			showDvar		{ "2" }
			onFocus
			{
				play "mouse_over";
			}
		}

		/*------------------------------
		MEDIC
		------------------------------*/
		itemDef 
		{
			name			"button_medic"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_MEDIC"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_medic"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "medic";
			}
			onFocus
			{
				//hide
				play "mouse_over";
				//show
			}
		}
		itemDef 
		{
			name			"button_medic"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_MEDIC"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_medic"
			showDvar		{ "2" }
			onFocus
			{
				play "mouse_over";
			}
		}

		/*------------------------------
		SNIPER
		------------------------------*/
		itemDef 
		{
			name			"button_sniper"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_SNIPER"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_sniper"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "sniper";
			}
			onFocus
			{
				//hide
				play "mouse_over";
				//show
			}
		}
		itemDef 
		{
			name			"button_sniper"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_SNIPER"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_sniper"
			showDvar		{ "2" }
			onFocus
			{
				play "mouse_over";
			}
		}
		/*------------------------------
		ENGINEER
		------------------------------*/
		itemDef 
		{
			name			"button_engineer"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_ENGINEER"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_engineer"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "engineer";
			}
			onFocus
			{
				//hide
				play "mouse_over";
				//show
			}
		}
		itemDef 
		{
			name			"button_engineer"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_ENGINEER"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_engineer"
			showDvar		{ "2" }
			onFocus
			{
				play "mouse_over";
			}
		}
		/*------------------------------
		SUPPORT
		------------------------------*/
		itemDef 
		{
			name			"button_support"
			visible			1
			rect			16 126 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_SUPPORT"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_support"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "support";
			}
			onFocus
			{
				//hide
				play "mouse_over";
				//show
			}
		}
		itemDef 
		{
			name			"button_support"
			visible			1
			rect			16 126 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_GE_SUPPORT"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_axis_support"
			showDvar		{ "2" }
			onFocus
			{
				play "mouse_over";
			}
		}
//CLASS COUNT INFO

		itemDef
		{
			name			"ClassInfo"
			visible 		1
			rect			116 335 160 15
			textstyle		3
			type			ITEM_TYPE_EDITFIELD
			forecolor		1 1 1 1
			autowrapped
			text			"Soldaten: "
			dvar			"ui_axis_soldier"
			textfont		UI_FONT_BOLD
			textscale		.18
			decoration
		}
		itemDef
		{
			name			"ClassInfo"
			visible 		1
			rect			116 345 160 15
			textstyle		3
			type			ITEM_TYPE_EDITFIELD
			dvar			"ui_axis_medic"
			forecolor		1 1 1 1
			text			"Mediziner: "
			textfont		UI_FONT_BOLD
			textscale		.18
			decoration
		}


		itemDef
		{
			name			"ClassInfo"
			visible 		1
			rect			116 355 160 15
			textstyle		3
			type			ITEM_TYPE_EDITFIELD
			dvar			"ui_axis_sniper"
			forecolor		1 1 1 1
			autowrapped
			text			"Scharfschützen: "
			textfont		UI_FONT_BOLD
			textscale		.18
			decoration
		}
		itemDef
		{
			name			"ClassInfo"
			visible 		1
			rect			116 365 160 15
			textstyle		3
			type			ITEM_TYPE_EDITFIELD
			dvar			"ui_axis_engineer"
			forecolor		1 1 1 1
			autowrapped
			text			"Ingenieure: "
			textfont		UI_FONT_BOLD
			textscale		.18
			decoration
		}
		itemDef
		{
			name			"ClassInfo"
			visible 		1
			rect			116 375 160 15
			textstyle		3
			type			ITEM_TYPE_EDITFIELD
			dvar			"ui_axis_support"
			forecolor		1 1 1 1
			autowrapped
			text			"Pioniere: "
			textfont		UI_FONT_BOLD
			textscale		.18
			decoration
		}		
// CLASS IMAGES


/*
// CLASS DESCRIPTIONS

*/
// CLASS PROPERTIES
	}
}
