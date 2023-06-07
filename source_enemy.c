#include "header.h"
void generateEnemy(char map[baris][kolom], int xE[], int yE[],  bool enemyAlive[],bool inDistance[]){
    int i,j,k;
    for(i=0;i<12;i++){
        if(enemyAlive[i]){
            map[yE[i]][xE[i]]=enemy;
            if(inDistance[i] && map[yE[i]-1][xE[i]]!='#' && map[yE[i]-1][xE[i]]!='P'){
                map[yE[i]-1][xE[i]]='!';
            }
        }
    }
}
void enemyMovement(char map[baris][kolom],int x, int y, int xE[], int yE[],bool inDistance[],bool enemyAlive[]){
    int i;
    for(i=0;i<12;i++){
        if(enemyAlive[i]){
            if(y >=3 && y<=7 && x>=1 && x<=20){
                if(yE[i] >=3 && yE[i]<=7 && (xE[i]>=1 && xE[i]<=20 )){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=3 && y<=7 && x>=22 && x<=31){
                if(yE[i] >=3 && yE[i]<=7 && xE[i]>=22 && xE[i]<=31){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=9 && y<=13 && x>=11 && x<=21){
                if(yE[i] >=9 && yE[i]<=13 &&xE[i]>=11 && xE[i]<=21){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=9 && y<=13 && x>=33 && x<=42){
                if(yE[i] >=9 && yE[i]<=13 && xE[i]>=33 && xE[i]<=42){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=9 && y<=13 && x>=44 && x<=64){
                if(yE[i] >=9 && yE[i]<=13 && xE[i]>=44 && xE[i]<=64){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=1 && y<=5 && x>=33 && x<=42){
                if(yE[i]>=1 && yE[i]<=5 && xE[i]>=33 && xE[i]<=42){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=15 && y<=19 && x>=12 && x<=63){
                if(yE[i] >=15 && yE[i]<=19 && xE[i]>=12 && xE[i]<=63){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=17 && y<=23 && x>=1 && x<=10){
                if(yE[i] >=17 && yE[i]<=23 && xE[i]>=1 && xE[i]<=10){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=21 && y<=22 && x>=33 && x<=57){
                if(yE[i] >=21 && yE[i]<=22 && xE[i]>=33 && xE[i]<=57){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else if(y >=21 && y<=25 && x>=59 && x<=68){
                if(yE[i] >=21 && yE[i]<=25 && xE[i]>=59 && xE[i]<=68){
                    inDistance[i]=true;
                    aprroachMove(map,xE,yE,x,y,i);
                }else{
                    inDistance[i]=false;
                    randMove(map,xE,yE,i);
                }
            }else{
                inDistance[i]=false;
                randMove(map,xE,yE,i);
            }
        }
    }
}
void randMove(char map[baris][kolom] ,int xE[], int yE[], int idxE){
   bool valid=false;
   int move,i;
   int tempY=yE[idxE],tempX=xE[idxE];
    do{
        move=(rand() % (8-1+1)+1);
        if(move==1){ //up
            if(map[(yE[idxE])-1][(xE[idxE])]!='#' && map[(yE[idxE])-1][(xE[idxE])]!='E'  && map[(yE[idxE])-1][(xE[idxE])]!='~'){
                yE[idxE]=yE[idxE]-1;
            }
        }else if(move==2){ //left
            if(map[(yE[idxE])][(xE[idxE]-1)]!='#' && map[(yE[idxE])][(xE[idxE]-1)]!='E'  && map[(yE[idxE])][(xE[idxE]-1)]!='~'){
                xE[idxE]=xE[idxE]-1;
            }
        }else if(move==3){ //down
            if(map[(yE[idxE])+1][(xE[idxE])]!='#' && map[(yE[idxE])+1][(xE[idxE])]!='E'  && map[(yE[idxE])+1][(xE[idxE])]!='~'){
                yE[idxE]=yE[idxE]+1;
            }
        }else if(move==4){ //right
            if(map[(yE[idxE])][(xE[idxE]+1)]!='#' && map[(yE[idxE])][(xE[idxE]+1)]!='E'  && map[(yE[idxE])][(xE[idxE]+1)]!='~'){
                xE[idxE]=xE[idxE]+1;
            }
        }else if(move==5){ //up-left
            if(map[(yE[idxE]-1)][(xE[idxE]-1)]!='#' && map[(yE[idxE]-1)][(xE[idxE]-1)]!='E' && map[(yE[idxE]-1)][(xE[idxE]-1)]!='~'){
                yE[idxE]=yE[idxE]-1;
                xE[idxE]=xE[idxE]-1;
            }
        }else if(move==6){ //down-left
            if(map[(yE[idxE]+1)][(xE[idxE]-1)]!='#' && map[(yE[idxE]+1)][(xE[idxE]-1)]!='E' && map[(yE[idxE]+1)][(xE[idxE]-1)]!='~'){
                yE[idxE]=yE[idxE]+1;
                xE[idxE]=xE[idxE]-1;
            }
        }else if(move==7){//down-right
            if(map[(yE[idxE]+1)][(xE[idxE]+1)]!='#' && map[(yE[idxE]+1)][(xE[idxE]+1)]!='E' &&  map[(yE[idxE]+1)][(xE[idxE]+1)]!='~'){
                yE[idxE]=yE[idxE]+1;
                xE[idxE]=xE[idxE]+1;
            }
        }else if(move==8){//up-right
            if(map[(yE[idxE]-1)][(xE[idxE]+1)]!='#' && map[(yE[idxE]-1)][(xE[idxE]+1)]!='E' &&  map[(yE[idxE]-1)][(xE[idxE]+1)]!='~'){
                yE[idxE]=yE[idxE]-1;
                xE[idxE]=xE[idxE]+1;
            }
        }
        if(yE[idxE] >=3 && yE[idxE]<=7 && (xE[idxE]>=1 && xE[idxE]<=20 || xE[idxE]>=22 && xE[idxE]<=31)){
            valid=true;
        }else if(yE[idxE] >=9 && yE[idxE]<=13 && (xE[idxE]>=11 && xE[idxE]<=21 || xE[idxE]>=33 && xE[idxE]<=42 || xE[idxE]>=44 && xE[idxE]<=64)){
            valid=true;
        }else if(yE[idxE] >=1 && yE[idxE]<=5 && xE[idxE]>=33 && xE[idxE]<=42){
            valid=true;
        }else if(yE[idxE] >=15 && yE[idxE]<=19 && xE[idxE]>=12 && xE[idxE]<=63){
            valid=true;
        }else if(yE[idxE] >=17 && yE[idxE]<=23 && xE[idxE]>=1 && xE[idxE]<=10){
            valid=true;
        }else if(yE[idxE] >=21 && yE[idxE]<=22 && xE[idxE]>=33 && xE[idxE]<=57){
            valid=true;
        }else if(yE[idxE] >=21 && yE[idxE]<=25 && xE[idxE]>=59 && xE[idxE]<=68){
            valid=true;
        }else{
            yE[idxE]=tempY;
            xE[idxE]=tempX;
        }
    }while(!valid);
}
void aprroachMove(char map[baris][kolom] ,int xE[], int yE[],int x, int y,int idxE){
   int i;
   double move,min;
   int tempX=xE[idxE],tempY=yE[idxE];
   bool valid=false;
    min=sqrt(pow(y-yE[idxE],2)+pow(x-xE[idxE],2));
    for(i=1;i<=8;i++){
        switch(i){
            case 1:
                //up
                    if(map[(yE[idxE])-1][(xE[idxE])]!='#' && map[(yE[idxE])-1][(xE[idxE])]!='E' && map[(yE[idxE])-1][(xE[idxE])]!='~'){
                        move=sqrt(pow(y-(yE[idxE]-1),2)+pow(x-xE[idxE],2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE]-1;
                            tempX=xE[idxE];
                        }
                    }
            break;
            case 2:
                //left
                    if(map[(yE[idxE])][(xE[idxE]-1)]!='#' && map[(yE[idxE])][(xE[idxE]-1)]!='E' && map[(yE[idxE])][(xE[idxE]-1)]!='~'){
                        move=sqrt(pow(y-yE[idxE],2)+pow(x-(xE[idxE]-1),2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE];
                            tempX=xE[idxE]-1;
                        }
                    }
            break;
            case 3:
                //down
                    if(map[(yE[idxE])+1][(xE[idxE])]!='#' && map[(yE[idxE])+1][(xE[idxE])]!='E' && map[(yE[idxE])+1][(xE[idxE])]!='~'){
                        move=sqrt(pow(y-(yE[idxE]+1),2)+pow(x-xE[idxE],2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE]+1;
                            tempX=xE[idxE];
                        }
                    }
            break;
            case 4:
                //right
                    if(map[(yE[idxE])][(xE[idxE]+1)]!='#' && map[(yE[idxE])][(xE[idxE]+1)]!='E' && map[(yE[idxE])][(xE[idxE]+1)]!='~'){
                        move=sqrt(pow(y-yE[idxE],2)+pow(x-(xE[idxE]+1),2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE];
                            tempX=xE[idxE]+1;
                        }
                    }
            break;
            case 5:
                //up-left
                    if(map[(yE[idxE]-1)][(xE[idxE]-1)]!='#' && map[(yE[idxE]-1)][(xE[idxE]-1)]!='E' && map[(yE[idxE]-1)][(xE[idxE]-1)]!='~'){
                        move=sqrt(pow(y-(yE[idxE]-1),2)+pow(x-(xE[idxE]-1),2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE]-1;
                            tempX=xE[idxE]-1;
                        }
                    }
            break;
            case 6:
                //down-left
                    if(map[(yE[idxE]+1)][(xE[idxE]-1)]!='#' && map[(yE[idxE]+1)][(xE[idxE]-1)]!='E' && map[(yE[idxE]+1)][(xE[idxE]-1)]!='~'){
                        move=sqrt(pow(y-(yE[idxE]+1),2)+pow(x-(xE[idxE]-1),2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE]+1;
                            tempX=xE[idxE]-1;
                        }
                    }
            break;
            case 7:
                //down-right
                    if(map[(yE[idxE]+1)][(xE[idxE]+1)]!='#' && map[(yE[idxE]+1)][(xE[idxE]+1)]!='E' && map[(yE[idxE]+1)][(xE[idxE]+1)]!='~'){
                        move=sqrt(pow(y-(yE[idxE]+1),2)+pow(x-(xE[idxE]+1),2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE]+1;
                            tempX=xE[idxE]+1;
                        }
                    }
            break;
            case 8:
                //up-right
                    if(map[(yE[idxE]-1)][(xE[idxE]+1)]!='#' && map[(yE[idxE]-1)][(xE[idxE]+1)]!='E' && map[(yE[idxE]-1)][(xE[idxE]+1)]!='~'){
                        move=sqrt(pow(y-(yE[idxE]-1),2)+pow(x-(xE[idxE]+1),2));
                        if(min>move){
                            min=move;
                            tempY=yE[idxE]-1;
                            tempX=xE[idxE]+1;
                        }
                    }
            break;
        }
    }
    yE[idxE]=tempY;
    xE[idxE]=tempX;
}


