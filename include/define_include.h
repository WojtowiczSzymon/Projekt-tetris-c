#include <SFML/Graphics.h>
#include <SFML/Window.h>
//#include <SF
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef INCLUDE_DEFINE_H
#define INCLUDE_DEFINE_H

#define SQUARE_SIZE 128/2.5
//colors for the board
#define darkBlue sfColor_fromRGBA(14,20,61,255)
#define Gray sfColor_fromRGBA(43,51,100,255)
#define darkGray sfColor_fromRGBA(14,20,61,150)
#define dirtyBlue sfColor_fromRGB(41,66,155)
//colors for the blocks
#define Red sfColor_fromRGB(220,30,30)
#define darkRed sfColor_fromRGB(75,5,5)
#define Green sfColor_fromRGB(46,176,47)
#define darkGreen sfColor_fromRGB(3,86,5)
#define Yellow sfColor_fromRGB(215,202,41)
#define darkYellow sfColor_fromRGB(171,160,13)
#define Purple sfColor_fromRGB(175,47,183)
#define darkPurple sfColor_fromRGB(115,17,121)
#define lightPurple sfColor_fromRGB(105,105,225)


struct point{
    int x;
    int y;
};
typedef struct point point;

struct blockColor{
    sfColor fill;
    sfColor outline;
};
typedef struct blockColor blockColor;

struct button{
    sfRectangleShape *b; //button
    sfText *t; //text
};
typedef struct button button;

void startGame();

sfRenderWindow *createWindow();

sfRectangleShape *defineSquare(sfVector2f position, sfVector2f size, sfColor fillColor, sfColor outlineColor);

void drawMenu(sfRenderWindow *window, sfRectangleShape *menu[6][11]);

void defineMenu(sfRectangleShape *menu[6][11]);

sfRectangleShape *createButton(sfVector2f buttonPos);

sfText *createText(sfFont *font, sfColor color, sfColor outlineColor, int size, sfVector2f position);

void defineButtons(button buttons[4], sfFont *font);

void deleteAll(sfRenderWindow *window, sfRectangleShape *background[10][15], sfRectangleShape *shapes[4], sfText *text_result, sfFont *font, sfText *new_game, sfRectangleShape *resultBackground); //sfRectangleShape *menu[6][11]);

#endif