// Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função que retorne a soma
// do dobro dos dois números lidos. A função deverá armazenar o dobro de A na própria variável A e o dobro de
// B na própria variável B.

#include <stdio.h>

// Função que dobra A e B e retorna a soma dos dobros
int somaDobro(int *a, int *b) {
    *a *= 2;  // Dobra o valor de A (modifica a variável original)
    *b *= 2;  // Dobra o valor de B (modifica a variável original)
    return *a + *b;  // Retorna a soma dos dobros
}

int main() {
    int A, B;
    
    printf("Digite dois valores inteiros (A e B): ");
    scanf("%d %d", &A, &B);
    
    int resultado = somaDobro(&A, &B);  // Passa os endereços de A e B
    
    printf("\nApos a funcao:\n");
    printf("Novo A (dobro): %d\n", A);
    printf("Novo B (dobro): %d\n", B);
    printf("Soma dos dobros: %d\n", resultado);
    
    return 0;
}