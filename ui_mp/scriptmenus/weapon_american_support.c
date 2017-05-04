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
		name			"weapon_american_support"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc 
		{
			close weapon_american_support;
		}
		onOpen 
		{
			hide bar_info;
			hide thompson_info;
			hide mb30cal_info;
			hide weapon_propertiestext;
			hide grenade_info;
		}
		onClose
		{
			hide bar_info;
			hide thompson_info;
			hide mb30cal_info;
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
			background		"gfx/custom/hud@ingame_american_background.tga"
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
			text			"@MC2_US_SUPPORT2"
			textfont		UI_FONT_BOLD
			forecolor		1 1 1 .5
			textscale		.5
			textalignx		8
			textaligny		22
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
				close weapon_american_support;
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
		
		execKey "1" { play "mouse_click"; scriptMenuResponse "mb30cal_mp" }
		execKey "2" { play "mouse_click"; scriptMenuResponse "bar_mp" }
		execKey "3" { play "mouse_click"; scriptMenuResponse "thompson_mp" }

		itemDef 
		{
			name			"button_mb30cal"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_1_BROWNING"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_browning"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "mb30cal_mp";
			}
			onFocus
			{
				hide thompson_info;
				hide bar_info;
				play "mouse_over";
				show mb30cal_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_mb30cal"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_1_BROWNING"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_browning"
			showDvar		{ "2" }
			onFocus
			{
				hide thompson_info;
				hide bar_info;
				play "mouse_over";
				show mb30cal_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		
		itemDef 
		{
			name			"button_bar"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_2_BAR"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_bar"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "bar_mp";
			}
			onFocus
			{
				hide thompson_info;
				hide mb30cal_info;
				play "mouse_over";
				show bar_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_bar"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_2_BAR"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_bar"
			showDvar		{ "2" }
			onFocus
			{
				hide thompson_info;
				hide mb30cal_info;
				play "mouse_over";
				show bar_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
//Thompson		
		itemDef 
		{
			name			"button_thompson"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_THOMPSON"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_thompson"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "thompson_mp";
			}
			onFocus
			{
				hide bar_info;
				hide mb30cal_info;
				play "mouse_over";
				show thompson_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_thompson"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_THOMPSON"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_thompson"
			showDvar		{ "2" }
			onFocus
			{
				hide bar_info;
				hide mb30cal_info;
				play "mouse_over";
				show thompson_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		
// WEAPON IMAGES
		itemDef
		{
			name			"mb30cal_info"
			visible 		0
			rect			0 0 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_30cal"
			decoration
		}
		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 -2 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_bar"
			decoration
		}
		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_thompson"
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
			name			"mb30cal_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"mb30cal_info"
			visible 		0
			rect			0 0 50 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"mb30cal_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"mb30cal_info"
			visible 		0
			rect			0 0 75 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"mb30cal_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"mb30cal_info"
			visible 		0
			rect			0 0 50 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 0 72 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 0 120 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bar_info"
			visible 		0
			rect			0 0 64 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		
//thompson info
}
		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 50 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 75 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"thompson_info"
			visible 		0
			rect			0 0 50 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
//grenade
	itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT2
	 		style			WINDOW_STYLE_SHADER
			background		"gfx/icons/hud@incenhandgrenade_c.tga"
			decoration
		}
		itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT3
	 		style			WINDOW_STYLE_SHADER
			background		"gfx/icons/hud@us_grenade_C.tga"
			decoration
		}
		itemDef
		{
			name			"grenade_info"
			visible 		0
			rect			0 0 32 32
			origin			ORIGIN_GRENADESLOT0
	 		style			WINDOW_STYLE_SHADER
			background		"gfx/icons/hud@artillery.tga"
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
