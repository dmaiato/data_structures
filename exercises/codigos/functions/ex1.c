// Escreva uma função que gera um triângulo lateral de altura 2*n-1 e n largura. Por exemplo, a saı́da para n = 4
// seria:
// *
// **
// ***
// ****
// ***
// **
// *

#include <stdio.h>

void triangulo_lateral(int n) {
    // Parte superior (crescente)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Parte inferior (decrescente)
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    triangulo_lateral(n);
    
    return 0;
}