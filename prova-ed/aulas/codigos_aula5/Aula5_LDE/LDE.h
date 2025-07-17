
typedef struct tarefa
{
    char descricao [30];
    int id, prioridade, concluida;
    struct tarefa *anterior;
    struct tarefa *proximo;
}Tarefa;


typedef struct LDE
{
    Tarefa *primeiro;
    Tarefa *ultimo; //facultativo
    int num;
}LDE;

//protótipos das Funções

//Definição ou assinatura da Função

Tarefa* criaTarefa(int id); 

LDE* criaListaLDE();

void mostraTarefa(Tarefa tf);

void insereInicio(LDE *lt, Tarefa *tf);

void insereFim(LDE *lt, Tarefa *tf);

void inserePosicao(LDE *lt, Tarefa *tf, int pos);

Tarefa* removeInicio(LDE *lt);

Tarefa* removeFim(LDE *lt);

Tarefa* removePosicao(LDE *lt, int pos);

void mostraListaED(LDE lt);

void mostraListaDE(LDE lt);

void menu(LDE *lt);



