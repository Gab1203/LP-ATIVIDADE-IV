#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
Exerc�cio 4:

Modele uma struct "ContaBancaria" que represente uma conta banc�ria com n�mero da conta,
 nome do titular, saldo e tipo de conta (poupan�a ou corrente).
 Implemente fun��es para depositar e sacar dinheiro da conta, bem como para imprimir o saldo atual.
  Crie um programa que utilize essas fun��es para simular opera��es banc�rias. Crie um menu para as opera��es dispon�veis.*/

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

  printf("N�mero da conta: %s\n", contaFinal.numeroConta);
  printf("Nome do titular: %s\n", contaFinal.nomeTitular);
  printf("Tipo da conta: %s\n", contaFinal.tipoConta);
  printf("Saldo: %.2f\n", contaFinal.saldo);
}

int main()
{

  setlocale(LC_ALL, "portuguese");

  struct ContaBancaria conta;
  int codigo;


  printf("CADASTRE SUA CONTA BANC�RIA!!!!\n\n");

  fflush(stdin);
  printf("Insira o n�mero da sua conta banc�ria:\n");
  gets(conta.numeroConta);
  fflush(stdin);

  fflush(stdin);
  printf("Insira o nome do titular da sua conta banc�ria:\n");
  gets(conta.nomeTitular);
  fflush(stdin);

  do
  {
    fflush(stdin);
    printf("Insira o tipo de conta (Poupan�a ou Corrente):\n");
    gets(conta.tipoConta);
    fflush(stdin);

    if (strcmp("Poupanca", conta.tipoConta) != 0 && strcmp("Corrente", conta.tipoConta) != 0)
    {
      printf("Tipo de conta inv�lido, digite novamente!\n");
      Sleep(3000);
      limpaTela();
    }

  } while (strcmp("Poupanca", conta.tipoConta) != 0 && strcmp("Corrente", conta.tipoConta) != 0);

  limpaTela();

  printf("Conta CADASTRADA!\n\n");

  do
  {

    printf("Agora, selecione dentre as op��es a seguir para continuar:\n");
    printf("\n1 - Depositar dinheiro\n2 - Sacar dinheiro\n3 - Vizualizar o saldo atual da conta banc�ria\n4 - Sair e exibir os resultados finais\n\n");
    printf("Insira o n�mero desejado:\n");
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
      printf("C�digo INV�LIDO, digite novamente!!\n");
      Sleep(3000);
      limpaTela();

      break;
    }

  } while (codigo != 4);

  return 0;
}