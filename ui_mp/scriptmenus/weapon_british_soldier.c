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
		name			"weapon_british_soldier"
		rect			0 0 640 480
		focuscolor		GLOBAL_FOCUSED_COLOR
		style			WINDOW_STYLE_EMPTY
		blurWorld		5.0
		onEsc 
		{
			close weapon_british_soldier;
		}
		onOpen 
		{
			hide enfield_info;
			hide m1garand_info;
			hide thompson_info;
			hide bren_info;
			hide weapon_propertiestext;
			hide grenade_info;
		}
		onClose
		{
			hide enfield_info;
			hide m1garand_info;
			hide thompson_info;
			hide bren_info;
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
			background		"gfx/custom/hud@ingame_british_background.tga"
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
				close weapon_british_soldier;
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
		execKey "1" { play "mouse_click"; scriptMenuResponse "enfield_mp"; }
		execKey "2" { play "mouse_click"; scriptMenuResponse "m1garand_mp"; }
		execKey "3" { play "mouse_click"; scriptMenuResponse "sten_mp"; }
		execKey "4" { play "mouse_click"; scriptMenuResponse "bren_mp"; }
		execKey "5" { play "mouse_click"; scriptMenuResponse "m1903_mp"; }
		
		itemDef 
		{
			name			"button_enfield"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_LEEENFIELD"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_enfield"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "enfield_mp";
			}
			onFocus
			{
				hide bren_info;
				hide thompson_info;
				hide sten_info;
				hide m1903_info;
				hide m1garand_info;
				play "mouse_over";
				show enfield_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_enfield"
			visible			1
			rect			16 46 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_1_LEEENFIELD"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_enfield"
			showDvar		{ "2" }
			onFocus
			{
				hide thompson_info;
				hide m1903_info;
				hide m1garand_info;
				hide sten_info;
				hide bren_info;
				play "mouse_over";
				show enfield_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_m1garand"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_2_M1_GARAND"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_m1garand"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "m1garand_mp";
			}
			onFocus
			{
				hide thompson_info;
				hide m1903_info;
				hide enfield_info;
				hide sten_info;
				hide bren_info;
				play "mouse_over";
				show m1garand_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_m1garand"
			visible			1
			rect			16 66 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MPUI_2_M1_GARAND"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_m1garand"
			showDvar		{ "2" }
			onFocus
			{
				hide thompson_info;
				hide m1903_info;
				hide enfield_info;
				hide sten_info;
				hide bren_info;
				play "mouse_over";
				show m1garand_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_sten"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_STEN"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_sten"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "sten_mp";
			}
			onFocus
			{
				hide thompson_info;
				hide m1903_info;
				hide enfield_info;
				hide m1garand_info;
				hide bren_info;
				play "mouse_over";
				show sten_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_sten"
			visible			1
			rect			16 86 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_3_STEN"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_sten"
			showDvar		{ "2" }
			onFocus
			{
				hide thompson_info;
				hide m1903_info;
				hide enfield_info;
				hide m1garand_info;
				hide bren_info;
				play "mouse_over";
				show sten_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}

		itemDef 
		{
			name			"button_bren"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_BREN_LMG"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_bren"
			showDvar		{ "1" }
			action
			{
				play "mouse_click";
				scriptMenuResponse "bren_mp";
			}
			onFocus
			{
				hide thompson_info;
				hide m1903_info;
				hide enfield_info;
				hide m1garand_info;
				hide sten_info;
				play "mouse_over";
				show bren_info;
				show weapon_propertiestext;
				show grenade_info;
			}
		}
		itemDef 
		{
			name			"button_bren"
			visible			1
			rect			16 106 60 60
			origin			ORIGIN_MENUWINDOW
			forecolor		1 1 1 1
			type			ITEM_TYPE_BUTTON
			text			"@MC2_4_BREN_LMG"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		0
			textaligny		16
			dvartest		"ui_allow_bren"
			showDvar		{ "2" }
			onFocus
			{

				hide thompson_info;
				hide m1903_info;
				hide enfield_info;
				hide m1garand_info;
				hide sten_info;
				play "mouse_over";
				show bren_info;
				show weapon_propertiestext;
				show grenade_info;				
			}
		}
	
			itemDef 
			{
				name			"button_m1903"
				visible			1
				rect			16 126 60 60
				origin			ORIGIN_MENUWINDOW
				forecolor		1 1 1 1
				type			ITEM_TYPE_BUTTON
				text			"@MC2_3_M1903"
				textfont		UI_FONT_NORMAL
				textscale		.24
				textalignx		0
				textaligny		16
				dvartest		"ui_allow_m1903"
				showDvar		{ "1" }
				action
				{
					play "mouse_click";
					scriptMenuResponse "m1903_mp";
				}
				onFocus
				{
					hide thompson_info;
					hide bren_info;
					hide enfield_info;
					hide m1garand_info;
					hide sten_info;
					play "mouse_over";
					show m1903_info;
					show weapon_propertiestext;
					show grenade_info;
				}
			}
			itemDef 
			{
				name			"button_m1903"
				visible			1
				rect			16 126 60 60
				origin			ORIGIN_MENUWINDOW
				forecolor		1 1 1 1
				type			ITEM_TYPE_BUTTON
				text			"@MC2_3_m1903"
				textfont		UI_FONT_NORMAL
				textscale		.24
				textalignx		0
				textaligny		16
				dvartest		"ui_allow_m1903"
				showDvar		{ "2" }
				onFocus
				{
	
					hide thompson_info;
					hide bren_info;
					hide enfield_info;
					hide m1garand_info;
					hide sten_info;
					play "mouse_over";
					show m1903_info;
					show weapon_propertiestext;
					show grenade_info;
				}
			}
	
			itemDef 
			{
				name			"button_thompson"
				visible			1
				rect			16 146 60 60
				origin			ORIGIN_MENUWINDOW
				forecolor		1 1 1 1
				type			ITEM_TYPE_BUTTON
				text			"@MC2_6_THOMPSON"
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
					hide m1903_info;
					hide bren_info;
					hide enfield_info;
					hide m1garand_info;
					hide sten_info;
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
				rect			16 146 60 60
				origin			ORIGIN_MENUWINDOW
				forecolor		1 1 1 1
				type			ITEM_TYPE_BUTTON
				text			"@MC2_6_THOMPSON"
				textfont		UI_FONT_NORMAL
				textscale		.24
				textalignx		0
				textaligny		16
				dvartest		"ui_allow_thompson"
				showDvar		{ "2" }
				onFocus
				{
	
					hide m1903_info;
					hide bren_info;
					hide enfield_info;
					hide m1garand_info;
					hide sten_info;
					play "mouse_over";
					show thompson_info;
					show weapon_propertiestext;
					show grenade_info;
					
				}
			}
		
// WEAPON IMAGES
		itemDef
		{
			name			"enfield_info"
			visible 		0
			rect			0 0 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_enfield"
			decoration
		}
		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_m1garand"
			decoration
		}
		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 6 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_sten"
			decoration
		}
		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 -2 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_bren"
			decoration
			
			}
							itemDef
							{
								name			"thompson_info"
								visible 		0
								rect			0 6 224 112
								origin			ORIGIN_WEAPONIMAGE
						 		style			WINDOW_STYLE_SHADER
								background		"weapon_thompson"
								decoration
		}
		itemDef
		{
			name			"m1903_info"
			visible 		0
			rect			0 -2 224 112
			origin			ORIGIN_WEAPONIMAGE
	 		style			WINDOW_STYLE_SHADER
			background		"weapon_springfiel1"
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
			name			"enfield_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"enfield_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"enfield_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"enfield_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"enfield_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"enfield_info"
			visible 		0
			rect			0 0 80 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 96 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 110 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"m1garand_info"
			visible 		0
			rect			0 0 80 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 0 70 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 0 77 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"sten_info"
			visible 		0
			rect			0 0 96 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 0 72 6
			origin			ORIGIN_WEAPONACCURACY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 0 120 6
			origin			ORIGIN_WEAPONDAMAGE
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
		}

		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 0 128 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 .125
	 		style			WINDOW_STYLE_FILLED
			decoration
		}
		itemDef
		{
			name			"bren_info"
			visible 		0
			rect			0 0 64 6
			origin			ORIGIN_WEAPONMOBILITY
			backcolor		1 1 1 1
	 		style			WINDOW_STYLE_FILLED
			decoration
			
										}
										itemDef
										{
											name			"m1903_info"
											visible 		0
											rect			0 0 128 6
											origin			ORIGIN_WEAPONACCURACY
											backcolor		1 1 1 .125
									 		style			WINDOW_STYLE_FILLED
											decoration
										}
										itemDef
										{
											name			"m1903_info"
											visible 		0
											rect			0 0 96 6
											origin			ORIGIN_WEAPONACCURACY
											backcolor		1 1 1 1
									 		style			WINDOW_STYLE_FILLED
											decoration
										}
								
										itemDef
										{
											name			"m1903_info"
											visible 		0
											rect			0 0 128 6
											origin			ORIGIN_WEAPONDAMAGE
											backcolor		1 1 1 .125
									 		style			WINDOW_STYLE_FILLED
											decoration
										}
										itemDef
										{
											name			"m1903_info"
											visible 		0
											rect			0 0 96 6
											origin			ORIGIN_WEAPONDAMAGE
											backcolor		1 1 1 1
									 		style			WINDOW_STYLE_FILLED
											decoration
										
										}
										itemDef
										{
											name			"m1903_info"
											visible 		0
											rect			0 0 128 6
											origin			ORIGIN_WEAPONMOBILITY
											backcolor		1 1 1 .125
									 		style			WINDOW_STYLE_FILLED
											decoration
										}
										itemDef
										{
											name			"m1903_info"
											visible 		0
											rect			0 0 80 6
											origin			ORIGIN_WEAPONMOBILITY
											backcolor		1 1 1 1
									 		style			WINDOW_STYLE_FILLED
											decoration
											
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
																	rect			0 0 56 6
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
																	rect			0 0 83 6
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
																	rect			0 0 96 6
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
