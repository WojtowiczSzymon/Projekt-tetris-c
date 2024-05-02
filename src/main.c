#include "../include/define_include.h"

int action_code_for_falling_block = 0;
int posx1 = 5;
int posy1 = 0; 
int plansza[10][15];

int main(){
	//set window
	sfVideoMode mode = {4 * SQUARE_SIZE*2.5, 6 * SQUARE_SIZE*2.5, 32}; //git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {400,100};
	sfRenderWindow_setPosition(window,vf);
	sfRenderWindow_setFramerateLimit(window, 30);

	sfRectangleShape *background[10][15]; 
	defineBoard(background);

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

		//render spirits and shapes
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
            //end_czas = sfClock_getElapsedTime(clock);
            gettimeofday(&time_start,NULL);
            end_czas = time_start.tv_sec;
        //printf("sus");
        }
		move_down(window, test, background);
        printf("amogus\n");
		spriteMove(test);
		sleep(1.0-end_czas+start_czas);

		sfRenderWindow_drawRectangleShape(window, test, NULL);
     	sfRenderWindow_display(window);
	}

    //clear everything
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 15; j++){
			sfRectangleShape_destroy(background[i][j]);
		}
	}
	sfRectangleShape_destroy(test);
    sfRenderWindow_destroy(window);

    return 0;
}