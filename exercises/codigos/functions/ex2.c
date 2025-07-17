// Escreva uma função que gera um triângulo de altura e lados n e base 2*n-1. Por exemplo, a saı́da para n = 6
// seria:
// *
// ***
// *****
// *******
// *********
// ***********

#include <stdio.h>

void triangulo(int n) {
    for (int i = 0; i < n; i++) {
        // Imprime (2*i + 1) asteriscos por linha
        for (int j = 0; j < 2*i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    triangulo(n);
    
    return 0;
}