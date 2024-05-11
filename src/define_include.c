#include "../include/define_include.h"

extern int blockType;
extern int punkty;
extern int newRecord;
extern int mode;
extern int plansza[10][15];
extern blockColor colors[5];

void startGame()
{
	punkty = 0;
	newRecord = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
			plansza[i][j] = 0;
	}

	colors[0].fill = Red;
	colors[0].outline = darkRed;
	colors[1].fill = Green;
	colors[1].outline = darkGreen;
	colors[2].fill = Yellow;
	colors[2].outline = darkYellow;
	colors[3].fill = Purple;
	colors[3].outline = darkPurple;
}

sfRenderWindow *createWindow()
{
	sfVideoMode mode = {4 * SQUARE_SIZE * 2.5, 6 * SQUARE_SIZE * 2.5, 32}; // git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {400, 100};
	sfRenderWindow_setPosition(window, vf);
	sfRenderWindow_setFramerateLimit(window, 30);

	return window;
}

sfRectangleShape *createSquare(sfVector2f position, sfVector2f size, sfColor fillColor, sfColor outlineColor)
{
	sfRectangleShape *square = sfRectangleShape_create();
	sfRectangleShape_setPosition(square, position);
	sfRectangleShape_setSize(square, size);
	sfRectangleShape_setFillColor(square, fillColor);
	sfRectangleShape_setOutlineThickness(square, 1);
	sfRectangleShape_setOutlineColor(square, outlineColor);

	return square;
}

sfCircleShape *createCircle(sfVector2f position, sfColor fillColor, sfColor outlineColor)
{
	float radius = 10;
	sfCircleShape *circle = sfCircleShape_create();
	sfCircleShape_setPosition(circle, position);
	sfCircleShape_setRadius(circle, radius);
	sfCircleShape_setFillColor(circle, fillColor);
	sfCircleShape_setOutlineThickness(circle, 1);
	sfCircleShape_setOutlineColor(circle, outlineColor);
	return circle;
}

sfText *createText(sfFont *font, sfColor color, sfColor outlineColor, int size, sfVector2f position, float thickness)
{
	sfText *txt = sfText_create();
	sfText_setFont(txt, font);
	sfText_setCharacterSize(txt, size);
	sfText_setColor(txt, color);
	sfText_setOutlineThickness(txt, thickness);
	sfText_setOutlineColor(txt, outlineColor);
	sfText_setPosition(txt, position);

	return txt;
}

sfSprite *createPicture(sfTexture *t, sfVector2f position){
	sfSprite *sprite = sfSprite_create();
	sfSprite_setTexture(sprite, t, 0);
	sfSprite_setScale(sprite, (sfVector2f){0.5,0.5});
	sfSprite_setPosition(sprite, position);
	return sprite;
}

sfRectangleShape *createButtonRec(sfVector2f buttonPos)
{
	sfVector2f buttonSize = {4 * SQUARE_SIZE, 1.5 * SQUARE_SIZE};
	sfRectangleShape *b = createSquare(buttonPos, buttonSize, lightPurple, darkBlue);

	return b;
}

void defineButtons(buttonRec buttons[5], buttonCirc bExit[1], sfFont *font)
{
	float thickness = 2;
	sfVector2f position[] = {(sfVector2f){3 * SQUARE_SIZE, 3 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 6.75 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 10.5 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 8 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 10.5 * SQUARE_SIZE}, (sfVector2f){1.25* SQUARE_SIZE, 4.75*SQUARE_SIZE}};
	sfVector2f txtPos[] = {(sfVector2f){position[0].x + SQUARE_SIZE, position[0].y + 0.25 * SQUARE_SIZE}, (sfVector2f){position[1].x + SQUARE_SIZE, position[1].y + 0.25 * SQUARE_SIZE}, (sfVector2f){position[2].x + 1.1 * SQUARE_SIZE, position[2].y + 0.25 * SQUARE_SIZE}, (sfVector2f){position[3].x + 0.58 * SQUARE_SIZE, position[3].y + 0.4 * SQUARE_SIZE}, (sfVector2f){position[4].x + 0.87* SQUARE_SIZE, position[4].y + 0.25 * SQUARE_SIZE},};
	int size = 40;
	for (int i = 0; i < 5; i++)
	{
		buttons[i].b = createButtonRec(position[i]);
		if(i == 3) buttons[i].t = createText(font, sfWhite, sfBlack, 25, txtPos[i], thickness);
		else buttons[i].t = createText(font, sfWhite, sfBlack, size, txtPos[i], thickness);
		buttons[i].pos = (sfVector2i){position[i].x, position[i].y};
	}
	sfText_setString(buttons[0].t, "PLAY");
	sfText_setString(buttons[1].t, "HELP");
	sfText_setString(buttons[2].t, "EXIT");
	sfText_setString(buttons[3].t, "PLAY AGAIN");

	sfText_setString(buttons[4].t, "MENU");

	bExit[0].c = createCircle(position[5], darkBlue, darkBlue);
	bExit[0].t = createText(font, lightPurple, lightPurple, 15, (sfVector2f){position[5].x + 6.5, position[5].y - 1}, 0);
	sfText_setString(bExit[0].t, "x");
	bExit[0].pos = (sfVector2i){position[5].x, position[5].y};
}

void deleteAll(sfRenderWindow *window, sfRectangleShape *background[10][15], sfRectangleShape *shapes[4], sfFont *font, sfFont *specialFont, sfRectangleShape *menu[6][11], buttonRec buttons[5], buttonCirc bExit[1], sfText *gameText[5], sfRectangleShape *helpBackground[8][6], image images[3])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++) sfRectangleShape_destroy(background[i][j]);
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++) sfRectangleShape_destroy(menu[i][j]);
	}
	for (int i = 0; i < 5; i++)
	{
		if(i != 4) sfRectangleShape_destroy(shapes[i]);
		sfRectangleShape_destroy(buttons[i].b);
		sfText_destroy(buttons[i].t);
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 6; j++) sfRectangleShape_destroy(helpBackground[i][j]);
	}
	
	sfCircleShape_destroy(bExit[0].c);
	sfText_destroy(bExit[0].t);
	for (int i = 0; i < 5; i++) sfText_destroy(gameText[i]);
	for(int i = 0; i < 2; i++){
		sfSprite_destroy(images[i].picture);
		sfTexture_destroy(images[i].texture);
	}
	sfFont_destroy(font);
	sfFont_destroy(specialFont);
	sfRenderWindow_destroy(window);
}