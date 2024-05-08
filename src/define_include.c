#include "../include/define_include.h"

sfRenderWindow *createWindow(){
    sfVideoMode mode = {4 * SQUARE_SIZE * 2.5, 6 * SQUARE_SIZE * 2.5, 32}; // git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {400, 100};
	sfRenderWindow_setPosition(window, vf);
	sfRenderWindow_setFramerateLimit(window, 30);

    return window;
}

sfRectangleShape *defineSquare(sfVector2f position, sfVector2f size, sfColor fillColor, sfColor outlineColor){
    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setPosition(square, position);
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setFillColor(square, fillColor);
    sfRectangleShape_setOutlineThickness(square, 1);
    sfRectangleShape_setOutlineColor(square, outlineColor);

    return square;    
}

sfText *createText(sfFont *font){
    sfText *textResults = sfText_create();
    sfText_setFont(textResults, font);
	sfText_setCharacterSize(textResults, 24);
    sfVector2f position = {5 * SQUARE_SIZE, 7 * SQUARE_SIZE};
	sfText_setPosition(textResults, position);

    return textResults;
}