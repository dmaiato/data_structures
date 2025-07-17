#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, *px, y, *py, aux;

    x = 10; 
    y = 20;

    printf("\n X = %d e Y = %d",x,y);
    
    px = &x;
    py = &y;

    printf("\n PX = %d e PY = %d",*px,*py);

    //troca de endereços
    px = &y;
    py = &x;

    printf("\n PX = %d e PY = %d",*px,*py);

    printf("\n X = %d e Y = %d \n",x,y);

}

