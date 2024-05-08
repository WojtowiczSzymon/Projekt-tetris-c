#include "../include/define_include.h"

void defineBoard(sfRectangleShape *background[10][15]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 15; j++){
            sfVector2f position = {i * SQUARE_SIZE, j * SQUARE_SIZE}; 
            sfVector2f size = {SQUARE_SIZE, SQUARE_SIZE}; //128-square size
            background[i][j] = defineSquare(position, size, darkBlue, Gray);
        }
    }
}

void drawBoard(sfRenderWindow *window, sfRectangleShape *background[10][15]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 15; j++){
            sfRenderWindow_drawRectangleShape(window, background[i][j], NULL);
        }
    }
}

void changeBoard(sfRectangleShape *shapes[4], point points[4], sfRectangleShape *background[10][15]){
    for(int i = 0; i < 4; i++){
        sfColor color = sfRectangleShape_getFillColor(shapes[i]);
        sfRectangleShape_setFillColor(background[points[i].x][points[i].y], color);
    }
}

void adjustBoard(int plansza[10][15], sfRectangleShape *background[10][15]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 15; j++){
            if(plansza[i][j]== 0){
                sfRectangleShape_setFillColor(background[i][j], darkBlue);
                sfRectangleShape_setOutlineColor(background[i][j], Gray);
            }
            else{
                sfRectangleShape_setFillColor(background[i][j], darkRed);
            }
        }
    }
}
