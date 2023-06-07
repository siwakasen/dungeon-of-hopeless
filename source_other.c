#include "header.h"
void red(){
    printf("\033[0;31m");
}
void green(){
    printf("\033[0;32m");
}
void reset(){
    printf("\033[0;0m");
}
void hide_cur()	//MENGHILANGKAN VISUAL KURSOR
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void screen_console(int WIDTH,int HEIGHT)	//UNTUK MENENTUKAN PANJANG DAN LEBAR LAYAR KONSOL
{
	SMALL_RECT windowSize = {0, 0, WIDTH, HEIGHT};
   	COORD bufferSize = {WIDTH+1, HEIGHT+1};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &windowSize);
}

void gotoxy(int x, int y) 		//UNTUK MENENTUKAN KOORDINAT X dan Y
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void resetGame(int *y, int *x, bool *playerAlive, int yE[], int xE[], bool enemyAlive[],bool inDistance[], bool key[], bool gateStatus[]){
	*y=1;*x= 2;
	*playerAlive=true;
	int i;

	for(i=0;i<3;i++){
		key[i]=false;
		gateStatus[i]=false;
	}
	for(i=0;i<12;i++){
		enemyAlive[i]=true;
		inDistance[i]=false;
	}
	yE[0]=5;xE[0]=10;
	yE[1]=11;xE[1]=16; 
	yE[2]=11;xE[2]=37;
	yE[3]=3;xE[3]=37; 
	yE[4]=5;xE[4]=27;  
	yE[5]=11;xE[5]=49; 
	yE[6]=11;xE[6]=59; 
	yE[7]=19;xE[7]=43; 
	yE[8]=19;xE[8]=22; 
	yE[9]=20;xE[9]=6;  
	yE[10]=22;xE[10]=54; 
	yE[11]=23;xE[11]=64;
}

int killCount(bool enemyAlive[]){
	int i,sum=0;
	for(i=0;i<12;i++){
		if(enemyAlive[i]==false) sum+=1;
	}
	return sum;
}
void showInfo(){
	gotoxy(80,3);printf("--===[ DUNGEON OF HOPELESS ]===--");
	gotoxy(80,5);printf("    W         ");
	gotoxy(80,6);printf("  A S D       [Spacebar]"); 
	gotoxy(80,7);printf(" Movement       Attack");
	gotoxy(80,9);printf("   [F]         [ENTER]");
	gotoxy(80,10);printf("Take a key    Open Gate");
}
void clearRightMap(){
	gotoxy(80,3);printf("                                 ");
	gotoxy(80,5);printf("                                 ");
	gotoxy(80,6);printf("                                 "); 
	gotoxy(80,7);printf("                                 ");
	gotoxy(80,9);printf("                                 ");
	gotoxy(80,10);printf("                                ");
	gotoxy(80,13);printf("                                ");
	gotoxy(80,14);printf("                                ");
	gotoxy(80,16);printf("                                ");

}
void showGameOver(){
	red();
	gotoxy(0,10);printf("                                                                                        ");
	gotoxy(0,11);printf(" oooooo   oooo   .oooooo.   ooooo     ooo  oooooooooo.   ooooo oooooooooooo oooooooooo. ");
	gotoxy(0,12);printf("  `888.   .8'   d8P'  `Y8b  `888'     `8'  `888'   `Y8b  `888' `888'     `8 `888'   `Y8b ");
	gotoxy(0,13);printf("   `888. .8'   888      888  888       8    888      888  888   888          888      888 ");
	gotoxy(0,14);printf("    `888.8'    888      888  888       8    888      888  888   888oooo8     888      888 ");
	gotoxy(0,15);printf("     `888'     888      888  888       8    888      888  888   888    '     888      888 ");
	gotoxy(0,16);printf("      888      `88b    d88'  `88.    .8'    888     d88'  888   888       o  888     d88' ");
	gotoxy(0,17);printf("     o888o      `Y8bood8P'     `YbodP'     o888bood8P'   o888o o888ooooood8 o888bood8P' ");
	gotoxy(0,18);printf("                                                                                       ");
	reset();
}            

void showWin(){
	green();
	gotoxy(0,10);printf("                                                                                        ");
	gotoxy(0,11);printf(" oooooo   oooo   .oooooo.   ooooo     ooo  oooooo   oooooo     oooo ooooo ooooo      ooo ");
	gotoxy(0,12);printf("  `888.   .8'   d8P'  `Y8b  `888'     `8'   `888.    `888.     .8'  `888' `888b.     `8' ");
	gotoxy(0,13);printf("   `888. .8'   888      888  888       8     `888.   .8888.   .8'    888   8 `88b.    8 ");
	gotoxy(0,14);printf("    `888.8'    888      888  888       8      `888  .8'`888. .8'     888   8   `88b.  8 ");
	gotoxy(0,15);printf("     `888'     888      888  888       8       `888.8'  `888.8'      888   8     `88b.8 ");
	gotoxy(0,16);printf("      888      `88b    d88'  `88.    .8'        `888'    `888'       888   8       `888 ");
	gotoxy(0,17);printf("     o888o      `Y8bood8P'     `YbodP'           `8'      `8'       o888o o8o        `8 ");
	gotoxy(0,18);printf("                                                                                       ");
	reset();	
}
void showHowPlay(){
	printf("\n\t\t--=== How To Play ===--\n");
	printf("\n\t[W]        : Move Up");
	printf("\n\t[S]        : Move Down");
	printf("\n\t[A]        : Move Left");
	printf("\n\t[D]        : Move Right");
	printf("\n\t[SPACEBAR] : Attack");
	printf("\n\t[F]        : Take Item");
	printf("\n\t[ENTER]    : Open Gate");
	printf("\n\n\tP --> Player");
	printf("\n\tE --> Enemy");
	printf("\n\t~ --> Key");
	printf("\n\t| --> Closed Gate");
	printf("\n\t%c --> Opened Gate",177);
	printf("\n\n\tTips to play : ");
	printf("\n\tThere is some tips to play this game : ");
	printf("\n\t - To kill enemy, u must stand next to the enemy to kill it");
	printf("\n\t - To taking key, u must stand on the key");
	printf("\n\t - To Open the gate, u must have the right key");
	printf("\n\t   and stand next to the gate to open it");
	printf("\n\t - For full guide to play this game, open FULLGUIDE.pdf");
}
