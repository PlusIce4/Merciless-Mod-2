// This file was edited on 5/18/14 by PlusIce to add credits menu
//This file was edited on 2/23/06 by Philip A. Mecozzi to add the
// Mods menu back into CoD2's Main menu.
//Search for "-edit-" to find what was changed.
#include "ui/menudef.h"

#define MAIN_RECT_X			385
#define MAIN_RECT_WIDTH		210
#define MAIN_RECT_HEIGHT	20
#define MAIN_RECT_HORZALIGN	HORIZONTAL_ALIGN_DEFAULT
#define MAIN_RECT_VERTALIGN	VERTICAL_ALIGN_DEFAULT
#define MAIN_TEXTSCALE		.4
#define MAIN_TEXTALIGN		0
#define	MAIN_TEXTALIGN_X	0
#define MAIN_TEXTALIGN_Y	20
#define MAIN_FORECOLOR		.9 .9 .9 .9

{
	assetGlobalDef // global not per file settings
	{
		consoleFont "fonts/consoleFont" 18		// font
		smallFont "fonts/smallFont" 12			// font
		font "fonts/normalFont" 16				// font
		bigFont "fonts/bigFont" 24				// font
		extraBigFont "fonts/extraBigFont" 32	// font
		boldFont "fonts/boldFont" 30			// font
		cursor "ui/assets/3_cursor3"			// cursor
//		gradientBar "ui/assets/gradientbar2.tga"	// gradient bar
		itemFocusSound	"sound/misc/menu2.wav"		// sound for item getting focus (via keyboard or mouse )
	}

	assetGlobalDef
	{
		fadeClamp 1.0				// sets the fadeup alpha
		fadeCycle 1					// how often fade happens in milliseconds
		fadeAmount 0.1				// amount to adjust alpha per cycle
		
		shadowColor 0.1 0.1 0.1 0.25			// shadow color
	}

	menuDef 
	{
		name			main
		fullScreen		1				
		rect			0 0 640 480		// Size and position of the menu
		focusColor		GLOBAL_FOCUSED_COLOR		// Menu focus color for text and items
		soundloop "music_mainmenu_mp"
		onOpen
		{ 
			close bg;
			close main_text;

			open bg;
			open main_text;
			
			uiScript addPlayerProfiles;
			uiScript openMenuOnDvar com_playerProfile "" player_profile;
			uiScript openMenuOnDvarNot ui_playerProfileCount 1 player_profile;
		}
		onClose
		{
			close bg;
			close main_text;
		}
		onESC 
		{
		}
	}

	menuDef 
	{
		name "main_text"
//		background "menuback_cw"		// Spinning Circle Background
//		fullScreen MENU_TRUE				
		fullScreen 0
		rect 0 0 640 480				// Size and position of the menu
		focusColor GLOBAL_FOCUSED_COLOR			// Menu focus color for text and items
					
		onOpen 
		{ 
//			setitemcolor fadebox backcolor 0 0 0 1; 
			setdvar ui_background "background_american_w";
			setdvar ui_logo_show "1";
			setdvar ui_version_show "1";
			setdvar ui_separator_show "1";
			setdvar ui_background_gradient_show "0";
			uiScript stopRefresh ;
		}
		
		onESC 
		{ 
//			open quit_popmenu 
//			close main
			close mods_menu;
			close options_multi;
			ingameclose main;
//			open quit_popmenu 
		}
		onclose
		{
			close mods_menu;
			close options_multi;
//			ingameclose main;
		}
		
		// Temp full screen backdrop image
/*
		itemDef 
		{
			name main_back
			style WINDOW_STYLE_SHADER
			rect 0 0 640 480
			background "background_mc2_menu"
			visible 1
			decoration
		}
*/
		#include "ui_mp/menu_background.menu"		
////////// GAMETYPE //////////////////////////////////////////////////////// 



/*
		//ingame - return to game
		itemDef 
		{
			name resume
			text "@MENU_JOIN_AN_INTERNET_GAME"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle ITEM_TEXTSTYLE_SHADOWED
			rect 385 160 210 15 
			textalign 0
			textscale .4		
			textalignx 0
			textaligny 14
			backcolor 0 0 1 1
			forecolor .9 .9 .9 .9
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
			//ui_netSource 1
				play "mouse_click";
				setdvar ui_netSource 1
				close main ; 
				close mods_menu;
				close credits_menu;
				close options_multi;
				open multi_menu;
				open joinserver
			}
			dvarTest "cl_ingame"
			showDvar { "0" }
		}
*/
		itemDef 
		{
			name		resume
			text		"@MENU_BACKTOGAME"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 160 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				ingameclose main;
				close credits_menu;
				close mods_menu;
				close options_multi;
				close main;

			}
			dvarTest "cl_ingame"
			showDvar { "1" }
		}
		itemDef 
		{
			name		play
			text		"@MENU_JOIN_GAME"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 160 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN 		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
//				setdvar ui_netSource 0
//				close mods_menu;
//				close options_multi;
				
				close main_text; 
//				open multi_menu;
				open joinserver
			}
			dvarTest "cl_ingame"
			showDvar { "0" }
		}
		itemDef 
		{
			name		play
			text		"@MENU_DISCONNECT"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 190 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close credits_menu;
				close mods_menu;
				close options_multi;
				exec "disconnect";
			}
			dvarTest "cl_ingame"
			showDvar { "1" }
		}
// AUTO UPDATE GOES HERE

		itemDef 
		{
			name		play
			text		"@MENU_START_NEW_SERVER"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 190 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN 		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
//				close main;
//				close mods_menu;
//				close options_multi;
//				open multi_menu;
				close main_text;
				open createserver;
			}
			dvarTest "cl_ingame"
			showDvar { "0" }
		}

		itemDef 
		{
			name		player_select
			text		"@MENU_SELECT_PROFILE"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 220 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			dvarTest	"cl_ingame"
			showDvar	{ "0" }
			textfont	UI_FONT_NORMAL
			mouseEnter
			{
				play "mouse_over";
			}
			action 
			{ 
				setdvar ui_playerProfileAlreadyChosen 0;
				open player_profile;
				play "mouse_click";
			}
		}
		itemDef 
		{
			name		player_select
			text		"@MENU_SELECT_PROFILE"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 220 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			dvarTest	"cl_ingame"
			showDvar	{ "1" }
			textfont	UI_FONT_NORMAL
			mouseEnter
			{
				play "mouse_over";
			}
			action 
			{ 
				open player_profile_ingame_warning;
				play "mouse_click";
			}
		}
		itemDef 
		{
			name		options
			text		"@MENU_MULTIPLAYER_OPTIONS"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY	
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 250 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				play "mouse_click"; 
//				close main;
//				close mods_menu;
//				open options_menu;
//				open options_multi;
				
				close mods_menu;
				close credits_menu;
				open options_multi;
			} 
		}
		itemDef 
		{
			name		options
			text		"@MENU_OPTIONS"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY	
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 280 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				close mods_menu;
				close main_text;
				open options_menu;
				close credits_menu;
				play "mouse_click"; 
//				open control_menu;
			} 
		}
//------------------------------edit------------------------------//	
//This is the button for the Mods menu.	
		itemDef 
		{
			name		mods
			text		"@MENU_MODS"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY	
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 310 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				play "mouse_click"; 
//				close main;
//				close mods_menu;
//				open options_menu;
//				open options_multi;
				
				open mods_menu;
				close options_multi;
			} 
		}		
//----------------------------------------------------------------//
		itemDef 
		{
			name		option
		  	text		"Contact"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY	
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 340 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				play "mouse_click";
				close mods_menu;
				close options_multi;
				open contact_menu;
			}
//			action { uiScript startMultiplayer }
	    	}


		itemDef 
		{
			name		quit
			text		"@MENU_QUIT"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY	
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 370 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				close mods_menu;
				close options_multi;
				play "mouse_click";
				open quit_popmenu;
			}
		}	
//----------------------------------------------credits-----------------------------------------------------------------//			
		itemDef 
		{
			name		options
			text		"@MENU_CREDITS"
			type		ITEM_TYPE_BUTTON
			style		WINDOW_STYLE_EMPTY	
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		MAIN_RECT_X 130 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				close mods_menu;
				close options_multi;
				play "mouse_click";
				open credits_menu;
			}	
//-----------------------------------------------------------------------------------------------------------------------//			
		}	

		itemDef 
		{
			name 		play
			text 		"@MENU_AUTO_UPDATE"
			type 		ITEM_TYPE_BUTTON
			style 		WINDOW_STYLE_EMPTY
			textstyle 	ITEM_TEXTSTYLE_SHADOWED
			rect 		MAIN_RECT_X 400 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN		//-edit-
			textalign	MAIN_TEXTALIGN
			textscale	MAIN_TEXTSCALE		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click"; 
				close mods_menu; 
				close options_multi; 
				open auconfirm 
			}	

			dvarTest "cl_updateavailable"
			showDvar { "1" }
		}

		itemDef 
		{
			name 		esrb
			text 		"@MENU_GAME_EXPERIENCE_MAY_CHANGE"
			type 		ITEM_TYPE_BUTTON
			style 		WINDOW_STYLE_EMPTY
			textstyle 	ITEM_TEXTSTYLE_SHADOWED
			rect 		20 390 MAIN_RECT_WIDTH MAIN_RECT_HEIGHT MAIN_RECT_HORZALIGN MAIN_RECT_VERTALIGN
			textalign	MAIN_TEXTALIGN
			textscale	.25		
			textalignx	MAIN_TEXTALIGN_X
			textaligny	MAIN_TEXTALIGN_Y
			forecolor	MAIN_FORECOLOR
			visible		1
			textfont	UI_FONT_NORMAL
			decoration
		}
/*
		itemDef 
		{
			name backtogame
			type 1
			text "@MENU_BACKTOGAME" 
			style WINDOW_STYLE_FILLED
			textscale .3 
			textstyle ITEM_TEXTSTYLE_SHADOWED
			rect 500 425 141 41	
			textalign 1
			textalignx 73
			textaligny 25
			textfont UI_FONT_NORMAL
			//decoration
			forecolor 1 1 1 1
			visible 0
			action { play "mouse_click"; close mods_menu; close options_multi; close main }	

			dvarTest "cl_ingame"
			showDvar { "1" }
			mouseEnter 
			{
				play "mouse_over";
			}
		}
	*/			

		//
		// Box for fading in menus
		//
/*
		itemDef 	
		{
	      	name fadebox
	      	style WINDOW_STYLE_FILLED
	 		background "ui/assets/fadebox.tga"
			forecolor 0 0 0 1
			backcolor 0 0 0 1
			rect 0 0 640 480
	      	visible 0 
			decoration
    		}

		itemDef 
		{
			name auwindow
			rect 220 428 146 45
			style WINDOW_STYLE_FILLED
			border 1
			bordercolor .5 .5 .5 .5
			forecolor 1 1 1 1
			backcolor 0 0 0 0
			visible 1
			decoration

			dvarTest "cl_updateavailable"
			showDvar { "1" }
		}

		itemDef 
		{
			name auwindow2
			rect 222 430 142 41	
			style WINDOW_STYLE_FILLED
			border 1
			bordercolor .1 .1 .1 .2
			forecolor 1 1 1 1
//			backcolor .3 0.5 0.2 .55
			backcolor .3 0.2 0.5 .55
			visible 1
			decoration

			dvarTest "cl_updateavailable"
			showDvar { "1" }
		}
		itemDef 
		{
			name autoupdateclick
			type 1
			text "@MENU_CLICK_FOR_AUTOUPDATE" 
			style WINDOW_STYLE_FILLED
			textscale .25 
			textstyle 3
			rect 222 430 141 41	
			textalign 1
			textalignx 73
			textaligny 25
			textfont UI_FONT_NORMAL
			//decoration
			forecolor 1 1 1 1
			visible 1
			action { play "mouse_click"; close mods_menu; close options_multi; open auconfirm }	

			dvarTest "cl_updateavailable"
			showDvar { "1" }
		}
*/
}

	menuDef 
	{
		name single_popmenu
		visible 0
		fullscreen 0
		//rect 217 200 210 85
		rect 204 140 235 135
		focusColor GLOBAL_FOCUSED_COLOR
		style 1
		border 1
		popup
		onESC { close single_popmenu;  }
		onOpen { setfocus yes; }

		itemDef 
		{
			name window
			group grpControlbutton
			rect 0 2 235 135
			style WINDOW_STYLE_FILLED
			border 1
			bordercolor .5 .5 .5 .5
			forecolor 1 1 1 1
			backcolor 0 0 0 .5
			visible 0
			decoration
		}

		itemDef 
		{
			name backimage2fade
			style WINDOW_STYLE_SHADER
			rect -332 -162 896 484
	 		background "white"
			forecolor 0 0 0 0.3
			backcolor 0 0 0 0.3
			visible 1
			decoration
		}
	
		itemDef 
		{
			name window2
			group grpControlbutton
			rect 2 3 231 20	
			style WINDOW_STYLE_FILLED
			border 1
			bordercolor .1 .1 .1 .2
			forecolor 1 1 1 1
			backcolor 1 1 .3 .3
			visible 0
			decoration
		}
		itemDef 
		{
			name backimage2fade
			style WINDOW_STYLE_SHADER
			rect -150 2 535 150
	 		background "popmenu_bg"
//			forecolor 0 0 0 0.4
//			backcolor 0 0 0 0.4
			visible 1
			decoration
		}
		itemDef 
		{
			name backimage2fade
			style WINDOW_STYLE_SHADER
			rect -50 20 335 24
	 		background "popmenu_goldline"
//			forecolor 0 0 0 0.4
//			backcolor 0 0 0 0.4
			visible 1
			decoration
		}

		itemDef 
		{
			name confirm
			text "@MENU_SWITCH_TO_SINGLE_PLAYER" 
			style 0
			textscale HEADER_SIZE 
			textstyle ITEM_TEXTSTYLE_SHADOWED
			rect 126 25 110 20
			textalign 1
			textalignx -7
			textaligny 5
			decoration
			forecolor		POPMENU_HEADER_COLOR
			visible 1
		}

		itemDef 
		{
			name		yes
			text		"@MENU_YES"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		90 45 60 30
			textalign	1
			textalignx	29
			textaligny	21
			forecolor	UI_BUTTON_TEXT_COLOR
//			backcolor	UI_BUTTON_BACK_COLOR 
			visible		1
//			border		UI_BUTTON_BORDER
//			bordercolor	UI_BUTTON_BORDER_COLOR

			action 
			{ 
				play "mouse_click"; 
				uiScript startsingleplayer;
			}
			mouseEnter { play "mouse_over";  } 
//			mouseExit { setitemcolor yes backcolor UI_BUTTON_BACK_COLOR } 	
		}

		itemDef 
		{
			name		no
			text		"@MENU_NO"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		91 85 60 30
			textalign	1
			textalignx	29
			textaligny	21
			forecolor	UI_BUTTON_TEXT_COLOR
//			backcolor	UI_BUTTON_BACK_COLOR 
			visible		1
//			border		UI_BUTTON_BORDER
//			bordercolor	UI_BUTTON_BORDER_COLOR
			action 
			{ 
				play "mouse_click"; 
				close single_popmenu ; 
			}
			mouseEnter { play "mouse_over";  } 
//			mouseExit { setitemcolor no backcolor UI_BUTTON_BACK_COLOR } 		
		}	
	}
	menuDef 
	{
		name "player_profile_ingame_warning"
		visible 0
		fullscreen 0
		//rect 217 200 210 85
		rect 204 160 235 135
		focusColor GLOBAL_FOCUSED_COLOR
		style 1
		border 1
		popup
		onESC { close player_profile_ingame_warning; }

		itemDef 
		{
			name window
			group grpControlbutton
			rect 0 2 235 135
			style WINDOW_STYLE_FILLED
			border 1
			bordercolor .5 .5 .5 .5
			forecolor 1 1 1 1
			backcolor 0 0 0 .5
			visible 0
			decoration
		}

		itemDef 
		{
			name backimage2fade
			style WINDOW_STYLE_SHADER
			rect -332 -162 896 484
	 		background "white"
			forecolor 0 0 0 0.3
			backcolor 0 0 0 0.3
			visible 1
			decoration
		}
	
		itemDef 
		{
			name window2
			group grpControlbutton
			rect 2 3 231 20	
			style WINDOW_STYLE_FILLED
			border 1
			bordercolor .1 .1 .1 .2
			forecolor 1 1 1 1
			backcolor 1 1 .3 .3
			visible 0
			decoration
		}
		itemDef 
		{
			name backimage2fade
			style WINDOW_STYLE_SHADER
			rect -150 2 535 150
	 		background "popmenu_bg"
//			forecolor 0 0 0 0.4
//			backcolor 0 0 0 0.4
			visible 1
			decoration
		}
		itemDef 
		{
			name backimage2fade
			style WINDOW_STYLE_SHADER
			rect -50 20 335 24
	 		background "popmenu_goldline"
//			forecolor 0 0 0 0.4
//			backcolor 0 0 0 0.4
			visible 1
			decoration
		}

		itemDef 
		{
			name confirm
			text "@MENU_QUIT_CURRENT_GAME" 
			style 0
			textscale HEADER_SIZE 
			textstyle ITEM_TEXTSTYLE_SHADOWED
			rect 126 25 110 20
			textalign 1
			textalignx -7
			textaligny 5
			decoration
			forecolor		POPMENU_HEADER_COLOR
			visible 1
		}
		itemDef 
		{
			text "@MENU_CANT_SWITCH_PROFILES_INGAME"
			type 1
			textscale .3
			style UI_BUTTON_STYLE
			textfont UI_FONT_NORMAL
			textstyle UI_BUTTON_TEXT_STYLE
			rect 70 35 100 17
			textalign 1
			textalignx 50
			textaligny 19
			forecolor UI_BUTTON_TEXT_COLOR
			backcolor UI_BUTTON_BACK_COLOR 
			border UI_BUTTON_BORDER
			bordercolor UI_BUTTON_BORDER_COLOR
			visible 1
			decoration
		}
		itemDef 
		{
			name		yes
			text		"@MENU_YES"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		90 65 60 30
			textalign	1
			textalignx	29
			textaligny	21
			forecolor	UI_BUTTON_TEXT_COLOR
//			backcolor	UI_BUTTON_BACK_COLOR 
			visible		1
//			border		UI_BUTTON_BORDER
//			bordercolor	UI_BUTTON_BORDER_COLOR

			action
			{ 
				play "mouse_click";
				exec "disconnect";
			}
			mouseEnter { play "mouse_over";  } 
//			mouseExit { setitemcolor yes backcolor UI_BUTTON_BACK_COLOR } 	
		}

		itemDef 
		{
			name		no
			text		"@MENU_NO"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		91 105 60 30
			textalign	1
			textalignx	29
			textaligny	21
			forecolor	UI_BUTTON_TEXT_COLOR
//			backcolor	UI_BUTTON_BACK_COLOR 
			visible		1
//			border		UI_BUTTON_BORDER
//			bordercolor	UI_BUTTON_BORDER_COLOR

			action
			{ 
				play "mouse_click"; 
				close player_profile_ingame_warning ; 
			}
			mouseEnter { play "mouse_over";  } 
//			mouseExit { setitemcolor no backcolor UI_BUTTON_BACK_COLOR } 		
		}	

	

	}
}
