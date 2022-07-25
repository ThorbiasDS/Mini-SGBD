#include <stdio.h>

#include "pedido.h"

#ifndef DEF
#define DEF

typedef struct {
  int idPedido;
  int idProduto;
  float quantidade;
} PedidoItens;

#endif