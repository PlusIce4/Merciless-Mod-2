#include "ui_mp/menudef.h"

#define ORIGIN_TITLE				48 64
#define ORIGIN_CHOICE1				80 84
#define ORIGIN_CHOICE2				80 108
#define ORIGIN_CHOICE3				80 132
#define ORIGIN_CHOICE4				80 156
#define ORIGIN_CHOICE5				80 180
#define ORIGIN_CHOICE6				80 204
#define ORIGIN_CHOICE7				80 228

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


//-[Merciless2]
#define ORIGIN_WEAPONIMAGE2			296 96
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

{
	menuDef
	{
		name			"weapon_russian_soldier"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc 
		{
			close weapon_russian_soldier;
		}
		onOpen 
		{
			hide nagant_info;
			hide svt40_info;
			hide pps42_info;
			hide ppsh_info;
			hide weapon_propertiestext;
			hide grenade_info;
		}
		onClose
		{
			hide nagant_info;
			hide svt40_info;
			hide pps42_info;
			hide ppsh_info;
			hide weapon_propertiestext;
			hide grenade_info;
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
			background		"gfx/custom/hud@ingame_russian_background.tga"
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
			text			"@MC2_US_SOLDIER2"
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
		//WPN
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			185 35 2 250
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
				close weapon_russian_soldier;
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
			background		"gfx/custom/hud@button_back.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			text			"@MC2_MENU_CLASS"
			textfont		UI_FONT_BOLD
			textscale		.24
			textalignx		45
			textaligny		24
			textalign		ITEM_ALIGN_CENTER
			//decoration
			action
			{
				play "mouse_click";
				scriptMenuResponse "back2";
			}
			onFocus
			{
				play "mouse_over";
			}
		}
		
// WPN BUTTON

		itemDef
		{
			name			"button_empty"
			visible			1
			rect			269 0 90 32
			origin			ORIGIN_MENUTABS
			style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@button_press.tga"
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			text			"@MC2_MENU_WPN"
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
		execKey "1" { play "mouse_click"; scriptMenuResponse "mosin_nagant_mp" }
		execKey "2" { play "mouse_click"; scriptMenuResponse "SVT40_mp" }
		execKey "3" { play "mouse_click"; scriptMenuResponse "PPS42_mp" }
		execKey "4" { play "mouse_click"; scriptMenuResponse "ppsh_mp" }
		
		itemDef 
		{
			name			"button_nagant"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_MOSINNAGANT"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_nagant"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "mosin_nagant_mp";
			}
			onFocus
			{
				hide ppsh41_info;
				hide svt40_info;
				hide pps42_info;
				hide ppsh_info;
				play "mouse_over";
				show nagant_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_nagant"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_MOSINNAGANT"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_nagant"
			showDvar		{ "2" }
			onFocus
			{
				hide ppsh41_info;
				hide svt40_info;
				hide pps42_info;
				hide ppsh_info;
				play "mouse_over";
				show nagant_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_svt40"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_2_TOKAREV_SVT40"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_svt40"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "SVT40_mp";
			}
			onFocus
			{
				hide ppsh41_info;
				hide nagant_info;
				hide pps42_info;
				hide ppsh_info;
				play "mouse_over";
				show svt40_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_svt40"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_2_TOKAREV_SVT40"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_svt40"
			showDvar		{ "2" }
			onFocus
			{
				hide ppsh41_info;
				hide nagant_info;
				hide pps42_info;
				hide ppsh_info;
				play "mouse_over";
				show svt40_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_pps42"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_PPS42"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_pps42"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "PPS42_mp";
			}
			onFocus
			{
				hide ppsh41_info;
				hide nagant_info;
				hide svt40_info;
				hide ppsh_info;
				play "mouse_over";
				show pps42_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_pps42"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_PPS42"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_pps42"
			showDvar		{ "2" }
			onFocus
			{
				hide ppsh41_info;
				hide nagant_info;
				hide svt40_info;
				hide ppsh_info;
				play "mouse_over";
				show pps42_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}

		itemDef 
		{
			name			"button_ppsh"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_PPSH"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_ppsh"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "ppsh_mp";
			}
			onFocus
			{
				hide nagant_info;
				hide svt40_info;
				hide pps42_info;
				play "mouse_over";
				show ppsh_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_ppsh"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_PPSH"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_ppsh"
			showDvar		{ "2" }
			onFocus
			{

				hide pps42_info;
				hide nagant_info;
				hide svt40_info;
				play "mouse_over";
				show ppsh_info;
				show weapon_propertiestext;
				show grenade_info;
//new ppsh with 35 rounds

}

		itemDef 
		{
			name			"button_ppsh41"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_PPSH"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_ppsh41"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "ppsh41_mp";
			}
			onFocus
			{
				hide nagant_info;
				hide svt40_info;
				hide pps42_info;
				play "mouse_over";
				show ppsh41_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_ppsh41"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_PPSH"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_ppsh41"
			showDvar		{ "2" }
			onFocus
			{

				hide pps42_info;
				hide nagant_info;
				hide svt40_info;
				play "mouse_over";
				show ppsh41_info;
				show weapon_propertiestext;
				show grenade_info;

			}
		}
		
// WEAPON IMAGES
		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 6 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_pps42"
			decoration
		}
		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 10 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_ppsh"
			decoration
		}
		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_svt40"
			decoration
		}
		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_nagant"
			decoration
		}

// WEAPON PROPERTIES
		itemDef
		{
			name			"weapon_propertiestext"
			visible 		0
			origin			ORIGIN_WEAPONPROPERTIESTEXT
			forecolor		1 1 1 1
			autowrapped
			text			"@MPUI_ACCURACY_DAMAGE_MOBILITY"
			textfont		UI_FONT_NORMAL
			textscale		.24
			decoration
		}
		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 0 56 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 0 83 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"pps42_info"
			visible 		0
			rect			0 0 96 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 0 48 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 0 93 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"ppsh41_info"
			visible 		0
			rect			0 0 96 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 96 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 96 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"svt40_info"
			visible 		0
			rect			0 0 80 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"nagant_info"
			visible 		0
			rect			0 0 80 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

//grenades
		itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT1
	 		style			WINDOW_STYLE_SHADER
			background		"gfx/icons/hud@us_grenade_C.tga"
			decoration
		}
		itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT2
	 		style			WINDOW_STYLE_SHADER
			background		"gfx/icons/hud@us_grenade_C.tga"
			decoration
		}
		itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT3
	 		style			WINDOW_STYLE_SHADER
			background		"hud_us_smokegrenade_C"
			decoration
		}
		itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT4
	 		style			WINDOW_STYLE_SHADER
			background		"gfx/custom/hud@landmine.tga"
			decoration	
		}
	}
}
