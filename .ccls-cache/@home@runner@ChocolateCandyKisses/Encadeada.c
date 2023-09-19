#include "Encadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct elemento {
  int dado;
  struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criar_lista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

Elemento *criar_elemento() {
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));
  return no;
}

int liberar_lista(Lista *li) {
  if (li == NULL) {
    return 0;
  }

  Elemento *no;         // libera todos os nós da lista
  while (*li != NULL) { // enqunto não chegar ao fim da lista
    no = *li; // o ponteiro no aponta para o ponteiro do inicio da lista
    *li = (*li)->prox; // o ponteiro do inicio da lista a percorre passando para
                       // o proximo elemento da lista
    free(no);
  }
  free(li); // libera o ponteiro que aponta para o início da lista
  return 1;
}

int tamanho_lista(Lista *li) {
  if (li == NULL) {
    return 0;
  }
  Elemento *no = *li; // o ponteiro no aponta para o inicio da lista
  int cont = 0;
  while (no != NULL) { // enquanto o ponteiro nao encontrar NULL, ele vai
                       // contando os elementos da lista
    cont++;
    no = no->prox; // e o ponteiro aponta para o próximo elemento da lista
  }
  return cont;
}

int lista_vazia(Lista *li) {
  if (li == NULL) { // lista nao foi alocada corretamente
    return -1;
  }
  if (*li == NULL) { // se o ponteiro que aponta para a primeira posição da
                     // lista apontar para NULL significa que a lista está vazia
    return 1;
  }
  return 0; // se houver elementos, retorna 0
}

int inserir_lista_inicio(Lista *li, int dado) {
  if (li == NULL) {
    return 0;
  }
  Elemento *no;
  no = criar_elemento();
  if (no == NULL) {
    return 0;
  }
  no->dado = dado;  //
  no->prox = (*li); // aponta para a primeira casa da lista
  *li = no;         // li aponta para o ponteiro do novo elemento criado

  return 1;
}

int inserir_lista_ordenada(Lista *li, int dado) {
  if (li == NULL) {
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  if (no == NULL) {
    return 0;
  }

  no->dado = dado;

  if ((*li) == NULL) { // se a lista estiver vazia
    no->prox = NULL;   // o ponteiro apontara para null
    *li = no;          // o primeiro ponteiro apontara para o ponteiro no
  } else {
    Elemento *anterior, *atual; // criacao de dois ponteiros
    atual = *li;                // atual aponta para o inicio da lista

    while (atual != NULL &&
           atual->dado <
               dado) { // enquanto o atual nao chegar ao fim da lista e o dado
                       // da lista for menor do que o dado desejado
      anterior = atual;    // ponteiro anterior apónta para o atual
      atual = atual->prox; // atual apontara para a proxima posicao da lista
    }

    if (atual == (*li)) { // se o atual for igual a li
      no->prox = *li;     // aponta para li
      *li = no;           // li aponta para o no
    } else {
      no->prox = atual;    // no aponta para o atual
      anterior->prox = no; // anterior aponta para o no
    }
  }
  return 1;
}

int inserir_lista_fim(Lista *li, int dado) {
  if (li == NULL) {
    return 0;
  }

  Elemento *no;
  no = criar_elemento();

  if (no == NULL) {
    return 0;
  }

  no->dado = dado; // adiciona o dado
  no->prox = NULL; // no aponta para NULL

  if ((*li) == NULL) { // se a lista for vazia
    *li = no;          // li aponta para no
  } 
  else {
    Elemento *aux;
    aux = *li;

    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = no;
  }
  return 1;
}

int remover_lista_inicio(Lista *li){
  if(li == NULL){
    return 0;
  }

  if((*li)==NULL){
    return 0;
  }

  Elemento *atual;
  atual = *li;
  *li = atual->prox;

  free(atual);
  return 1;
}
