#include <stdio.h>

#include "pedido.h"
#include "menus.h"

int main(void) {

  int op = 0;
  
  op = imprimirMenu();

  switch(op){
    
    case 1:
    inserirProduto();
    break;

    case 2:
    subdois();
    break;

    case 3:
    inserirCliente();
    break;

    case 4:
    subquatro();
    break;

    case 5:
    inserirPedido(NULL, NULL);
    break;

    case 6:
    mostrarPedido();
    break;

    case 7:
    mostrarNotaFiscal();
    break;

    case 8:
    finalizacao();
    break;
    
  }

  return 0;
}