#include <stdio.h>
#include <stdlib.h>

#define STR 100

typedef char string[STR];

typedef struct dados_pessoa
{
    int identificacao;
    string nome;
    int idade;
    struct dados_pessoa *proximo;
} dados_pessoa;

// Prot�tipo das fun��es auxiliares
int menu();
dados_pessoa *cria_novo_registro();
void ler_dados_pessoa(dados_pessoa *pessoa);
void listar_registros(dados_pessoa *lista);
void mostrar_dados_registro(dados_pessoa *pessoa);
void incluir_registro_lista(dados_pessoa **lista, dados_pessoa *novo);
void incluir_registro_lista_v2(dados_pessoa **lista, dados_pessoa *novo);
dados_pessoa *procura_ultimo_registro_da_lista(dados_pessoa *lista);
dados_pessoa *localiza_pessoa(dados_pessoa *lista);
void excluir_pessoa(dados_pessoa **lista);
void escrever_dados_arquivo(string nome_arquivo, dados_pessoa *pessoa);
void salvar_dados_em_aquivo(string nome_arq, dados_pessoa *lista);
void importar_dados_arquivo(string nome_arq, dados_pessoa **lista);

int main()
{
    string nome_arq;
    dados_pessoa *lista = NULL, *aux;
    int opcao;
    int size;
    char resposta;

    printf("Deseja importar dados de arquivo texto?(s/n)");
    scanf("%c", &resposta);

    if (toupper(resposta) == 'S')
    {
        printf("Qual o nome do arquivo de entrada de dados?");
        getchar();
        fgets(nome_arq, STR, stdin);
        size = strlen(nome_arq);
        nome_arq[size - 1] = '\0';
        void importar_dados_arquivo(nome_arq, &lista);
    }

    do
    {
        int size;
        opcao = menu();

        switch (opcao)
        {
        case 1:
            aux = cria_novo_registro();
            ler_dados_pessoa(aux);
            // incluir_registro_lista(&lista, aux);
            incluir_registro_lista_v2(&lista, aux);
            break;

        case 2:
            listar_registros(lista);
            break;

        case 3:
            aux = localiza_pessoa(lista);
            if (aux)
            {
                mostrar_dados_registro(aux);
            }
            else
            {
                printf("Registro nao cadastrado!\n");
            }
            break;
        case 4:
            excluir_pessoa(&lista);
            break;
        case 0:
            printf("Qual o nome do arquivo onde os dados serao armazenados? ");
            getchar();
            fgets(nome_arq, STR, stdin);
            size = strlen(nome_arq);
            nome_arq[size - 1] = '\0';
            salvar_dados_em_arquivo(nome_arq, lista);
        }
    } while (opcao != 0);

    return 0;
}

// Implementa��o das fun��es auxiliares
int menu()
{
    int opcao;

    printf("1.Incluir novo registro\n");
    printf("2.Listar registros cadastrados\n");
    printf("3.Localizar registro\n");
    printf("4.Excluir registro\n");
    printf("0.Sair do programa (tchau!!!)\n");
    printf(":? ");
    scanf("%d", &opcao);

    return opcao;
}

dados_pessoa *cria_novo_registro()
{
    dados_pessoa *novo = (dados_pessoa *)malloc(sizeof(dados_pessoa));
    novo->proximo = NULL;

    return novo;
}

void ler_dados_pessoa(dados_pessoa *pessoa)
{
    int size;

    printf("Identificacao.........: ");
    scanf("%d", &pessoa->identificacao);
    getchar();
    printf("Nome..................: ");
    fgets(pessoa->nome, STR, stdin);
    size = strlen(pessoa->nome);
    pessoa->nome[size - 1] = '\0';
    printf("Idade.................: ");
    scanf("%d", &pessoa->idade);
}

void listar_registros(dados_pessoa *lista)
{
    dados_pessoa *aux = lista;

    while (aux != NULL)
    {
        mostrar_dados_registro(aux);
        aux = aux->proximo;
    }
}

void mostrar_dados_registro(dados_pessoa *pessoa)
{
    printf("Identificacao.........: %d\n", pessoa->identificacao);
    printf("Nome..................: %s\n", pessoa->nome);
    printf("Idade.................: %d\n", pessoa->idade);
    printf("Meu endereco..........: %p\n", pessoa);
    printf("Endereco do proximo...: %p\n", pessoa->proximo);
    printf("\n");
}

void incluir_registro_lista(dados_pessoa **lista, dados_pessoa *novo)
{
    dados_pessoa *aux = NULL;

    // Lista vazia
    // O registro sera o primeiro
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        // Alocar o registro no fim da fila
        // Procura o fim da fila
        aux = procura_ultimo_registro_da_lista(*lista);
        aux->proximo = novo;
    }
}
void incluir_registro_lista_v2(dados_pessoa **lista, dados_pessoa *novo)
{
    dados_pessoa *aux = NULL;
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

dados_pessoa *procura_ultimo_registro_da_lista(dados_pessoa *lista)
{
    dados_pessoa *aux = lista;

    // Procura o ultimo registro da fila
    while (aux)
    {
        if (aux->proximo == NULL)
        {
            return aux;
        }
        aux = aux->proximo;
    }

    return aux;
}

dados_pessoa *localiza_pessoa(dados_pessoa *lista)
{

    int size;
    dados_pessoa *aux = lista;
    string nome_comp;

    printf("Digite o nome a ser procurado: ");
    getchar();
    fgets(nome_comp, STR, stdin);
    size = strlen(nome_comp);
    nome_comp[size - 1] = '\0';

    while (aux)
    {
        if (!strcmp(aux->nome, nome_comp))
        {
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}

void excluir_pessoa(dados_pessoa **lista)
{
    dados_pessoa *anterior = NULL, *atual = NULL;
    int size;
    string nome_comp;

    printf("Digite o nome a ser procurado: ");
    getchar();
    fgets(nome_comp, STR, stdin);
    size = strlen(nome_comp);
    nome_comp[size - 1] = '\0';

    anterior = *lista;
    atual = *lista;

    while (atual)
    {
        if (!strcmp(atual->nome, nome_comp))
        {
            mostrar_dados_registro(atual);
            if (*lista != atual)
            {
                anterior->proximo = atual->proximo;
            }
            else
            {
                *lista = atual->proximo;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void salvar_dados_em_arquivo(string nome_arq, dados_pessoa *lista)
{
    FILE *fp;

    fp = fopen(nome_arq, "w+");

    if (fp == NULL)
    {

        printf("Nao foi possivel abrir/criar o arquivo %s\n", nome_arq);
        exit(0);
    }

    while (lista)
    {
        fprintf(fp, "%d\n", lista->identificacao);
        fprintf(fp, "%s\n", lista->nome);
        fprintf(fp, "%d\n", lista->idade);
        lista = lista->proximo;
    }
    fclose(fp);
}
void importar_dados_arquivo(string nome_arq, **lista)
{
    FILE *fp;
    string nome;
    int id;
    int idade;
    dados_pessoa *aux;

    fp = fopen(nome_arq, "r");

    if (fp == NULL)
    {
        printf("Nao foi possivel abrir/criar o arquivo %s\n", nome_arq);
        exit(0);
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d\n", &id);
        fgets(nome, STR, fp);
        fscanf(fp, "%d\n", &idade);

        // aloca registro dinamicamente
        aux = cria_novo_registro();
        aux->identificacao = id;
        strcpy(aux->nome, nome);
        aux->idade = idade;

        incluir_registro_lista(lista, aux);
    }
}