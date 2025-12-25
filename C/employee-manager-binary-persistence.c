#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario
{
    char nome[64];
    char dataNascimento[12];
    char cidade[64];
    float salario;
    struct funcionario *prox;
};
struct funcionario *lista = NULL;
void carregar_dados();
void salvar_dados();
void liberar_memoria();
void inserir_funcionario();
void atualizar_funcionario();
void deletar_funcionario();
void relatorio_funcionario(char *nome_arquivo);
int calcular_idade(int dia_atual, int mes_atual, int ano_atual, int dia, int mes, int ano);
void consultar_funcionario();
void relatorio_salario_digitado();
void relatorio_salario_minimo();
void relatorio_cidades();
void remove_enter(char *str);

int main()
{
    carregar_dados();

    int opcao;
    while (1)
    {
        printf("1. Inserir funcionario\n");
        printf("2. Atualizar dados de um funcionario\n");
        printf("3. Deletar registro de um funcionario\n");
        printf("4. Relatorio de funcionarios\n");
        printf("5. Consulta por nome do funcionario\n");
        printf("6. Relatorio de funcionarios com salario maior ou igual ao salario digitado\n");
        printf("7. Relatorio do numero de funcionarios por salario minimo\n");
        printf("8. Relatorio do numero de funcionarios por cidade\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            inserir_funcionario();
            break;
        case 2:
            atualizar_funcionario();
            break;
        case 3:
            deletar_funcionario();
            break;
        case 4:
        {
            int escolha;
            printf("Escolha o formato de saida:\n");
            printf("1. Tela\n");
            printf("2. Arquivo CSV\n");
            scanf("%d", &escolha);
            getchar();

            if (escolha == 1)
            {
                relatorio_funcionario(NULL);
            }
            else if (escolha == 2)
            {
                char nome_arquivo[64];
                printf("Digite o nome do arquivo: ");
                scanf("%s", nome_arquivo);
                getchar();
                relatorio_funcionario(nome_arquivo);
            }
            else
            {
                printf("Opcao invalida.\n");
            }

            break;
        }
        case 5:
            consultar_funcionario();
            break;
        case 6:
        {
            relatorio_salario_digitado();
        }
        break;

        case 7:
        {
            relatorio_salario_minimo();
        }
        break;

        case 8:
        {
            relatorio_cidades();
        }
        break;
        case 0:
            salvar_dados();
            liberar_memoria();
            return 0;
        default:
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}

void salvar_dados()
{
    FILE *arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo != NULL)
    {
        struct funcionario *atual = lista;
        while (atual != NULL)
        {
            fwrite(atual, sizeof(struct funcionario), 1, arquivo);
            atual = atual->prox;
        }

        fclose(arquivo);
    }
}

void carregar_dados()
{
    FILE *arquivo = fopen("funcionarios.bin", "rb");
    if (arquivo != NULL)
    {
        struct funcionario *atual = lista;
        struct funcionario *proximo;

        while (atual != NULL)
        {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }

        lista = NULL;

        while (1)
        {
            struct funcionario *novoFuncionario = malloc(sizeof(struct funcionario));
            if (fread(novoFuncionario, sizeof(struct funcionario), 1, arquivo) != 1)
            {
                free(novoFuncionario);
                break;
            }

            novoFuncionario->prox = lista;
            lista = novoFuncionario;
        }

        fclose(arquivo);
    }
}

void liberar_memoria()
{
    struct funcionario *atual = lista;
    while (atual != NULL)
    {
        struct funcionario *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

void inserir_funcionario()
{
    struct funcionario *novoFuncionario = malloc(sizeof(struct funcionario));
    if (novoFuncionario == NULL)
    {
        printf("Nao foi possivel alocar a memoria.\n");
        exit(0);
        return;
    }

    printf("Nome: ");
    fgets(novoFuncionario->nome, 64, stdin);
    remove_enter(novoFuncionario->nome);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    fgets(novoFuncionario->dataNascimento, 12, stdin);
    remove_enter(novoFuncionario->dataNascimento);

    printf("Cidade: ");
    fgets(novoFuncionario->cidade, 64, stdin);
    remove_enter(novoFuncionario->cidade);

    printf("Salario: ");
    scanf("%f", &novoFuncionario->salario);
    getchar();

    novoFuncionario->prox = lista;
    lista = novoFuncionario;
}

void atualizar_funcionario()
{
    char nomeBusca[64];
    printf("Nome do funcionario a ser atualizado: ");
    fgets(nomeBusca, 64, stdin);
    remove_enter(nomeBusca);

    struct funcionario *atual = lista;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (strcasecmp(atual->nome, nomeBusca) == 0)
        {
            printf("Novo nome: ");
            fgets(atual->nome, 64, stdin);
            remove_enter(atual->nome);

            printf("Nova data de Nascimento (dd/mm/aaaa): ");
            fgets(atual->dataNascimento, 12, stdin);
            remove_enter(atual->dataNascimento);

            printf("Nova cidade: ");
            fgets(atual->cidade, 64, stdin);
            remove_enter(atual->cidade);

            printf("Novo salario: ");
            scanf("%f", &atual->salario);
            getchar();

            encontrado = 1;
            break;
        }

        atual = atual->prox;
    }

    if (!encontrado)
    {
        printf("Funcionario nao encontrado.\n");
    }
}

void deletar_funcionario()
{
    char nomeBusca[64];
    printf("Nome do funcionario a ser excluido: ");
    fgets(nomeBusca, 64, stdin);
    remove_enter(nomeBusca);

    struct funcionario *anterior = NULL;
    struct funcionario *atual = lista;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (strcasecmp(atual->nome, nomeBusca) == 0)
        {
            if (anterior == NULL)
            {
                lista = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);
            encontrado = 1;
            printf("Funcionario excluido\n");
            break;
        }

        anterior = atual;
        atual = atual->prox;
    }

    if (!encontrado)
    {
        printf("Funcionario nao encontrado.\n");
    }
}

void relatorio_funcionario(char *nome_arquivo)
{
    int dia_atual, mes_atual, ano_atual, dia, mes, ano;

    printf("Data do relatorio (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia_atual, &mes_atual, &ano_atual);

    FILE *arquivo = NULL;
    if (nome_arquivo != NULL)
    {
        arquivo = fopen(strcat(nome_arquivo, ".csv"), "w");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo para relatorio.\n");
            return;
        }
        fprintf(arquivo, "Nome,Idade,Cidade,Salario\n");
    }

    struct funcionario *atual = lista;

    while (atual != NULL)
    {
        sscanf(atual->dataNascimento, "%d/%d/%d", &dia, &mes, &ano);

        int idade = calcular_idade(dia_atual, mes_atual, ano_atual, dia, mes, ano);

        if (nome_arquivo == NULL)
        {
            printf("\n%s,%d,%s,%.2f\n", atual->nome, idade, atual->cidade, atual->salario);
        }
        else
        {
            fprintf(arquivo, "%s,%d,%s,%.2f\n", atual->nome, idade, atual->cidade, atual->salario);
        }

        atual = atual->prox;
    }

    if (nome_arquivo != NULL)
    {
        fclose(arquivo);
    }
}

int calcular_idade(int dia_atual, int mes_atual, int ano_atual, int dia, int mes, int ano)
{
    int idade = ano_atual - ano;

    if (mes_atual < mes || (mes_atual == mes && dia_atual < dia))
    {
        idade--;
    }

    return idade;
}

void consultar_funcionario()
{
    char nomeBusca[64];
    printf("Nome do funcionario a ser consultado: ");
    fgets(nomeBusca, 64, stdin);
    remove_enter(nomeBusca);

    struct funcionario *atual = lista;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (strcasecmp(atual->nome, nomeBusca) == 0)
        {
            printf("Nome: %sData de Nascimento: %sCidade: %sSalario: %.2f\n",
                   atual->nome, atual->dataNascimento, atual->cidade, atual->salario);
            encontrado = 1;
            break;
        }

        atual = atual->prox;
    }

    if (!encontrado)
    {
        printf("Funcionario nao encontrado\n");
    }
}

void relatorio_salario_digitado()
{
    float salarioLimite;
    printf("Informe o valor do salario minimo atual: ");
    scanf("%f", &salarioLimite);

    struct funcionario *atual = lista;

    while (atual != NULL)
    {
        if (atual->salario >= salarioLimite)
        {
            printf("Nome: %s\nSalario: %.2f\n", atual->nome, atual->salario);
        }

        atual = atual->prox;
    }
}

void relatorio_salario_minimo()
{
    int salariop1 = 0, salariop2 = 0, salariop3 = 0;
    float salarioMinimo;

    printf("Digite o salario minimo atual: ");
    scanf("%f", &salarioMinimo);
    getchar();

    struct funcionario *atual = lista;

    while (atual != NULL)
    {
        if (atual->salario <= salarioMinimo)
        {
            salariop1++;
        }
        else if (atual->salario <= (salarioMinimo * 3))
        {
            salariop2++;
        }
        else
        {
            salariop3++;
        }

        atual = atual->prox;
    }

    printf("1. Ganham 1 salario minimo ou menos: %d funcionarios\n", salariop1);
    printf("2. Mais de 1 salario minimo a 3 salarios minimos: %d funcionarios\n", salariop2);
    printf("3. Mais que 3 salarios minimos: %d funcionarios\n", salariop3);
}

void relatorio_cidades()
{
    struct CidadeFuncionarios
    {
        char cidade[64];
        int numFuncionarios;
    };

    struct CidadeFuncionarios cidades[64];
    int numCidades = 0;
    int i, j;

    struct funcionario *atual = lista;

    while (atual != NULL)
    {
        int cidadeEncontrada = 0;

        for (j = 0; j < numCidades; j++)
        {
            if (strcasecmp(atual->cidade, cidades[j].cidade) == 0)
            {
                cidades[j].numFuncionarios++;
                cidadeEncontrada = 1;
                break;
            }
        }

        if (!cidadeEncontrada)
        {
            strcpy(cidades[numCidades].cidade, atual->cidade);
            cidades[numCidades].numFuncionarios = 1;
            numCidades++;
        }

        atual = atual->prox;
    }

    for (i = 0; i < numCidades; i++)
    {
        printf("%s %d funcionarios\n", cidades[i].cidade, cidades[i].numFuncionarios);
    }
}

void remove_enter(char *str)
{
    size_t size = strlen(str);
    if (size > 0 && str[size - 1] == '\n')
    {
        str[size - 1] = '\0';
    }
}
