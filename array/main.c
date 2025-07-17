#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(char matriz[3][3])
{
  printf("     0  1  2\n");
  printf("  *-----------*\n");
  printf("0 |  %c  %c  %c  |\n", matriz[0][0], matriz[0][1], matriz[0][2]);
  printf("1 |  %c  %c  %c  |\n", matriz[1][0], matriz[1][1], matriz[1][2]);
  printf("2 |  %c  %c  %c  |\n", matriz[2][0], matriz[2][1], matriz[2][2]);
  printf("  *-----------*\n");
  printf("     0  1  2\n");
}

int lerLinhaJogada(char jogador, int *linha)
{
  printf("Informe a linha: ");
  scanf("%d", linha);

  if (*linha < 0 || *linha > 2)
    return 0;

  return 1;
}

int lerColunaJogada(char jogador, int *coluna)
{
  printf("Informe a coluna: ");
  scanf("%d", coluna);
  printf("\n\n");

  if (*coluna < 0 || *coluna > 2)
    return 0;

  return 1;
}

int jogadaValida(char matriz[3][3], int linha, int coluna)
{
  if (matriz[linha][coluna] == 'x' || matriz[linha][coluna] == 'o')
    return 0;

  return 1;
}

int jogada(char matriz[3][3], int *linha, int *coluna, char jogador)
{
  int linhaValida = 0;
  int colunaValida = 0;
  int validado = 0;

  do
  {
    do
    {
      linhaValida = lerLinhaJogada(jogador, linha);

      if (!linhaValida)
        printf("Linha inválida! Tente novamente.\n");
    } while (!linhaValida);

    do
    {
      colunaValida = lerColunaJogada(jogador, coluna);

      if (!colunaValida)
        printf("Coluna inválida! Tente novamente.\n");
    } while (!colunaValida);

    validado = jogadaValida(matriz, *linha, *coluna);

    if (!validado)
    {
      imprimirMatriz(matriz);
      printf("\n");
      printf("Jogada inválida! Tente novamente.\n");
    }

  } while (!validado);

  printf("Jogada válida!\n\n");

  matriz[*linha][*coluna] = jogador;

  return 1;
}

int fimJogo(char matriz[3][3])
{
  for (int i = 0; i <= 2; i++)
  {
    for (int j = 0; j <= 2; j++)
    {
      if (matriz[i][j] == '-')
        return 0;
    }
  }
  return 1;
}

int vencedor(char matriz[3][3], int linha, int coluna, char jogador)
{
  int contador = 0;

  // verifica linha jogada
  for (int i = 0; i <= 2; i++)
  {
    if (matriz[linha][i] != jogador)
      break;
    contador++;
  }

  if (contador == 3)
    return 1;

  contador = 0;

  // verifica coluna jogada
  for (int i = 0; i < 3; i++)
  {
    if (matriz[i][coluna] != jogador)
      break;
    contador++;
  }

  if (contador == 3)
    return 1;

  contador = 0;

  // verifica diagonal primária//
  if (linha == coluna)
  {
    for (int i = 0; i <= 2; i++)
    {
      if (matriz[i][i] != jogador)
        break;
      contador++;
    }
    if (contador == 3)
      return 1;
    contador = 0;
  }

  // verifica diagonal secundária
  if (linha - coluna == 2 || linha - coluna == -2 || linha == coluna)
  {
    for (int i = 0; i <= 2; i++)
    {
      if (matriz[2 - i][i] != jogador)
        break;
      contador++;
    }
    if (contador == 3)
      return 1;
  }

  return 0;
}

int main()
{
  char matriz[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

  int turno = 0;

  int *linha = malloc(sizeof(int));
  int *coluna = malloc(sizeof(int));

  printf("\n");
  imprimirMatriz(matriz);
  printf("\n");

  // inicializador de jogador aleatório
  srand(time(NULL));
  int random = rand() % 100;

  int boolJogador = random % 2;
  char jogador = boolJogador ? 'x' : 'o';

  while (turno <= 8)
  {
    printf("Jogador (%c) nesta jogada;\n", jogador);

    if (jogada(matriz, linha, coluna, jogador))
      imprimirMatriz(matriz);

    if (vencedor(matriz, *linha, *coluna, jogador))
    {
      printf("\nJOGADOR (%c) VENCEU!!!", jogador);
      break;
    }

    if (fimJogo(matriz) || turno > 8)
    {
      printf("\nDEU VELHA!!!");
      break;
    }

    boolJogador = !boolJogador;
    jogador = boolJogador ? 'x' : 'o';
    turno++;
    printf("\n");
  }
}