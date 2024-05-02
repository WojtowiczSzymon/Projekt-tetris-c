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
#include "../include/board.h"

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
	sfVideoMode mode = {4 * SQUARE_SIZE, 6 * SQUARE_SIZE, 32}; //git rozmiar
	sfRenderWindow *window = sfRenderWindow_create(mode, "Tetris", sfResize | sfClose, NULL);
	sfVector2i vf = {400,100};
	sfRenderWindow_setPosition(window,vf);
	sfRenderWindow_setFramerateLimit(window, 30);

	sfRectangleShape *background[12][18];
	defineBoard(background);

   	while (sfRenderWindow_isOpen(window)) {
     	sfEvent event;
     	while (sfRenderWindow_pollEvent(window, &event)) {
       		if (event.type == sfEvtClosed) {
        		sfRenderWindow_close(window);
       		}
     	}

    	sfRenderWindow_clear(window, sfBlack);
		//render spirits and shapes
		drawBoard(window, background);

     	sfRenderWindow_display(window);
	}


    //clear everything
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 18; j++){
			sfRectangleShape_destroy(background[i][j]);
		}
	}
    sfRenderWindow_destroy(window);
	//sfRectangleShape_destroy();

    return 0;
}