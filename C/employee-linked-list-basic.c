#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 64

typedef char string[T];

typedef struct funcionario
{
    string nome[T];
    string cargo[T];
    float salario;
    struct funcionario *proximo;
} funcionario;

int menu();
int submenu();
funcionario *dados_novos();
void ler_funcionarios(funcionario *dados_funcionario);
void incluir_inicio(funcionario **lista, funcionario *novo);
void incluir_fim(funcionario **lista, funcionario *novo);
void listar_funcionarios(funcionario *lista);
funcionario *buscar_funcionario(funcionario *lista, const char *nome);
float calcular_media_salarial(funcionario *lista);

int main()
{
    funcionario *lista = NULL, *aux;
    int opcao, opcao2;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            opcao2 = submenu();
            aux = dados_novos();
            ler_funcionarios(aux);
            switch (opcao2)
            {
            case 1:
                incluir_inicio(&lista, aux);
                break;
            case 2:
                incluir_fim(&lista, aux);
                break;
            }
            break;
        case 2:
            printf("----------------------------------------------------------\n");
            listar_funcionarios(lista);
            break;
        case 3:
            printf("Digite o nome do funcionario para buscar: ");
            string nome_busca;
            fgets(nome_busca, T, stdin);
            nome_busca[strcspn(nome_busca, "\n")] = '\0';
            funcionario *encontrado = buscar_funcionario(lista, nome_busca);
            if (encontrado != NULL)
            {
                mostrar_dados_registro(encontrado);
            }
            else
            {
                printf("Funcionario nao encontrado.\n");
            }
            break;
        case 4:
            printf("A media salarial e: R$%.2f\n", calcular_media_salarial(lista));
            break;
        case 0:
            return 0;
        }

    } while (opcao != 0);

    return 0;
}

int menu()
{
    int opcao;

    printf("1.Inserir Funcionario\n");
    printf("2.Listar Funcionarios\n");
    printf("3.Buscar Funcionario\n");
    printf("4.Media Salarial\n");
    printf("0.Sair\n");
    scanf("%d", &opcao);
    getchar();

    return opcao;
}

int submenu()
{
    int opcao2;
    printf("1.Inserir no Inicio\n");
    printf("2.Inserir no Fim\n");
    scanf("%d", &opcao2);
    getchar();

    return opcao2;
}

funcionario *dados_novos()
{
    funcionario *novo = (funcionario *)malloc(sizeof(funcionario));
    novo->proximo = NULL;
    return novo;
}

void ler_funcionarios(funcionario *dados_funcionario)
{
    int size;

    printf("Nome do Funcionario:\n");
    fgets(dados_funcionario->nome, T, stdin);
    size = strlen(dados_funcionario->nome);
    dados_funcionario->nome[size - 1] = '\0';
    printf("Cargo do Funcionario:\n");
    fgets(dados_funcionario->cargo, T, stdin);
    size = strlen(dados_funcionario->cargo);
    dados_funcionario->cargo[size - 1] = '\0';
    printf("Salario do Funcionario:\n");
    scanf("%f", &dados_funcionario->salario);
    getchar();
}

void incluir_inicio(funcionario **lista, funcionario *novo)
{
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        novo->proximo = *lista;
        *lista = novo;
    }
}

void incluir_fim(funcionario **lista, funcionario *novo)
{
    if (*lista == NULL)
    {
        *lista = novo;
        novo->proximo = NULL;
    }
    else
    {
        funcionario *aux = *lista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->proximo = NULL;
    }
}

void mostrar_dados_registro(funcionario *mostrar)
{
    printf("Nome: %s\n", mostrar->nome);
    printf("Cargo: %s\n", mostrar->cargo);
    printf("R$ %.2f\n", mostrar->salario);
    printf("----------------------------------------------------------\n");
}

void listar_funcionarios(funcionario *lista)
{
    funcionario *aux = lista;

    while (aux != NULL)
    {
        mostrar_dados_registro(aux);
        aux = aux->proximo;
    }
}

funcionario *buscar_funcionario(funcionario *lista, const char *nome)
{
    funcionario *aux = lista;

    while (aux != NULL)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}

float calcular_media_salarial(funcionario *lista)
{
    if (lista == NULL)
    {
        return 0.0;
    }

    float soma = 0.0;
    int i = 0;

    funcionario *aux = lista;

    while (aux != NULL)
    {
        soma += aux->salario;
        i++;
        aux = aux->proximo;
    }

    return soma / i;
}