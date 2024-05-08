#include "../include/define_include.h"

#include "../include/board.h"
#include "../include/sprites.h"

extern int plansza[10][15];
extern point points[4];
extern int type;
extern int punkty;

void lost(){
    FILE * results;
    for(int i=0;i<8;i++){
        if(plansza[i][0]==1){
            // punkty >> plik;
            results = fopen("results.txt","w+");
            int pkt;
            fscanf(results,"%d",&pkt);
            if(punkty > pkt) fprintf(results,"%d",punkty);
            printf("przegrana");
			//wyswietl wynik i ugabuga jak lepszy
			while(1){
                if(sfKeyboard_isKeyPressed(sfKeyQ)) exit(0); //Q zakonczy
            }
		}
    }
    fclose(results);
}

void deleteRow(sfRectangleShape *background[10][15], sfRenderWindow *window){
    int check;
    for(int i=14;i>=0;i--){
        check = 1;
        for(int j=0;j<10;j++) if(plansza[j][i]==0) check = 0;
        if(check==1){
            punkty++;
            for(int j=0;j<10;j++) plansza[j][i] = 0;
            for(int k=i;k>0;k--){
                for(int g1=0;g1<10;g1++){
                    plansza[g1][k] = plansza[g1][k-1];
                    plansza[g1][k-1]=0;
                }
            }
            i++;
        }
    }
    adjustBoard(plansza, background);
    drawBoard(window, background);
}

void addRandomBlock(sfRectangleShape *shapes[4], sfRectangleShape *background[10][15],sfRenderWindow *window){
    deleteRow(background,window);
    lost();
    int randomType = rand()%2+1;
    switch(randomType){
        case 1:
            add_block_2x2(shapes);
            break;
        case 2: 
            add_dlugas(shapes);
            break;
    }
}

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
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
            }
            break;
        case 3: //dlugas poziomo
            if(points[3].x < 9 && plansza[points[3].x+1][points[3].y] == 0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
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
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
           }
           break;
        case 3: //dlugas poziomo
            if(points[0].x > 0 && plansza[points[0].x-1][points[0].y] == 0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
            }
            break;

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
                addRandomBlock(shapes, background,window);
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
                addRandomBlock(shapes, background,window);
            }
            break;
        case 3:
            if(points[0].y < 14 && plansza[points[0].x][points[0].y+1] == 0 && points[1].y < 14 && plansza[points[1].x][points[1].y+1] == 0 && points[2].y < 14 && plansza[points[2].x][points[2].y+1] == 0 && points[3].y < 14 && plansza[points[3].x][points[3].y+1] == 0){
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
                addRandomBlock(shapes, background,window);
            }

    }
}

void rotation(sfRectangleShape *shapes[4]){
    switch(type){
        case 2:
            /*
                x 0 x x
                x 1 x x
                x 2 x x
                x 3 x x

                x x x x
                0 1 2 3
                x x x x
                x x x x
           */
            if(points[0].x-1 >= 0 && points[2].x+1 <= 9 && points[3].x+2 <= 9 && plansza[points[0].x-1][points[0].y+1]==0 && plansza[points[2].x+1][points[2].y-1]==0 && plansza[points[3].x+2][points[3].y-2]==0){
                type = 3;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[2].x][points[2].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x -= 1; points[0].y = points[1].y;
                points[2].x += 1; points[2].y = points[1].y;
                points[3].x += 2; points[3].y = points[1].y;
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[2].x][points[2].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
            }
            break;
        case 3:
            printf("rot2\n");
            if(points[0].y -1 >=0 && points[2].y+1 <= 14 && points[3].y+2 <= 14 && plansza[points[0].x+1][points[0].y-1]==0 && plansza[points[2].x-1][points[2].y+1]==0 && plansza[points[3].x-2][points[3].y+2]==0){
                type = 2;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[2].x][points[2].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].y -= 1; points[0].x = points[1].x;
                points[2].y += 1; points[2].x = points[1].x;
                points[3].y += 2; points[3].x = points[1].x;
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[2].x][points[2].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
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