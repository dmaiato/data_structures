#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, *px, y, *py;

    x = 10; 
    y = 20;

    //copia o endereço de x, para o ponteiro px;
    px = &x;
    py = &y;

    printf("\n X = %d - Endereço = %x",x,px);
    printf("\n Y = %d - Endereço = %x",y,py);

    //troca 
    px = &y;

    printf("\n Px = %d - Endereço Px = %x\n",*px,px);

}

