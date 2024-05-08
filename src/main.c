#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

int action_code_for_falling_block = 0;
point points[4]; // points[0] górny, points[1] dolny, points[2] lewy, points[3] prawy.
int plansza[10][15];
int type = 1;
int punkty = 0;
int win = 0;

int main()
{
	char result[10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
			plansza[i][j] = 0;
	}

	// set window
	sfRenderWindow *window = createWindow();

	sfRectangleShape *background[10][15];
	defineBoard(background);
	sfRectangleShape *shapes[4]; // tablica czterech kwadratow, na ktore skalda sie ksztalt
	defineSprites(shapes);
	addRandomBlock(shapes, background, window);

	sfFont *font = sfFont_createFromFile("../figure/Arial.ttf");
	sfText *text_result = createText(font);

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

		gettimeofday(&time_start, NULL);

		if (win == 0)
		{
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
		}
		else{
			endBoard(window, background);
			if(sfKeyboard_isKeyPressed(sfKeyQ)){
				deleteAll(window, background, shapes, text_result, font);
				exit(0);
			} //Q - quit
		}
		sfRenderWindow_display(window);
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
	// clear everything
	deleteAll(window, background, shapes, text_result, font);
	return 0;
}