#include "../include/define_include.h"

extern int type;
extern int punkty;
extern int newRecord;
extern int mode;
extern int plansza[10][15];
extern blockColor colors[5];

void startGame()
{
	type = 1;
	punkty = 0;
	mode = 0;
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
	printf("pos: %f %f\n", sfCircleShape_getPosition(circle).x, sfCircleShape_getPosition(circle).x);
	sfCircleShape_setRadius(circle, radius);
	sfCircleShape_setFillColor(circle, fillColor);
	sfCircleShape_setOutlineThickness(circle, 1);
	sfCircleShape_setOutlineColor(circle, outlineColor);
	printf("circe\n");
	return circle;
}

void defineMenu(sfRectangleShape *menu[6][11])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			sfVector2f position = {
				(i + 2) * SQUARE_SIZE,
				(j + 2) * SQUARE_SIZE,
			};
			menu[i][j] = createSquare(position, (sfVector2f){SQUARE_SIZE, SQUARE_SIZE}, dirtyBlue, dirtyBlue);
		}
	}
}

void drawMenu(sfRenderWindow *window, sfRectangleShape *menu[6][11], buttonRec buttons[5], buttonCirc bExit[1], int type)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			sfRenderWindow_drawRectangleShape(window, menu[i][j], NULL);
		}
	}
	switch (type)
	{
		case 1:
			for (int i = 0; i < 3; i++)
			{
				sfRenderWindow_drawRectangleShape(window, buttons[i].b, NULL);
				sfRenderWindow_drawText(window, buttons[i].t, NULL);
			}
			break;
		case 2:
		 	sfRenderWindow_drawCircleShape(window, bExit[0].c, NULL);
		 	sfRenderWindow_drawText(window, bExit[0].t, NULL);
		 	break;
	}

}

void drawHelp(){
	printf("help\n");
}

sfRectangleShape *createButtonRec(sfVector2f buttonPos)
{
	sfVector2f buttonSize = {4 * SQUARE_SIZE, 1.5 * SQUARE_SIZE};
	sfRectangleShape *b = createSquare(buttonPos, buttonSize, lightPurple, darkBlue);

	return b;
}

sfText *createText(sfFont *font, sfColor color, sfColor outlineColor, int size, sfVector2f position)
{
	sfText *txt = sfText_create();
	sfText_setFont(txt, font);
	sfText_setCharacterSize(txt, size);
	sfText_setColor(txt, color);
	sfText_setOutlineThickness(txt, 1);
	sfText_setOutlineColor(txt, outlineColor);
	sfText_setPosition(txt, position);

	return txt;
}

void defineButtons(buttonRec buttons[5], buttonCirc bExit[1], sfFont *font)
{
	//printf("b\n");
	sfVector2f position[] = {(sfVector2f){3 * SQUARE_SIZE, 3 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 6.75 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 10.5 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 12 * SQUARE_SIZE}, (sfVector2f){3 * SQUARE_SIZE, 12 * SQUARE_SIZE},(sfVector2f){2.2 * SQUARE_SIZE, 2.2 * SQUARE_SIZE}};
	int size = 40;
	for (int i = 0; i < 5; i++)
	{
		buttons[i].b = createButtonRec(position[i]);
		if (i == 2)
			buttons[i].t = createText(font, sfWhite, sfBlack, size, (sfVector2f){position[i].x + 1.1 * SQUARE_SIZE, position[i].y + 0.25 * SQUARE_SIZE});
		else if (i == 3)
			buttons[i].t = createText(font, sfWhite, sfBlack, size, (sfVector2f){position[i].x + 0.5 * SQUARE_SIZE, position[i].y + 0.25 * SQUARE_SIZE});
		else
			buttons[i].t = createText(font, sfWhite, sfBlack, size, (sfVector2f){position[i].x + SQUARE_SIZE, position[i].y + 0.25 * SQUARE_SIZE});
		buttons[i].pos = (sfVector2i){position[i].x, position[i].y};
	}
	sfText_setString(buttons[0].t, "PLAY");
	sfText_setString(buttons[1].t, "HELP");
	sfText_setString(buttons[2].t, "EXIT");
	sfText_setString(buttons[3].t, "PLAY AGAIN");
	bExit[0].c = createCircle(position[5], darkBlue, darkBlue);
	bExit[0].t = createText(font, lightPurple, lightPurple, 10, (sfVector2f){position[5].x+8, position[5].y+3});
	sfText_setString(bExit[0].t, "x");
	bExit[0].pos = (sfVector2i){position[5].x, position[5].y};
}

void deleteAll(sfRenderWindow *window, sfRectangleShape *background[10][15], sfRectangleShape *shapes[4], sfText *text_result, sfFont *font, sfRectangleShape *resultBackground, sfRectangleShape *menu[6][11], buttonRec buttons[4], buttonCirc bExit[1])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			sfRectangleShape_destroy(background[i][j]);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			sfRectangleShape_destroy(menu[i][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		sfRectangleShape_destroy(shapes[i]);
		sfRectangleShape_destroy(buttons[i].b);
		sfText_destroy(buttons[i].t);
	}
	sfCircleShape_destroy(bExit[0].c);
	sfText_destroy(bExit[0].t);
	sfText_destroy(text_result);
	sfFont_destroy(font);
	sfRenderWindow_destroy(window);
}