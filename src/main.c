#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

point points[4]; // points[0] górny, points[1] dolny, points[2] lewy, points[3] prawy.
int plansza[10][15];
int type;
int punkty;
int win;
blockColor colors[4];

int main()
{
	char result[10];
	char newGame[] = "Play Again";
	startGame();
	win = 1;
	printf("%d", win);

	// set window
	sfRenderWindow *window = createWindow();

	sfRectangleShape *background[10][15];
	defineBoard(background);
	sfRectangleShape *shapes[4]; // tablica czterech kwadratow, na ktore skalda sie ksztalt
	defineSprites(shapes);
	addRandomBlock(shapes, background, window);

	sfFont *font = sfFont_createFromFile("Arial.ttf");
	int size_text_result = 50, size_new_game = 30;
	sfVector2f buttonPos = {3*SQUARE_SIZE, 12*SQUARE_SIZE};
	sfVector2f resultPos = {2*SQUARE_SIZE, 5.5*SQUARE_SIZE};
	sfVector2f resultsBackgroundSize = {7*SQUARE_SIZE, 2.5*SQUARE_SIZE};
	sfText *text_result = createText(font, sfWhite, sfBlack, size_text_result, resultPos);
	sfText *new_game = createText(font, sfWhite, sfBlack, size_new_game, (sfVector2f){buttonPos.x+0.65*SQUARE_SIZE, buttonPos.y+0.25*SQUARE_SIZE});
	sfRectangleShape *resultsBackground = defineSquare((sfVector2f){resultPos.x-0.5*SQUARE_SIZE, resultPos.y-0.5*SQUARE_SIZE}, resultsBackgroundSize, dirtyBlue, sfBlack);

	sfRectangleShape *playAgainButton = createButton(buttonPos);
	sfVector2i playAgain = {5 * SQUARE_SIZE, 12 * SQUARE_SIZE};

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

		if (win == 0)
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
			printf("\n");
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					printf("%d ", plansza[j][i]);
				}
				printf("\n");
			}
		}
		else
		{
			endBoard(window, background);
			sfRenderWindow_drawRectangleShape(window, playAgainButton, NULL);
			sfRenderWindow_drawRectangleShape(window, resultsBackground, NULL);
			sprintf(result, "Points: %d", punkty);
			sfText_setString(text_result, result);
			sfText_setString(new_game, newGame);
			sfRenderWindow_drawText(window, text_result, NULL);
			sfRenderWindow_drawText(window, new_game, NULL);
			if (event.type == sfEvtMouseButtonPressed)
			{
				if (sfMouse_isButtonPressed(sfMouseLeft))
				{
					sfVector2i mousePos = {event.mouseButton.x, event.mouseButton.y};
					if (mousePos.x <= playAgain.x + SQUARE_SIZE && mousePos.x >= playAgain.x - SQUARE_SIZE && mousePos.y <= playAgain.y + SQUARE_SIZE && mousePos.y >= playAgain.y - SQUARE_SIZE)
					{
						startGame();
						defineBoard(background);
						gettimeofday(&time_start, NULL);
						start_czas = time_start.tv_sec;
						end_czas = time_start.tv_sec;
						while (end_czas - start_czas < 0.5){gettimeofday(&time_start, NULL); end_czas = time_start.tv_sec;}
						sleep(1.0 - end_czas + start_czas);
						addRandomBlock(shapes, background, window);
						printf("%d\n", win);
					}
				}
			}
			if (sfKeyboard_isKeyPressed(sfKeyQ))
			{
				deleteAll(window, background, shapes, text_result, font, playAgainButton, new_game, resultsBackground);
				exit(0);
			} // Q - quit
		}
		sfRenderWindow_display(window);
		// pomocnicza plansza w terminalu
	}
	// clear everything
	deleteAll(window, background, shapes, text_result, font, playAgainButton, new_game, resultsBackground);
	return 0;
}