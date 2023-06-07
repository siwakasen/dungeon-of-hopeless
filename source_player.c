#include "header.h"
void generatePlayer(char map[baris][kolom],int x, int y){
    map[y][x]=player;
}
void movement(int *x, int *y,char move,char map[baris][kolom]){
    if(move=='w'){ //up
        *y=*y-1;
    }else if(move=='a'){ //left        
        *x=*x-1;
    }else if(move=='s'){ //down
        *y=*y+1;
    }else if(move=='d'){ //right
        *x=*x+1;
    }
    // semua pengecekan movement di pindah ke isValidMove
}

boolean isValidMove(int x, int y,char move,char map[baris][kolom]){
	if(move=='w'){ //up
        if(map[(y-1)][(x)]=='#' || map[(y-1)][(x)]=='|'){
            return false;
        }else return true;
    }else if(move=='a'){ //left
        if(map[(y)][(x-1)]=='#' || map[(y)][(x-1)]=='|'){
            return false;
        }else return true;
    }else if(move=='s'){ //down
        if(map[(y+1)][(x)]=='#' || map[(y+1)][(x)]=='|'){
            return false;
        }else return true;
    }else if(move=='d'){ //right
        if(map[(y)][(x+1)]=='#' || map[(y)][(x+1)]=='|'){
            return false;
        }else return true;
    }
    else return false;
}

void attack(int x, int y,char map[baris][kolom], bool isEnemy[], int xE[], int yE[]){
    int i;
    for(i=0;i<12;i++){
        if(map[(y-1)][(x)]!='#' && map[(y-1)][(x)]!='|'){
            if(y-1==yE[i] && x==xE[i]) isEnemy[i]=false;
            map[(y-1)][(x)]='@';
        }
        if(map[(y)][(x-1)]!='#' && map[(y)][(x-1)]!='|'){
            if(y==yE[i] && x-1==xE[i]) isEnemy[i]=false;
            map[(y)][(x-1)]='@';
        }
        if(map[(y+1)][(x)]!='#' && map[(y+1)][(x)]!='|'){ 
            if(y+1==yE[i] && x==xE[i]) isEnemy[i]=false; 
            map[(y+1)][(x)]='@';
        }
        if(map[(y)][(x+1)]!='#' && map[(y)][(x+1)]!='|'){
            if(y==yE[i] && x+1==xE[i]) isEnemy[i]=false;
            map[(y)][(x+1)]='@';
        }
    }
    showMap(map);
    Sleep(20);
}

void takeItem(int x, int y, bool key[]){ //nggak bisa untuk map lain
    if(y==13 && x==42){
        key[0]=true;
    }else if(y==7 && x==22){
        key[1]=true;
    }else if(y==22 && x==57){
        key[2]=true;
    }
}

boolean isValidTakeItem(int x, int y, bool key[]){
	if(y==13 && x==42 && !key[0]){
        return true;
    }else if(y==7 && x==22 && !key[1]){
        return true;
    }else if(y==22 && x==57 && !key[2]){
        return true;
    }else return false;
}

void openGate(int x, int y, bool key[],bool gateStatus[]){
    if(key[0] && y==3 && x==33){
        gateStatus[0]=true;
    }
    if(key[1] && y==1 && x==42){
        gateStatus[1]=true;
    }
    if(key[2] && y==25 && x==68){
        gateStatus[2]=true;
    }
}

bool isValidOpenGate(int x, int y, bool key[],bool gateStatus[]){
    if(key[0] && y==3 && x==33 && !gateStatus[0]){
        return true;
    }
    if(key[1] && y==1 && x==42 && !gateStatus[1]){
        return true;
    }
    if(key[2] && y==25 && x==68 && !gateStatus[2]){
        return true;
    }
    
    return false;
}


bool checkAlive(int x, int y, int xE[], int yE[], bool enemyAlive[]){
    int i;
    for(i=0;i<12;i++){
        if(xE[i]==x && yE[i]==y && enemyAlive[i]){
            return false;
        }
    }
    return true;
}
