#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ncurses.h> 
#include<stdlib.h>
#include<ctype.h>

#include "../include/fallingBlock.h"

int action_code_for_falling_block=0;

void update(int plansza[8][16]){
	sleep(100);
	printf("k\n");
	return;
}


void display_message(int s)
{
     printf("copyit: Still working...\n" );
     alarm(1);    //for every second
     signal(SIGALRM, display_message);
}

int main(){
	int i,j;
    printf("%s", "ok\n");
	int plansza[8][16];
	for(i = 0; i < 8; i++){
		for(j = 0; j < 16; j++) plansza[i][j] = 0; //zerowanie na poczatku
	}
	// while (1) update(plansza);
	while(1){

	
	initscr();
	refresh();
	action_code_for_falling_block=0;
	fallingBlock();
	signal(SIGALRM, fallingBlock);
    alarm(10);     // Initial timeout setting
	endwin();
	if(action_code_for_falling_block==1){ // przesuniecie w lewo
		printf("lewo");
	}else if(action_code_for_falling_block==2){
		printf("prawo");
	}
	}
	//printf("c to gowno");
    //    pause();
    return 0;
}