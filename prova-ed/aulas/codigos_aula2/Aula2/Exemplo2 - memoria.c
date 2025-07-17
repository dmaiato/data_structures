#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float f;
    double d;
    char c;

    printf("\n Tamanho do int = %d",sizeof(i));
    printf("\n Tamanho do float = %d",sizeof(f));
    printf("\n Tamanho do dooble = %d",sizeof(d));
    printf("\n Tamanho do char = %d\n",sizeof(c));

    char nome[20];
    printf("\n Tamanho do Vetor(20) = %d\n",sizeof(nome));


}

