#include "../include/define_include.h"

#ifndef MENU_H
#define MENU_H

void defineMenu(sfRectangleShape *menu[6][11]);

void defineHelp(sfText *helpText[4], sfRectangleShape *helpBackground[8][6], sfFont *font, image images[3]);

void drawMenu(sfRenderWindow *window, sfRectangleShape *menu[6][11], buttonRec buttons[5], sfFont *font, int type);

void drawHelp(sfRenderWindow *window, sfRectangleShape *helpBackground[8][6], sfText *gameText[5], buttonCirc bExit[1], image images[3]);

#endif