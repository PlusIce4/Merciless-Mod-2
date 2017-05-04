#include "ui/menudef.h"

#define TEXT_ON_BG_STYLE 	3	//

{
\\ SETUP MENU \\

	menuDef 
	{
	
		name "options_menu"
		fullScreen 0				
		rect 0 0 640 480				// Size and position of the menu
		focusColor GLOBAL_FOCUSED_COLOR			// Menu focus color for text and items
		soundloop ""
					
		onOpen 
		{ 
			setitemcolor fadebox backcolor 0 0 0 1; 
//			play "music_mainmenu";
			fadeout fadebox ;
			setdvar ui_background "background_american_w";
			setdvar ui_logo_show "1";
			setdvar ui_version_show "1";
			setdvar ui_separator_show "1";
			setdvar ui_background_gradient_show "0";
			setdvar g_reloading "0";
		}
		onClose
		{
			open main_text;
			close options_look;
			close options_move;
			close options_shoot;
			close options_misc;
			close options_graphics;
			close options_sound;
			close options_game;
			close options_view;
			close options_defaults;
			close options_driverinfo;
			close options_credits;
			close options_multi;
			close options_graphics_defaults;
			close options_graphics_texture;
			close options_control_defaults;
			close options_voice;
			close options_multi;
		}
		onESC 
		{ 
			open main_text;
			close options_menu;		
		}
		#include "ui_mp/menu_background2.menu"
/*		
		itemDef 
		{
			name main_back_top
			style WINDOW_STYLE_SHADER
			rect 0 0 640 320
			background "main_back_top"
			visible 1
			decoration
		}
		itemDef 
		{
			name main_back_bottom
			style WINDOW_STYLE_SHADER
			rect 0 320 640 160
			background "main_back_bottom"
			visible 1
			decoration
		}
*/
	//Right Hand Menu items

		itemDef 
		{
			name resume
			text "@MENU_CONTROLS"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 385 130 240 13 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			decoration
			action 
			{ 
//				close main;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_LOOK"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 145 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				open options_look;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_MOVE"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 160 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_look;
				close options_misc;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				open options_move;
//				close main;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_SHOOT"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 175 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_move;
				close options_look;
				close options_misc;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				open options_shoot;
//				close main;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_INTERACT"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 190 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_move;
				close options_look;
				close options_shoot;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				open options_misc;
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_MULTIPLAYER"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 205 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 0
			textfont UI_FONT_NORMAL
			dvartest "ui_multiplayer"
			showDvar { "1" }
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_move;
				close options_look;
				close options_shoot;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				close options_misc;
				open options_multi;
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_SET_DEFAULT_CONTROLS"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 205 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_move;
				close options_look;
				close options_shoot;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_voice;
				close options_multi;
				close options_misc;
				open options_control_defaults;
			}
		}

		itemDef 
		{
			name resume
			text "@MENU_SYSTEM"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 385 240 240 13 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			decoration
			action 
			{ 
//				close main;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_GRAPHICS"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 255 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_multi;
				close options_voice;
				open options_graphics;
				
//				close main;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_SOUND"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 270 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_multi;
				close options_voice;
				open options_sound;
				
//				close main;
//				exec "loadgame_continue";
			}
		}
		itemDef 
		{
			name resume
			text "@MENU_VOICECHAT"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 285 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_game;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_sound;
				close quick_filter;
				close options_multi;
				open options_voice;
				
//				close main;
//				exec "loadgame_continue";
			}
		}

		itemDef 
		{
			name resume
			text "@MENU_GAME_OPTIONS"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 300 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_sound;
				close options_view;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_graphics_texture;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				open options_game;
//				close main;
//				exec "loadgame_continue";
			}
		}

		itemDef 
		{
			name resume
			text "@MENU_RESET_SYSTEM_DEFAULTS"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 400 315 240 13 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_defaults;
				close options_credits;
				close options_multi;
				close options_control_defaults;
				close options_voice;
				close options_multi;
				open options_graphics_defaults;
				close options_graphics_texture;
			}
			dvartest "sv_running"
			hideDvar { "1" }
		}

		itemDef 
		{
			name resume
			text "@MENU_BACK"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 385 360 240 13 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				close options_menu;
				open main_text;
				play "mouse_click";
//				exec "loadgame_continue";
			}
		}
	}
/* vince'd
		itemDef 
		{
			name resume
			text "Game Options"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle ITEM_TEXTSTYLE_NORMAL
			rect 385 295 130 15 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 14
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			decoration
			action 
			{ 
//				close main;
//				exec "loadgame_continue";
			}
		}
*/
/*
		itemDef 
		{
			name resume
			text "@MENU_MULTIPLAYER"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle ITEM_TEXTSTYLE_NORMAL
			rect 385 340 130 13 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			dvartest "ui_multiplayer"
			showDvar { "1" }
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_driverinfo;
				close options_defaults;
				close options_credits;
				close options_graphics_defaults;
				close options_control_defaults;
				open options_multi;
			}
		}
*/
/*
		itemDef 
		{
			name resume
			text "View"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle ITEM_TEXTSTYLE_NORMAL
			rect 400 325 130 15 
			textalign 0
			textscale .3		
			textalignx 0
			textaligny 14
			forecolor .9 .9 .9 1
			visible 0
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				fadein message_accept 
			}
			action 
			{ 
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_defaults;
				close options_driverinfo;
				close options_credits;
				close options_voice;
				open options_view;
				
//				close main;
//				exec "loadgame_continue";
			}
		}
*/
/*
		itemDef 
		{
			name resume
			text "@MENU_CREDITS"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle TEXT_ON_BG_STYLE
			rect 385 360 130 13 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 12
			forecolor .9 .9 .9 1
			visible 1
			textfont UI_FONT_NORMAL
			dvartest "ui_multiplayer"
			showDvar { "0" }
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_driverinfo;
				close options_defaults;
				close options_multi;
				close options_graphics_defaults;
				close options_control_defaults;
//				open options_credits;
				exec "map credits";
			}
		}
*/
/*
		itemDef 
		{
			name resume
			text "Reset to Defaults"
			type ITEM_TYPE_BUTTON
			style WINDOW_STYLE_EMPTY
			textstyle ITEM_TEXTSTYLE_NORMAL
			rect 385 380 130 15 
			textalign 0
			textscale .35		
			textalignx 0
			textaligny 14
			forecolor .9 .9 .9 1
			visible 0
			textfont UI_FONT_NORMAL
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{ 
				play "mouse_click";
				close options_shoot;
				close options_move;
				close options_misc;
				close options_look;
				close options_graphics;
				close options_sound;
				close options_game;
				close options_view;
				close options_driverinfo;
				close options_credits;
				close options_multi;
				close options_graphics_defaults;
				close options_control_defaults;
				close options_voice;
				open options_defaults;

//				close main;
//				exec "loadgame_continue";
			}
		}
*/


	}

} //end bracket
