#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ncurses.h> 
#include<stdlib.h>
#include<ctype.h>

#include "../include/fallingBlock.h"

int action_code_for_falling_block = 0;
int posx1;
int posy1; 
int plansza[8][16];

void update();

void update(){
	printf("weszlo\n");
	move_down();
    print_plansza();
	if(getchar() == 'a') move_left();
	
	alarm(1);
}

int main(){
	int i,j;
    printf("%s", "ok\n");
	for(i = 0; i < 8; i++){
		for(j = 0; j < 16; j++) plansza[i][j] = 0; //zerowanie na poczatku
	}

	printf("Press key \"P\" to start\n");
	char start = getchar();
	add_block_1x1();
	print_plansza();
	signal(SIGALRM, update);
	alarm(1);
	if(start = 'P'){ //można potem dac enter czy cos
		while(1){

		//initscr();
		//refresh();
		//print_plansza();
		//action_code_for_falling_block = 0;
			pause();
		//fallingBlock);
    	     // Initial timeout setting
		// if(action_code_for_falling_block == 1){ // przesuniecie w lewo
		// 	//printf("lewo");
		// 	move_left();
		// }else if(action_code_for_falling_block == 2){
		// 	//printf("prawo");
		// 	move_right();
		// }else if(action_code_for_falling_block == 3){
		// 	//printf("rotation\n");
		// 	;
		// }
		//endwin();

		}
	}
    return 0;
}