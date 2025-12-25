// Arquivos Binários
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STR 580

struct dados_filme
{
    char nome[SIZE_STR];
    char genero[SIZE_STR];
    int ano_lancamento;
};

struct dados_filme novo_filme();
int menu();
void listar_filmes(struct dados_filme *filme, int qtd);
void salvar_dados_arquivo_binario(char *nome_arq, struct dados_filme *filmes, int qtd);
void importar_dados_arquivo_binario(char *nome_arq, struct dados_filme *filmes, int *qtd);
void salvar_dados_arquivo_binario_v2(char *nome_arq, struct dados_filme *filmes, int qtd);
void importar_dados_arquivo_binario_v2(char *nome_arq, struct dados_filme *filmes, int *qtd);

int main()
{
    struct dados_filme filmes[10];
    int qtd_filmes = 0, opcao;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            filmes[qtd_filmes++] = novo_filme();
            break;
        case 2:
            listar_filmes(filmes, qtd_filmes);
            break;
        case 3:
            salvar_dados_arquivo_binario_v2("dados.bin", filmes, qtd_filmes);
            break;
        case 4:
            importar_dados_arquivo_binario_v2("dados.bin", filmes, &qtd_filmes);
            break;
        case 5:
            break;
        }
    } while (opcao != 0);

    return 0;
}

struct dados_filme novo_filme()
{
    struct dados_filme novo;
    int size;

    printf("\nQual o Nome do Filme?\n");
    getchar();
    fgets(novo.nome, SIZE_STR, stdin);
    size = strlen(novo.nome);
    novo.nome[size - 1] = '\0';
    printf("\nQual o Genero do Filme?\n");
    fgets(novo.genero, SIZE_STR, stdin);
    size = strlen(novo.genero);
    novo.genero[size - 1] = '\0';
    printf("Qual o Ano de Lancamento do Filme?\n");
    scanf("%d", &novo.ano_lancamento);
    return novo;
}

int menu()
{
    int opcao;
    printf("1. Incluir Novo Filme\n");
    printf("2. Listar Filmes Cadastrados\n");
    printf("3. Salvar Filmes em Arquivo Binário\n");
    printf("4. Importar Dados em Arquivo Binário\n");
    printf("0. Sair\n");
    printf(":? ");
    scanf("%d", &opcao);

    return opcao;
}
void listar_filmes(struct dados_filme *filmes, int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("O Nome do Filme eh.....: %s\n", filmes[i].nome);
        printf("O Genero do Filme eh...: %s\n", filmes[i].genero);
        printf("O Ano de Lancamento eh.: %d\n", filmes[i].ano_lancamento);
        printf("\n");
    }
}

void salvar_dados_arquivo_binario(char *nome_arq, struct dados_filme *filmes, int qtd)
{
    FILE *fp = fopen(nome_arq, "w+b");
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir arquivo%s\n", nome_arq);
        exit(0);
    }

    fwrite(filmes, sizeof(struct dados_filme), qtd, fp);

    fclose(fp);
}

void importar_dados_arquivo_binario(char *nome_arq, struct dados_filme *filmes, int *qtd)
{
    FILE *fp = fopen(nome_arq, "rb");
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir arquivo%s\n", nome_arq);
        exit(0);
    }
    fread(filmes, sizeof(struct dados_filme), 1, fp);
    *qtd = 1;

    fclose(fp);
}

void salvar_dados_arquivo_binario_v2(char *nome_arq, struct dados_filme *filmes, int qtd)
{
    FILE *fp = fopen(nome_arq, "w+b");
    int i;
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir arquivo%s\n", nome_arq);
        exit(0);
    }

    for (i = 0; i < qtd; i++)
    {
        fwrite(&filmes[i], sizeof(struct dados_filme), 1, fp);
    }

    fclose(fp);
}

void importar_dados_arquivo_binario_v2(char *nome_arq, struct dados_filme *filmes, int *qtd)
{
    FILE *fp = fopen(nome_arq, "rb");
    struct dados_filme filme;
    int i = 0;
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir arquivo%s\n", nome_arq);
        exit(0);
    }

    while (!feof(fp))
    {
        fread(&filme, sizeof(struct dados_filme), 1, fp);
        if (!feof(fp))
        {
            filmes[i] = filme;
            i++;
        }
    }
    *qtd = i;

    fclose(fp);
}