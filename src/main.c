#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//#include <ncurses.h> 
#include <stdlib.h>
#include <ctype.h>



#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>

#include "../include/operations.h"

int action_code_for_falling_block = 0;
int posx1;
int posy1; 
int plansza[8][16];

void update();

void update(){
	move_down();
    print_plansza();
	alarm(1);
}
#define SQUARE_SIZE 128

int main(){
	//set window
	sfVideoMode mode = {6 * SQUARE_SIZE, 6 * SQUARE_SIZE, 32}; //git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {200,100};
	sfRenderWindow_setPosition(window,vf);
	sfRenderWindow_setFramerateLimit(window, 30);


	// sfRectangleShape *shape = sfRectangleShape_create();
   	// sfVector2f vf = {200, 200}, pos = {30, 30};
   	// sfRectangleShape_setSize(shape, vf);
   	// sfRectangleShape_setFillColor(shape, sfGreen);
   	// sfRectangleShape_setPosition(shape, pos);

   	while (sfRenderWindow_isOpen(window)) {
     	sfEvent event;
     	while (sfRenderWindow_pollEvent(window, &event)) {
       		if (event.type == sfEvtClosed) {
        		sfRenderWindow_close(window);
       		}
     	}

    	sfRenderWindow_clear(window, sfBlack);
    //  sfRenderWindow_drawRectangleShape(window, shape, NULL);
     	sfRenderWindow_display(window);
   }

//    sfRectangleShape_destroy(shape);
   sfRenderWindow_destroy(window);





	// int i,j;
    // printf("%s", "ok\n");
	// for(i = 0; i < 8; i++){
	// 	for(j = 0; j < 16; j++) plansza[i][j] = 0; //zerowanie na poczatku
	// }

	// printf("Press key \"P\" to start\n");
	// char start = getchar();
	// add_block_1x1();
	// print_plansza();
	// signal(SIGALRM, update);
	// alarm(1);
	// if(start = 'P'){ //można potem dac enter czy cos
	// 	while(1){
	// 		pause();
	// 	}
	// }


	// 	//initscr();
	// 	//refresh();
	// 	//print_plansza();
	// 	//action_code_for_falling_block = 0;
	// 		pause();
	// 	//fallingBlock);
    // 	     // Initial timeout setting
	// 	// if(action_code_for_falling_block == 1){ // przesuniecie w lewo
	// 	// 	//printf("lewo");
	// 	// 	move_left();
	// 	// }else if(action_code_for_falling_block == 2){
	// 	// 	//printf("prawo");
	// 	// 	move_right();
	// 	// }else if(action_code_for_falling_block == 3){
	// 	// 	//printf("rotation\n");
	// 	// 	;
	// 	// }
	// 	//endwin();
    return 0;
}