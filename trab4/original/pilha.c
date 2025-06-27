#include <stdlib.h>
#include <stdbool.h>

#define MAX_PILHA 4
typedef enum { VERMELHO, AZUL, VERDE, AMARELO } Cor;

typedef struct item {
    Cor cor;
    struct item *prox;
} item;

typedef struct {
    item *topo;
    int tamanho;
} Pilha;

void inicializa_pilha(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

bool push(Pilha *p, Cor cor) {
    if (p->tamanho >= MAX_PILHA) return false;
    item *novo = malloc(sizeof(item));
    if (!novo) return false;
    novo->cor = cor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    return true;
}

bool pop(Pilha *p, Cor *cor) {
    if (p->tamanho == 0) return false;
    item *tmp = p->topo;
    *cor = tmp->cor;
    p->topo = tmp->prox;
    free(tmp);
    p->tamanho--;
    return true;
}

void libera_pilha(Pilha *p) {
    Cor c;
    while (pop(p, &c));
}