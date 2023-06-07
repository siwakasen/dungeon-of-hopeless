#include "header.h"


int main(int argc, char *argv[]) {
	srand(time(NULL));
	char menu;
	//mapping
	char map[baris][kolom];

	//player
	int y=1,x= 2;
	char move;
	bool playerAlive=true;
	
	//enemy
	int yE[12]={5,11,11,3,5,11,11,19,19,20,22,23},xE[12]={10,16,37,37,27,49,59,43,22,6,54,64};
	bool enemyAlive[12]={true,true,true,true,true,true,true,true,true,true,true,true};
	bool inDistance[12]={false,false,false,false,false,false,false,false,false,false,false,false};

	//gate
	bool key[3]={false,false,false};
	bool gateStatus[3]={false,false,false};
	hide_cur();
	do{
		system("cls");
		printf("\n --===[ Dungeon of Hopeless ]===--\n");
		printf("\n [1] Play ");
		printf("\n [2] Introduction");
		printf("\n [ESC] Exit");
		printf("\n >>> "); menu=getch();

		switch(menu){
			case '1':
				system("cls");
				do{
					generateMap(map);
					generateKey(map,key);
					generateGate(map,gateStatus);
					generatePlayer(map,x,y);
					generateEnemy(map,xE,yE,enemyAlive,inDistance);
					showMap(map);
//					gotoxy(80, 16); printf("         "); 
//					gotoxy(80, 16); printf("%d %d",y,x); 
					 if(key[0]){
					 	gotoxy(80,13); printf("Key : ~");
					 }
					 if(key[1]){
					 	gotoxy(88,13); printf("~");
					 }
					 if(key[2]){
					 	gotoxy(90,13); printf("~");
					 }
					 if(killCount(enemyAlive)!=0){
						gotoxy(80,14); printf("Kill Count : %d",killCount(enemyAlive));
					 } 
					showInfo();
					move=getch();
          			move=tolower(move);
					
					if(move != 'w' && move != 'a' && move != 's' && move != 'd' && 
					   move != 'f' && move != 32  && move != 13)
					   continue;
					if(move == 'w' || move == 'a' || move == 's' || move == 'd'){
						if(isValidMove(x, y, move, map)) movement(&x,&y,move,map);
						else continue;
					}else if(move==32){
						attack(x,y,map,enemyAlive,xE,yE);
					}else if(move=='f'){
						if(isValidTakeItem(x, y, key)) takeItem(x,y,key);
						else continue;
					}else if(move==13){
						if(isValidOpenGate(x, y, key, gateStatus)) openGate(x,y,key,gateStatus);
						else continue;
					}
					enemyMovement(map,x,y,xE,yE,inDistance, enemyAlive);
					playerAlive=checkAlive(x,y,xE,yE,enemyAlive);
					if(!playerAlive){
						generateMap(map);
						generateKey(map,key);
						generateGate(map,gateStatus);
						generatePlayer(map,x,y);
						generateEnemy(map,xE,yE,enemyAlive,inDistance);
						showMap(map);
						clearRightMap();
						showGameOver();
					}
					if(y==1 && x==0){
						generateMap(map);
						generateKey(map,key);
						generateGate(map,gateStatus);
						generatePlayer(map,x,y);
						generateEnemy(map,xE,yE,enemyAlive,inDistance);
						showMap(map);
						showInfo();
						gotoxy(80,15);printf("[!] Back to menu . . . ");
						break;
					}if(y==25 && x==69){
						generateMap(map);
						generateKey(map,key);
						generateGate(map,gateStatus);
						generatePlayer(map,x,y);
						generateEnemy(map,xE,yE,enemyAlive,inDistance);
						showMap(map);
						playerAlive=false;
						clearRightMap();
						showWin();
					}
				}while(playerAlive);
				if(!playerAlive){
					resetGame(&y,&x,&playerAlive,yE,xE,enemyAlive,inDistance,key,gateStatus);
				}

			break;
			case '2':
				showHowPlay();
				
			break;
			case 27:
				printf("\n [~] Closing program . . .");
			break;
			default:
				printf("\n [!] Menu doesn't exist");
			break;
		}
		getch();
	}while(menu!=27);

						
	
	return 0;
}
