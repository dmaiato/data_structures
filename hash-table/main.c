#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAM_HASH 500
#define NUM_PLACAS 10000

typedef struct no {
    char placa[8];
    struct no *prox;
} No;

typedef struct {
    No **tabela;
    int tamanho;
} TabelaHash;

// Funções da Tabela Hash
unsigned long hash_djb2(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

TabelaHash* criarTabela(int tamanho) {
    TabelaHash *th = (TabelaHash*)malloc(sizeof(TabelaHash));
    th->tamanho = tamanho;
    th->tabela = (No**)calloc(tamanho, sizeof(No*));
    return th;
}

int hash_index(TabelaHash *th, char *placa) {
    return hash_djb2(placa) % th->tamanho;
}

void inserirNaTabela(TabelaHash *th, char *placa) {
    int index = hash_index(th, placa);
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->placa, placa);
    novo->prox = th->tabela[index];
    th->tabela[index] = novo;
}

No* buscarNaTabela(TabelaHash *th, char *placa) {
    int index = hash_index(th, placa);
    No *atual = th->tabela[index];
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

// Funções de Ordenação
void selectionSort(char arr[][8], int n) {
    char temp[8];
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        if (min_idx != i) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
    }
}

void insertionSort(char arr[][8], int n) {
    char key[8];
    for (int i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j+1], key);
    }
}

void bubbleSort(char arr[][8], int n) {
    char temp[8];
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

void shellSort(char arr[][8], int n) {
    char temp[8];
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            strcpy(temp, arr[i]);
            int j;
            for (j = i; j >= gap && strcmp(arr[j-gap], temp) > 0; j -= gap) {
                strcpy(arr[j], arr[j-gap]);
            }
            strcpy(arr[j], temp);
        }
    }
}

void quickSortRec(char arr[][8], int low, int high) {
    if (low < high) {
        char pivot[8];
        strcpy(pivot, arr[(low + high) / 2]);
        int i = low, j = high;
        char temp[8];
        
        do {
            while (strcmp(arr[i], pivot) < 0) i++;
            while (strcmp(arr[j], pivot) > 0) j--;
            if (i <= j) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
                i++;
                j--;
            }
        } while (i <= j);
        
        if (low < j) quickSortRec(arr, low, j);
        if (i < high) quickSortRec(arr, i, high);
    }
}

void quickSort(char arr[][8], int n) {
    quickSortRec(arr, 0, n-1);
}

// Funções de Busca
int buscaSequencial(char arr[][8], int n, char *placa) {
    for (int i = 0; i < n; i++)
        if (strcmp(arr[i], placa) == 0)
            return i;
    return -1;
}

int buscaBinaria(char arr[][8], int n, char *placa) {
    int inicio = 0, fim = n-1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(arr[meio], placa);
        if (cmp == 0) return meio;
        if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// Geração de Placas
void gerarPlacas(char placas[][8], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        placas[i][0] = 'A' + rand() % 26;
        placas[i][1] = 'A' + rand() % 26;
        placas[i][2] = 'A' + rand() % 26;
        placas[i][3] = '0' + rand() % 10;
        placas[i][4] = 'A' + rand() % 26;
        placas[i][5] = '0' + rand() % 10;
        placas[i][6] = '0' + rand() % 10;
        placas[i][7] = '\0';
    }
}

// Função Principal
int main() {
    char placas[NUM_PLACAS][8];
    
    // Parte 1: Gerar placas e tabela hash
    gerarPlacas(placas, NUM_PLACAS);
    TabelaHash *th = criarTabela(TAM_HASH);
    for (int i = 0; i < NUM_PLACAS; i++)
        inserirNaTabela(th, placas[i]);
    
    // Parte 2: Preparar cópias para ordenação
    char copia1[NUM_PLACAS][8];
    char copia2[NUM_PLACAS][8];
    char copia3[NUM_PLACAS][8];
    char copia4[NUM_PLACAS][8];
    char copia5[NUM_PLACAS][8];
    
    for (int i = 0; i < NUM_PLACAS; i++) {
        strcpy(copia1[i], placas[i]);
        strcpy(copia2[i], placas[i]);
        strcpy(copia3[i], placas[i]);
        strcpy(copia4[i], placas[i]);
        strcpy(copia5[i], placas[i]);
    }
    
    // Parte 3: Medição de tempo de ordenação
    clock_t begin, end;
    double tempo;
    
    // Selection Sort
    begin = clock();
    selectionSort(copia1, NUM_PLACAS);
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.6f segundos\n", tempo);
    
    // Insertion Sort
    begin = clock();
    insertionSort(copia2, NUM_PLACAS);
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %.6f segundos\n", tempo);
    
    // Bubble Sort
    begin = clock();
    bubbleSort(copia3, NUM_PLACAS);
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.6f segundos\n", tempo);
    
    // Shell Sort
    begin = clock();
    shellSort(copia4, NUM_PLACAS);
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Shell Sort: %.6f segundos\n", tempo);
    
    // Quick Sort
    begin = clock();
    quickSort(copia5, NUM_PLACAS);
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Quick Sort: %.6f segundos\n", tempo);
    
    // Parte 4: Sistema de busca
    int n_buscas;
    printf("\nQuantas placas deseja buscar? ");
    scanf("%d", &n_buscas);
    getchar(); // Limpar buffer
    
    char placas_busca[n_buscas][8];
    printf("Digite as placas (formato ABC1D23):\n");
    for (int i = 0; i < n_buscas; i++) {
        fgets(placas_busca[i], 8, stdin);
        getchar(); // Limpar ENTER
        for (int j = 0; j < 7; j++) {
            if (j < 3 || j == 4) placas_busca[i][j] = toupper(placas_busca[i][j]);
        }
    }
    
    // Busca na lista desordenada
    begin = clock();
    for (int i = 0; i < n_buscas; i++) {
        buscaSequencial(placas, NUM_PLACAS, placas_busca[i]);
    }
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTempo lista desordenada: %.6f segundos\n", tempo);
    
    // Busca na lista ordenada (usando Quick Sort)
    begin = clock();
    for (int i = 0; i < n_buscas; i++) {
        buscaBinaria(copia5, NUM_PLACAS, placas_busca[i]);
    }
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo lista ordenada: %.6f segundos\n", tempo);
    
    // Busca na tabela hash
    begin = clock();
    for (int i = 0; i < n_buscas; i++) {
        buscarNaTabela(th, placas_busca[i]);
    }
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo tabela hash: %.6f segundos\n", tempo);
    
    // Resultados e conclusão
    printf("\n=== RESULTADOS FINAIS ===\n");
    printf("- Melhor algoritmo de ordenacao: Quick Sort (mais rapido em grandes conjuntos)\n");
    printf("- Melhor metodo de busca: Tabela Hash (tempo constante em operacoes tipicas)\n");
    printf("- Lista ordenada com busca binaria: Excelente para multiplas buscas estaticas\n");
    printf("- Lista desordenada: Ineficiente para buscas (apenas recomendada para poucos itens)\n");
    
    // Liberar memória
    for (int i = 0; i < TAM_HASH; i++) {
        No *atual = th->tabela[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(th->tabela);
    free(th);
    
    return 0;
}