#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Tipos e constantes compartilhados
#define NUM_PILHAS 4
#define NUM_TEMP 2 // Número de temporários | dificuldade
#define MAX_PILHA 4
#define NUM_CORES 4
#define PINOS_INICIAIS 3

typedef enum { VERMELHO, AZUL, VERDE, AMARELO } Cor;
const char* nomes_cores[] = { "V", "A", "E", "M" };

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

// Prototipagem das funções implementadas em outros arquivos .c
void inicializa_pilha(Pilha *p);
bool push(Pilha *p, Cor cor);
bool pop(Pilha *p, Cor *cor);
void libera_pilha(Pilha *p);

void inicializa_temp(Temporario *t);
bool push_temp(Temporario *t, Cor cor);
bool pop_temp(Temporario *t, Cor *cor);

void mostra_pilhas(Pilha pilhas[], Temporario temps[], int num_temp);
void distribui_pinos(Pilha pilhas[]);

bool jogo_finalizado(Pilha pilhas[]) {
    // Verifica se todas as pilhas têm 3 pinos e se todos os pinos têm a mesma cor
    for (int i = 0; i < NUM_PILHAS; i++) {
        // Se a pilha não tiver 3 pinos, o jogo não está finalizado
        if (pilhas[i].tamanho != PINOS_INICIAIS)
            return false;
        item *n = pilhas[i].topo;
        if (!n) return false; //  pilha vazia
        // Verifica se todos os pinos na pilha têm a mesma cor
        Cor cor_base = n->cor;
        while (n) {
            if (n->cor != cor_base)
                return false;
            n = n->prox;
        }
    }
    return true;
}

int main() {
    Pilha pilhas[NUM_PILHAS];
    Temporario temps[NUM_TEMP];
    int num_temp = NUM_TEMP;

    srand(time(NULL));
    // Inicializa as pilhas e temporários
    for (int i = 0; i < NUM_PILHAS; i++) inicializa_pilha(&pilhas[i]);
    for (int i = 0; i < num_temp; i++) inicializa_temp(&temps[i]);
    distribui_pinos(pilhas);

    // Inicia o cronômetro
    time_t inicio = time(NULL);

    while (1) {
        mostra_pilhas(pilhas, temps, num_temp);
        if (jogo_finalizado(pilhas)) {
            printf("\nParabens! Voce venceu!\n");
            break;
        }
        printf("\nEscolha a acao:\n");
        printf("1) Mover pino de uma pilha para outra\n");
        printf("2) Mover pino de uma pilha para um temporario\n");
        printf("3) Mover pino de um temporario para uma pilha\n");
        printf("0) Sair\n");
        int op, origem, destino;
        scanf("%d", &op);
        if (op == 0) break;
        Cor cor;
        switch (op) {
            case 1:
                printf("De qual pilha (1-4)? ");
                scanf("%d", &origem);
                printf("Para qual pilha (1-4)? ");
                scanf("%d", &destino);
                if (origem < 1 || origem > 4 || destino < 1 || destino > 4) {
                    printf("Pilha inválida!\n");
                    break;
                }
                if (pop(&pilhas[origem-1], &cor) && push(&pilhas[destino-1], cor))
                    printf("Movimento realizado!\n");
                else {
                    printf("Movimento invalido!\n");
                    if (cor >= 0 && cor < NUM_CORES) push(&pilhas[origem-1], cor);
                }
                break;
            case 2:
                printf("De qual pilha (1-4)? ");
                scanf("%d", &origem);
                printf("Para qual temporario (1-%d)? ", num_temp);
                scanf("%d", &destino);
                if (origem < 1 || origem > 4 || destino < 1 || destino > num_temp) {
                    printf("Opcao invalida!\n");
                    break;
                }
                if (pop(&pilhas[origem-1], &cor) && push_temp(&temps[destino-1], cor))
                    printf("Movimento realizado!\n");
                else {
                    printf("Movimento invalido!\n");
                    if (cor >= 0 && cor < NUM_CORES) push(&pilhas[origem-1], cor);
                }
                break;
            case 3:
                printf("De qual temporario (1-%d)? ", num_temp);
                scanf("%d", &origem);
                printf("Para qual pilha (1-4)? ");
                scanf("%d", &destino);
                if (origem < 1 || origem > num_temp || destino < 1 || destino > 4) {
                    printf("Opcao invalida!\n");
                    break;
                }
                if (pop_temp(&temps[origem-1], &cor) && push(&pilhas[destino-1], cor))
                    printf("Movimento realizado!\n");
                else {
                    printf("Movimento invalido!\n");
                    if (cor >= 0 && cor < NUM_CORES) push_temp(&temps[origem-1], cor);
                }
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    time_t fim = time(NULL);
    int tempo_total = (int)(fim - inicio);
    int minutos = tempo_total / 60;
    int segundos = tempo_total % 60;
    printf("Tempo total: %d minutos e %d segundos\n", minutos, segundos);

    for (int i = 0; i < NUM_PILHAS; i++) libera_pilha(&pilhas[i]);
    return 0;
}