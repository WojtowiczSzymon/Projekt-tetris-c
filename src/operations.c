#include "../include/define_include.h"

#include "../include/board.h"
#include "../include/sprites.h"

extern int plansza[10][15];
extern point points[4];
extern int blockType;
extern int punkty;
extern int newRecord;
extern int mode;

void lost(){
    FILE * results;
    for(int i=0;i<8;i++){
        if(plansza[i][0]==1){
            // punkty >> plik;
            results = fopen("results.txt","w+");
            int pkt;
            fscanf(results,"%d",&pkt);
            if(punkty > pkt){
                newRecord = 1;
                fprintf(results,"%d",punkty);
            }
			fclose(results);
            mode = 3;
            return;
		}
    }
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
    int randomType;
    time_t t;
    srand((unsigned) time(&t));
    if(mode == 1){
        randomType = rand()%4+1;
        switch(randomType){
            case 1:
                add_block_2x2(shapes);
                break;
            case 2: 
                add_dlugas(shapes);
                break;
            case 3:
                add_L(shapes);
                break;
            case 4:
                add_zygzag(shapes);
                break;
        }
    }
}

void move_right(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]){
    switch(blockType){
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
        case 4:
            if(points[1].x < 9 && points[3].x < 9  && plansza[points[1].x+1][points[1].y] == 0 && plansza[points[3].x+1][points[3].y] == 0 && points[2].x < 9  && plansza[points[2].x+1][points[2].y] == 0){
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
        case 5:
            if(points[3].x + 1 <= 9 && plansza[points[3].x+1][points[3].y]==0 && plansza[points[0].x+1][points[0].y]==0 ){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
            }
            break;
        case 6:
            if(points[0].x + 1 <= 9 && plansza[points[0].x+1][points[0].y]==0 && plansza[points[2].x+1][points[2].y]==0 && plansza[points[3].x+1][points[3].y]==0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
            }
            break;
        case 7:
            if(points[0].x + 1 <= 9 && plansza[points[0].x+1][points[0].y]==0 && plansza[points[1].x+1][points[1].y]==0){
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
            }
            break;
        case 8:
            if(points[0].x + 1 <= 9 && plansza[points[0].x+1][points[0].y]==0 && plansza[points[1].x+1][points[1].y]==0 &&  plansza[points[3].x+1][points[3].y]==0){
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
            }
        break;
        case 9:
            if(points[0].x + 1 <= 9 && plansza[points[0].x+1][points[0].y]==0 && plansza[points[2].x+1][points[2].y]==0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x+1][points[0].y]=1;
                points[0].x++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x+1][points[2].y]=1;
                points[2].x++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x+1][points[3].y]=1;
                points[3].x++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x+1][points[1].y]=1;
                points[1].x++;
            }

    }
 }

 void move_left(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]){
     switch(blockType){
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
        case 4:
            if(points[0].x > 0 && points[2].x > 0  && plansza[points[0].x-1][points[0].y] == 0 && plansza[points[2].x-1][points[2].y] == 0 && points[3].x > 0 && plansza[points[3].x-1][points[3].y] == 0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
           }
           break;
        case 5:
            if(points[0].x > 0 && points[1].x > 0  && plansza[points[0].x-1][points[0].y] == 0 && plansza[points[1].x-1][points[1].y] == 0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
           }
           break;
        case 6:
            if(points[2].x > 0 && plansza[points[2].x-1][points[2].y] == 0 && points[1].x > 0 && points[3].x > 0  && plansza[points[1].x-1][points[1].y] == 0 && plansza[points[3].x-1][points[3].y] == 0){
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
        case 7:
            if(points[0].x > 0 && points[3].x > 0  && plansza[points[0].x-1][points[0].y] == 0 && plansza[points[3].x-1][points[3].y] == 0){
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
        case 8:
            if(points[3].x-1>=0 && plansza[points[2].x-1][points[2].y] == 0 && plansza[points[0].x-1][points[0].y] == 0 && plansza[points[3].x-1][points[3].y] == 0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
            }
            break;
        case 9:
            if(points[3].x-1>=0 && plansza[points[3].x-1][points[3].y]==0 && plansza[points[1].x-1][points[1].y]==0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x-1][points[3].y]=1;
                points[3].x--;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x-1][points[1].y]=1;
                points[1].x--;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x-1][points[2].y]=1;
                points[2].x--;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x-1][points[0].y]=1;
                points[0].x--;
            }
     }
 }
void move_down(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]){
    switch(blockType){
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
        break;
        case 4:
            if(points[3].y<14 && plansza[points[3].x][points[3].y+1] == 0 && plansza[points[0].x][points[0].y+1]==0){
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
        case 5:
            if(points[0].y+1<=14 && plansza[points[0].x][points[0].y+1]==0 && plansza[points[2].x][points[2].y+1]==0 && plansza[points[3].x][points[3].y+1]==0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
            }else{
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                addRandomBlock(shapes, background,window);
            }
            break;
        case 6:
            if(points[0].y < 14 && points[1].y < 14  && plansza[points[0].x][points[0].y+1] == 0 && plansza[points[1].x][points[1].y+1] == 0){
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
            }else{
                
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                addRandomBlock(shapes, background,window);
            }
            break;
        case 7:
            if(points[1].y+1<=14 && plansza[points[1].x][points[1].y+1]==0 && plansza[points[2].x][points[2].y+1]==0 && plansza[points[3].x][points[3].y+1]==0){
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
            }else{  
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                addRandomBlock(shapes, background,window);
            }
            break;
        case 8:
            if(points[3].y+1<=14 && plansza[points[3].x][points[3].y+1]== 0 && plansza[points[1].x][points[1].y+1]== 0){
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
            }else{  
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                addRandomBlock(shapes, background,window);
            }
            break;
        case 9:
            if(points[0].y+1<=14 && plansza[points[0].x][points[0].y+1] == 0 && plansza[points[1].x][points[1].y+1] == 0 && plansza[points[3].x][points[3].y+1] == 0){
                plansza[points[0].x][points[0].y]=0;
                plansza[points[0].x][points[0].y+1]=1;
                points[0].y++;
                plansza[points[3].x][points[3].y]=0;
                plansza[points[3].x][points[3].y+1]=1;
                points[3].y++;
                plansza[points[1].x][points[1].y]=0;
                plansza[points[1].x][points[1].y+1]=1;
                points[1].y++;
                plansza[points[2].x][points[2].y]=0;
                plansza[points[2].x][points[2].y+1]=1;
                points[2].y++;
            }else{  
                changeBoard(shapes, points, background); 
                drawBoard(window, background);
                addRandomBlock(shapes, background,window);
            }

            break;
    }
}

void rotation(sfRectangleShape *shapes[4]){
    switch(blockType){
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
                blockType = 3;
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
                blockType = 2;
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
        case 4:
            /*
            x 0 1 x
            x x 2 x
            x x 3 x

            x x x x
            x 1 2 3
            x 0 x x

            x x 3 x
            x x 2 x
            x x 1 0

            x x x 0
            x 3 2 1
            x x x x
            
            */
           if(plansza[points[0].x][points[0].y+2]==0 && plansza[points[1].x-1][points[1].y+1]==0 && points[3].x+1<=9 && plansza[points[3].x+1][points[3].y-1]==0){
                blockType = 5;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[1].x][points[1].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x += 0; points[0].y += 2; 
                points[1].x -= 1; points[1].y += 1; 
                points[3].x += 1; points[3].y -= 1; 
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[1].x][points[1].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
            }
            break;
        case 5:
            if(plansza[points[0].x+2][points[0].y]==0 && plansza[points[1].x+1][points[1].y+1]==0 && points[3].y-1>=0 && plansza[points[3].x-1][points[3].y-1]==0){
                blockType = 6;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[1].x][points[1].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x += 2; points[0].y += 0; 
                points[1].x += 1; points[1].y += 1; 
                points[3].x -= 1; points[3].y -= 1; 
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[1].x][points[1].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
            }
            break;
        case 6:
            if(plansza[points[0].x][points[0].y-2]==0 && plansza[points[1].x+1][points[1].y-1]==0 && points[3].y+1<=14 && plansza[points[3].x-1][points[3].y+1]==0){
                blockType = 7;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[1].x][points[1].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x += 0; points[0].y -= 2; 
                points[1].x += 1; points[1].y -= 1; 
                points[3].x -= 1; points[3].y += 1; 
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[1].x][points[1].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
            }
            break;
        case 7:
            if(plansza[points[0].x-2][points[0].y]==0 && plansza[points[1].x-1][points[1].y-1]==0 && points[3].y+1<=14 && plansza[points[3].x+1][points[3].y+1]==0){
                blockType = 4;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[1].x][points[1].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x -= 2; points[0].y += 0; 
                points[1].x -= 1; points[1].y -= 1; 
                points[3].x += 1; points[3].y += 1; 
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[1].x][points[1].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
            }
            break;
        case 8:
            /*
            x x 0 x
            x 2 1 x
            x 3 x x

            x 3 2 x
            x x 1 0
            x x x x

            */
           if(points[0].x+1<=9 && plansza[points[0].x+1][points[0].y+1]==0 && plansza[points[3].x][points[3].y-2]==0){
                blockType = 9;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[2].x][points[2].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x += 1; points[0].y += 1; 
                points[2].x += 1; points[2].y -= 1; 
                points[3].x += 0; points[3].y -= 2; 
                plansza[points[0].x][points[0].y] = 1;
                plansza[points[2].x][points[2].y] = 1;
                plansza[points[3].x][points[3].y] = 1;
           }
           break;
        case 9:
            if(points[0].y-2>=0 && plansza[points[2].x-1][points[2].y+1]==0 && plansza[points[3].x][points[3].y+2]==0){
                blockType = 8;
                plansza[points[0].x][points[0].y] = 0;
                plansza[points[2].x][points[2].y] = 0;
                plansza[points[3].x][points[3].y] = 0;
                points[0].x -= 1; points[0].y -= 1; 
                points[2].x -= 1; points[2].y += 1; 
                points[3].x += 0; points[3].y += 2; 
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