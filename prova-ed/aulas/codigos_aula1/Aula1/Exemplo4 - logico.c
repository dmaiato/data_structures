#include <stdio.h>
#include <stdlib.h>

int main(){
    int vLogico1, vLogico2;

    vLogico1 = 10 > 5;
    vLogico2 = 10 < 5;

    printf("\n Valor Lógico 1 = %d",vLogico1);
    printf("\n Valor Lógico 2 = %d\n",vLogico2);

    if(vLogico1)
        printf("\n 1 = Verdadeiro!\n");
    else
        printf("\n  Menor que 1 < Falso!\n");
}

