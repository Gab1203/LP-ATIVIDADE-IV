#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*Exerc�cio 2:
Crie uma fun��o chamada "calcularMedia" que recebe como par�metro uma struct "Aluno",
esta struct ter� informa��es como: nome, data de nascimento, duas notas e m�dia e retorna a m�dia das notas.
Em seguida, crie um programa que declare um array de
5 alunos e utilize a fun��o "calcularMedia" para imprimir a m�dia de cada aluno.
Tamb�m crie uma fun��o para verificar se um aluno est� aprovado ou
reprovado sendo necess�rio m�dia maior ou igual a 7,0 para aprova��o.
*/

#define quantidadeNotas 2
#define quantidadeAlunos 5

struct Aluno
{

    char nome[101];
    char dataNascimento[101];
    float notas[quantidadeNotas];
    float media;
};

float calcularMedia(struct Aluno dadosAlunos[])
{
    float somaNotas;
    int i, j;

    for (i = 0; i < quantidadeAlunos; i++)
    {
        for (j = 0; j < quantidadeNotas; j++)
        {
            somaNotas += dadosAlunos[i].notas[j];
        }

        dadosAlunos[i].media = somaNotas / quantidadeNotas;
        somaNotas = 0;
    }
    return dadosAlunos->media;
}

void aprovacao(struct Aluno decentes[])
{
    int i;

    for (i = 0; i < quantidadeAlunos; i++)
    {
        decentes[i].media >= 7 ? printf("Situa��o do %d� aluno: Aprovado!\n", i + 1) : printf("Situa��o do %d� aluno: Reprovado!\n", i + 1);
        }
}

void limpaTela()
{
    fflush(stdin);
    system("cls || clear");
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Aluno alunosDados[quantidadeAlunos];
    int i, j;

    for (i = 0; i < quantidadeAlunos; i++)
    {
        fflush(stdin);
        printf("Digite o nome do %d� aluno:\n", i + 1);
        gets(alunosDados[i].nome);
        fflush(stdin);

        fflush(stdin);
        printf("Digite a data de nascimento do %d� aluno:\n", i + 1);
        gets(alunosDados[i].dataNascimento);
        fflush(stdin);

        for (j = 0; j < quantidadeNotas; j++)
        {

            printf("Insira a %d� nota do %d� aluno:\n", j + 1, i + 1);
            scanf("%f", &alunosDados[i].notas[j]);
        }

        printf("\n");
    }

    limpaTela();

    for (i = 0; i < quantidadeAlunos; i++)
    {

        printf("Nome do %d� aluno: %s\n", i + 1, alunosDados[i].nome);
        printf("Data de nascimento do %d� aluno: %s\n", i + 1, alunosDados[i].dataNascimento);

        for (j = 0; j < quantidadeNotas; j++)
        {
            printf("%d� nota do %d� aluno: %.2f\n", j + 1, i + 1, alunosDados[i].notas[j]);
        }

        calcularMedia(alunosDados);

        printf("M�dia do %d� aluno: %.2f\n", i + 1, alunosDados[i].media);
        printf("\n");
    }

    aprovacao(alunosDados);

    return 0;
}