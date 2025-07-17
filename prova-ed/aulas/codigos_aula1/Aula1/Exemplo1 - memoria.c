#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade;

    printf("\n Informe sua idade:");  //saída
    scanf("%d",&idade);  //entrada de dados

    printf("\n Sua idade é: %d",idade);
    printf("\n Sua idade está armazenada na posição de memória = %x \n\n",&idade);


}

