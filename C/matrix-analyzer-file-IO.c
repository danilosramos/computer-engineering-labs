#include <stdio.h>
#include <stdlib.h>
#define LINHA 5
#define COLUNA 5

void ler(float matriz[LINHA][COLUNA]);
float calcularSomaDiagonal(float matriz[LINHA][COLUNA]);
float encontrarMaiorValor(float matriz[LINHA][COLUNA], int *linha, int *coluna);
void salvarArquivo(float matriz[LINHA][COLUNA], float somaDiagonal, float maiorValor, int iMaior, int jMaior);

int main()
{
    float matriz[LINHA][COLUNA];
    float somaDiagonal;
    float maiorValor;
    int iMaior, jMaior;

    ler(matriz);
    somaDiagonal = calcularSomaDiagonal(matriz);
    printf("Soma da Diagonal: %.2f\n", somaDiagonal);
    maiorValor = encontrarMaiorValor(matriz, &iMaior, &jMaior);
    printf("%.2f e o maior valor e esta na posicao [%d][%d]\n", maiorValor, iMaior, jMaior);
    salvarArquivo(matriz, somaDiagonal, maiorValor, iMaior, jMaior);

    return 0;
}

void ler(float matriz[LINHA][COLUNA])
{
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("Numero posicao [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

float calcularSomaDiagonal(float matriz[LINHA][COLUNA])
{
    float soma = 0.0;
    for (int i = 0; i < LINHA; i++)
    {
        soma += matriz[i][i];
    }
    return soma;
}

float encontrarMaiorValor(float matriz[LINHA][COLUNA], int *linha, int *coluna)
{
    float maior = matriz[0][0];
    *linha = 0;
    *coluna = 0;

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                *linha = i;
                *coluna = j;
            }
        }
    }

    return maior;
}

void salvarArquivo(float matriz[LINHA][COLUNA], float soma, float maiorValor, int iMaior, int jMaior)
{
    FILE *arquivo;
    arquivo = fopen("matriz.txt", "w+");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.txt\n");
        exit(0);
    }

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            fprintf(arquivo, "%.2f ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "\nSoma da Diagonal e %.2f\n", soma);
    fprintf(arquivo, "\n%.2f e o maior valor e esta na posicao [%d][%d]\n", maiorValor, iMaior, jMaior);
    fclose(arquivo);
}
