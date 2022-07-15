#include <stdio.h>
#include <string.h>

typedef struct {
  int idCliente;
  char nome[30];
  char celular[10];
} Cliente;

Cliente lerCliente(){
  
  Cliente client;
  
  fgets(client.nome, 30, stdin);
  if(client.nome[strlen(client.nome) - 1] == '\n')
    client.nome[strlen(client.nome) - 1] = '\0';

  fgets(client.celular, 10, stdin);
  if(client.celular[strlen(client.celular) - 1] == '\n')
    client.celular[strlen(client.celular) - 1] = '\0';

  return client;
}

void inserirCliente(){
  
}

void mostrarCliente(){
  
}

void atualizarCliente(Cliente carinha){
  
}

void deletarCliente(Cliente carinha){
  
}