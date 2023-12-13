#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*Exercício 2:
Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno",
esta struct terá informações como: nome, data de nascimento, duas notas e média e retorna a média das notas.
Em seguida, crie um programa que declare um array de
5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno.
Também crie uma função para verificar se um aluno está aprovado ou
reprovado sendo necessário média maior ou igual a 7,0 para aprovação.
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
        decentes[i].media >= 7 ? printf("Situação do %d° aluno: Aprovado!\n", i + 1) : printf("Situação do %d° aluno: Reprovado!\n", i + 1);
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
        printf("Digite o nome do %d° aluno:\n", i + 1);
        gets(alunosDados[i].nome);
        fflush(stdin);

        fflush(stdin);
        printf("Digite a data de nascimento do %d° aluno:\n", i + 1);
        gets(alunosDados[i].dataNascimento);
        fflush(stdin);

        for (j = 0; j < quantidadeNotas; j++)
        {

            printf("Insira a %d° nota do %d° aluno:\n", j + 1, i + 1);
            scanf("%f", &alunosDados[i].notas[j]);
        }

        printf("\n");
    }

    limpaTela();

    for (i = 0; i < quantidadeAlunos; i++)
    {

        printf("Nome do %d° aluno: %s\n", i + 1, alunosDados[i].nome);
        printf("Data de nascimento do %d° aluno: %s\n", i + 1, alunosDados[i].dataNascimento);

        for (j = 0; j < quantidadeNotas; j++)
        {
            printf("%d° nota do %d° aluno: %.2f\n", j + 1, i + 1, alunosDados[i].notas[j]);
        }

        calcularMedia(alunosDados);

        printf("Média do %d° aluno: %.2f\n", i + 1, alunosDados[i].media);
        printf("\n");
    }

    aprovacao(alunosDados);

    return 0;
}