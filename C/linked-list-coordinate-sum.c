#include <stdio.h>
#include <stdlib.h>

struct pontos
{
    int coord_x;
    int coord_y;
    struct pontos *proximo;
};

struct pontos *lista = NULL;

void inserirPonto();
void somaPontos();

int main()
{
    int opcao;

    do
    {
        printf("1. Inserir Ponto\n");
        printf("2. Resultado Pontos\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirPonto();
            break;
        case 2:
            somaPontos();
            break;
        case 0:
            printf("Agradecemos por usar nosso programa !!!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void inserirPonto()
{
    struct pontos *novoPonto = malloc(sizeof(struct pontos));

    if (novoPonto == NULL)
    {
        printf("Lamentamos mas nao foi possivel alocar a memoria.\n");
        exit(0);
    }

    printf("Digite um ponto em X :\n");
    scanf("%d", &novoPonto->coord_x);

    printf("Digite um ponto em Y :\n");
    scanf("%d", &novoPonto->coord_y);

    if (lista != NULL)
    {
        novoPonto->proximo = lista;
    }

    lista = novoPonto;
}

void somaPontos()
{
    if (lista == NULL)
    {
        printf("A lista de pontos está vazia.\n");
        return;
    }

    int soma_x = 0, soma_y = 0;
    struct pontos *atual = lista;

    while (atual != NULL)
    {
        soma_x += atual->coord_x;
        soma_y += atual->coord_y;
        atual = atual->proximo;
    }

    printf("Soma das coordenadas X: %d\n", soma_x);
    printf("Soma das coordenadas Y: %d\n", soma_y);
}
