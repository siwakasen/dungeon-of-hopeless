#include "header.h"

void hide_cur()	//MENGHILANGKAN VISUAL KURSOR
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize=20;
	ConCurInf.bVisible=FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
}

void gotoxy(int x, int y) 		//UNTUK MENENTUKAN KOORDINAT X dan Y
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
