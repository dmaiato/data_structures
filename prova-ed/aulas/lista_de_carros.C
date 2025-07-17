#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Arquivo de prototipos das funções e definicao das estruturas

//Estrutura para armazenar clientes
typedef struct cliente{
    char nome[100];
    int codigo;
}Cliente;

//Estrutura para armazenar carros
typedef struct carro{
    char modelo[100];
    char placa[8];
    float valor_locacao;
    Cliente ultimaLocacao;
    struct carro *proximo;
}Carro;

//Estrutura para gerenciar a lista
typedef struct lse{
    Carro *primeiro;
    int n_elementos;
    char lista_de [20]; //Definirmos um nome para cada lista
}LSE;


LSE* criaLista(char nome[]){
    //recebe a estrutura de lista e preenche os parâmetros
    LSE *nova = (LSE*)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    strcpy(nova->lista_de,nome);
    return nova;
}

Carro* novoCarro(){
    Carro *novo = (Carro*)malloc(sizeof(Carro));
    printf("\nInforme o modelo do Carro:");
    scanf("%s",novo->modelo);
    printf("Placa do Carro:");
    scanf("%s",novo->placa);
    novo->valor_locacao = 100;
    novo->ultimaLocacao.codigo = 0;
    strcpy(novo->ultimaLocacao.nome,"");
    novo->proximo = NULL;
    return novo;
}


void insereInicio(LSE *lista, Carro *novo){
    //insere um elemento no início da lista forma reduzida
    novo->proximo = lista->primeiro;
    lista->primeiro = novo;
    lista->n_elementos++;
}

void insereFim(LSE *lista, Carro *novo){
    //insere um novo elemento no fim da lista (último)
    novo->proximo = NULL;
    if(lista->primeiro == NULL){
        //Lista Vazia
        lista->primeiro = novo;
    }else{
        //Lista com elementos
        Carro *aux = lista->primeiro;
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    lista->n_elementos++;
}

void inserePosicao(LSE *lista, Carro *novo, int posicao);
    //inserir um elemento em qualquer posição da lista (posicao)

Carro* removeInicio(LSE *lista){
    //remove o primeiro elemento da lista
    Carro *aux = lista->primeiro;
    if(aux != NULL){
        //lista com um ou mais elementos//
        lista->primeiro = lista->primeiro->proximo;
        lista->n_elementos--;
    }
    aux->proximo = NULL;
    return aux;
}

Carro* removeFim(LSE *lista);
    //remove o último elemento da lista

Carro* removePosicao(LSE *lista, int posicao);
    //remove o elemento da lista na posicao definida (posicao)


void mostraCarro(Carro novo){
    //mostra os dados de um elemento Carro
    printf("\n\tCarro Modelo: %s Placa %s Valor %.2f",novo.modelo,novo.placa,novo.valor_locacao);
    printf("\n\t\t Cod. Locador %d Nome: %s",novo.ultimaLocacao.codigo,novo.ultimaLocacao.nome);
}

void mostraLista(LSE lista){
    //mostra todos elementos da lista 
    printf("\n\tMostra Lista Simplesmente Encadeada; \n");
    Carro *aux; //ponteiro auxiliar
    aux = lista.primeiro;
    for(int i=0;i<lista.n_elementos;i++){
        mostraCarro(*aux);
        aux = aux->proximo;
    }
    printf("\n\t\tTotal de Carros na Lista = %d ",lista.n_elementos);
    printf("\n\tFim da Lista!\n");
}


//programa principal para teste 

void menuTesteLista(LSE *lista) {
    int op = 0, posicao = 0;
    Carro *aux = NULL;
    printf("\nMenu de operacoes sobre um LSE:\n");
    printf("\n\t1 - Insere no Inicio:");
    printf("\n\t2 - Insere no Fim:");
    printf("\n\t3 - Insere na Posicao:");
    printf("\n\t4 - Remove no Inicio:");
    printf("\n\t5 - Remove no Fim:");
    printf("\n\t6 - Remove na Posicao:");
    printf("\n\t7 - Mostra Lista:");
    printf("\n\t8 - Mostra Carro na Posicao:");
    printf("\n\t9 - Apaga Lista:");
    printf("\n\t0 - Para Sair da Funcao Menu:");
    printf("\n\tInforme a opcao:");
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("\n\tFuncao Insere no Inicio!!");
            insereInicio(lista, novoCarro());
            break;
        case 2:
            printf("\n\tFuncao Insere no Fim!!");
            insereFim(lista, novoCarro());
            break;
        case 3:
            printf("\n\tFuncao Insere na Posicao!!");
            printf("\n\t\tInforme a posicao:");
            // scanf("%d", &posicao);
            // inserePosicao(lista, lerCarro(), posicao);
            break;
        case 4:
            printf("\n\tFuncao Remove no Inicio:");
            aux = removeInicio(lista);
            if (aux != NULL) {
                mostraCarro(*aux);
                free(aux);
            }
            break;
    //     case 5:
    //         printf("\n\tFuncao Remove no Fim:");
    //         // aux = removeFim(lista);
    //         // if (aux != NULL) {
    //         //     mostraCarro(*aux);
    //         //     free(aux);
    //         // }
    //         break;
    //     case 6:
    //         printf("\n\tFuncao Remove na Posicao!!");
    //         // printf("\n\t\tInforme a posicao:");
    //         // scanf("%d", &posicao);
    //         // aux = removePosicao(lista, posicao);
    //         // if (aux != NULL) {
    //         //     mostraCarro(*aux);
    //         //     free(aux);
    //         // }
    //         break;
        case 7:
            printf("\n\nMostra Lista de %s!!!", lista->lista_de);
            mostraLista(*lista);
            break;
    //     case 8:
    //         printf("\n\tFuncao Mostra um Carro na Posicao - Pos!!");
    //         printf("\n\t\tInforme a posicao:");
    //         break;
    //     case 9:
    //         printf("\n\tFuncao Apaga toda Lista!");
    //         break;
        case 0:
            printf("\n\n*** Fim do Programa!!! ***\n");
            break;
        default:
            printf("\n\n*** Opcao Invalida!!! ***\n");
    }
    if (op > 0 && op < 10) {
        menuTesteLista(lista);
    }
}

void sistemaLocadora(LSE *livres, LSE *locados){
    //função para gerenciar as locações e devoluções de carros
    printf("\n SISTEMA LOCADORA DE CARROS!!");
}



int main(){

    printf("Sistema Locadora de Carros:\n");

    //declaração um ponteiro de Lista
    LSE *listaLivres, *listaLocados;

    //Aloca e preenche os dados para uma nova Lista
    listaLivres = criaLista("ListaLivres");

    menuTesteLista(listaLivres);

    listaLocados = criaLista("ListaLocados");

    sistemaLocadora(listaLivres,listaLocados);

    printf("\n Fim do Programa Locadora!\n");



    exit(0);
}