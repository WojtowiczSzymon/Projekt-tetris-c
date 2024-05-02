#include "../include/define_include.h"

#include "../include/board.h"

extern int posx1, posy1, posx2, posy2, posy2, posx3, posy3, posx4, posy4;
extern int plansza[8][16];

void lose(){
    for(int i=0;i<8;i++){
        if(plansza[i][0]==1){
            printf("przegrana");
            exit(0);
        }
    }
}

void add_block_1x1(){
    //lose();
    posx1 = 4;
    posy1 = 0;
    plansza[posx1][posy1] = 1;
}

void add_block_2x2(){
    //lose();
    posx1 = 4; posy1 = 0; //najwyzszy, najbardziej na lewo
    posx2 = 5; posy2 = 0;
    posx3 = 4; posy3 = 1;
    posx4 = 5; posy4 = 1; //najnizszy, najbardziej na prawo
    for(int i = 4; i <= 5; i++){
        for(int j = 0; j <= 1; j++) plansza[i][j] = 1;
    }
}

void move_right(){
    if(posx1 < 9 && (plansza[posx1+1][posy1] == 0)){
        plansza[posx1][posy1]=0;
        plansza[posx1+1][posy1]=1;
        posx1++;
    }
}
void move_left(){
    if(posx1 > 0 && plansza[posx1-1][posy1] == 0){
        plansza[posx1][posy1] = 0;
        plansza[posx1-1][posy1] = 1;
        posx1--;
    }
}
void move_down(sfRenderWindow *window, sfRectangleShape *name, sfRectangleShape *background[10][15]){
    if(posy1 < 14 && plansza[posx1][posy1+1] == 0){
        plansza[posx1][posy1]=0;
        plansza[posx1][posy1+1]=1;
        posy1++;
    }else{
        changeBoard(name, posx1, posy1, background); 
        drawBoard(window, background);
        add_block_1x1();
    }
}

void spriteMove(sfRectangleShape *name){ //zmienic na sprite'a
    sfVector2f old_pos = sfRectangleShape_getPosition(name);
    sfVector2f new_pos = {posx1*128/2.5, posy1*128/2.5}; 
    sfRectangleShape_setPosition(name, new_pos);
}