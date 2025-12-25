#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 10

int qtd_produtos = 0;
char codigo[TAMANHO_VETOR]; // Alterado para vetor de caracteres simples
int estoque[TAMANHO_VETOR];
float valor[TAMANHO_VETOR];
int opcao;

int main() {
    do {
        printf("\n=== GESTAO DE ESTOQUE ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos em Estoque\n");
        printf("3. Buscar Produto por Codigo\n");
        printf("4. Produto mais Caro\n");
        printf("5. Produto mais Barato\n");
        printf("6. Produto com Menos Estoque\n");
        printf("7. Produto com Mais Estoque\n");
        printf("8. Valor Total do Estoque da Empresa\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (qtd_produtos < TAMANHO_VETOR) {
                    printf("\n--- Cadastro ---\n");
                    printf("Digite uma letra para o codigo: ");
                    scanf(" %c", &codigo[qtd_produtos]); // Espaço antes do %c limpa buffer
                    
                    printf("Digite o valor unitario: ");
                    scanf("%f", &valor[qtd_produtos]);
                    
                    printf("Digite a quantidade: ");
                    scanf("%d", &estoque[qtd_produtos]);
                    
                    qtd_produtos++;
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("Erro: Limite Maximo de Produtos (%d) atingido.\n", TAMANHO_VETOR);
                }
                break;
            }
            case 2: {
                if (qtd_produtos > 0) {
                    printf("\n--- Lista de Produtos ---\n");
                    for (int i = 0; i < qtd_produtos; i++) {
                        printf("Codigo: %c | Valor: R$ %.2f | Qtd: %d\n", codigo[i], valor[i], estoque[i]);
                    }
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 3: {
                char busca;
                int encontrado = 0;
                printf("Digite o codigo a buscar: ");
                scanf(" %c", &busca);
                
                for (int i = 0; i < qtd_produtos; i++) {
                    if (codigo[i] == busca) {
                        printf("\nProduto encontrado:\n");
                        printf("Codigo: %c\n", codigo[i]);
                        printf("Valor: R$ %.2f\n", valor[i]);
                        printf("Estoque: %d\n", estoque[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Produto nao encontrado.\n");
                }
                break;
            }
            case 4: { // Mais caro
                if (qtd_produtos > 0) {
                    int mc = 0; // Começa assumindo que o primeiro é o maior
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (valor[i] > valor[mc]) {
                            mc = i;
                        }
                    }
                    printf("\nProduto mais caro:\n");
                    printf("Codigo: %c (R$ %.2f)\n", codigo[mc], valor[mc]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 5: { // Mais barato
                if (qtd_produtos > 0) {
                    int mb = 0;
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (valor[i] < valor[mb]) {
                            mb = i;
                        }
                    }
                    printf("\nProduto mais barato:\n");
                    printf("Codigo: %c (R$ %.2f)\n", codigo[mb], valor[mb]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 6: { // Menos estoque
                if (qtd_produtos > 0) {
                    int mees = 0;
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (estoque[i] < estoque[mees]) {
                            mees = i;
                        }
                    }
                    printf("\nProduto com menos estoque:\n");
                    printf("Codigo: %c (Qtd: %d)\n", codigo[mees], estoque[mees]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 7: { // Mais estoque
                if (qtd_produtos > 0) {
                    int maes = 0;
                    for (int i = 1; i < qtd_produtos; i++) {
                        if (estoque[i] > estoque[maes]) {
                            maes = i;
                        }
                    }
                    printf("\nProduto com mais estoque:\n");
                    printf("Codigo: %c (Qtd: %d)\n", codigo[maes], estoque[maes]);
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;
            }
            case 8: {
                if (qtd_produtos > 0) {
                    float total = 0; // Reinicia o total
                    for (int i = 0; i < qtd_produtos; i++) {
                        total += valor[i] * estoque[i];
                    }
                    printf("\nValor total do estoque da empresa: R$ %.2f\n", total);
                } else {
                    printf("Nenhum produto cadastrado para calcular.\n");
                }
                break;
            }
            case 9: {
                printf("Encerrando o sistema...\n");
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 9);

    return 0;
}