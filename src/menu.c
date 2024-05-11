#include "../include/define_include.h"

void defineHelp(sfText *gameText[5], sfRectangleShape *helpBackground[8][6], sfFont *font, image images[3])
{
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 6; j++){
			sfVector2f position = {(i+1)* SQUARE_SIZE,(j + 4.5) * SQUARE_SIZE};
			helpBackground[i][j] = createSquare(position, (sfVector2f){SQUARE_SIZE, SQUARE_SIZE}, dirtyBlue, dirtyBlue);
		}
	}
	float thickness = 1;
	sfVector2f position[] = {(sfVector2f){3.25* SQUARE_SIZE, 5.75 * SQUARE_SIZE}, (sfVector2f){3.25 * SQUARE_SIZE, 7.25 * SQUARE_SIZE}, (sfVector2f){3.25 * SQUARE_SIZE, 8.75 * SQUARE_SIZE}, (sfVector2f){3.5 * SQUARE_SIZE, 11 * SQUARE_SIZE}};
	gameText[0] = createText(font, sfWhite, darkBlue, 20, position[0], thickness);
	sfText_setString(gameText[0], "Use left and right arrow to \nmove a falling piece.");
	gameText[1] = createText(font, sfWhite, darkBlue, 20, position[1], thickness);
	sfText_setString(gameText[1], "Click on R to rotate a falling\npiece.");
	gameText[2] = createText(font, sfWhite, darkBlue, 20, position[2], thickness);
	sfText_setString(gameText[2], "Click on Q to exit the game.");
	images[0].texture = sfTexture_createFromFile("../figure/arrows.png", NULL); //arrows
	images[0].picture = createPicture(images[0].texture, (sfVector2f){position[0].x-2*SQUARE_SIZE, position[0].y-1});
	images[1].texture = sfTexture_createFromFile("../figure/RKey.png", NULL); //R
	images[1].picture = createPicture(images[1].texture, (sfVector2f){position[1].x-1.6*SQUARE_SIZE, position[1].y-10});
	images[2].texture = sfTexture_createFromFile("../figure/QKey.png", NULL); //Q
	images[2].picture = createPicture(images[2].texture, (sfVector2f){position[2].x-1.6*SQUARE_SIZE, position[2].y-20});
}

void drawHelp(sfRenderWindow *window, sfRectangleShape *helpBackground[8][6], sfText *gameText[5], buttonCirc bExit[1], image images[3])
{
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 6; j++){
			sfRenderWindow_drawRectangleShape(window, helpBackground[i][j], NULL);
		}
	}
	sfRenderWindow_drawCircleShape(window, bExit[0].c, NULL);
	sfRenderWindow_drawText(window, bExit[0].t, NULL);
	for (int i = 0; i < 3; i++)
	{
		sfRenderWindow_drawText(window, gameText[i], NULL);
		sfRenderWindow_drawSprite(window, images[i].picture, NULL);
	}
}

void defineMenu(sfRectangleShape *menu[6][11])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			sfVector2f position = {(i + 2) * SQUARE_SIZE,(j + 2) * SQUARE_SIZE};
			menu[i][j] = createSquare(position, (sfVector2f){SQUARE_SIZE, SQUARE_SIZE}, dirtyBlue, dirtyBlue);
		}
	}
}

void drawMenu(sfRenderWindow *window, sfRectangleShape *menu[6][11], buttonRec buttons[5], sfFont *font, int type)
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
		for (int i = 3; i < 5; i++)
		{
			sfRenderWindow_drawRectangleShape(window, buttons[i].b, NULL);
			sfRenderWindow_drawText(window, buttons[i].t, NULL);
		}
	}
}