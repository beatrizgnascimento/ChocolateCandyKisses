#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

typedef struct elemento *Lista;

Lista *criar_lista();
int liberar_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int inserir_lista_inicio(Lista *li, int dado);
int inserir_lista_ordenada(Lista *li, int dado);
int inserir_lista_fim(Lista *li, int dado);
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li);
int remover_ultimos_n(Lista *li, int dado);
int buscar_lista_posicao(Lista *li, int pos, int *dado);
int buscar_lista_dado(Lista *li, int *pos, int dado);
int imprimir_lista(Lista *li);

#endif