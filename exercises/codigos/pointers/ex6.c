// Implemente uma função que calcule a área da superfı́cie e o volume de uma esfera de raio R. Essa função
// deve obedecer ao protótipo: void calc_esfera(float R, float *area, float *volume)


#include <stdio.h>
#include <math.h>

#define PI 3.14159

void calc_esfera(float R, float *area, float *volume) {
    *area = 4 * PI * pow(R, 2);      // Área = 4πR²
    *volume = (4.0f / 3.0f) * PI * pow(R, 3);  // Volume = (4/3)πR³
}

int main() {
    float raio, area, volume;
    
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);
    
    calc_esfera(raio, &area, &volume);  // Passa endereços de área e volume
    
    printf("Area da superficie: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
    
    return 0;
}