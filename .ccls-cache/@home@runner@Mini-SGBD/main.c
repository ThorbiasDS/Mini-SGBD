#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int idCliente;
  char nome[30];
  char celular[10];
} Cliente;

typedef struct {
  int idProduto;
  char descricao[40];
  float preco;
} Produto;

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  int idPedido;
  Data data;
  int idCliente;
} Pedido;

typedef struct {
  int idPedido;
  int idProduto;
  float quantidade;
} PedidoItens;

void exibirMenu() {
  printf("\nEcclesia Reformata Store\n");
  printf("---------------------------------------------\n");
  printf("1. Cadastrar um novo cliente\n");
  printf("2. Listar, alterar ou remover um cliente\n");
  printf("3. Cadastrar um novo produto\n");
  printf("4. Listar, alterar ou remover um produto\n");
  printf("5. Fazer um novo pedido\n");
  printf("6. Listar os pedidos\n");
  printf("7. Exibir a nota fiscal de um pedido\n");
  printf("8. Encerrar o programa\n");
  printf("---------------------------------------------\n");
  printf("Escolha uma opção: ");
}

int inserirCliente(Cliente *clientes, int ncli) {

  Cliente client;

  printf("Informe: id[ENTER] nome[ENTER] celular[ENTER]\n");
  scanf(" %d ", &client.idCliente);

  fgets(client.nome, 30, stdin);
  if (client.nome[strlen(client.nome) - 1] == '\n')
    client.nome[strlen(client.nome) - 1] = '\0';

  fgets(client.celular, 10, stdin);
  if (client.celular[strlen(client.celular) - 1] == '\n')
    client.celular[strlen(client.celular) - 1] = '\0';

  setbuf(stdin, NULL);
  clientes[ncli] = client;
  ncli++;

  return ncli;
}

int inserirProduto(Produto *produtos, int nprod) {

  Produto product;

  printf("Informe: id[ENTER] descricao[ENTER] preco[ENTER]\n");
  scanf(" %d ", &product.idProduto);
  fgets(product.descricao, 40, stdin);
  scanf(" %f ", &product.preco);
  setbuf(stdin, NULL);

  if (product.descricao[strlen(product.descricao) - 1] == '\n')
    product.descricao[strlen(product.descricao) - 1] = '\0';

  produtos[nprod] = product;
  nprod++;

  return nprod;
}

int inserirPedidos(Pedido *pedidos, Cliente *cliente, int nped) {

  Data data;

  printf("Digite a data no formato dd mm aaaa: ");
  scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

  return nped;
}

void listarClientes(Cliente *clientes, int ncli) {

  printf("O cadastro tem %d cliente(s):\n", ncli);
  printf("--------------------------------------------------------\n");
  for (int i = 0; i < ncli; i++) {
    printf("| %6d ", clientes[i].idCliente);
    printf("| %-30s ", clientes[i].nome);
    printf("| %-10s |\n", clientes[i].celular);
  }
  printf("--------------------------------------------------------\n");
}

void listarProdutos(Produto *produtos, int nprod) {

  printf("Lista de produtos:\n");
  printf("----------------------------------------\n");
  printf("| Codigo | Produto          | Val Unit |\n");
  for (int i = 0; i < nprod; i++){
    printf("| %6d ", produtos[i].idProduto);
    printf("| %-40s ", produtos[i].descricao);
    printf("| %-6.2f |\n", produtos[i].preco);
  }
  printf("----------------------------------------\n");
  
  //printf("O cadastro tem %d produto(s):\n", nprod);
  //printf("--------------------------------------------------------\n");
  //for (int i = 0; i < nprod; i++) {
    //printf("| %6d ", produtos[i].idProduto);
    //printf("| %-30s ", produtos[i].descricao);
    //printf("| R$%8.2f |\n", produtos[i].preco);
  //}
  //printf("--------------------------------------------------------\n");
}

void atualizarClientes(Cliente *cliente) {

  printf("Digite um novo nome para o cliente: ");
  fgets(cliente->nome, 30, stdin);
  if (cliente->nome[strlen(cliente->nome) - 1] == '\n')
    cliente->nome[strlen(cliente->nome) - 1] = '\0';

  printf("Digite um novo número de telefone para o cliente: ");
  fgets(cliente->celular, 10, stdin);
  if (cliente->celular[strlen(cliente->celular) - 1] == '\n')
    cliente->celular[strlen(cliente->celular) - 1] = '\0';

  setbuf(stdin, NULL);

  printf("\nAlterando o cliente do id %d...\n", cliente->idCliente);
}

void atualizarProdutos(Produto *produto) {

  printf("Informe uma nova descrição para o produto: \n");
  fgets(produto->descricao, 40, stdin);
  if (produto->descricao[strlen(produto->descricao) - 1] == '\n')
    produto->descricao[strlen(produto->descricao) - 1] = '\0';

  printf("Informe um novo preço para o produto: \n");
  scanf(" %f ", &produto->preco);
  setbuf(stdin, NULL);

  printf("\nAlterando o produto do id %d...\n", produto->idProduto);
}

void removerClientes() {}

void removerProdutos() {}

int main(void) {

  char acao, lixo;
  int ncli = 0, nprod = 0, nped = 0, npedit = 0;
  int opcao = 0;

  Cliente c, *clientes = NULL;
  Produto p, *produtos = NULL;
  Pedido pe, *pedidos = NULL;
  PedidoItens pi, *peditens = NULL;

  while (opcao != 8) {

    exibirMenu();

    scanf("%d", &opcao);
    scanf("%c", &lixo);

    switch (opcao) {

    case 1:

      clientes = realloc(clientes, (ncli + 1) * sizeof(Cliente));
      ncli = inserirCliente(clientes, ncli);
      break;

    case 2:

      listarClientes(clientes, ncli);
      printf("Escolha a(alterar) ou r(remover) um cliente: \n");
      scanf("%c", &acao);
      scanf("%c", &lixo);

      if (acao == 'a') {
        printf("Informe id do cliente que deseja alterar: \n");
        scanf("%d", &c.idCliente);
        scanf("%c", &lixo);
        for (int i = 0; i < ncli; i++) {
          if (c.idCliente == clientes[i].idCliente)
            atualizarClientes(&clientes[i]);
        }
        listarClientes(clientes, ncli);
      } else if (acao == 'r') {
        removerClientes();
      }
      break;

    case 3:

      produtos = realloc(produtos, (nprod + 1) * sizeof(Produto));
      nprod = inserirProduto(produtos, nprod);
      break;

    case 4:

      listarProdutos(produtos, nprod);
      printf("Escolha a(alterar) ou r(remover) um produto: \n");
      scanf(" %c ", &acao);
      scanf(" %c ", &lixo);

      if (acao == 'a') {
        printf("Informe id do produto que deseja alterar: \n");
        scanf(" %d ", &p.idProduto);
        scanf(" %c ", &lixo);
        for (int i = 0; i < nprod; i++) {
          if (p.idProduto == produtos[i].idProduto)
            atualizarProdutos(&produtos[i]);
        }
        listarProdutos(produtos, nprod);
      } else if (acao == 'r') {
        removerProdutos();
      }
      break;

    case 5:

      pedidos = realloc(pedidos, (ncli + 1) * sizeof(Produto));
      printf("Informe o id do cliente para fazer um novo pedido: ");
      scanf(" %d \n", &pe.idCliente);
      for (int i = 0; i < ncli; i++) {
        if (pe.idCliente == clientes[i].idCliente)
          inserirPedidos(pedidos, &clientes[i], nped);
      }
    }
  }

  return 0;
}