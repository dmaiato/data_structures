#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[20];

    printf("Informe seu nome:");  //saída
    scanf("%s",nome);  //entrada de dados

    printf("\n Seu nome é = %s \n",nome);

    printf("\n Seu nome é = %c \n",nome[0]);
    printf("\n Seu nome é = %c \n",nome[1]);
    printf("\n Seu nome é = %c \n",nome[2]);
}

