#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Considere a estrutura abaixo e escreva uma funcao para inserir dados na lista encadeada pelo inicio e outra funcao para excluir dados da lista. Para operar a exclusao as coordenadas x e y devem ser iguais a referencia do usuario.
*/
struct pontos
{
    int coord_x;
    int coord_y;
    struct pontos *proximo;
};

struct ponteirosAA
{
    struct pontos *atual;
    struct pontos *anterior;
};

struct pontos novoPonto();
int get_aleatorio(int referencia);
void inserirPonto(struct pontos **lista_pontos, struct pontos *novo);
void excluirPonto();
struct ponteirosAA localizaRegistro(int x, int y, struct pontos *lista);

int main()
{
    struct pontos *lista_pontos = NULL;
    srand(time(NULL) % 10);

    return 0;
}

struct pontos *novoPonto()
{
    struct pontos *novo;
    novo = (struct pontos *)malloc(sizeof(struct pontos));

    novo->coord_x = get_aleatorio(10);
    novo->coord_y = get_aleatorio(10);
    novo->proximo = NULL;
}

int get_aleatorio(int referencia)
{
    return rand() % referencia;
}

void inserirPonto(struct pontos **lista_pontos, struct pontos *novo)
{
    if (*lista_pontos != NULL)
    {
        novo->proximo = *lista_pontos;
    }
    *lista_pontos = novo;
}
struct ponteirosAA localizaRegistro(int x, int y, struct pontos *lista)
{
    struct ponteirosAA aux;
    struct pontosAA lista;
    aux.atual = NULL;
    aux.anterior = NULL;
    aux.atual = lista;
    while (lista)
    {
        if (lista->coord_x == x && lista->coord_y == y)
        {
            aux.anterior->aux.atual = proximo;
        }
    }
    return aux;
}

struct pontos excluirPontos()
{
    int x, y;
    printf("Digite a coordanada x: \n");
    scanf("%d", x);

    printf("Digite a coordanada y: \n");
    scanf("%d", y);

    struct pontos *aux = *lista_pontos->proximo;
    if (aux->coord_x == x || aux->coord_y == y)
    {
    }
}