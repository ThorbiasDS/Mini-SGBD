#include <stdio.h>
#include <string.h>

typedef struct {
  int idProduto;
  char descricao[40];
  float preco;
} Produto;

Produto lerProduto(){
  
  Produto prod;
  
  fgets(prod.descricao, 40, stdin);
  if(prod.descricao[strlen(prod.descricao) - 1] == '\n')
    prod.descricao[strlen(prod.descricao) - 1] = '\0';

  scanf("%f", &prod.preco);

  return prod;
}

void inserirProduto() {
  
}

void mostrarProduto(){
  
}

void atualizarProduto(Produto comprinha){
  
}

void deletarProduto(Produto comprinha){
  
}