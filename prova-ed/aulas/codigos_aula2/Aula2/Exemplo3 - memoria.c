#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y;

    x = 10, y = 20;

    printf("\n X = %d - Endereço = %x",x,&x);
    printf("\n Y = %d - Endereço = %x\n",y,&y);
}

