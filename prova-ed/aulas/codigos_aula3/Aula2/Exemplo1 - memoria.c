#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 10, y = 50; //variavel
    int *px;    //ponteiro

    px = &x;

    printf("\n Valor de x = %d",x);
    printf("\n Valor referenciado por px = %d",*px);

    *px = *px + 25;

    printf("\n Valor de x = %d",x);
    printf("\n Valor referenciado por px = %d\n",*px);

    px = &y;
    printf("\n Valor de x = %d",x);
    printf("\n Valor de y = %d",y);


    int aux;

    aux = *px;   //aux = y;
    *px =  x;    //y = x;
    px = &x;
    *px = aux;

    printf("\n Valor de x = %d",x);
    printf("\n Valor de y = %d",y);









}

