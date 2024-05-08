#include "define_include.h"

#ifndef BOARD_H
#define BOARD_H

void defineBoard(sfRectangleShape *background[10][15]);

void drawBoard(sfRenderWindow *window, sfRectangleShape *background[10][15]);

void changeBoard(sfRectangleShape *shapes[4], point points[4], sfRectangleShape *background[10][15]); 

void adjustBoard(int plansza[10][15], sfRectangleShape *background[10][15]);

void endBoard(sfRectangleShape *background[10][15]);

#endif