#include "../include/define_include.h"

extern int type;
extern int punkty;
extern int mode;
extern int plansza[10][15];
extern blockColor colors[4];

void startGame(){
	type = 1;
	punkty = 0;
	mode = 1;
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

void defineMenu(sfRectangleShape *menu[6][11]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			sfVector2f position = {(i+2)*SQUARE_SIZE, (j+2)*SQUARE_SIZE,};
			menu[i][j] = defineSquare(position, (sfVector2f){SQUARE_SIZE, SQUARE_SIZE}, dirtyBlue, dirtyBlue);
		}
	}
}

void drawMenu(sfRenderWindow *window, sfRectangleShape *menu[6][11]){
	for(int i = 0; i < 10; i++){
        for(int j = 0; j < 15; j++){
            sfRenderWindow_drawRectangleShape(window, menu[i][j], NULL);
        }
    }
}

sfRectangleShape *createButton(sfVector2f buttonPos){
	sfVector2f buttonSize = {4*SQUARE_SIZE, 1.5*SQUARE_SIZE};
	sfRectangleShape *b = defineSquare(buttonPos, buttonSize, lightPurple, sfBlack);
	
	return b;
}

sfText *createText(sfFont *font, sfColor color, sfColor outlineColor, int size, sfVector2f position){
    sfText *txt = sfText_create();
    sfText_setFont(txt, font);
	sfText_setCharacterSize(txt, size);
	sfText_setColor(txt, color);
	sfText_setOutlineThickness(txt, 2);
	sfText_setOutlineColor(txt, outlineColor);
	sfText_setPosition(txt, position);

    return txt;
}

void defineButtons(button buttons[4], sfFont *font){
	sfVector2f position[] = {(sfVector2f){3*SQUARE_SIZE, 12*SQUARE_SIZE}, (sfVector2f){3*SQUARE_SIZE, 12*SQUARE_SIZE}, (sfVector2f){3*SQUARE_SIZE, 12*SQUARE_SIZE}, (sfVector2f){3*SQUARE_SIZE, 12*SQUARE_SIZE}};
	int size = 40;
	for(int i = 0; i < 4; i++){
		buttons[i].b = createButton(position[i]);
		buttons[i].t = createText(font, sfWhite, sfBlack, size, (sfVector2f){position[i].x+0.65*SQUARE_SIZE, position[i].y+0.25*SQUARE_SIZE});
	}

}

void deleteAll(sfRenderWindow *window, sfRectangleShape *background[10][15], sfRectangleShape *shapes[4], sfText *text_result, sfFont *font, sfText *new_game, sfRectangleShape *resultBackground){//, sfRectangleShape *menu[6][11]){
    for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			sfRectangleShape_destroy(background[i][j]);
		}
	}
	// for(int i = 0; i < 6; i++){
	// 	for(int j = 0; j < 11; j++){
	// 		sfRectangleShape_destroy(menu[i][j]);
	// 	}
	// }
	for (int i = 0; i < 4; i++)
	{
		sfRectangleShape_destroy(shapes[i]);
		//sfRectangleShape_destroy(buttons[i].b);
		//sfText_destroy(buttons[i].t);

	}
	sfText_destroy(text_result);
	sfText_destroy(new_game);
	sfFont_destroy(font);
	sfRenderWindow_destroy(window);
}