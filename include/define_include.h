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

struct point{
    int x;
    int y;
};
typedef struct point point;

sfRectangleShape *defineSquare(sfVector2f position, sfVector2f size, sfColor fillColor, sfColor outlineColor);

#endif