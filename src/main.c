#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/fallingBlock.h"

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
	//fallingBlock();
	signal(SIGALRM, fallingBlock);
    alarm(10);     // Initial timeout setting

       pause();
    return 0;
}