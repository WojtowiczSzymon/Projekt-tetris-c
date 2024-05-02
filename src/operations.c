#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include<ctype.h>

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include <stdio.h>

extern int action_code_for_falling_block;
extern int posx1;
extern int posy1;
extern int plansza[8][16];

void add_block_1x1(){
    for(int i=0;i<8;i++){
        if(plansza[i][0]==1){
            printf("przegrana");
            exit(0);
        }
    }
    posx1=4;
    posy1=0;
    plansza[posx1][posy1]=1;
}
void move_right(){
    if(posx1<7 && plansza[posx1+1][posy1]==0){
        plansza[posx1][posy1]=0;
        plansza[posx1+1][posy1]=1;
        posx1++;
    }
}
void move_left(){
    if(posx1>0 && plansza[posx1-1][posy1]==0){
        plansza[posx1][posy1]=0;
        plansza[posx1-1][posy1]=1;
        posx1--;
    }
}
void move_down(){
    if(posy1<15 && plansza[posx1][posy1+1]==0){
        plansza[posx1][posy1]=0;
        plansza[posx1][posy1+1]=1;
        posy1++;
    }
}

void set_sprite_to_position(sfRectangleShape *name){
    sfVector2f old_pos = sfRectangleShape_getPosition(name);
    sfVector2f new_pos = {old_pos.x, old_pos.y+128/2.5}; 
    sfRectangleShape_setPosition(name, new_pos);
    //sprite.x = posx1 sprite.y = posy1;
}

void fallingBlock(){
    
    switch(tolower(getchar())){
        case 'a':
        //left
            action_code_for_falling_block=1;
            break;
        case 'd':
            //right
            action_code_for_falling_block=2;
            break;
        case 'w':
            action_code_for_falling_block=3;
            break;
            //rotation
    }
    
    return;

}