#include "../include/define_include.h"

extern int type;
extern int punkty;
extern int win;
extern int plansza[10][15];
extern blockColor colors[4];

void startGame(){
	type = 1;
	punkty = 0;
	win = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
			plansza[i][j] = 0;
	}
	
	colors[0].fill = Red; colors[0].outline = darkRed;
	colors[1].fill = Green; colors[1].outline = darkGreen;
	colors[2].fill = Yellow; colors[2].outline = darkYellow;
	colors[3].fill = Purple; colors[3].outline = darkPurple;
}

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

sfRectangleShape *createButton(){
	sfVector2f play_again_pos = {4*SQUARE_SIZE, 12*SQUARE_SIZE}; //pozycja przycisku play Again
	sfVector2f play_again_size = {2*SQUARE_SIZE, 1*SQUARE_SIZE};
	sfRectangleShape *button = defineSquare(play_again_pos, play_again_size, sfBlack, sfBlack);
	
	return button;
}

sfText *createText(sfFont *font, sfColor color){
    sfText *textResults = sfText_create();
    sfText_setFont(textResults, font);
	sfText_setCharacterSize(textResults, 50);
	sfText_setColor(textResults, color);
    sfVector2f position = {5 * SQUARE_SIZE, 7 * SQUARE_SIZE};
	sfText_setPosition(textResults, position);

    return textResults;
}



void deleteAll(sfRenderWindow *window, sfRectangleShape *background[10][15], sfRectangleShape *shapes[4], sfText *text_result, sfFont *font, sfRectangleShape *playAgainButton){
    for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			sfRectangleShape_destroy(background[i][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		sfRectangleShape_destroy(shapes[i]);
	}
	sfRectangleShape_destroy(playAgainButton);
	sfText_destroy(text_result);
	sfFont_destroy(font);
	sfRenderWindow_destroy(window);
}