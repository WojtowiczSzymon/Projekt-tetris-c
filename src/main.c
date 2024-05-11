#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

point points[4]; // points[0] górny, points[1] dolny, points[2] lewy, points[3] prawy.
int plansza[10][15];
int type;
int punkty;
int mode; // 0 - start, 1 - play, 2 - end, 3 - help
blockColor colors[4];

int main()
{
	char result[10];
	char newGame[] = "Play Again";
	startGame();

	// set window
	sfRenderWindow *window = createWindow();

	//start screen
	sfRectangleShape *menu[6][11];
	defineMenu(menu);
	//printf("ok\n");

	//game
	sfRectangleShape *background[10][15];
	defineBoard(background);
	sfRectangleShape *shapes[4]; // tablica czterech kwadratow, na ktore skalda sie ksztalt
	defineSprites(shapes);

	sfFont *font = sfFont_createFromFile("Arial.ttf");

	//end screen
	int size_text_result = 50, size_new_game = 30;
	sfVector2f resultPos = {2*SQUARE_SIZE, 5.5*SQUARE_SIZE};
	sfVector2f resultsBackgroundSize = {7*SQUARE_SIZE, 2.5*SQUARE_SIZE};
	sfText *text_result = createText(font, sfWhite, sfBlack, size_text_result, (sfVector2f){resultPos.x+1*SQUARE_SIZE, resultPos.y});
	sfRectangleShape *resultsBackground = createSquare((sfVector2f){resultPos.x-0.5*SQUARE_SIZE, resultPos.y-0.5*SQUARE_SIZE}, resultsBackgroundSize, dirtyBlue, sfBlack);

	buttonRec buttons[4]; //0 - start game, 1 - help, 2 - exit, 3 - play again
	// buttonCirc bExit;
	defineButtons(buttons, font);
	

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

		// render sprites and shapes
		drawBoard(window, background);

		if(mode == 0){
			//printf("ok\n");
			drawMenu(window, menu, buttons, 1);
			//printf("ok\n");
			if (event.type == sfEvtMouseButtonPressed)
			{
				if (sfMouse_isButtonPressed(sfMouseLeft))
				{
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					//printf("mouse %d %d\nhorizontal range %d %f\nvertical range %d %f\n\n", mousePos.x, mousePos.y, buttons[1].pos.x, buttons[1].pos.y+4*SQUARE_SIZE,buttons[1].pos.y, buttons[1].pos.y+1.5*SQUARE_SIZE);
					if (mousePos.x >= buttons[0].pos.x && mousePos.x <= buttons[0].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[0].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[0].pos.y)
					{
						printf("start\n");
						mode = 1;
						//sleep(1);
						addRandomBlock(shapes, background, window);
						// drawSprites(window, shapes);
						// gettimeofday(&time_start, NULL);
						// start_czas = time_start.tv_sec;
						// end_czas = time_start.tv_sec;
						// while (end_czas - start_czas < 0.5){gettimeofday(&time_start, NULL); end_czas = time_start.tv_sec;}
						// sleep(1.0 - end_czas + start_czas);
						//sleep(1);

					}
					else if(mousePos.x >= buttons[1].pos.x && mousePos.x <= buttons[1].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[1].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[1].pos.y){
						printf("help\n");
						//drawMenu(window, menu, buttons, 2);

					}
					else if(mousePos.x >= buttons[2].pos.x && mousePos.x <= buttons[2].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[2].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[2].pos.y){
						printf("exit\n");
						deleteAll(window, background, shapes, text_result, font, resultsBackground, menu, buttons);// bExit);
						exit(0);
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
		else if(mode == 2)
		{
			endBoard(window, background);
			//sfRenderWindow_drawRectangleShape(window, buttons[3].b, NULL);
			sfRenderWindow_drawRectangleShape(window, resultsBackground, NULL);
			sprintf(result, "Points: %d", punkty);
			sfText_setString(text_result, result);
			sfRenderWindow_drawText(window, text_result, NULL);
			sfRenderWindow_drawText(window, buttons[3].t, NULL);
			if (event.type == sfEvtMouseButtonPressed)
			{
				if (sfMouse_isButtonPressed(sfMouseLeft))
				{
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					if (mousePos.x <= buttons[1].pos.x + SQUARE_SIZE && mousePos.x >= buttons[1].pos.x - SQUARE_SIZE && mousePos.y <= buttons[1].pos.y + SQUARE_SIZE && mousePos.y >= buttons[1].pos.y - SQUARE_SIZE)
					{ //play again
						// startGame();
						// defineBoard(background);
						// gettimeofday(&time_start, NULL);
						// start_czas = time_start.tv_sec;
						// end_czas = time_start.tv_sec;
						// while (end_czas - start_czas < 0.5){gettimeofday(&time_start, NULL); end_czas = time_start.tv_sec;}
						// sleep(1.0 - end_czas + start_czas);
						// addRandomBlock(shapes, background, window);
					}
					//powrot do menu
				}
			}
			if (sfKeyboard_isKeyPressed(sfKeyQ))
			{
				deleteAll(window, background, shapes, text_result, font, resultsBackground, menu, buttons);//, bExit);
				exit(0);
			} // Q - quit
		}
		sfRenderWindow_display(window);
	}
	// clear everything
	deleteAll(window, background, shapes, text_result, font, resultsBackground, menu, buttons);//, bExit);
	return 0;
}