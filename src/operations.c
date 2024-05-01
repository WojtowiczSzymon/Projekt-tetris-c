#include <stdio.h>
#include <ncurses.h> 
#include <time.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include<ctype.h>

extern int action_code_for_falling_block;
extern int posx1;
extern int posy1;
extern int plansza[8][16];

void print_plansza(){
    system("clear");
    for(int i=0;i<16;i++){
        for(int j=0;j<8;j++){
            printf("%d ",plansza[j][i]);
        }
        putchar('\n');
        fflush(stdout);
    }
}
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

void fallingBlock(){
    //printf("weszlo\n");
    //alarm(5);
    //char choice = 'K';  
    
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
    //printf("wyszlo\n");
    //alarm(0);    
    //signal(SIGALRM, fallingBlock);
    return;

}