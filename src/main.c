#include <stdio.h>
#include <unistd.h>
#include "../include/fallingBlock.h"

void update(int plansza[8][16]){
	sleep(100);
	printf("k\n");
	return;
}

int main(){
	int i,j;
    printf("%s", "ok");
	int plansza[8][16];
	for(i = 0; i < 8; i++){
		for(j = 0; j < 16; j++) plansza[i][j] = 0; //zerowanie na poczatku
	}
	while (1) update(plansza);
    return 0;
}