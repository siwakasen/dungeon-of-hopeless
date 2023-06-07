#include "header.h"
void generateMap(char map[baris][kolom]){
    int i,j;
    for(i=0;i<baris;i++){
        for(j=0;j<kolom;j++){
            if(i==0 || i==baris-1 || j==0 || j==kolom-1){
                map[i][j]='#';
            }else if(i==2 && j>=1 && j<11){
                map[i][j]='#';
            }else if(i==8 && j>=11 && j<32){
                map[i][j]='#';
            }else if(i==14 && j>=1 && j<66){
                map[i][j]='#';
            }else if(i==20 && j>=11 && j<69){
                map[i][j]='#';
            }else if(i==2 && j>=22 && j<32){
                map[i][j]='#';
            }else if(i==23 && j>=33 && j<59){
                map[i][j]='#';
            }else if(j==21 && i>=1 && i<8){
                map[i][j]='#';
            }else if(j==32 && i>=2 && i<9){
                map[i][j]='#';
            }else if(j==43 && i>=2 && i<14){
                map[i][j]='#';
            }else if(j==54 && i>=1 && i<9){
                map[i][j]='#';
            }else if(j==65 && i>=2 && i<14){
                map[i][j]='#';
            }else if(j==11 && i>=17 && i<24){
                map[i][j]='#';
            }else if(j==22 && i>=22 && i<27){
                map[i][j]='#';
            }else if(j==58 && i>=21 && i<23){
                map[i][j]='#';
            }else if(j==22 && i>=15 && i<18){
                map[i][j]='#';
            }else if(j==43 && i>=15 && i<18){
                map[i][j]='#';
            }else if(j==64 && i>=15 && i<18){
                map[i][j]='#';
            }else if(j==54 && i>=17 && i<20){
                map[i][j]='#';
            }else if(j==33 && i>=17 && i<20){
                map[i][j]='#';
            }else{
                map[i][j]=' ';
            }
        }
    }
    map[1][0]=177;
}


void generateGate(char map[baris][kolom],bool gateStatus[]){
    if(gateStatus[0]){
        map[3][32]=177;
    }else{
        map[3][32]='|';
    }
    if(gateStatus[1]){
        map[1][43]=177;
    }else{
        map[1][43]='|';
    }
    if(gateStatus[2]){
        map[25][69]=177;
    }else{
        map[25][69]='|';
    }
}


void showMap(char map[baris][kolom]){
    int i,j;
    printf("\n");
    for(i=0;i<baris;i++){
        for(j=0;j<kolom;j++){
            gotoxy(j+3, i+1); 
			printf("%c",map[i][j]);
            //sakit mata aku ku convert jadi gotoxy game mu :D xixixi
        }
        printf("\n");
    }
    
}
void generateKey(char map[baris][kolom], bool key[]){
    if(!key[0]){
        map[13][42]='~';
    }
    if(!key[1]){
        map[7][22]='~';
    }
    if(!key[2]){
        map[22][57]='~';
    }
}


