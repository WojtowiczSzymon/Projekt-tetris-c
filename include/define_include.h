#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef INCLUDE_DEFINE_H
#define INCLUDE_DEFINE_H

#define SQUARE_SIZE 128/2.5
#define darkBlue sfColor_fromRGB(14,20,61)
#define Gray sfColor_fromRGB(43,51,100)
#define darkRed sfColor_fromRGB(200,0,0)
#define Red sfColor_fromRGB(135,5,5)
#define darkGray sfColor_fromRGB(32,35,53)

struct point{
    int x;
    int y;
};
typedef struct point point;

sfRenderWindow *createWindow();

sfRectangleShape *defineSquare(sfVector2f position, sfVector2f size, sfColor fillColor, sfColor outlineColor);

sfText *createText(sfFont *font);

void deleteAll(sfRenderWindow *window, sfRectangleShape *background[10][15], sfRectangleShape *shapes[4], sfText *text_result, sfFont *font);

#endif