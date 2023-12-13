#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*Exercício 3:
Desenvolva uma struct "Produto" que contenha informações como nome, preço e quantidade em estoque. Em seguida,
desenvolva um menu para facilitar a escolha das opções:

1 - Realizar uma compra
2 - Consultar estoque
3 - Sair do programa.

Escreva funções necessárias para calcular o valor total em estoque do produto e para atualizar
a quantidade em estoque com base em uma compra. Crie um programa que utiliza essas funções para um produto.
*/

struct Produto
{

    char nome[101];
    float preco;
    float quantidade;
    float valorCompra;
};

void limpaTela()
{

    fflush(stdin);
    system("cls || clear");
}

struct Produto compras(struct Produto compraProduto)
{

    float quantidadeCompra, precoCompra;

    do
    {
        printf("Digite a quantidade de %s que queira adquirir:\n", compraProduto.nome);
        scanf("%f", &quantidadeCompra);

        if ((quantidadeCompra < 1) || (quantidadeCompra > compraProduto.quantidade))
        {
            printf("Quantidade inválida, digite novamente!");
            Sleep(3000);
            limpaTela();
        }

    } while ((quantidadeCompra < 1) || (quantidadeCompra > compraProduto.quantidade));

    precoCompra = compraProduto.preco * quantidadeCompra;
    compraProduto.quantidade -= quantidadeCompra;
    compraProduto.valorCompra += precoCompra;


    return compraProduto;
}

void consultaEstoque(struct Produto produtoEstoque)
{

    float precoTotal = produtoEstoque.preco * produtoEstoque.quantidade;

    printf("Nome do produto: %s\n", produtoEstoque.nome);
    printf("Preço individual do produto: R$ %.2f\n", produtoEstoque.preco);
    printf("Quantidade em estoque do produto: %.0f\n", produtoEstoque.quantidade);
    printf("Valor total atual do produto em estoque: R$ %.2f\n", precoTotal);
    printf("Valor parcial da compra: R$ %.2f\n", produtoEstoque.valorCompra);
}

void dadosFinais(struct Produto dadosFinais)
{

    float precoTotal = dadosFinais.preco * dadosFinais.quantidade;

    printf("Nome do produto: %s\n", dadosFinais.nome);
    printf("Preço individual do produto: R$ %.2f\n", dadosFinais.preco);
    printf("Quantidade em estoque do produto: %.0f\n", dadosFinais.quantidade);
    printf("Valor final do produto em estoque: R$ %.2f\n", precoTotal);
    printf("Valor total da compra: R$ %.2f\n", dadosFinais.valorCompra);
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    struct Produto dadosProduto;
    int codigo;

    strcpy(dadosProduto.nome, "Lápis");
    dadosProduto.preco = 2;
    dadosProduto.quantidade = 20;

    do
    {
        printf("1 - Realizar uma compra\n2 - Consultar estoque\n3 - Sair do programa\n\n");

        printf("Insira o código desejado:\n");
        scanf("%d", &codigo);
        printf("\n\n");

        switch (codigo)
        {
        case 1:

            limpaTela();
            printf("1 - Realizar uma compra\n\n");
            dadosProduto = compras(dadosProduto);
            printf("\n");
            break;

        case 2:
            limpaTela();
            printf("2 - Consultar estoque\n\n");
            consultaEstoque(dadosProduto);
            printf("\n");
            break;

        case 3:
            limpaTela();
            printf("3 - Sair do programa\n\n");
            dadosFinais(dadosProduto);
            break;

        default:

            printf("O código é inválido, reescreva!\n");
            Sleep(3000);
            limpaTela();

            break;
        }

    } while (codigo != 3);

    return 0;
}