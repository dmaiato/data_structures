// Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrı́cula do
// aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
// (a) Permita ao usuário entrar com os dados de 5 alunos.
// (b) Encontre o aluno com maior nota da primeira prova.
// (c) Encontre o aluno com maior média geral.
// (d) Encontre o aluno com menor média geral
// (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação


#include <stdio.h>
#include <string.h>

#define NUM_ALUNOS 5
#define NOTA_MINIMA 6.0

typedef struct {
    int matricula;
    char nome[50];
    float nota1, nota2, nota3;
    float media;
} Aluno;

int main() {
    Aluno alunos[NUM_ALUNOS];
    
    // (a) Entrada de dados
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        getchar(); // Limpa o buffer do teclado
        
        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // Remove a quebra de linha
        
        printf("Notas (Prova 1, 2 e 3): ");
        scanf("%f %f %f", &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);
        
        // Calcula a média imediatamente
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
    }

    // (b) Aluno com maior nota da primeira prova
    int indiceMaiorNota1 = 0;
    for (int i = 1; i < NUM_ALUNOS; i++) {
        if (alunos[i].nota1 > alunos[indiceMaiorNota1].nota1) {
            indiceMaiorNota1 = i;
        }
    }

    // (c) e (d) Alunos com maior e menor média geral
    int indiceMaiorMedia = 0, indiceMenorMedia = 0;
    for (int i = 1; i < NUM_ALUNOS; i++) {
        if (alunos[i].media > alunos[indiceMaiorMedia].media) {
            indiceMaiorMedia = i;
        }
        if (alunos[i].media < alunos[indiceMenorMedia].media) {
            indiceMenorMedia = i;
        }
    }

    // Exibindo resultados
    printf("\n(b) Maior nota na Prova 1: %s (Matricula: %d, Nota: %.1f)\n",
           alunos[indiceMaiorNota1].nome, alunos[indiceMaiorNota1].matricula, alunos[indiceMaiorNota1].nota1);
    
    printf("(c) Maior media geral: %s (Matricula: %d, Media: %.1f)\n",
           alunos[indiceMaiorMedia].nome, alunos[indiceMaiorMedia].matricula, alunos[indiceMaiorMedia].media);
    
    printf("(d) Menor media geral: %s (Matricula: %d, Media: %.1f)\n\n",
           alunos[indiceMenorMedia].nome, alunos[indiceMenorMedia].matricula, alunos[indiceMenorMedia].media);

    // (e) Verificação de aprovação
    printf("(e) Situacao dos alunos:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("%s: %s (Media: %.1f)\n", alunos[i].nome,
               alunos[i].media >= NOTA_MINIMA ? "Aprovado" : "Reprovado", alunos[i].media);
    }

    return 0;
}