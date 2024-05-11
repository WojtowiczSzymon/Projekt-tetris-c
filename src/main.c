#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

point points[4]; // points[0] górny, points[1] dolny, points[2] lewy, points[3] prawy.
int plansza[10][15];
int blockType;
int punkty;
int newRecord;
int mode = 0; // 0 - start, 1 - play, 3 - end, 2 - help, 4 - back to menu

blockColor colors[4];

int main()
{
	char result[10];
	startGame();
	mode = 3;
	
	// set window
	sfRenderWindow *window = createWindow();

	//start screen
	sfRectangleShape *menu[6][11];
	sfRectangleShape *helpBackground[8][6];
	defineMenu(menu);
	sfText *gameText[5];
	sfFont *font = sfFont_createFromFile("Arial.ttf");
	sfFont *specialFont = sfFont_createFromFile("Nurjan_Free.ttf");
	image images[3];
	defineHelp(gameText, helpBackground, font, images);

	//game
	sfRectangleShape *background[10][15];
	defineBoard(background);
	sfRectangleShape *shapes[4]; // tablica czterech kwadratow, na ktore skalda sie ksztalt
	defineSprites(shapes);

	//end screen
	gameText[3] = createText(font, sfWhite, darkBlue, 45, (sfVector2f){2.75*SQUARE_SIZE, 5*SQUARE_SIZE},3);
	gameText[4] = createText(specialFont, darkRed, Yellow, 50, (sfVector2f){2.35*SQUARE_SIZE, 3*SQUARE_SIZE},3);
	//sfRectangleShape *resultsBackground = createSquare((sfVector2f){resultPos.x-0.5*SQUARE_SIZE, resultPos.y-0.5*SQUARE_SIZE}, resultsBackgroundSize, dirtyBlue, sfBlack);

	buttonRec buttons[5]; //0 - start game, 1 - help, 2 - exit, 3 - play again, 4 - back to menu
	buttonCirc bExit[1];
	defineButtons(buttons, bExit, font);
	

	struct timeval time_start;
	long long start_czas, end_czas;

	while (sfRenderWindow_isOpen(window))
	{
		sfEvent event;
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}
		sfRenderWindow_clear(window, sfBlack);

		drawBoard(window, background);

		if(mode == 0){
			drawMenu(window, menu, buttons, font, 1);
			if (event.type == sfEvtMouseButtonPressed)
			{
				if (sfMouse_isButtonPressed(sfMouseLeft))
				{
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					if (mousePos.x >= buttons[0].pos.x && mousePos.x <= buttons[0].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[0].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[0].pos.y)
					{
						mode = 1;
						addRandomBlock(shapes, background, window);
					}
					else if(mousePos.x >= buttons[1].pos.x && mousePos.x <= buttons[1].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[1].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[1].pos.y){
						mode = 2;
					}
					else if(mousePos.x >= buttons[2].pos.x && mousePos.x <= buttons[2].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[2].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[2].pos.y){
						deleteAll(window, background, shapes, font, specialFont, menu, buttons, bExit, gameText, helpBackground, images);
						printf("exiting...\n");
						exit(0);
					}
				}
			}
		}
		if(mode == 2){
			drawHelp(window, helpBackground, gameText, bExit, images);
			if (event.type == sfEvtMouseButtonPressed){
				if (sfMouse_isButtonPressed(sfMouseLeft)){
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					if (mousePos.x >= bExit[0].pos.x && mousePos.x <= bExit[0].pos.x + 20 && mousePos.y <= bExit[0].pos.y + 20 && mousePos.y >= bExit[0].pos.y){
						mode = 0;
					}
				}
			}
		}
		if (mode == 1)
		{
			gettimeofday(&time_start, NULL);
			start_czas = time_start.tv_sec;
			end_czas = time_start.tv_sec;
			while (end_czas - start_czas < 0.5)
			{
				if (sfKeyboard_isKeyPressed(sfKeyLeft))
				{
					move_left(window, shapes, background);
					spriteMove(shapes);
					break;
				}
				if (sfKeyboard_isKeyPressed(sfKeyRight))
				{
					move_right(window, shapes, background);
					spriteMove(shapes);
					break;
				}
				if (sfKeyboard_isKeyPressed(sfKeyR))
				{
					rotation(shapes);
					spriteMove(shapes);
					break;
				}
				gettimeofday(&time_start, NULL);
				end_czas = time_start.tv_sec;
			}
			
			move_down(window, shapes, background);
			spriteMove(shapes);

			sleep(1.0 - end_czas + start_czas);

			drawSprites(window, shapes);
			// printf("\n");
			// for (int i = 0; i < 15; i++)
			// {
			// 	for (int j = 0; j < 10; j++)
			// 	{
			// 		printf("%d ", plansza[j][i]);
			// 	}
			// 	printf("\n");
			// }
		}
		else if(mode == 3)
		{
			endBoard(window, background);
			drawMenu(window, menu, buttons, font, 2);
			sprintf(result, "POINTS: %d", punkty);
			sfText_setString(gameText[3], result);
			sfText_setString(gameText[4], "NEW RECORD!");
			sfRenderWindow_drawText(window, gameText[3], NULL);
			sfRenderWindow_drawText(window, buttons[3].t, NULL);
			if(newRecord == 1) sfRenderWindow_drawText(window, gameText[4], NULL);
			if (event.type == sfEvtMouseButtonPressed)
			{
				if (sfMouse_isButtonPressed(sfMouseLeft))
				{
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					printf("mouse: %d %d\nhorizontal range %d %d\nvertical range: %d %d\n", mousePos.x, mousePos.y, buttons[3].pos.x, buttons[3].pos.x + 10, buttons[3].pos.y, buttons[3].pos.y+10);
					if (mousePos.x >= buttons[3].pos.x && mousePos.x <= buttons[3].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[3].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[3].pos.y)
					{
						startGame();
						mode = 1;
						newGameBoard(window, background);
						addRandomBlock(shapes, background, window);
					}
					else if (mousePos.x >= buttons[4].pos.x && mousePos.x <= buttons[4].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[4].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[4].pos.y)
					{
						startGame();
						printf("mode %d\n", mode);
						gettimeofday(&time_start, NULL);
						start_czas = time_start.tv_sec;
						end_czas = time_start.tv_sec;
						while (end_czas - start_czas < 0.1){gettimeofday(&time_start, NULL); end_czas = time_start.tv_sec;}
						sleep(1.0 - end_czas + start_czas);
						newGameBoard(window, background);
						// sleep(1);
						mode = 0;
					}
				}
			}
		}
		if (sfKeyboard_isKeyPressed(sfKeyQ))
			{
				deleteAll(window, background, shapes, font, specialFont, menu, buttons, bExit, gameText, helpBackground, images);
				exit(0);
			}
		sfRenderWindow_display(window);
	}
	// clear everything
	deleteAll(window, background, shapes, font, specialFont, menu, buttons, bExit, gameText, helpBackground, images);
	return 0;
}