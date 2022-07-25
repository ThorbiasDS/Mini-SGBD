#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int idProduto;
  char descricao[40];
  float preco;
} Produto;

Produto lerProduto() {

  Produto compra;
  char lixo;

  compra.descricao[0] = '\0';
  printf("Digite aqui a descriação do produto: \n");
  fgets(compra.descricao, 40, stdin);

  if (compra.descricao[strlen(compra.descricao) - 1] == '\n')
    compra.descricao[strlen(compra.descricao) - 1] = '\0';

  scanf("%f", &compra.preco);
  scanf("%c", &lixo);

  return compra;
}

void inserirProduto(Produto *compras, int *t, Produto prod) {

  compras[*t] = prod;
  (*t)++;
}

void mostrarProduto() {}

void atualizarProduto(Produto comprinha) {}

void deletarProduto(Produto comprinha) {}