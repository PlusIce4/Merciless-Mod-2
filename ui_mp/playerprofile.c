#include "ui/menudef.h"
#define TEXT_ON_BG_STYLE 	3	//
{

/////////////////////
//
//	player profile menu
//
/////////////////////

menuDef {
   	name "player_profile"
   	visible 1
   	fullscreen 0
	rect 0 0 640 480
   	focusColor GLOBAL_FOCUSED_COLOR
   	style 1
   	border 0
	onOpen
	{
		close main_text;
		setdvar ui_separator_show "1";
		setdvar ui_version_show "0";
		uiScript closeMenuOnDvar ui_playerProfileAlreadyChosen 1 player_profile;
		uiScript addPlayerProfiles;
		uiScript selectActivePlayerProfile;
		uiScript openMenuOnDvar ui_playerProfileCount 0 profile_create_popmenu;
	}
	onClose
	{
		setdvar ui_separator_show "1";
		setdvar ui_version_show "1";
		open main_text;
	}
	onEsc
	{
		setdvar ui_playerProfileAlreadyChosen 1;
		uiScript closeMenuOnDvarNot com_playerProfile "" player_profile;
	}

#include "ui_mp/menu_background2.menu"
///////////// name and date //////////////// 

		itemDef
		{
			type			ITEM_TYPE_TEXT
			origin			HEADER_ORIGIN
			forecolor		1 1 1 1
			text			"@MENU_SELECT_PROFILE"
			textfont		UI_FONT_NORMAL
			textscale		HEADER_SIZE
			visible			1
			decoration
		}
		itemDef
		{
//			type			ITEM_TYPE_TEXT
			rect			371 115 300 300
			style			WINDOW_STYLE_FILLED
			backcolor		0 0 0 .25
			visible			1
			decoration
		}
		itemDef
		{
//			type			ITEM_TYPE_TEXT
			rect			375 148 260 1 
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .7
			visible			1
			decoration
		}
		itemDef 
		{
			name profileNameBar
			text "@MENU_NAME"
			textscale .3
			style 0	
			type ITEM_TYPE_BUTTON
			textalign ITEM_ALIGN_LEFT
			textfont UI_FONT_NORMAL
			textstyle 6
//			rect 450 134 100 20  //centered
			rect 350 134 100 20
			textalign 1	 
			textalignx 45  	
			textaligny 12        
			backcolor 0 0 0 0
			forecolor 1 1 1 1
			visible MENU_TRUE
//			decoration
			mouseEnter 
			{
				play "mouse_over";
			}
			action 
			{
				play "mouse_click";
				uiScript sortPlayerProfiles 0
			}
		}

		itemDef 
		{
			name profilelist
			rect 380 150 250 260
			type ITEM_TYPE_LISTBOX
			style WINDOW_STYLE_FILLED
			elementwidth 120
			elementheight 14
			textscale .23

			elementtype LISTBOX_TEXT
			feeder FEEDER_PLAYER_PROFILES
			doubleclick
			{
				play "mouse_click";
				setdvar ui_playerProfileAlreadyChosen 1;
				uiScript loadPlayerProfile;
				close player_profile;
			}
			textalign 3
			textaligny 10
			forecolor 1 1 1 .9
			backcolor 0 0 0 0
			outlinecolor .9 .9 .9 .1
			visible MENU_TRUE
			mouseEnter {  setitemcolor profilelist bordercolor .7 0 0 1 } 
			mouseExit {  setitemcolor profilelist bordercolor .5 .5 .5 .5 } 
		}



////////////////////////////////////////////////////// 
		itemDef 
		{
			name load
			text "@MENU_OK"
			type 1
			textfont UI_FONT_NORMAL
			style UI_BUTTON_STYLE	
			textstyle UI_BUTTON_TEXT_STYLE
			border UI_BUTTON_BORDER
			bordercolor UI_BUTTON_BORDER_COLOR
			rect 370 420 60 20 			
			textalign 1
			textscale .3		
			textalignx 30
			textaligny 15
			forecolor UI_BUTTON_TEXT_COLOR
			backcolor	UI_BUTTON_BACK_COLOR
			visible MENU_TRUE
			dvarTest "ui_playerProfileSelected"
			hideDvar { "" }
			mouseEnter { play "mouse_over"; setitemcolor load backcolor UI_BUTTON_BACK_COLOR_HOVER } 
			mouseExit { setitemcolor load backcolor UI_BUTTON_BACK_COLOR }
			action
			{
				play "mouse_click";
				setdvar ui_playerProfileAlreadyChosen 1;
				uiScript loadPlayerProfile;
				close player_profile;
			}
  		}

		itemDef 
		{
			name load
			text "@MENU_CANCEL"
			type 1
			textfont UI_FONT_NORMAL
			style UI_BUTTON_STYLE	
			textstyle UI_BUTTON_TEXT_STYLE
			border UI_BUTTON_BORDER
			bordercolor UI_BUTTON_BORDER_COLOR
			rect 435 420 60 20 			
			textalign 1
			textscale .3		
			textalignx 30
			textaligny 15
			forecolor UI_BUTTON_TEXT_COLOR
			backcolor	UI_BUTTON_BACK_COLOR
			visible MENU_TRUE
			dvarTest "com_playerProfile"
			hideDvar { "" }
			mouseEnter { play "mouse_over"; setitemcolor load backcolor UI_BUTTON_BACK_COLOR_HOVER } 
			mouseExit { setitemcolor load backcolor UI_BUTTON_BACK_COLOR }
			action
			{
				play "mouse_click"; 
				setdvar ui_playerProfileAlreadyChosen 1;
				close player_profile;
			}
  		}
		itemDef 
		{
			name create
			text "@MENU_NEW"
			type 1
			textfont UI_FONT_NORMAL
			style UI_BUTTON_STYLE	
			textstyle UI_BUTTON_TEXT_STYLE
			border UI_BUTTON_BORDER
			bordercolor UI_BUTTON_BORDER_COLOR
			rect 500 420 60 20 
			textalign 1
			textscale .3		
			textalignx 30
			textaligny 15
			forecolor UI_BUTTON_TEXT_COLOR
			backcolor	UI_BUTTON_BACK_COLOR
			visible MENU_TRUE
			action { play "mouse_click"; open profile_create_popmenu;  }
			mouseEnter { play "mouse_over"; setitemcolor back backcolor UI_BUTTON_BACK_COLOR_HOVER } 
			mouseExit { setitemcolor back backcolor UI_BUTTON_BACK_COLOR }
		}

		itemDef 
		{
			name del
			text "@MENU_DELETE"
			type 1
			textfont UI_FONT_NORMAL
			style UI_BUTTON_STYLE	
			textstyle UI_BUTTON_TEXT_STYLE
			border UI_BUTTON_BORDER
			bordercolor UI_BUTTON_BORDER_COLOR
			rect 565 420 60 20 
			textalign 1
			textscale .3		
			textalignx 30
			textaligny 15
			forecolor UI_BUTTON_TEXT_COLOR
			backcolor	UI_BUTTON_BACK_COLOR
			visible MENU_TRUE
			mouseEnter { play "mouse_over"; setitemcolor del backcolor UI_BUTTON_BACK_COLOR_HOVER } 
			mouseExit { setitemcolor del backcolor UI_BUTTON_BACK_COLOR }
			action { play "mouse_click"; open profile_del_sure_popmenu }
  		}


	}	// end player_profile menudef 


/////////////////////
//
// Create profile popup
//
/////////////////////
	menuDef 
	{
		name "profile_create_popmenu"
		visible 0
		fullscreen 0
		//rect 217 200 210 85
		rect 204 160 235 135
		focusColor GLOBAL_FOCUSED_COLOR
		style 1
		border 1
		popup
		onOpen { setfocus createprofile; }
		onESC {	close profile_create_popmenu; }
		onClose { uiScript openMenuOnDvar ui_playerProfileCount 0 profile_must_create_popmenu; }


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
			text "@MENU_CREATE_PLAYER_PROFILE" 
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
		itemDef {
			name createprofile
			group "createprofilegroup"
			type ITEM_TYPE_VALIDFILEFIELD	// only take text that's valid for a profile
			dvar "ui_playerProfileNameNew"
			//text "@MENU_SAVEAS"
			text "@MENU_NAME1"
			style 1
			maxchars 14			// (SA)
			maxPaintChars 14	// (SA)
			rect 40 55 200 20
			//border 1
			//bordercolor .5 .5 .5 .5
			textalign ITEM_ALIGN_LEFT
			textaligny 14
			textalignx 0
			textscale .35        
			outlinecolor 1 .5 .5 .5
			forecolor .9 .9 .9 1
			backcolor OPTIONS_CONTROL_BACKCOLOR
			mouseEnter { setitemcolor loadname backcolor .3 .5 .2 .25 play "mouse_over"}
			mouseExit { setitemcolor loadname backcolor 0 0 0 .25 }
			visible 1 

			accept
			{
				play "mouse_click"; 
				uiScript createPlayerProfile;
				close profile_create_popmenu; 
			}
		}
		itemDef 
		{
			name		createsure_ok
			text		"@MENU_OK"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		30 110 60 30
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
				uiScript createPlayerProfile;
				close profile_create_popmenu; 
			}
			mouseEnter { 
				setitemcolor sdelsure_yes backcolor UI_BUTTON_BACK_COLOR_HOVER ;
				play "mouse_over";
			} 
			mouseExit { setitemcolor sdelsure_yes backcolor UI_BUTTON_BACK_COLOR } 	
			
		}

		itemDef 
		{
			name		createsure_cancel
			text		"@MENU_CANCEL"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		150 110 60 30
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
				close profile_create_popmenu; 
				
			}
			mouseEnter
			{ 
				setitemcolor sdelsure_no backcolor UI_BUTTON_BACK_COLOR_HOVER 
				play "mouse_over"
			} 
			mouseExit
			{ 
			setitemcolor sdelsure_no backcolor UI_BUTTON_BACK_COLOR 
			}		
		}	

	

	}


/////////////////////
//
// Must create new profile popup
//
/////////////////////
	menuDef 
	{
		name "profile_must_create_popmenu"
		visible 0
		fullscreen 0
		//rect 217 200 210 85
		rect 204 160 235 135
		focusColor GLOBAL_FOCUSED_COLOR
		style 1
		border 1
		popup
		onESC { close profile_must_create_popmenu; }
		onClose { open profile_create_popmenu; }


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
			text "@MENU_CREATE_PLAYER_PROFILE" 
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
			name confirm
			text "@MENU_NEED_PLAYER_PROFILE"
			style 0
			textscale .35
			textstyle ITEM_TEXTSTYLE_SHADOWED
			rect 126 55 110 20
			textalign 1
			textalignx -7
			textaligny 5
			decoration
			forecolor .9 .9 .9 1
			visible 1
		}
		itemDef 
		{
			name		createsure_ok
			text		"@MENU_OK"
			type		1
			textscale	.45
			style		UI_BUTTON_STYLE
			textfont	UI_FONT_NORMAL
			textstyle	ITEM_TEXTSTYLE_SHADOWED
			rect		87 110 60 30
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
				close profile_must_create_popmenu; 
			}
			mouseEnter { 
				setitemcolor sdelsure_yes backcolor UI_BUTTON_BACK_COLOR_HOVER ;
				play "mouse_over";
			} 
			mouseExit { setitemcolor sdelsure_yes backcolor UI_BUTTON_BACK_COLOR } 	
		}
	}



/////////////////////
//
// Delete for sure? popup
//
/////////////////////
	menuDef 
	{
		name "profile_del_sure_popmenu"
		visible 0
		fullscreen 0
		//rect 217 200 210 85
		rect 204 160 235 135
		focusColor GLOBAL_FOCUSED_COLOR
		style 1
		border 1
		popup
		onESC { close profile_del_sure_popmenu;	}

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
			text "@MENU_DELETE_PROFILE" 
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

			// delete the selected profile and update the list
			action
			{
				play "mouse_click"; 
				uiScript deletePlayerProfile;
				uiScript openMenuOnDvar ui_playerProfileCount 0 profile_must_create_popmenu;
				close profile_del_sure_popmenu; 
			}
			mouseEnter
			{ 
				setitemcolor sdelsure_yes backcolor UI_BUTTON_BACK_COLOR_HOVER 
				play "mouse_over"
			} 
			mouseExit
			{ 
			setitemcolor sdelsure_yes backcolor UI_BUTTON_BACK_COLOR
			} 
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
				close profile_del_sure_popmenu ; 
			}

			mouseEnter { setitemcolor sdelsure_no backcolor UI_BUTTON_BACK_COLOR_HOVER 
			play "mouse_over"} 
			mouseExit { setitemcolor sdelsure_no backcolor UI_BUTTON_BACK_COLOR } 		

			}	// end item		
		}	// end profile_del_sure_popmenu menudef 


menuDef {
	name profile_exists_popmenu
	visible 0
	fullscreen 0
	rect 220 220 200 80
	focusColor GLOBAL_FOCUSED_COLOR

	backcolor .1 .15 .1 1
	border 1
	bordercolor .5 .5 .5 .5
	style WINDOW_STYLE_FILLED
	popup
	onESC {
		close profile_exists_popmenu;
	}


	itemDef {
		name confirm
//		text "@MENU_OVERWRITE_EXISTING_FILE"
		text "@MENU_A_PROFILE_WITH_THE_SAME_NAME_ALREADY_EXISTS"
		style 0
		textscale .24
		textstyle 3
		rect 0 0 212 60
		textalign ITEM_ALIGN_CENTER
		textalignx 100
		textaligny 20
		decoration
		forecolor 1 1 1 1
		visible 1
		}



	itemDef {
		name already_exist_ok
		text "@MENU_OK"
		type 1
		style UI_BUTTON_STYLE
		textstyle UI_BUTTON_TEXT_STYLE
		textfont UI_FONT_NORMAL
		textscale .25
		rect 25 35 50 20
		textalign ITEM_ALIGN_CENTER
		textalignx 23
		textaligny 15
		border UI_BUTTON_BORDER
		bordercolor UI_BUTTON_BORDER_COLOR
		forecolor UI_BUTTON_TEXT_COLOR
		backcolor UI_BUTTON_BACK_COLOR
		visible 1
		action { play "mouse_click"; close profile_exists_popmenu;}
		mouseEnter { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR_HOVER 
		play "mouse_over"} 
		mouseExit { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR } 		
		}

	}	// end profile_exists_popmenu menudef


menuDef {
	name profile_create_fail_popmenu
	visible 0
	fullscreen 0
	rect 220 200 200 100
	focusColor GLOBAL_FOCUSED_COLOR

	backcolor .1 .15 .1 1
	border 1
	bordercolor .5 .5 .5 .5
	style WINDOW_STYLE_FILLED
	popup
	onESC {
		close profile_create_fail_popmenu;
	}

	itemDef {
		name confirm
//		text "@MENU_PROFILE_CREATE_FAIL"
		text "@MENU_PROFILE_CREATION_FAILED"	
		style 0
		textscale .24
		textstyle 3
		rect 0 0 212 60
		textalign ITEM_ALIGN_CENTER
		textalignx 100
		textaligny 20
		decoration
		forecolor 1 1 1 1
		visible 1
		}

	itemDef {
		name create_fail_ok
		text "@MENU_OK"
		type 1
		style UI_BUTTON_STYLE
		textstyle UI_BUTTON_TEXT_STYLE
		textfont UI_FONT_NORMAL
		textscale .25
		rect 75 75 50 20
		textalign ITEM_ALIGN_CENTER
		textalignx 23
		textaligny 15
		border UI_BUTTON_BORDER
		bordercolor UI_BUTTON_BORDER_COLOR
		forecolor UI_BUTTON_TEXT_COLOR
		backcolor UI_BUTTON_BACK_COLOR
		visible 1
		action { play "mouse_click"; close profile_create_fail_popmenu;}
		mouseEnter { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR_HOVER 
		play "mouse_over"} 
		mouseExit { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR } 		
		}

	}	// end profile_create_fail_popmenu menudef




menuDef {
	name profile_create_too_many_popmenu
	visible 0
	fullscreen 0
	rect 220 200 200 100
	focusColor GLOBAL_FOCUSED_COLOR

	backcolor .1 .15 .1 1
	border 1
	bordercolor .5 .5 .5 .5
	style WINDOW_STYLE_FILLED
	popup
	onESC {
		close profile_create_too_many_popmenu;
	}

	itemDef {
		name confirm
		text "@MENU_PROFILE_CREATE_TOO_MANY"	
		style 0
		textscale .24
		textstyle 3
		rect 0 0 212 60
		textalign ITEM_ALIGN_CENTER
		textalignx 100
		textaligny 20
		decoration
		forecolor 1 1 1 1
		visible 1
		}

	itemDef {
		name create_too_many_ok
		text "@MENU_OK"
		type 1
		style UI_BUTTON_STYLE
		textstyle UI_BUTTON_TEXT_STYLE
		textfont UI_FONT_NORMAL
		textscale .25
		rect 75 75 50 20
		textalign ITEM_ALIGN_CENTER
		textalignx 23
		textaligny 15
		border UI_BUTTON_BORDER
		bordercolor UI_BUTTON_BORDER_COLOR
		forecolor UI_BUTTON_TEXT_COLOR
		backcolor UI_BUTTON_BACK_COLOR
		visible 1
		action { play "mouse_click"; close profile_create_too_many_popmenu;}
		mouseEnter { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR_HOVER 
		play "mouse_over"} 
		mouseExit { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR } 		
		}

	}	// end profile_create_too_many_popmenu menudef


player_profile_ingame_warning

menuDef {
	name profile_delete_fail_popmenu
	visible 0
	fullscreen 0
	rect 220 200 200 100
	focusColor GLOBAL_FOCUSED_COLOR

	backcolor .1 .15 .1 1
	border 1
	bordercolor .5 .5 .5 .5
	style WINDOW_STYLE_FILLED
	popup
	onESC {
		close profile_delete_fail_popmenu;
	}

	itemDef {
		name confirm
//		text "@MENU_PROFILE_DELETE_FAIL"
		text "@MENU_PROFILE_DELETION_FAILED"	
		style 0
		textscale .24
		textstyle 3
		rect 0 0 212 60
		textalign ITEM_ALIGN_CENTER
		textalignx 100
		textaligny 20
		decoration
		forecolor 1 1 1 1
		visible 1
		}

	itemDef {
		name create_fail_ok
		text "@MENU_OK"
		type 1
		style UI_BUTTON_STYLE
		textstyle UI_BUTTON_TEXT_STYLE
		textfont UI_FONT_NORMAL
		textscale .25
		rect 75 75 50 20
		textalign ITEM_ALIGN_CENTER
		textalignx 23
		textaligny 15
		border UI_BUTTON_BORDER
		bordercolor UI_BUTTON_BORDER_COLOR
		forecolor UI_BUTTON_TEXT_COLOR
		backcolor UI_BUTTON_BACK_COLOR
		visible 1
		action { play "mouse_click"; close profile_delete_fail_popmenu;}
		mouseEnter { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR_HOVER 
		play "mouse_over"} 
		mouseExit { setitemcolor overwrite_ok backcolor UI_BUTTON_BACK_COLOR } 		
		}

	}	// end profile_delete_fail_popmenu menudef


}	// end menu
