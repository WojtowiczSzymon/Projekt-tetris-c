#include "../include/define_include.h"


extern int plansza[10][15];
extern point points[4];
extern int type;

void defineSprites(sfRectangleShape *shapes[4]){
    for(int i = 0; i < 4; i++){
        sfVector2f position = {0,0};
        sfVector2f size = {SQUARE_SIZE, SQUARE_SIZE};
        shapes[i] = defineSquare(position, size, darkRed, Red); 
    }
}

void definePosition(sfRectangleShape *shapes[4]){
    sfVector2f size = {SQUARE_SIZE, SQUARE_SIZE};
    for(int i = 0; i < 4; i++){
        sfVector2f position = {(float)points[i].x * SQUARE_SIZE, (float)points[i].y * SQUARE_SIZE};
        sfRectangleShape_setPosition(shapes[i], position);
    }
}

void drawSprites(sfRenderWindow *window, sfRectangleShape *shapes[4]){
    for(int i = 0; i < 4; i++){
        sfRenderWindow_drawRectangleShape(window, shapes[i], NULL);
    }
}

void add_block_2x2(sfRectangleShape *shapes[4]){
    type = 1;
    points[0].x = 4; points[0].y = 0; //najwyzszy, najbardziej na lewo
    points[1].x = 5; points[1].y = 0; // najwyzszy, na prawo
    points[2].x = 4; points[2].y = 1; //najnizszy, na lewo
    points[3].x = 5; points[3].y = 1; //najnizszy, najbardziej na prawo
    for(int i = 4; i <= 5; i++){
        for(int j = 0; j <= 1; j++) plansza[i][j] = 1;
    }
    definePosition(shapes);
}

void add_dlugas(sfRectangleShape *shapes[4]){
    type = 2; //type = 3 -> poziomo
    points[0].x = 4; points[0].y = 0; //najwyzszy
    points[1].x = 4; points[1].y = 1; //2
    points[2].x = 4; points[2].y = 2; //3
    points[3].x = 4; points[3].y = 3; //najnizszy
    for(int i = 0; i < 4; i++){
        plansza[4][i] = 1;
    }
    definePosition(shapes);
}

void add_L(sfRectangleShape *shapes[4]){
    type = 4;
    /*
    x 0 1 x
    x x 2 x
    x x 3 x
    */
    points[0].x = 3; points[0].y = 0; 
    points[1].x = 4; points[1].y = 0; 
    points[2].x = 4; points[2].y = 1; 
    points[3].x = 4; points[3].y = 2; 
    definePosition(shapes);
}