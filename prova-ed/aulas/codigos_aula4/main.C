#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Arquivo de prototipos das funções e definicao das estruturas

//Estrutura para armazenar alunos
typedef struct aluno{
    char nome[100];
    int idade;
    int matricula;
    struct aluno *proximo;
}Aluno;

//Estrutura para gerenciar a lista
typedef struct lse{
    Aluno *primeiro;
    int n_elementos;
    char turma [20];
}LSE;


LSE* criaLista( char nome []){
    //recebe a estrutura de lista e preenche os parâmetros
    LSE *nova = (LSE*)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    strcpy(nova->turma,nome);
    return nova;
}

void insereInicio(LSE *lista, Aluno *novo){
    //insere um elemento no início da lista (primeiro) 
    if(lista->primeiro == NULL){
        //Lista Vazia
        novo->proximo = NULL;
    }else{
        //Lista com elementos
        novo->proximo = lista->primeiro;
    }
    lista->primeiro = novo;
    lista->n_elementos++;
}

void insereInicioReduzida(LSE *lista, Aluno *novo){
    //insere um elemento no início da lista forma reduzida
    novo->proximo = lista->primeiro;
    lista->primeiro = novo;
    lista->n_elementos++;
}

void insereFim(LSE *lista, Aluno *novo){
    //insere um novo elemento no fim da lista (último)
    novo->proximo = NULL;
    if(lista->primeiro == NULL){
        //Lista Vazia
        lista->primeiro = novo;
    }else{
        //Lista com elementos
        Aluno *aux = lista->primeiro;
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    lista->n_elementos++;
}

void inserePosicao(LSE *lista, Aluno *novo, int posicao);
    //inserir um elemento em qualquer posição da lista (posicao)

Aluno* removeInicio(LSE *lista){
    //remove o primeiro elemento da lista
    Aluno *aux = lista->primeiro;
    if(aux != NULL){
        //lista com um ou mais elementos//
        lista->primeiro = aux->proximo;
        lista->n_elementos--;
    }else{
        printf("\n\t\t NÃO PODE REMOVER - Lista VAZIA!\n");
    }
    return aux;
}

Aluno* removeFim(LSE *lista);
    //remove o último elemento da lista

Aluno* removePosicao(LSE *lista, int posicao);
    //remove o elemento da lista na posicao definida (posicao)


void cadastraAluno(Aluno *aluno, char nome[], int idade, int matricula){
    //recebe um ponteiro de aluno e atribui os valores aos membros
    strcpy(aluno->nome,nome);
    aluno->idade = idade;
    aluno->matricula = matricula;
    aluno->proximo = NULL;
}

Aluno* lerAluno(){
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    printf("\nInforme os dados do novo Aluno:");
    printf("\nNome:");
    scanf("%s",novo->nome);
    printf("Idade:");
    scanf("%s",&novo->idade);
    printf("Matricula:");
    scanf("%s",&novo->matricula);
    novo->proximo = NULL;
    return novo;
}

void mostraAluno(Aluno novo){
    //mostra os dados de um elemento Aluno
    printf("\t\tAluno: %s Idade %d Matricula %d\n",novo.nome,novo.idade,novo.matricula);
}

void mostraLista(LSE lista){
    //mostra todos elementos da lista 
    printf("\n\tMostra Lista Simplesmente Encadeada; \n");
    Aluno *aux; //ponteiro auxiliar
    aux = lista.primeiro;
    for(int i=0;i<lista.n_elementos;i++){
        mostraAluno(*aux);
        aux = aux->proximo;
    }
    printf("\t\tTotal de alunos na Lista = %d \n",lista.n_elementos);
    printf("\tFim da Lista!\n");
}

void mostraLista2(Aluno *aluno){
    //mostra todos elementos da lista com o uso de recursão na função
    if(aluno!=NULL){
        mostraAluno(*aluno);
        mostraLista2(aluno->proximo);
    }
}

//programa principal para teste 

void menuTesteLista(LSE *lista) {
    int op = 0, posicao = 0;
    Aluno *aux = NULL;
    printf("\nMenu de operacoes sobre um LSE:\n");
    printf("\n\t1 - Insere no Inicio:");
    printf("\n\t2 - Insere no Fim:");
    printf("\n\t3 - Insere na Posicao:");
    printf("\n\t4 - Remove no Inicio:");
    printf("\n\t5 - Remove no Fim:");
    printf("\n\t6 - Remove na Posicao:");
    printf("\n\t7 - Mostra Lista:");
    printf("\n\t8 - Mostra Aluno na Posicao:");
    printf("\n\t9 - Apaga Lista:");
    printf("\n\t0 - Para Sair da Funcao Menu:");
    printf("\n\tInforme a opcao:");
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("\n\tFuncao Insere no Inicio!!");
            insereInicio(lista, lerAluno());
            break;
        case 2:
            printf("\n\tFuncao Insere no Fim!!");
            insereFim(lista, lerAluno());
            break;
        case 3:
            printf("\n\tFuncao Insere na Posicao!!");
            printf("\n\t\tInforme a posicao:");
            // scanf("%d", &posicao);
            // inserePosicao(lista, lerAluno(), posicao);
            break;
        case 4:
            printf("\n\tFuncao Remove no Inicio:");
            aux = removeInicio(lista);
            if (aux != NULL) {
                mostraAluno(*aux);
                free(aux);
            }
            break;
        case 5:
            printf("\n\tFuncao Remove no Fim:");
            // aux = removeFim(lista);
            // if (aux != NULL) {
            //     mostraAluno(*aux);
            //     free(aux);
            // }
            break;
        case 6:
            printf("\n\tFuncao Remove na Posicao!!");
            // printf("\n\t\tInforme a posicao:");
            // scanf("%d", &posicao);
            // aux = removePosicao(lista, posicao);
            // if (aux != NULL) {
            //     mostraAluno(*aux);
            //     free(aux);
            // }
            break;
        case 7:
            printf("\n\nMostra Lista %s!!!", lista->turma);
            mostraLista(*lista);
            break;
        case 8:
            printf("\n\tFuncao Mostra um Aluno na Posicao - Pos!!");
            printf("\n\t\tInforme a posicao:");
            break;
        case 9:
            printf("\n\tFuncao Apaga toda Lista!");
            break;
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


int main(){

    printf("Exemplo - Lista Simplesmente Encadeada - Lista de Alunos\n");

    //declaração um ponteiro de Lista
    LSE *matematica;

    //Aloca e preenche os dados para uma nova Lista
    matematica = criaLista("Matematica");

    menuTesteLista(matematica);

    printf("\n Fim do Programa de TESTES!\n");



    exit(0);
}