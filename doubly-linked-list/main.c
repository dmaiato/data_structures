#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa {
  char descricao[100];
  int id, prioridade, concluida;
  struct tarefa *anterior;
  struct tarefa *proximo;
} Tarefa;

typedef struct LDE {
  Tarefa *primeiro;
  Tarefa *ultimo;
  int tamanho;
} LDE;

Tarefa* criaTarefa(int id) {
  char descricao[100];
  int prioridade;

  Tarefa *novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
  if (novaTarefa == NULL) {
    return NULL;
  }

  printf("Descrição da tarefa: ");
  scanf(" %[^\n]", descricao);
  printf("Prioridade da tarefa (1-5): ");
  scanf("%d", &prioridade);

  if (descricao == NULL || id <= 0 || prioridade < 1 || prioridade > 5) {
    return NULL;
  }

  strcpy(novaTarefa->descricao, descricao);
  novaTarefa->id = id;
  novaTarefa->prioridade = prioridade;
  novaTarefa->concluida = 0;
  novaTarefa->anterior = NULL;
  novaTarefa->proximo = NULL;
  return novaTarefa;
}

Tarefa* criaTarefaBuffer(char *descricao, int id, int prioridade, int concluida) {
  Tarefa *novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
  if (novaTarefa == NULL) {
    return NULL;
  }
  strcpy(novaTarefa->descricao, descricao);
  novaTarefa->id = id;
  novaTarefa->prioridade = prioridade;
  novaTarefa->concluida = concluida;
  novaTarefa->anterior = NULL;
  novaTarefa->proximo = NULL;
  return novaTarefa;
}

LDE* criaLista() {
  LDE *lista = (LDE*)malloc(sizeof(LDE));
  if (lista == NULL) {
    printf("\n>> Erro ao alocar memória para a lista.\n");
    return NULL;
  }
  lista->primeiro = NULL;
  lista->ultimo = NULL;
  lista->tamanho = 0;
  return lista;
}

void mostraTarefa(Tarefa *tarefa) {
  if (tarefa != NULL) {
    printf("\t> ID - %d: \n", tarefa->id);
    printf("\t\tDescrição: %s\n", tarefa->descricao);
    printf("\t\tPrioridade: %d\n", tarefa->prioridade);
    printf("\t\tConcluída: %s\n", tarefa->concluida ? "Sim" : "Não");
  }
}

void insereInicio(LDE *lista, Tarefa *novaTarefa) {
  if (lista->primeiro == NULL) {
    lista->primeiro = novaTarefa;
    lista->ultimo = novaTarefa;
  } else {
    novaTarefa->proximo = lista->primeiro;
    lista->primeiro->anterior = novaTarefa;
    lista->primeiro = novaTarefa;
    lista->primeiro->anterior = NULL;
  }
  lista->tamanho++;
}

void insereFim(LDE *lista, Tarefa *novaTarefa) {
  if (lista->ultimo == NULL) {
    lista->primeiro = novaTarefa;
    lista->ultimo = novaTarefa;
  } else {
    lista->ultimo->proximo = novaTarefa;
    novaTarefa->anterior = lista->ultimo;
    lista->ultimo = novaTarefa;
    lista->ultimo->proximo = NULL;
  }
  lista->tamanho++;
}

void inserePosicao(LDE *lista, Tarefa *novaTarefa, int posicao) {
  if (posicao < 1 || posicao > lista->tamanho) {
    printf("\n>> Posição inválida.\n");
    return;
  }
  if (posicao == 1) {
    insereInicio(lista, novaTarefa);
  } else if (posicao == lista->tamanho) {
    insereFim(lista, novaTarefa);
  } else {
    Tarefa *aux = lista->primeiro;
    for (int i = 1; i < posicao; i++) {
      aux = aux->proximo;
    }
    novaTarefa->proximo = aux->proximo;
    novaTarefa->anterior = aux;
    aux->proximo->anterior = novaTarefa;
    aux->proximo = novaTarefa;
    lista->tamanho++;
  }
}

Tarefa* removeInicio(LDE *lista) {
  if (lista->primeiro == NULL) {
    printf("\n>> Lista vazia.\n");
    return NULL;
  }
  Tarefa *removida = lista->primeiro;
  lista->primeiro = lista->primeiro->proximo;
  if (lista->primeiro != NULL) { // Se não for o único elemento
    lista->primeiro->anterior = NULL;
  } else { // Se for o único elemento
    // primeiro já é NULL
    lista->ultimo = NULL;
  }
  lista->tamanho--;
  return removida;
}

Tarefa* removeFim(LDE *lista) {
  if (lista->ultimo == NULL) {
    printf("\n>> Lista vazia.\n");
    return NULL;
  }
  Tarefa *removida = lista->ultimo;
  lista->ultimo = lista->ultimo->anterior;
  if (lista->ultimo != NULL) { // Se não for o único elemento
    lista->ultimo->proximo = NULL;
  } else { // Se for o único elemento
    // último já é NULL
    lista->primeiro = NULL;
  }
  lista->tamanho--;
  return removida;
}

Tarefa* removePosicao(LDE *lista, int posicao) {
  if (posicao < 1 || posicao > lista->tamanho) {
    printf("\n>> Posição inválida.\n");
    return NULL;
  }
  if (posicao == 1) {
    return removeInicio(lista);
  } else if (posicao == lista->tamanho) {
    return removeFim(lista);
  } else {
    Tarefa *aux = lista->primeiro;
    for (int i = 1; i < posicao; i++) {
      aux = aux->proximo;
    }
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    lista->tamanho--;
    return aux;
  }
}

void mostraListaDE(LDE lista) { // início -> fim
  if (lista.primeiro == NULL) {
    printf("\n>> Lista vazia.\n");
    return;
  }
  printf("\n>> Lista de tarefas [%d]:\n", lista.tamanho);
  Tarefa *aux = lista.primeiro;
  printf("\n");
  while (aux != NULL) {
    mostraTarefa(aux);
    aux = aux->proximo;
  }
}

void mostraListaED(LDE *lista) { // fim -> início
  if (lista->ultimo == NULL) {
    printf("\n>> Lista vazia.\n");
    return;
  }
  Tarefa *aux = lista->ultimo;
  printf("\n");
  while (aux != NULL) {
    mostraTarefa(aux);
    aux = aux->anterior;
  }
}

void apagaElemento(Tarefa *tarefa) {
  if (tarefa != NULL) {
    free(tarefa);
  }
}

// apaga todos os elementos e a lista fica vazia, porém a lista ainda existe
void apagaLista(LDE *lista) {
  if (lista == NULL) {
    return;
  }
  Tarefa *aux = lista->primeiro;
  int pos = 1;
  while (aux != NULL) {
    apagaElemento(removePosicao(lista, pos));
    aux = aux->proximo;
  }
  printf("\n>> Lista apagada.\n");
}

int procurarTarefa(LDE *lista, int id) {
  Tarefa *aux = lista->primeiro;
  int pos = 1;
  while (aux != NULL) {
    if (aux->id == id) {
      return pos;
    }
    aux = aux->proximo;
    pos++;
  }
  return 0; // Tarefa não encontrada
}

void menuFuncoes() {
  printf("\n======= Menu de opções =======\n");
  printf("1. Inserir tarefa no início;\n");
  printf("2. Inserir tarefa no fim;\n");
  printf("3. Inserir tarefa em uma posição;\n");
  printf("4. Remover tarefa do início;\n");
  printf("5. Remover tarefa do fim;\n");
  printf("6. Remover tarefa de uma posição;\n");
  printf("7. Mostrar lista (início -> fim);\n");
  printf("8. Apaga um elemento da lista;\n");
  printf("9. Apaga a lista;\n");
  printf("0. Ir para o menu de tarefas;\n");
}

void mostrarTarefasComMesmaPrioridade(LDE *lista, int prioridade) {
  Tarefa *aux = lista->primeiro;
  printf("\n>> Tarefas com prioridade %d:\n", prioridade);
  while (aux != NULL) {
    if (aux->prioridade == prioridade) {
      mostraTarefa(aux);
    }
    aux = aux->proximo;
  }
}

void mostrarTarefasOrdenadasPorPrioridade(LDE *lista) {
  if (lista->tamanho == 0) {
    printf("\n>> Lista vazia.\n");
    return;
  }
  Tarefa *aux = lista->primeiro;
  Tarefa *tarefas[lista->tamanho];
  int i = 0;

  while (aux != NULL) {
    tarefas[i++] = aux;
    aux = aux->proximo;
  }

  // Ordenar as tarefas por prioridade
  for (int j = 0; j < lista->tamanho - 1; j++) {
    for (int k = j + 1; k < lista->tamanho; k++) {
      if (tarefas[j]->prioridade > tarefas[k]->prioridade) {
        Tarefa *temp = tarefas[j];
        tarefas[j] = tarefas[k];
        tarefas[k] = temp;
      }
    }
  }

  printf("\n>> Tarefas ordenadas por prioridade:\n");
  for (int j = 0; j < lista->tamanho; j++) {
    mostraTarefa(tarefas[j]);
  }
}

void mostrarTarefasConcluidas(LDE *lista) {
  Tarefa *aux = lista->primeiro;
  printf("\n>> Tarefas concluídas:\n");
  while (aux != NULL) {
    if (aux->concluida) {
      mostraTarefa(aux);
    }
    aux = aux->proximo;
  }
}

void verificarTarefaRepetida(LDE *lista, char *descricao) {
  Tarefa *aux = lista->primeiro;
  while (aux != NULL) {
    if (stricmp(aux->descricao, descricao) == 0) {
      printf("\n>> Tarefa repetida encontrada:\n", aux->descricao);
      mostraTarefa(aux);
      return;
    }
    aux = aux->proximo;
  }
  printf("\n>> Nenhuma tarefa repetida encontrada.\n");
}

void controlador(LDE *lista) {
  int opcao, id = 1;
  char descricao[100];
  int prioridade;
  
  do {
    menuFuncoes();
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 0) {
      printf("\n>> Saindo do menu de opções...\n");
      break;
    }

    switch (opcao) {
      case 1: {
        Tarefa *novaTarefa = criaTarefa(id++);
        if (novaTarefa == NULL) {
          printf("\n>> Erro ao criar tarefa.\n");
          break;
        }
        insereInicio(lista, novaTarefa);
        break;
      }
      case 2: {
        Tarefa *novaTarefa = criaTarefa(id++);
        if (novaTarefa == NULL) {
          printf("\n>> Erro ao criar tarefa.\n");
          break;
        }
        insereFim(lista, novaTarefa);
        break;
      }
      case 3: {
        Tarefa *novaTarefa = criaTarefa(id++);
        if (novaTarefa == NULL) {
          printf("\n>> Erro ao criar tarefa.\n");
          break;
        }
        int posicao;
        printf("Posição para inserir a tarefa: ");
        scanf("%d", &posicao);
        inserePosicao(lista, novaTarefa, posicao);
        break;
      }
      case 4:
        apagaElemento(removeInicio(lista));
        break;
      case 5:
        apagaElemento(removeFim(lista));
        break;
      case 6:
        int posicaoRemover;
        printf("Posição para remover a tarefa: ");
        scanf("%d", &posicaoRemover);
        apagaElemento(removePosicao(lista, posicaoRemover));
        break;
      case 7:
        mostraListaDE(*lista);
        break;
      case 8:
        int id;
        printf("ID da tarefa a ser removida: ");
        scanf("%d", &id);
        int pos = procurarTarefa(lista, id);
        if (pos == 0) {
          printf("\n>> Tarefa não encontrada.\n");
        } else {
          apagaElemento(removePosicao(lista, pos));
        }
        break;
      case 9:
        apagaLista(lista);
        printf("\n>> Conteúdo da lista apagado.\n");
        break;
      default:
        printf("\n>> Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 0);

  // Implemente um sistema para gerenciar Tarefas do dia. Crie uma lista com várias tarefas
  // pré-cadastradas e diferentes prioridades (mínimo de 15 tarefas), após mostre:
  // 1. Todos os elementos com a mesma prioridade;
  // 2. Todos os elementos ordenados por prioridade (modo crescente);
  // 3. Os elementos que a tarefa já foi concluída;
  // 4. Verifique existência de tarefa repetida (descrição igual).

  // insere tarefas pré-cadastradas
  for (int i = 0; i < 15 - lista->tamanho; i++) {
    insereFim(lista, criaTarefaBuffer("Tarefa pré-cadastrada", id++, rand() % 5 + 1, rand() % 2));
  }
  

  do {
    printf("\n======= Menu de tarefas =======\n");
    printf("1. Mostrar tarefas com a mesma prioridade;\n");
    printf("2. Mostrar tarefas ordenadas por prioridade (crescente);\n");
    printf("3. Mostrar tarefas concluídas;\n");
    printf("4. Verificar existência de tarefa repetida;\n");
    printf("0. Sair;\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 0) {
      printf("\n>> Saindo do menu de tarefas...\n");
      break;
    }

    switch (opcao) {
      case 1:
        int prioridade;
        printf("Prioridade: ");
        scanf("%d", &prioridade);
        mostrarTarefasComMesmaPrioridade(lista, prioridade);
        break;
      case 2:
        mostrarTarefasOrdenadasPorPrioridade(lista);
        break;
      case 3:
        mostrarTarefasConcluidas(lista);
        break;
      case 4:
        char descricao[100];
        printf("Descrição da tarefa: ");
        scanf("%s", descricao);
        verificarTarefaRepetida(lista, descricao);
        break;
      default:
        printf("\n>> Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 0);
}

int main() {
  LDE *lista = criaLista();
  if (lista == NULL) {
    return 1; // Erro ao criar a lista
  }
  controlador(lista);
  return 0;
}