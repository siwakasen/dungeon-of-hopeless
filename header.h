#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <ctype.h> //untuk tolower
#define ESC 27
#define baris 27
#define kolom 70
#define player 'P'
#define enemy 'E'

void red();
void green();
void reset();
void hide_cur();
void screen_console(int WIDTH,int HEIGHT);
void gotoxy(int x, int y);
void resetGame(int *y, int *x, bool *playerAlive, int yE[], int xE[], bool enemyAlive[],bool inDistance[], bool key[], bool gateStatus[]);
int killCount(bool enemyAlive[]);
void showInfo();
void clearRightMap();
void showGameOver();
void showWin();
void showHowPlay();

void showMap(char map[baris][kolom]);
void generateMap(char map[baris][kolom]);
void generateKey(char map[baris][kolom], bool key[]);
void generateGate(char map[baris][kolom],bool gateStatus[]);

//action player
void generatePlayer(char map[baris][kolom],int x, int y);
void movement(int *x, int *y,char move,char map[baris][kolom]);
boolean isValidMove(int x, int y,char move,char map[baris][kolom]);
void attack(int x, int y,char map[baris][kolom],bool isEnemy[], int xE[], int yE[]);
void takeItem(int x, int y,bool key[]);
boolean isValidTakeItem(int x, int y, bool key[]);
void openGate(int x, int y, bool key[],bool gateStatus[]);
bool isValidOpenGate(int x, int y, bool key[],bool gateStatus[]);
bool checkAlive(int x, int y, int xE[], int yE[], bool enemyAlive[]);

//action enemy
void enemyMovement(char map[baris][kolom],int x, int y, int xE[], int yE[], bool inDistance[],bool isEnemy[]);
void randMove(char map[baris][kolom] ,int xE[], int yE[], int indxE);
void aprroachMove(char map[baris][kolom] ,int xE[], int yE[],int x, int y,int idxE);
void generateEnemy(char map[baris][kolom], int xE[], int yE[],  bool isEnemy[],bool inDistance[]);
