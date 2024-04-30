#include <stdio.h>
#include <ncurses.h> 
#include <time.h>
#include <string.h>
#include <signal.h>
#include<stdlib.h>
#include <unistd.h>


void fallingBlock(){
    printf("weszlo\n");
    clock_t start=clock();
    char choice = 'K';
    // while(choice=getch() && clock()-start<10000){    
    switch(getchar()){
        case 'a':
            printf("przesuniety");
            break;
        case 'd':
            //right
            break;
        case 'w':
            break;
            //rotation
    }
    printf("wyszlo\n");
    alarm(10);    
    signal(SIGALRM, fallingBlock);

}