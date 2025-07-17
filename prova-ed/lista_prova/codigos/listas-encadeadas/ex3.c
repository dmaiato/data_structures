// 3. Considere as estruturas (Figura 3) para uma lista de números inteiros positivos. Implemente as
// funções insereInício e removeInício. Execute algumas inserções e remoções.
// 4. Considere as estruturas (Figura 3) para uma lista de números inteiros positivos. Implemente as
// funções insereOrdenado e removePosicao. A função insere ordenado sempre insere o elemento
// mantendo a ordem crescente do valores. A função remove na posição remove o elemento escolhido
// pelo usuário, com base no seu valor.
// 5. Faça uma função que retorne quantos números pares existem na lista.
// 6. Considere uma lista contendo números inteiros positivos. Faça uma função que retorne uma nova
// lista contendo apenas os números pares da lista (cópia).
// 7. Considere uma lista contendo números inteiros positivos. Faça uma função que retorne a média da
// lista.
// 8. Considere uma lista contendo números inteiros positivos. Faça uma função que retorne uma nova
// lista como os elementos em ordem inversa a lista original. Mostre as listas.

#include <stdio.h>
#include <stdlib.h>

// estrutura dada
typedef struct numero {
  int id;
  struct numero *anterior;
  struct numero *proximo;
} Num;

typedef struct LDE {
  Num *primeiro;
  Num *ultimo; 
  int qtd;
} LDEN;

// 3 - Insere no início da lista
void insereInicio(LDEN *lista, int valor) {
  Num *novo = (Num*) malloc(sizeof(Num));
  novo->id = valor;
  novo->anterior = NULL;
  novo->proximo = lista->primeiro;

  if (lista->primeiro == NULL) { // Lista vazia
      lista->ultimo = novo;
  } else {
      lista->primeiro->anterior = novo;
  }

  lista->primeiro = novo;
  lista->qtd++;
}

// 3 - Remove do início da lista
int removeInicio(LDEN *lista) {
  if (lista->primeiro == NULL) return -1; // Lista vazia

  Num *remover = lista->primeiro;
  int valor = remover->id;

  lista->primeiro = remover->proximo;
  if (lista->primeiro == NULL) { // Lista ficou vazia
      lista->ultimo = NULL;
  } else {
      lista->primeiro->anterior = NULL;
  }

  free(remover);
  lista->qtd--;
  return valor;
}

// 4 - Insere em ordem crescente
void insereOrdenado(LDEN *lista, int valor) {
  Num *novo = (Num*) malloc(sizeof(Num));
  novo->id = valor;

  if (lista->primeiro == NULL) { // Lista vazia
      novo->anterior = novo->proximo = NULL;
      lista->primeiro = lista->ultimo = novo;
  } else {
      Num *atual = lista->primeiro;
      while (atual != NULL && atual->id < valor) {
          atual = atual->proximo;
      }

      if (atual == lista->primeiro) { // Inserir no início
          novo->proximo = lista->primeiro;
          lista->primeiro->anterior = novo;
          lista->primeiro = novo;
      } else if (atual == NULL) { // Inserir no fim
          novo->anterior = lista->ultimo;
          lista->ultimo->proximo = novo;
          lista->ultimo = novo;
      } else { // Inserir no meio
          novo->proximo = atual;
          novo->anterior = atual->anterior;
          atual->anterior->proximo = novo;
          atual->anterior = novo;
      }
  }
  lista->qtd++;
}

// 4 - Remove pelo valor
int removePosicao(LDEN *lista, int valor) {
  Num *atual = lista->primeiro;
  while (atual != NULL && atual->id != valor) {
      atual = atual->proximo;
  }

  if (atual == NULL) return -1; // Valor não encontrado

  if (atual->anterior == NULL) { // É o primeiro
      lista->primeiro = atual->proximo;
  } else {
      atual->anterior->proximo = atual->proximo;
  }

  if (atual->proximo == NULL) { // É o último
      lista->ultimo = atual->anterior;
  } else {
      atual->proximo->anterior = atual->anterior;
  }

  free(atual);
  lista->qtd--;
  return valor;
}

// 5 - Conta números pares
int contaPares(LDEN *lista) {
  int pares = 0;
  Num *atual = lista->primeiro;
  while (atual != NULL) {
      if (atual->id % 2 == 0) pares++;
      atual = atual->proximo;
  }
  return pares;
}

// 6 - Retorna nova lista com números pares
LDEN* copiaPares(LDEN *original) {
  LDEN *novaLista = (LDEN*) malloc(sizeof(LDEN));
  novaLista->primeiro = novaLista->ultimo = NULL;
  novaLista->qtd = 0;

  Num *atual = original->primeiro;
  while (atual != NULL) {
      if (atual->id % 2 == 0) {
          Num *novo = (Num*) malloc(sizeof(Num));
          novo->id = atual->id;
          novo->proximo = NULL;
          novo->anterior = novaLista->ultimo;

          if (novaLista->ultimo == NULL) { // Lista vazia
              novaLista->primeiro = novo;
          } else {
              novaLista->ultimo->proximo = novo;
          }
          novaLista->ultimo = novo;
          novaLista->qtd++;
      }
      atual = atual->proximo;
  }
  return novaLista;
}

// 7 - Retorna média da lista
float mediaLista(LDEN *lista) {
  if (lista->qtd == 0) return 0.0;
  float soma = 0;
  Num *atual = lista->primeiro;
  while (atual != NULL) {
      soma += atual->id;
      atual = atual->proximo;
  }
  return soma / lista->qtd;
}

// 8 - Retorna nova lista com elementos em ordem inversa
LDEN* inverteLista(LDEN *original) {
  LDEN *novaLista = (LDEN*) malloc(sizeof(LDEN));
  novaLista->primeiro = novaLista->ultimo = NULL;
  novaLista->qtd = 0;

  Num *atual = original->ultimo; // Começa pelo fim da original
  while (atual != NULL) {
      Num *novo = (Num*) malloc(sizeof(Num));
      novo->id = atual->id;
      novo->proximo = NULL;
      novo->anterior = novaLista->ultimo;

      if (novaLista->ultimo == NULL) {
          novaLista->primeiro = novo;
      } else {
          novaLista->ultimo->proximo = novo;
      }
      novaLista->ultimo = novo;
      novaLista->qtd++;

      atual = atual->anterior; // Move para o anterior na original
  }
  return novaLista;
}

// Função para exibir a lista
void mostraLista(LDEN *lista) {
    if (lista->primeiro == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Num *atual = lista->primeiro;
    printf("Lista (%d elementos): [ ", lista->qtd);
    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->proximo;
    }
    printf("]\n");
}

int main() {
    LDEN lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;
    lista.qtd = 0;

    int opcao, valor;
    LDEN *novaLista;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Remover do inicio\n");
        printf("3. Inserir ordenado\n");
        printf("4. Remover por valor\n");
        printf("5. Contar pares\n");
        printf("6. Copiar lista de pares\n");
        printf("7. Calcular media\n");
        printf("8. Inverter lista\n");
        printf("9. Mostrar lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor para inserir no inicio: ");
                scanf("%d", &valor);
                insereInicio(&lista, valor);
                mostraLista(&lista);
                break;

            case 2:
                valor = removeInicio(&lista);
                if (valor == -1) printf("Lista vazia!\n");
                else printf("Valor removido: %d\n", valor);
                mostraLista(&lista);
                break;

            case 3:
                printf("Valor para inserir ordenado: ");
                scanf("%d", &valor);
                insereOrdenado(&lista, valor);
                mostraLista(&lista);
                break;

            case 4:
                printf("Valor para remover: ");
                scanf("%d", &valor);
                int removido = removePosicao(&lista, valor);
                if (removido == -1) printf("Valor nao encontrado!\n");
                else printf("Valor %d removido!\n", removido);
                mostraLista(&lista);
                break;

            case 5:
                printf("Quantidade de pares: %d\n", contaPares(&lista));
                break;

            case 6:
                novaLista = copiaPares(&lista);
                printf("Lista de pares copiada:\n");
                mostraLista(novaLista);
                free(novaLista); // Libera memória da lista temporária
                break;

            case 7:
                printf("Media: %.2f\n", mediaLista(&lista));
                break;

            case 8:
                novaLista = inverteLista(&lista);
                printf("Lista invertida:\n");
                mostraLista(novaLista);
                free(novaLista); // Libera memória da lista temporária
                break;

            case 9:
                mostraLista(&lista);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    // Libera memória da lista principal (opcional)
    while (lista.primeiro != NULL) {
        removeInicio(&lista);
    }

    return 0;
}