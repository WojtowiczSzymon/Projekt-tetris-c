#include "../include/define_include.h"

#include "../include/operations.h"
#include "../include/board.h"
#include "../include/sprites.h"

int action_code_for_falling_block = 0;
int posx1, posy1, posx2, posy2, posy2, posx3, posy3, posx4, posy4;
int plansza[10][15];

int main(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 15; j++) plansza[i][j] = 0;
	}

	//set window
	sfVideoMode mode = {4 * SQUARE_SIZE*2.5, 6 * SQUARE_SIZE*2.5, 32}; //git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {400,100};
	sfRenderWindow_setPosition(window,vf);
	sfRenderWindow_setFramerateLimit(window, 30);

	sfRectangleShape *background[10][15]; 
	defineBoard(background);
	sfSprite *shapes[4];
	defineSprites(shapes); //zrobic structa na sprigte'y ze to sa cztery rectangles i masz ich pozycje

	sfRectangleShape *test = sfRectangleShape_create();
	sfVector2f pos = {posx1 * SQUARE_SIZE, posy1 * SQUARE_SIZE}; //128.2/5 - square_size2
	sfVector2f size = {SQUARE_SIZE, SQUARE_SIZE};
	sfRectangleShape_setPosition(test, pos);
    sfRectangleShape_setSize(test, size);
    sfRectangleShape_setFillColor(test, sfColor_fromRGB(200,0,0));
    sfRectangleShape_setOutlineThickness(test, 1);
    sfRectangleShape_setOutlineColor(test, sfColor_fromRGB(135,5,5));

 	struct timeval time_start;
    long long start_czas, end_czas;

   	while(sfRenderWindow_isOpen(window)){
     	sfEvent event;
     	while(sfRenderWindow_pollEvent(window, &event)){
       		if(event.type == sfEvtClosed){
        		sfRenderWindow_close(window);
       		}
     	}
    	sfRenderWindow_clear(window, sfBlack);

		//render sprites and shapes
		drawBoard(window, background);

		gettimeofday(&time_start,NULL);

        start_czas = time_start.tv_sec;
        end_czas = time_start.tv_sec;
        while(end_czas - start_czas < 0.5){
        if(sfKeyboard_isKeyPressed(sfKeyLeft)){
            move_left(test);
			printf("left\n");
            break;
        }
        if(sfKeyboard_isKeyPressed(sfKeyRight)){
            move_right();
			printf("right\n");
            break;
        }
            gettimeofday(&time_start,NULL);
            end_czas = time_start.tv_sec;
        }
		move_down(window, test, background);
        printf("amogus\n");
		spriteMove(test);
		sleep(1.0-end_czas+start_czas);

		//drawPiece();
		//sfRenderWindow_drawSprite(window, shapes[rand() % 4], NULL);
		//sfRenderWindow_drawRectangleShape(window, test, NULL);
     	sfRenderWindow_display(window);
	}

    //clear everything
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 15; j++){
			sfRectangleShape_destroy(background[i][j]);
		}
	}
	for(int i = 0; i < 4; i++){
		sfSprite_destroy(shapes[i]);
	}
	sfRectangleShape_destroy(test);
    sfRenderWindow_destroy(window);

    return 0;
}