#include "define_include.h"

#ifndef SPRITES_H
#define SPRITE_H

void defineSprites(sfRectangleShape *shapes[4]); 

void drawSprites(sfRenderWindow *window, sfRectangleShape *shapes[4]);

void add_block_2x2(sfRectangleShape *shapes[4]);

void add_dlugas(sfRectangleShape *shapes[4]);

void add_L(sfRectangleShape *shapes[4]);
#endif