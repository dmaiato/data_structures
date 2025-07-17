#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"


Tarefa* criaTarefa(int id){
//Cria e inicializa um nova tarefa.
    Tarefa *nova = (Tarefa*)malloc(sizeof(Tarefa));
    printf("\nInforme a Tarefa:");
    scanf("%s",nova->descricao);
    nova->id = id;
    printf("Informe a Prioridade:");
    scanf("%d",&nova->prioridade);
    nova->concluida = 0;  //Zero não concluida e 1 concluida
    nova->anterior = NULL;
    nova->proximo = NULL;
    return nova;
}

LDE* criaListaLDE(){
    LDE *nova = (LDE*)malloc(sizeof(LDE));
    nova->primeiro = NULL;
    nova->ultimo = NULL;
    nova->num = 0;
    return nova;
}

void mostraTarefa(Tarefa tf){
    printf("\n Tafera N° %d",tf.id);
    printf("\n\t Descricao: %s",tf.descricao);
    printf("\n\t Prioridade: %d",tf.prioridade);
    if(tf.concluida)
        printf("\n\t Tarefa já concluída.");
    else
        printf("\n\t Tarefa Não concluída.");
}

void insereInicio(LDE *lt, Tarefa *tf){
    //Insere um novo elemento no inicio da lista LDE
    tf->anterior = NULL;
    if(lt->primeiro == NULL){
        tf->proximo = NULL;
        lt->ultimo = tf;
    }else{
        tf->proximo = lt->primeiro;
        lt->primeiro->anterior = tf;
    }
    lt->primeiro = tf;
    lt->num++;
}

void insereFim(LDE *lt, Tarefa *tf){
    //Insere um novo elemento no Fim da lista LDE
    tf->proximo = NULL;
    if(lt->primeiro == NULL)
        insereInicio(lt,tf);
    else{
        tf->anterior = lt->ultimo;
        lt->ultimo->proximo = tf;
    }
    lt->ultimo = tf;
    lt->num++;
}

void inserePosicao(LDE *lt, Tarefa *tf, int pos);

Tarefa* removeInicio(LDE *lt);

Tarefa* removeFim(LDE *lt);

Tarefa* removePosicao(LDE *lt, int pos);


void mostraListaED(LDE lt){
    //Mostrar Lista da Esquerda para Direita - através do ponteiro Proximo
    Tarefa *aux = lt.primeiro;
    if(aux == NULL)
        printf("\n LISTA VAZIA!");
    else{
        printf("\n Início da Lista!");
        while(aux != NULL){
            mostraTarefa(*aux);
            aux = aux->proximo;
        }
        printf("\n Fim da Lista ED!");
    }
}

void mostraListaDE(LDE lt){
    //Mostra lista Ultimo para o Primeiro - através do ponteiro anterior
    Tarefa *aux = lt.ultimo;
    if(aux == NULL)
        printf("\n LISTA VAZIA!");
    else{
        printf("\n Início da Lista!");
        while(aux != NULL){
            mostraTarefa(*aux);
            aux = aux->anterior;
        }
        printf("\n Fim da Lista DE!");
    }
}  


void menu(LDE *lt){
    int opcao = 0, posicao, id=1;
    Tarefa *aux;
    do{
        printf("\n 1 - Insere no Inicio");
        printf("\n 2 - Insere no Fim");
        printf("\n 3 - Insere na Posição");
        printf("\n 4 - Remove no Inicio");
        printf("\n 5 - Remove no Fim");
        printf("\n 6 - Remove na Posicao");
        printf("\n 7 - Mostrar uma Tarefa Posicao");
        printf("\n 8 - Mostra Lista ED");
        printf("\n 9 - Mostra Lista DE");
        printf("\n 10 - Apaga Lista"); 
        printf("\n Informe uma Opcao:");
        scanf("%d",&opcao); 
        
        switch(opcao){
        case 1:
            insereInicio(lt,criaTarefa(id++));
        break;
        case 2:
            insereFim(lt,criaTarefa(id++));
        break;
        case 3:
            printf("\n Informe a Posicao");
            scanf("%d",&posicao);
            //inserePosicao(lt,criaTarefa(id++),posicao);
        break;
        case 4:
            //aux = removeInicio(lt);
            free(aux);
        break;
        case 5:
           // aux = removeFim(lt);
            free(aux);
        break;
        case 6:
            printf("\n Informe a Posicao");
            scanf("%d",&posicao);
            //aux = removePosicao(lt,posicao);
            free(aux);
        break;
        case 7:
            printf("\n Informe a Posicao");
            scanf("%d",&posicao);
            //navegar/ a ate a posição e mostrar
        break;
        case 8:
            mostraListaED(*lt);
        break;
        case 9:
            mostraListaDE(*lt);
        break;
        case 10:
            free(lt);
        break;
        default:
            printf("\n Opção Invalida!!");  
        }
    }while(opcao!= 0);
}
