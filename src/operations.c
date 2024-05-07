#include "../include/define_include.h"

#include "../include/board.h"
#include "../include/sprites.h"

extern int plansza[10][15];
extern point points[4];
extern int type;

void lose(){
    for(int i=0;i<8;i++){
        if(plansza[i][0]==1){
            printf("przegrana");
            exit(0);
        }
    }
}

// void add_block_1x1(){
//     //lose();
//     posx1 = 4;
//     posy1 = 0;
//     plansza[posx1][posy1] = 1;
// }

 void move_right(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]){
     switch(type){
        case 1:
            if(points[1].x < 9 && points[3].x < 9  && plansza[points[1].x+1][points[1].y] == 0 && plansza[points[3].x+1][points[3].y] == 0){
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                
           }
           break;
        case 2:
            if(points[1].x < 9 && points[3].x < 9  && plansza[points[1].x+1][points[1].y] == 0 && plansza[points[3].x+1][points[3].y] == 0 && points[0].x < 9 && points[2].x < 9  && plansza[points[0].x+1][points[0].y] == 0 && plansza[points[2].x+1][points[2].y] == 0){
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                
           }
           break;
 
    }
 }
 void move_left(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]){
     switch(type){
        case 1:
            if(points[0].x > 0 && points[2].x > 0  && plansza[points[0].x-1][points[0].y] == 0 && plansza[points[2].x-1][points[2].y] == 0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
            }
            break;
        case 2:
            if(points[0].x > 0 && points[2].x > 0  && plansza[points[0].x-1][points[0].y] == 0 && plansza[points[2].x-1][points[2].y] == 0 && points[1].x > 0 && points[3].x > 0  && plansza[points[1].x-1][points[1].y] == 0 && plansza[points[3].x-1][points[3].y] == 0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
            }
    }
 }
void move_down(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]){
    switch(type){
        case 1:
            if(points[3].y < 14 && points[2].y < 14  && plansza[points[3].x][points[3].y+1] == 0 && plansza[points[2].x][points[2].y+1] == 0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
            }else{
                
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                add_dlugas(shapes);
            } 
            break;
        case 2:
            if(points[3].y < 14 && plansza[points[3].x][points[3].y+1] == 0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
            }else{
                
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                add_block_2x2(shapes);
            }
            break;
    }
}

void spriteMove(sfRectangleShape *shapes[4]){
    for(int i = 0; i < 4; i++){
        sfVector2f old_pos = sfRectangleShape_getPosition(shapes[i]);
        sfVector2f new_pos = {(float)points[i].x * SQUARE_SIZE, (float)points[i].y * SQUARE_SIZE};
        sfRectangleShape_setPosition(shapes[i], new_pos);
    }
}