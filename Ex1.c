#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*Exercício 1:
Crie uma struct Contato para representar informações de contatos, incluindo nome, número de telefone e email.
Solicite que o usuário cadastre 3 contatos.
 Escreva uma função que recebe um nome como parâmetro,
 e retorna o número de telefone correspondente a esse nome. Em seguida,
  implemente um programa que utiliza essa função para buscar e imprimir
  o número de telefone de um contato específico.
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

            strcpy(telefoneRespectivo, "Contato não encontrado!");
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
        printf("Digite o nome do %d° contato:\n", i + 1);
        gets(contact[i].nome);
        fflush(stdin);

        fflush(stdin);
        printf("Digite o telefone do %d° contato:\n", i + 1);
        gets(contact[i].telefone);
        fflush(stdin);

        fflush(stdin);
        printf("Digite o email do %d° contato:\n", i + 1);
        gets(contact[i].email);
        fflush(stdin);

        printf("\n");
    }

    limpaTela();

    for (i = 0; i < quantidade; i++)
    {
        printf("Nome do %d° contato: %s\n", i + 1, contact[i].nome);
        printf("Telefone do %d° contato: %s\n", i + 1, contact[i].telefone);
        printf("Email do %d° contato: %s\n", i + 1, contact[i].email);
        printf("\n");
    }

    printf("\nTelefone respectivo do contato: %s\n", buscaContato(contact));

    return 0;
}
