// Faça uma função que dado um caractere qualquer retorne o mesmo caractere sempre
// em maiúsculo.

#include <stdio.h>

char paraMaiusculo(char letra) {
    // Converte para maiúsculo apenas se for letra minúscula (ASCII)
    if (letra >= 'a' && letra <= 'z') {
        return letra - 32; // Diferença entre 'a' (97) e 'A' (65) na tabela ASCII
    }
    return letra; // Mantém outros caracteres inalterados
}

int main() {
    char caractere;
    printf("Digite um caractere: ");
    scanf("%c", &caractere);
    
    printf("Maiusculo: %c\n", paraMaiusculo(caractere));
    
    return 0;
}