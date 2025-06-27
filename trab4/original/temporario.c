#include <stdbool.h>

typedef enum { VERMELHO, AZUL, VERDE, AMARELO } Cor;

typedef struct {
    Cor cor;
    bool ocupado;
} Temporario;

void inicializa_temp(Temporario *t) {
    t->ocupado = false;
}

bool push_temp(Temporario *t, Cor cor) {
    if (t->ocupado) return false;
    t->cor = cor;
    t->ocupado = true;
    return true;
}

bool pop_temp(Temporario *t, Cor *cor) {
    if (!t->ocupado) return false;
    *cor = t->cor;
    t->ocupado = false;
    return true;
}