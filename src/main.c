#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

point points[4]; // points[0] górny, points[1] dolny, points[2] lewy, points[3] prawy.
int plansza[10][15];
int type;
int punkty;
int newRecord;
int mode; // 0 - start, 1 - play, 3 - end, 2 - help, 4 - back to menu

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

		// render sprites and shapes
		drawBoard(window, background);

		if(mode == 0){
			drawMenu(window, menu, buttons, bExit, 1);
			if (event.type == sfEvtMouseButtonPressed)
			{
				if (sfMouse_isButtonPressed(sfMouseLeft))
				{
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					if (mousePos.x >= buttons[0].pos.x && mousePos.x <= buttons[0].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[0].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[0].pos.y)
					{
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
						mode = 2;
					}
					else if(mousePos.x >= buttons[2].pos.x && mousePos.x <= buttons[2].pos.x + 4*SQUARE_SIZE && mousePos.y <= buttons[2].pos.y+1.5*SQUARE_SIZE && mousePos.y >= buttons[2].pos.y){
						deleteAll(window, background, shapes, text_result, font, resultsBackground, menu, buttons, bExit);
						exit(0);
					}
				}
			}
		}
		if(mode == 2){
			drawMenu(window, menu, buttons, bExit, 2);
			drawHelp();
			if (event.type == sfEvtMouseButtonPressed){
				if (sfMouse_isButtonPressed(sfMouseLeft)){
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					if (mousePos.x >= bExit[0].pos.x && mousePos.x <= bExit[0].pos.x + 10 && mousePos.y <= bExit[0].pos.y + 10 && mousePos.y >= bExit[0].pos.y){
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
			//drawEndScreen();
			sfRenderWindow_drawRectangleShape(window, buttons[3].b, NULL);
			sfRenderWindow_drawText(window, buttons[3].t, NULL);
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
					if (mousePos.x <= buttons[3].pos.x + SQUARE_SIZE && mousePos.x >= buttons[3].pos.x - SQUARE_SIZE && mousePos.y <= buttons[3].pos.y + SQUARE_SIZE && mousePos.y >= buttons[3].pos.y - SQUARE_SIZE)
					{
						startGame();
						defineBoard(background);
						// gettimeofday(&time_start, NULL);
						// start_czas = time_start.tv_sec;
						// end_czas = time_start.tv_sec;
						// while (end_czas - start_czas < 0.5){gettimeofday(&time_start, NULL); end_czas = time_start.tv_sec;}
						// sleep(1.0 - end_czas + start_czas);
					}
					if (mousePos.x <= buttons[4].pos.x + SQUARE_SIZE && mousePos.x >= buttons[4].pos.x - SQUARE_SIZE && mousePos.y <= buttons[4].pos.y + SQUARE_SIZE && mousePos.y >= buttons[4].pos.y - SQUARE_SIZE)
					{
						mode = 0;
					}
					//powrot do menu
				}
			}
			if (sfKeyboard_isKeyPressed(sfKeyQ))
			{
				deleteAll(window, background, shapes, text_result, font, resultsBackground, menu, buttons, bExit);
				exit(0);
			} // Q - quit
		}
		sfRenderWindow_display(window);
	}
	// clear everything
	deleteAll(window, background, shapes, text_result, font, resultsBackground, menu, buttons, bExit);
	return 0;
}