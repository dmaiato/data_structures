// Implemente a função a qual recebe duas strings, str1 e str2, e concatena a string apontada por str2 à
// string apontada por str1.

#include <stdio.h>

void concatenar(char *str1, const char *str2) {
    // Encontra o final de str1 (onde está o '\0')
    while (*str1 != '\0') {
        str1++;
    }
    
    // Copia cada caractere de str2 para o final de str1
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    
    *str1 = '\0'; // Adiciona o terminador nulo no final
}

int main() {
    char str1[20] = "Olá, "; // Espaço suficiente para a concatenação
    char str2[] = "mundo!";
    
    concatenar(str1, str2);
    printf("Resultado: %s\n", str1); // Saída: "Olá, mundo!"
    
    return 0;
}