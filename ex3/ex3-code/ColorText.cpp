#include "ColorText.h"
#include <windows.h>
//------------------define------------------------------------------
#define FG_DEFAULT 7
#define FG_RED 12
//-----------------ShowConsoleCursor---------------------------------
// sets the visibility of console cursor
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO  cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;			// set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
//-----------------SetOutputColor------------------------------------
//sets the console colors (using WORD flags)
void SetOutputColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG_RED);
}
//----------------ResetOutputColor------------------------------------
//sets the console to default colors
void ResetOutputColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FG_DEFAULT);
}

