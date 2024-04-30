#include <stdio.h>
#include <ncurses.h> 
#include <time.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include<ctype.h>

 extern int action_code_for_falling_block;

void fallingBlock(){
    printf("weszlo\n");
    clock_t start=clock();
    char choice = 'K';  
    
    switch(tolower(getchar())){
        case 'a':
        //left
            action_code_for_falling_block=1;
            break;
        case 'd':
            //right
            action_code_for_falling_block=2;
            break;
        case 'w':
            action_code_for_falling_block=3;
            break;
            //rotation
    }
    printf("wyszlo\n");
    return;
    // alarm(10);    
    // signal(SIGALRM, fallingBlock);

}