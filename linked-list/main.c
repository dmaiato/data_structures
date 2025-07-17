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

Carro* novoCarro2(char modelo[], char placa[], float valor){
    //cria um novo carro com os dados passados como parâmetro
    Carro *novo = (Carro*)malloc(sizeof(Carro));
    strcpy(novo->modelo,modelo);
    strcpy(novo->placa,placa);
    novo->valor_locacao = valor;
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

void inserePosicao(LSE *lista, Carro *novo, int posicao) {
    //inserir um elemento em qualquer posição da lista (posicao)

    if (posicao < 1) {
        //posição inválida
        return;
    }

    if (posicao == 1) {
        insereInicio(lista, novo);
        return;
    } else if (posicao >= lista->n_elementos) {
        insereFim(lista, novo);
        return;
    }
    //insere no meio da lista
    Carro *aux = lista->primeiro;
    for (int i = 1; i < posicao - 1; i++) {
        aux = aux->proximo;
    }
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    lista->n_elementos++;
}

Carro* removeInicio(LSE *lista){
    //remove o primeiro elemento da lista
    Carro *aux = lista->primeiro;
    if(aux != NULL){
        //lista com um ou mais elementos//
        lista->primeiro = lista->primeiro->proximo;
        lista->n_elementos--;
    } else {
        //lista vazia
        return NULL;
    }
    aux->proximo = NULL;
    return aux;
}

Carro* removeFim(LSE *lista) {
    //remove o último elemento da lista
    Carro *aux = lista->primeiro;
    Carro *anterior = NULL;
    if (aux == NULL) {
        //lista vazia
        printf("\n\tLista Vazia!!\n");
        return NULL;
    }
    while (aux->proximo != NULL) {
        anterior = aux;
        aux = aux->proximo;
    }
    if (anterior == NULL) {
        //somente um elemento na lista
        lista->primeiro = NULL;
    } else {
        anterior->proximo = NULL;
    }
    lista->n_elementos--;
    return aux;
}

Carro* removePosicao(LSE *lista, int posicao) {
    //remove o elemento da lista na posicao definida (posicao)
    if (posicao < 1 || posicao > lista->n_elementos) {
        //posição inválida
        return NULL;
    }

    Carro *aux = lista->primeiro;
    Carro *anterior = NULL;
    if (aux == NULL) {
        //lista vazia
        return NULL;
    }
    if (posicao == 1) {
        //remove o primeiro elemento
        return removeInicio(lista);    
    }
    for (int i = 1; i < posicao; i++) {
        anterior = aux;
        aux = aux->proximo;
        if (aux == NULL) {
            //posicao maior que o tamanho da lista
            return NULL;
        }
    }
    anterior->proximo = aux->proximo;
    lista->n_elementos--;
    return aux;
}


void mostraCarro(Carro novo){
    //mostra os dados de um elemento Carro
    printf("\n\tCarro Modelo: %s Placa %s Valor %.2f",novo.modelo,novo.placa,novo.valor_locacao);
    printf("\n\t\t Cod. Locador %d Nome: %s",novo.ultimaLocacao.codigo,novo.ultimaLocacao.nome);
}

int buscarPorModelo(LSE* lista, char modelo[]){
    //busca um carro pelo modelo
    Carro *aux = lista->primeiro;
    int pos = 1;
    while(aux != NULL){
        if(strcasecmp(aux->modelo,modelo) == 0){
            return pos;
        }
        aux = aux->proximo;
        pos++;
    }
    return -1; //não encontrado
}

int quantidadeElementos(LSE* lista){
    //retorna a quantidade de elementos da lista
    return lista->n_elementos;
}

void mostraLista(LSE lista) {
    //mostra todos elementos da lista 
    if (lista.n_elementos == 0) {
        printf("\n\tLista Vazia!!\n");
        return;
    }
    
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

void apagarElemento(Carro *carro){
    //apaga um elemento Carro
    free(carro);
}

void apagarLista(LSE *lista){
    //apaga todos os elementos da lista
    Carro *aux = lista->primeiro;
    while(aux != NULL){
        Carro *temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    lista->primeiro = NULL;
    lista->n_elementos = 0;
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
    printf("\n\t8 - Buscar carro por modelo:");
    printf("\n\t9 - Apaga um elemento da lista:");
    printf("\n\t10 - Apaga Lista:");
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
            scanf("%d", &posicao);
            inserePosicao(lista, novoCarro(), posicao);
            break;
        case 4:
            printf("\n\tFuncao Remove no Inicio:");
            aux = removeInicio(lista);
            if (aux != NULL) {
                mostraCarro(*aux);
                free(aux);
            }
            break;
        case 5:
            printf("\n\tFuncao Remove no Fim:");
            aux = removeFim(lista);
            if (aux != NULL) {
                mostraCarro(*aux);
                free(aux);
            }
            break;
        case 6:
            printf("\n\tFuncao Remove na Posicao!!");
            printf("\n\t\tInforme a posicao:");
            scanf("%d", &posicao);
            aux = removePosicao(lista, posicao);
            if (aux != NULL) {
                mostraCarro(*aux);
                free(aux);
            } else {
                printf("\n\tPosicao Invalida ou Carro nao encontrado!!\n");
            }
            break;
        case 7:
            printf("\n\nMostra Lista de %s!!!", lista->lista_de);
            mostraLista(*lista);
            break;
        case 8:
            char modelo[100];
            printf("\n\tFuncao Buscar carro por modelo!!");
            printf("\n\t\tInforme o modelo:");
            scanf("%s", &modelo);
            posicao = buscarPorModelo(lista, modelo);
            if (posicao != -1) {
                printf("\n\tCarro encontrado na posicao %d", posicao);
            } else {
                printf("\n\tCarro nao encontrado na lista!\n");
            }
            break;
        case 9:
            printf("\n\tFuncao Apaga um Carro da Lista!!");
            printf("\n\t\tInforme a posicao:");
            scanf("%d", &posicao);
            aux = removePosicao(lista, posicao);
            if (aux != NULL) {
                mostraCarro(*aux);
                free(aux);
            } else {
                printf("\n\tPosicao Invalida ou Carro nao encontrado!!\n");
            }
            break;
        case 10:
            printf("\n\tFuncao Apaga toda Lista!");
            apagarLista(lista);
            break;
        case 0:
            printf("\n\n*** Fim do Programa!!! ***\n");
            break;
        default:
            printf("\n\n*** Opcao Invalida!!! ***\n");
    }
    if (op != 0) {
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

    insereFim(listaLivres, novoCarro2("Fusca","ABC1234",100));
    insereFim(listaLivres, novoCarro2("Civic","ABC1235",200));
    insereFim(listaLivres, novoCarro2("Corsa","ABC1236",150));
    insereFim(listaLivres, novoCarro2("Palio","ABC1237",120));
    insereFim(listaLivres, novoCarro2("Gol","ABC1238",130));

    menuTesteLista(listaLivres);

    listaLocados = criaLista("ListaLocados");

    sistemaLocadora(listaLivres,listaLocados);

    printf("\n Fim do Programa Locadora!\n");



    exit(0);
}