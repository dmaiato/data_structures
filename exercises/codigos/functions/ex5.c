// Implemente a função a qual recebe duas strings, str1 e str2, e um valor inteiro positivo
// N . A função concatena não mais que N caracteres da string apontada por str2 à string
// apontada por str1 e termina str1 com NULL.

#include <stdio.h>

void concatenar_n(char *str1, const char *str2, int n) {
    // Encontra o final de str1
    while (*str1 != '\0') {
        str1++;
    }
    
    // Copia até n caracteres de str2 ou até encontrar '\0' em str2
    while (n-- > 0 && *str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    
    *str1 = '\0'; // Termina a string com NULL
}

int main() {
    char str1[20] = "Inicio"; // Espaço suficiente para a concatenação
    char str2[] = "Fim";
    int n = 3;
    
    concatenar_n(str1, str2, n);
    printf("Resultado: %s\n", str1); // Saída: "InicioFim" (se n >= 3)
    
    return 0;
}