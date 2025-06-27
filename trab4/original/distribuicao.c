#include <stdlib.h>
#include <stdbool.h>

#define NUM_PILHAS 4
#define MAX_PILHA 4
#define NUM_CORES 4
#define PINOS_INICIAIS 3

typedef enum { VERMELHO, AZUL, VERDE, AMARELO } Cor;

typedef struct item {
    Cor cor;
    struct item *prox;
} item;

typedef struct {
    item *topo;
    int tamanho;
} Pilha;

bool push(Pilha *p, Cor cor);

void distribui_pinos(Pilha pilhas[]) {
    Cor pinos[NUM_PILHAS * PINOS_INICIAIS];
    int idx = 0;
    // Preenche o vetor com 3 de cada cor
    for (int c = 0; c < NUM_CORES; c++)
        for (int i = 0; i < 3; i++)
            pinos[idx++] = (Cor)c;

    // Embaralha os pinos
    for (int i = (NUM_PILHAS * PINOS_INICIAIS) - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório
		// Troca os pinos i e j
        Cor tmp = pinos[i];
		pinos[i] = pinos[j];
        pinos[j] = tmp;
    }

    // Distribui nas pilhas (apenas 3 pinos por pilha)
    idx = 0;
    for (int i = 0; i < NUM_PILHAS; i++)
        for (int j = 0; j < PINOS_INICIAIS; j++)
            push(&pilhas[i], pinos[idx++]);
}