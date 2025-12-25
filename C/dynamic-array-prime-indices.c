#include <stdio.h>
#include <stdlib.h>

int primo(int x);

int main()
{
    int n;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    int *vetor = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("Digite um numero para inserir no vetor: \n");
        scanf("%d", &vetor[i]);
    }

    printf("Posicao Primo: ");
    for (int i = 0; i < n; i++)
    {
        if (primo(vetor[i]))
        {
            printf("%d ", i);
        }
    }
    return 0;
}

int primo(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}