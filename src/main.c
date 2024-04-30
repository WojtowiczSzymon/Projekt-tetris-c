#include <stdio.h>

#include "../include/fallingBlock.h"

void update(){
    fallingBlock();
}

int main(){
    printf("%s", "ok");
    while(1) update();
    return 0;
}