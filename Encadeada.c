#include <stdio.h>
#include <stdlib.h>
#include "Encadeada.h"

struct elemento{
int dado;
struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criar_lista(){
  Lista *li = (Lista*)malloc(sizeof(Lista));
  if(li != NULL)
  {
    *li = NULL;
  }
  return li;
}

Elemento *criar_elemento(){
  Elemento *no = (Elemento*)malloc(sizeof(Elemento));
  return no;
}

int liberar_lista(Lista *li){
  if(li == NULL){
    return 0;
  }

  Elemento *no; //libera todos os nós da lista
  while(*li != NULL){ //enqunto não chegar ao fim da lista
    no = *li; //o ponteiro no aponta para o ponteiro do inicio da lista
    *li = (*li)->prox; //o ponteiro do inicio da lista a percorre passando para o proximo elemento da lista
    free(no);
  }
  free(li); //libera o ponteiro que aponta para o início da lista
  return 1;
}

int tamanho_lista(Lista *li){
  if(li == NULL){
    return 0;
  }
  Elemento *no = *li; //o ponteiro no aponta para o inicio da lista
  int cont = 0;
  while(no != NULL){ //enquanto o ponteiro nao encontrar NULL, ele vai contando os elementos da lista
    cont++;
    no = no->prox; //e o ponteiro aponta para o próximo elemento da lista
  }
  return cont;
}

int lista_vazia(Lista *li){
  if(li == NULL){ //lista nao foi alocada corretamente
    return -1;
  }
  if(*li == NULL){ //se o ponteiro que aponta para a primeira posição da lista apontar para NULL significa que a lista está vazia
    return 1;
  }
  return 0; //se houver elementos, retorna 0
}

int inserir_lista_inicio(Lista *li, int dado){
  if(li == NULL){
    return 0;
  }
  Elemento *no;
  no = criar_elemento();
  if(no == NULL){
    return 0;
  }
  no->dado = dado; //
  no->prox = (*li); //aponta para a primeira casa da lista
  *li = no; //li aponta para o ponteiro do novo elemento criado

  return 1;
}


