#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
Exercício 4:

Modele uma struct "ContaBancaria" que represente uma conta bancária com número da conta,
 nome do titular, saldo e tipo de conta (poupança ou corrente).
 Implemente funções para depositar e sacar dinheiro da conta, bem como para imprimir o saldo atual.
  Crie um programa que utilize essas funções para simular operações bancárias. Crie um menu para as operações disponíveis.*/

struct ContaBancaria
{

  char numeroConta[101];
  char nomeTitular[101];
  float saldo;
  char tipoConta[101];
  
};

void limpaTela()
{

  fflush(stdin);
  system("cls || clear");
}

struct ContaBancaria deposito(struct ContaBancaria depositoBanco)
{

  float valorDepositado;

  printf("Digite o valor em R$ que queira depositar em sua conta:\n");
  scanf("%f", &valorDepositado);

  depositoBanco.saldo = depositoBanco.saldo + valorDepositado;

  return depositoBanco;
}

struct ContaBancaria saque(struct ContaBancaria saqueBanco)
{

  float valorSaque;

  printf("Digite o valor em R$ que queira sacar em sua conta:\n");
  scanf("%f", &valorSaque);

  saqueBanco.saldo = saqueBanco.saldo - valorSaque;

  return saqueBanco;
}

void dadosFinais(struct ContaBancaria contaFinal)
{

  printf("Número da conta: %s\n", contaFinal.numeroConta);
  printf("Nome do titular: %s\n", contaFinal.nomeTitular);
  printf("Tipo da conta: %s\n", contaFinal.tipoConta);
  printf("Saldo: %.2f\n", contaFinal.saldo);
}

int main()
{

  setlocale(LC_ALL, "portuguese");

  struct ContaBancaria conta;
  int codigo;


  printf("CADASTRE SUA CONTA BANCÁRIA!!!!\n\n");

  fflush(stdin);
  printf("Insira o número da sua conta bancária:\n");
  gets(conta.numeroConta);
  fflush(stdin);

  fflush(stdin);
  printf("Insira o nome do titular da sua conta bancária:\n");
  gets(conta.nomeTitular);
  fflush(stdin);

  do
  {
    fflush(stdin);
    printf("Insira o tipo de conta (Poupança ou Corrente):\n");
    gets(conta.tipoConta);
    fflush(stdin);

    if (strcmp("Poupanca", conta.tipoConta) != 0 && strcmp("Corrente", conta.tipoConta) != 0)
    {
      printf("Tipo de conta inválido, digite novamente!\n");
      Sleep(3000);
      limpaTela();
    }

  } while (strcmp("Poupanca", conta.tipoConta) != 0 && strcmp("Corrente", conta.tipoConta) != 0);

  limpaTela();

  printf("Conta CADASTRADA!\n\n");

  do
  {

    printf("Agora, selecione dentre as opções a seguir para continuar:\n");
    printf("\n1 - Depositar dinheiro\n2 - Sacar dinheiro\n3 - Vizualizar o saldo atual da conta bancária\n4 - Sair e exibir os resultados finais\n\n");
    printf("Insira o número desejado:\n");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:
      
      conta = deposito(conta);
      printf("\n");
      break;

    case 2:

      conta = saque(conta);
      printf("\n");
      break;

    case 3:

      printf("Saldo atual: %.2f\n", conta.saldo);
      printf("\n");
      break;

    case 4:

      dadosFinais(conta);
      printf("\n");
      break;

    default:
      printf("Código INVÁLIDO, digite novamente!!\n");
      Sleep(3000);
      limpaTela();

      break;
    }

  } while (codigo != 4);

  return 0;
}