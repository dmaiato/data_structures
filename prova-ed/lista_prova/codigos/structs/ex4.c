// Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes
// dados: Nome, E-mail, Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade,
// estado, paı́s). Telefone (contendo campo para DDD e número)
// (a) Definir a estrutura acima.
// (b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes.
// (c) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome
// (se tiver mais de uma pessoa, imprime para todas).
// (d) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas
// que fazem aniversário nesse mês.
// (e) Definir um bloco de instruções insere pessoa: Insere por ordem alfabética de nome.
// (f) Definir um bloco de instruções retira pessoa: Retira todos os dados dessa pessoa e desloca todos os
// elementos seguintes do vetor para a posição anterior.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTATOS 100
#define TAM_STRING 50

// (a) Definição das estruturas
typedef struct {
    char rua[TAM_STRING];
    int numero;
    char complemento[TAM_STRING];
    char bairro[TAM_STRING];
    char cep[TAM_STRING];
    char cidade[TAM_STRING];
    char estado[TAM_STRING];
    char pais[TAM_STRING];
} Endereco;

typedef struct {
    int ddd;
    char numero[TAM_STRING];
} Telefone;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[TAM_STRING];
    char email[TAM_STRING];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
} Pessoa;

// (b) Vetor agenda
Pessoa agenda[MAX_CONTATOS];
int totalContatos = 0;

// (c) Busca por primeiro nome
void busca_primeiro_nome() {
    char nomeBusca[TAM_STRING];
    printf("Digite o primeiro nome: ");
    scanf("%s", nomeBusca);
    getchar(); // Limpa buffer

    printf("\nResultados:\n");
    for (int i = 0; i < totalContatos; i++) {
        // Compara até o primeiro espaço ou fim da string
        char primeiroNome[TAM_STRING];
        sscanf(agenda[i].nome, "%s", primeiroNome);
        
        if (strcasecmp(primeiroNome, nomeBusca) == 0) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Aniversario: %d/%d/%d\n\n", 
                   agenda[i].aniversario.dia, 
                   agenda[i].aniversario.mes, 
                   agenda[i].aniversario.ano);
        }
    }
}

// (d) Busca por mês de aniversário
void busca_mes_aniversario() {
    int mes;
    printf("Digite o mês (1-12): ");
    scanf("%d", &mes);
    getchar();

    printf("\nAniversariantes do mês %d:\n", mes);
    for (int i = 0; i < totalContatos; i++) {
        if (agenda[i].aniversario.mes == mes) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Data: %d/%d/%d\n\n", 
                   agenda[i].aniversario.dia, 
                   agenda[i].aniversario.mes, 
                   agenda[i].aniversario.ano);
        }
    }
}

// (e) Insere em ordem alfabética
void insere_pessoa() {
    if (totalContatos >= MAX_CONTATOS) {
        printf("Agenda lotada!\n");
        return;
    }

    Pessoa novo;
    printf("\nNovo contato:\n");
    printf("Nome: ");
    fgets(novo.nome, TAM_STRING, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    // Encontra posição correta para inserção
    int pos = 0;
    while (pos < totalContatos && strcasecmp(novo.nome, agenda[pos].nome) > 0) {
        pos++;
    }

    // Desloca contatos para abrir espaço
    for (int i = totalContatos; i > pos; i--) {
        agenda[i] = agenda[i - 1];
    }

    // Preenche os demais dados
    printf("Email: ");
    fgets(novo.email, TAM_STRING, stdin);
    novo.email[strcspn(novo.email, "\n")] = '\0';

    printf("Endereço (Rua, Número, Complemento, Bairro, CEP, Cidade, Estado, País):\n");
    scanf("%s %d %s %s %s %s %s %s", 
          novo.endereco.rua, 
          &novo.endereco.numero, 
          novo.endereco.complemento, 
          novo.endereco.bairro, 
          novo.endereco.cep, 
          novo.endereco.cidade, 
          novo.endereco.estado, 
          novo.endereco.pais);
    getchar();

    printf("Telefone (DDD e número): ");
    scanf("%d %s", &novo.telefone.ddd, novo.telefone.numero);
    getchar();

    printf("Data de aniversário (dd mm aaaa): ");
    scanf("%d %d %d", &novo.aniversario.dia, &novo.aniversario.mes, &novo.aniversario.ano);
    getchar();

    agenda[pos] = novo;
    totalContatos++;
    printf("Contato adicionado!\n");
}

// (f) Remove pessoa e desloca elementos
void retira_pessoa() {
    char nome[TAM_STRING];
    printf("Nome completo para remover: ");
    fgets(nome, TAM_STRING, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int removidos = 0;
    for (int i = 0; i < totalContatos; i++) {
        if (strcasecmp(agenda[i].nome, nome) == 0) {
            // Desloca contatos posteriores
            for (int j = i; j < totalContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            totalContatos--;
            removidos++;
            i--; // Reavalia a posição atual após remoção
        }
    }

    printf("%d contatos removidos.\n", removidos);
}

// Menu principal
int main() {
    int opcao;
    do {
        printf("\nAGENDA TELEFÔNICA\n");
        printf("1. Buscar por primeiro nome\n");
        printf("2. Buscar por mês de aniversário\n");
        printf("3. Inserir contato\n");
        printf("4. Remover contato\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer

        switch (opcao) {
            case 1: busca_primeiro_nome(); break;
            case 2: busca_mes_aniversario(); break;
            case 3: insere_pessoa(); break;
            case 4: retira_pessoa(); break;
            case 5: break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}