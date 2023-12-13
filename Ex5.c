#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
Exerc�cio 5:

Crie uma struct "Funcionario" com membros para nome, cargo e sal�rio. Escreva uma fun��o que recebe um array de
funcion�rios e um cargo como par�metro, e retorna a m�dia salarial dos funcion�rios com esse cargo.
Em seguida, implemente um programa que utiliza essa fun��o para calcular e imprimir a
m�dia salarial dos programadores em uma empresa.*/

struct Funcionario
{
    char nome[101];
    char cargo[101];
    float salario;
};

void limpaTela()
{

    fflush(stdin);
    system("cls || clear");
}

float calculoMediaDesenvolvedores(struct Funcionario cargosColetados[], int contadorTotal)
{
    int i, contadorCargo = 0;
    float somaNotas = 0, mediaDesenvolvedores;

    for (i = 0; i < contadorTotal; i++)
    {

        if (strcmp(cargosColetados[i].cargo, "Programador") == 0)
        {

            somaNotas += cargosColetados[i].salario;
            contadorCargo++;
        }
    }
    mediaDesenvolvedores = somaNotas / contadorCargo;

    return mediaDesenvolvedores;
}

void calculoMedia(struct Funcionario *funcionariosColetados, int counter)
{
    int i;
    float somaSalarios = 0;
    float mediaTotal;

    for (i = 0; i < counter; i++)
    {

        somaSalarios += funcionariosColetados[i].salario;
    }
    mediaTotal = somaSalarios / counter;

    printf("M�dia salarial total dos funcion�rios: R$ %.2f\n", mediaTotal);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Funcionario dadosFuncionarios[999];
    int contadorFuncionarios, i;

    printf("Digite o n�mero de funcion�rios da empresa:\n");
    scanf("%d", &contadorFuncionarios);

    printf("\n");

    for (i = 0; i < contadorFuncionarios; i++)
    {
        fflush(stdin);
        printf("Insira o nome do %d� funcion�rio:\n", i + 1);
        gets(dadosFuncionarios[i].nome);
        fflush(stdin);

        fflush(stdin);
        printf("Insira o cargo do %d� funcion�rio:\n", i + 1);
        gets(dadosFuncionarios[i].cargo);
        fflush(stdin);

        printf("Insira o sal�rio do %d� funcion�rio:\n", i + 1);
        scanf("%f", &dadosFuncionarios[i].salario);
        printf("\n");
    }

    limpaTela();

    for (i = 0; i < contadorFuncionarios; i++)
    {
        printf("Nome do %d� funcion�rio: %s\n", i + 1, dadosFuncionarios[i].nome);
        printf("Cargo do %d� funcion�rio: %s\n", i + 1, dadosFuncionarios[i].cargo);
        printf("Sal�rio do %d� funcion�rio: R$ %.2f\n", i + 1, dadosFuncionarios[i].salario);
        printf("\n");
    }

    printf("M�dia salarial dos programadores: %.2f\n", calculoMediaDesenvolvedores(dadosFuncionarios, contadorFuncionarios));
    printf("Quantidade de funcion�rios na empresa: %d\n", contadorFuncionarios);
    calculoMedia(dadosFuncionarios, contadorFuncionarios);

    return 0;
}