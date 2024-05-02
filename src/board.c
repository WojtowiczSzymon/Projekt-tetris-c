#include "../include/define_include.h"

sfRectangleShape *defineSquare(sfVector2f position, sfVector2f size){
    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setPosition(square, position);
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setFillColor(square, sfColor_fromRGB(14,20,61));
    sfRectangleShape_setOutlineThickness(square, 1);
    sfRectangleShape_setOutlineColor(square, sfColor_fromRGB(43,51,100));

    return square;    
}

void defineBoard(sfRectangleShape *background[10][15]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 15; j++){
            sfVector2f position = {i * SQUARE_SIZE, j * SQUARE_SIZE}; 
            sfVector2f size = {SQUARE_SIZE, SQUARE_SIZE}; //128-square size
            background[i][j] = defineSquare(position, size);
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

void changeBoard(sfRectangleShape *name, int posx, int posy, sfRectangleShape *background[10][15]){
    sfColor color = sfRectangleShape_getFillColor(name);
    sfRectangleShape_setFillColor(background[posx][posy], color);
}
