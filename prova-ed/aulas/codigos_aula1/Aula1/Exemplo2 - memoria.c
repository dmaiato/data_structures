#include <stdio.h>
#include <stdlib.h>

int main(){
    double salario1, salario2;

    printf("Informe sua salario1:");  //saída
    scanf("%lf",&salario1);  //entrada de dados

    printf("Informe sua salario2:");  //saída
    scanf("%lf",&salario2);  //entrada de dados

    printf("\n salario1 é: %.2f e salario2 é = %.2f",salario1,salario2);

    //Operador  & para consultar endereço de memória
    printf("\n salario1 está armazenada na posição de memória = %x ",&salario1);
    printf("\n salario2 está armazenada na posição de memória = %x \n\n",&salario2);


}

