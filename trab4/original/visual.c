#include <stdio.h>
#include <stdbool.h>

#define NUM_PILHAS 4
#define MAX_PILHA 4
#define NUM_TEMP 2
#define NUM_CORES 4

typedef enum { VERMELHO, AZUL, VERDE, AMARELO } Cor;
extern const char* nomes_cores[];

typedef struct item {
    Cor cor;
    struct item *prox;
} item;

typedef struct {
    item *topo;
    int tamanho;
} Pilha;

typedef struct {
    Cor cor;
    bool ocupado;
} Temporario;

void mostra_pilhas(Pilha pilhas[], Temporario temps[], int num_temp) {
    printf("\nTemp1   P1   P2   P3   P4   Temp2\n");
    int altura = MAX_PILHA;
    for (int nivel = altura - 1; nivel >= 0; nivel--) {
        // Só mostra Temp1 se existir pelo menos um temporário
        if (nivel == altura - 1 && num_temp > 0)
            printf(" [%s]  ", temps[0].ocupado ? nomes_cores[temps[0].cor] : " ");
        else
            printf("      ");
        for (int p = 0; p < NUM_PILHAS; p++) {
            item *n = pilhas[p].topo;
            int pos = pilhas[p].tamanho - 1;
            while (n && pos > nivel) {
                n = n->prox;
                pos--;
            }
            if (n && pos == nivel)
                printf(" [%s] ", nomes_cores[n->cor]);
            else
                printf(" [ ] ");
        }
        // Só mostra Temp2 se houver dois temporários
        if (nivel == altura - 1 && num_temp > 1)
            printf("  [%s]", temps[1].ocupado ? nomes_cores[temps[1].cor] : " ");
        printf("\n");
    }
}