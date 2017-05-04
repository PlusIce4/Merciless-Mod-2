#include "ui_mp/menudef.h"

#define ORIGIN_QUICKMESSAGETAB			32 224
#define ORIGIN_QUICKMESSAGEWINDOW		32 256

{
	menuDef
	{
		name			"class_special"
		visible			0
		fullscreen		0
		rect			0 0 640 480
		focuscolor		1 1 1 1
		disablecolor		0 0 0 0
 		style			WINDOW_STYLE_EMPTY

		onOpen
		{
			setDvar cl_bypassMouseInput "1"
		}
		onClose
		{
			setDvar cl_bypassMouseInput "0"
		}

// WINDOW BACKGROUND
		itemDef
		{
			name			"window_background"
			visible			1
			rect			0 0 224 192
			origin			ORIGIN_QUICKMESSAGEWINDOW
			style			WINDOW_STYLE_FILLED
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			decoration
		}
	
// WINDOW LINES
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			3 0 2 187
			origin			ORIGIN_QUICKMESSAGEWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			219 0 2 187
			origin			ORIGIN_QUICKMESSAGEWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			5 0 214 2
			origin			ORIGIN_QUICKMESSAGEWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}
		itemDef
		{
			name			"window_lines"
			visible			1
			rect			3 187 218 2
			origin			ORIGIN_QUICKMESSAGEWINDOW
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

// TITLE
		itemDef
		{
			name			"title"
			visible			1
			rect			0 0 224 32
			origin			ORIGIN_QUICKMESSAGETAB
			style			WINDOW_STYLE_FILLED
			forecolor		1 1 1 1
			backcolor		0 0 0 0.7975
			type			ITEM_TYPE_TEXT
			text			"@QUICKMESSAGE_QUICK_MESSAGE"
			textfont		UI_FONT_NORMAL
			textscale		.24
			textalignx		112
			textaligny		24
			textalign		ITEM_ALIGN_CENTER
			decoration
		}
		itemDef
		{
			name			"title_quickmessage_gray"
			visible			1
			rect			3 3 218 29
			origin			ORIGIN_QUICKMESSAGETAB
			style			WINDOW_STYLE_FILLED
			backcolor		1 1 1 .125
			decoration
		}

		itemDef
		{
			name			"window"
			visible			1
			rect			16 20 0 0
			origin			ORIGIN_QUICKMESSAGEWINDOW
			forecolor		1 1 1 1
			textfont		UI_FONT_NORMAL
			textscale		.24
			textaligny		8
			text			"@QUICKMESSAGE_1_COMMANDS"
			decoration
		}
		execKey "1" { close class_special; scriptMenuResponse "special" }

		itemDef
		{
			name			"window"
			visible			1
			rect			16 68 0 0
			origin			ORIGIN_QUICKMESSAGEWINDOW
			forecolor		1 1 1 1
			textfont		UI_FONT_NORMAL
			textscale		.24
			textaligny		8
			text			"@QUICKMESSAGE_ESC_EXIT"
			decoration
		}
	}
}
