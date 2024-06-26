#include "define_include.h"

#ifndef OPERATIONS_H
#define OPERATIONS_H

void move_right(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]);

void move_left(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]);

void move_down(sfRenderWindow *window, sfRectangleShape *shapes[4], sfRectangleShape *background[10][15]);

void rotation(sfRectangleShape *shapes[4]);

void spriteMove(sfRectangleShape *shapes[4]);

void addRandomBlock(sfRectangleShape *shapes[4], sfRectangleShape *background[10][15],sfRenderWindow *window);

#endif