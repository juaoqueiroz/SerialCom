#include "serialcom.h"
#include <iostream>

int main()
{
    Conta MinhaConta;
    

    //MinhaConta.saldo = 10;  ERRO!!!

    MinhaConta.inicializa("Fulano", 10.25);


    MinhaConta.deposita(12.75);
    MinhaConta.consulta();
    MinhaConta.saque(15.00);
    MinhaConta.consulta();
  
}