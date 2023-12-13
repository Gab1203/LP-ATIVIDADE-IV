#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*Exerc�cio 1:
Crie uma struct Contato para representar informa��es de contatos, incluindo nome, n�mero de telefone e email.
Solicite que o usu�rio cadastre 3 contatos.
 Escreva uma fun��o que recebe um nome como par�metro,
 e retorna o n�mero de telefone correspondente a esse nome. Em seguida,
  implemente um programa que utiliza essa fun��o para buscar e imprimir
  o n�mero de telefone de um contato espec�fico.
*/

#define quantidade 3

struct Contato
{

    char nome[101];
    char telefone[101];
    char email[101];
};
void limpaTela()
{

    fflush(stdin);
    system("cls || clear");
}

char *buscaContato(struct Contato dadosContato[])
{

    char nomeRecebido[101];
    static char telefoneRespectivo[101];
    int i;

    fflush(stdin);
    printf("Agora, digite nome que deseja para obter seu respectivo telefone:\n");
    gets(nomeRecebido);
    fflush(stdin);

    for (i = 0; i < quantidade; i++)
    {
        if (strcmp(dadosContato[i].nome, nomeRecebido) == 0)
        {

            strcpy(telefoneRespectivo, dadosContato[i].telefone);
        }
        else
        {

            strcpy(telefoneRespectivo, "Contato n�o encontrado!");
        }
    }

    return telefoneRespectivo;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Contato contact[quantidade];
    int i;

    for (i = 0; i < quantidade; i++)
    {

        fflush(stdin);
        printf("Digite o nome do %d� contato:\n", i + 1);
        gets(contact[i].nome);
        fflush(stdin);

        fflush(stdin);
        printf("Digite o telefone do %d� contato:\n", i + 1);
        gets(contact[i].telefone);
        fflush(stdin);

        fflush(stdin);
        printf("Digite o email do %d� contato:\n", i + 1);
        gets(contact[i].email);
        fflush(stdin);

        printf("\n");
    }

    limpaTela();

    for (i = 0; i < quantidade; i++)
    {
        printf("Nome do %d� contato: %s\n", i + 1, contact[i].nome);
        printf("Telefone do %d� contato: %s\n", i + 1, contact[i].telefone);
        printf("Email do %d� contato: %s\n", i + 1, contact[i].email);
        printf("\n");
    }

    printf("\nTelefone respectivo do contato: %s\n", buscaContato(contact));

    return 0;
}
