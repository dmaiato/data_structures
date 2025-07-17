// Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de entrada
// e retorne eles ordenados, ou seja, o menor valor na primeira variável, o segundo menor valor na variável do
// meio, e o maior valor na última variável. A função deve retornar o valor 1 se os três valores forem iguais e 0
// se existirem valores diferentes. Exibir os valores ordenados na tela.

#include <stdio.h>

int ordenar(int *a, int *b, int *c) {
    // Verifica se todos são iguais
    if (*a == *b && *b == *c) {
        return 1;
    }
    
    // Ordena os valores usando ponteiros
    if (*a > *b) { // Troca a e b
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) { // Troca a e c
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) { // Troca b e c
        int temp = *b;
        *b = *c;
        *c = temp;
    }
    
    return 0;
}

int main() {
    int x, y, z;
    
    printf("Digite tres valores inteiros: ");
    scanf("%d %d %d", &x, &y, &z);
    
    int iguais = ordenar(&x, &y, &z);
    
    printf("Ordenados: %d, %d, %d\n", x, y, z);
    
    return 0;
}