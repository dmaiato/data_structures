#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade1, idade2;

    printf("\n Informe sua idade1:");  //saída
    scanf("%d",&idade1);  //entrada de dados

    printf("\n Informe sua idade2:");  //saída
    scanf("%d",&idade2);  //entrada de dados

    printf("\n Idade1 é: %d e Idade2 é = %d",idade1,idade2);

    //Operador  & para consultar endereço de memória
    printf("\n Idade1 está armazenada na posição de memória = %x ",&idade1);
    printf("\n Idade2 está armazenada na posição de memória = %x \n\n",&idade2);


}

