#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, *px;

    x = 10;
    //copia o endereço de x, para o ponteiro px;
    px = &x;

    printf("\n X = %d - Endereço = %x",x,&x);

    //consulta a variável x, através do ponteiro px
    //operador "*" para consultar o valor referenciado por px
    printf("\n X = %d - Endereço = %x\n",*px,px);
}

