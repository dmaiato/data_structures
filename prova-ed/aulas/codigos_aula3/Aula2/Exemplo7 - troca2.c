#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, *px, y, *py, aux;

    x = 10; 
    y = 20;

    printf("\n X = %d e Y = %d",x,y);
    aux = x;
    px = &x;
    py = &y;

    //troca de valores
    x = *py;
    y = *px;

    printf("\n X = %d e Y = %d\n",x,y);

}

