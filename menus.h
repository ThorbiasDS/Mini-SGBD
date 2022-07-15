#include <stdio.h>

void imprimirNotaFiscal() {

  printf("===========================================================\n");
  printf("| Pedido: 124556          Data: 12/06/2022                |\n");
  printf("| Cliente: Fulano Beltrano Silva                          |\n");
  printf("-----------------------------------------------------------\n");
  printf("| Codigo | Produto          | Qtd. | Val Unit | Val Total |\n");
  printf("|    123 | Camisa Polo      |    1 |    89.90 |     89.90 |\n");
  printf("|    214 | Camiseta Basica  |    2 |    23.90 |     47.80 |\n");
  printf("-----------------------------------------------------------\n");
  printf("|                                          Total:  137.70 |\n");
  printf("===========================================================\n");
}

int imprimirMenu() {

  int op = 0;
  scanf("%d", &op);
  
  printf("---------------------------------------------\n");
  printf("Seja bem-vindo(a) à Ecclesia Reformata Store!\n");
  printf("---------------------------------------------\n");
  printf("\n");
  printf("Escolha uma das seguintes opções:\n");
  printf("1. Inserir um produto\n");
  printf("2. Listar, alterar ou remover um ou mais produtos\n");
  printf("3. Inserir um cliente no cadastro\n");
  printf("4. Listar, alterar ou remover um ou mais clientes\n");
  printf("5. Inserir um novo pedido\n");
  printf("6. Listar os pedidos que já foram realizados\n");
  printf("7. Exibir a nota fiscal de um pedido\n");
  printf("8. Encerrar o programa\n");
  printf("\n");
  printf("---------------------------------------------\n");
  printf("Ecclesia Reformata\n");
  printf("A sua loja online favorita de produtos teológicos!\n");
  printf("---------------------------------------------\n");

  return op;
}

int subdois(){
  return 0;
}

int subquatro(){
  return 0;
}

void finalizacao(){
  
}