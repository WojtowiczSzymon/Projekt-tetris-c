#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

int action_code_for_falling_block = 0;
point points[4]; // points[0] górny, points[1] dolny, points[2] lewy, points[3] prawy.
int plansza[10][15];
int type = 1;
int punkty = 0;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
			plansza[i][j] = 0;
	}
	// set window
	sfVideoMode mode = {4 * SQUARE_SIZE * 2.5, 6 * SQUARE_SIZE * 2.5, 32}; // git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {400, 100};
	sfRenderWindow_setPosition(window, vf);
	sfRenderWindow_setFramerateLimit(window, 30);

	sfRectangleShape *background[10][15];
	defineBoard(background);
	sfRectangleShape *shapes[4]; // tablica czterech kwadratow, na ktore skalda sie ksztalt
	defineSprites(shapes);
	addRandomBlock(shapes, background, window); // inicjowanie na poczatku 2x2

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

		start_czas = time_start.tv_sec;
		end_czas = time_start.tv_sec;
		while (end_czas - start_czas < 0.5)
		{
			if (sfKeyboard_isKeyPressed(sfKeyLeft))
			{
				move_left(window, shapes, background);
				printf("left\n");
				spriteMove(shapes);
				break;
			}
			if (sfKeyboard_isKeyPressed(sfKeyRight))
			{
				move_right(window, shapes, background);
				printf("right\n");
				spriteMove(shapes);
				break;
			}
			if (sfKeyboard_isKeyPressed(sfKeyR))
			{
				rotation(shapes); // typ = 3 = poziomy
				spriteMove(shapes);
				break;
			}
			gettimeofday(&time_start, NULL);
			end_czas = time_start.tv_sec;
		}
		move_down(window, shapes, background);
		spriteMove(shapes);
		// printf("amogus\n");

		sleep(1.0 - end_czas + start_czas);

		drawSprites(window, shapes);
		// sfRenderWindow_drawRectangleShape(window, test, NULL);
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

		// clear everything
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
		sfRenderWindow_destroy(window);

		return 0;
	}
}