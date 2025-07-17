// Faça um programa que leia os dados de 10 alunos (Nome, matricula, Média Final), armazenando em um
// vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores, o vetor dos aprovados e o vetor dos
// reprovados, considerando a média mı́nima para a aprovação como sendo 5.0. Exibir na tela os dados do
// vetor de aprovados, seguido dos dados do vetor de reprovados.

#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10
#define NOTA_MINIMA 5.0

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

int main() {
    Aluno alunos[MAX_ALUNOS];
    Aluno aprovados[MAX_ALUNOS], reprovados[MAX_ALUNOS];
    int numAprovados = 0, numReprovados = 0;

    // Leitura dos dados dos alunos
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        // Nome (permite espaços)
        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // Remove a quebra de linha

        // Matrícula e média
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media Final: ");
        scanf("%f", &alunos[i].media);

        // Limpa o buffer do teclado após scanf
        while (getchar() != '\n');
    }

    // Separa em aprovados e reprovados
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].media >= NOTA_MINIMA) {
            aprovados[numAprovados] = alunos[i];
            numAprovados++;
        } else {
            reprovados[numReprovados] = alunos[i];
            numReprovados++;
        }
    }

    // Exibe aprovados
    printf("\n===== APROVADOS =====\n");
    for (int i = 0; i < numAprovados; i++) {
        printf("Nome: %s\n", aprovados[i].nome);
        printf("Matricula: %d\n", aprovados[i].matricula);
        printf("Media: %.1f\n\n", aprovados[i].media);
    }

    // Exibe reprovados
    printf("\n===== REPROVADOS =====\n");
    for (int i = 0; i < numReprovados; i++) {
        printf("Nome: %s\n", reprovados[i].nome);
        printf("Matricula: %d\n", reprovados[i].matricula);
        printf("Media: %.1f\n\n", reprovados[i].media);
    }

    return 0;
}