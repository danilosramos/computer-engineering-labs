#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados_letra
{
    char letra;
    int codigo_tabela_ASCII;
    struct dados_letra *proximo;
};

struct dados_letra *lista = NULL;

void inserirLetra();
void mostrarLetras();

int main()
{
    int opcao;

    do
    {
        printf("1. Inserir Letra com Codigo ASCII\n");
        printf("2. Mostrar Letras e Codigo ASCII\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirLetra();
            break;
        case 2:
            mostrarLetras();
            break;
        case 0:
            printf("Agradecemos por usar nosso programa!!!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void inserirLetra()
{
    struct dados_letra *novaLetra = (struct dados_letra *)malloc(sizeof(struct dados_letra));
    if (novaLetra == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    printf("Digite a Letra: ");
    scanf(" %c", &novaLetra->letra);
    printf("Digite o Codigo ASCII: ");
    scanf("%d", &novaLetra->codigo_tabela_ASCII);

    novaLetra->proximo = lista;
    lista = novaLetra;
}

void mostrarLetras()
{
    struct dados_letra *aux = lista;
    if (aux == NULL)
    {
        printf("Lista esta Vazia\n");
        return;
    }
    while (aux != NULL)
    {
        printf("Letra: %c\nASCII: %d\n", aux->letra, aux->codigo_tabela_ASCII);
        aux = aux->proximo;
    }
}
