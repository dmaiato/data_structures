// Crie uma função que compara duas strings e que retorna se elas são iguais ou diferentes.

#include <stdio.h>

int saoIguais(const char *str1, const char *str2) {
    // Percorre ambas as strings até encontrar um caractere diferente ou o fim de uma delas
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; // Caracteres diferentes encontrados
        }
        str1++;
        str2++;
    }
    // Verifica se ambas as strings terminaram ao mesmo tempo
    return (*str1 == '\0' && *str2 == '\0');
}

int main() {
    char string1[100], string2[100];
    
    printf("Digite a primeira string: ");
    scanf("%99s", string1);
    
    printf("Digite a segunda string: ");
    scanf("%99s", string2);
    
    if (saoIguais(string1, string2)) {
        printf("As strings sao iguais.\n");
    } else {
        printf("As strings sao diferentes.\n");
    }
    
    return 0;
}