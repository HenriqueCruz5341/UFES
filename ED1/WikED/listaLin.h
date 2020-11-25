#ifndef ListaLin_H
#define ListaLin_H

typedef struct listaLin ListaLin;

#include "link.h"

/* Inicializa uma nova lista de links
*outpus: ponteiro para uma nova lista de links inicializada
*pos-condicao: a lista de links retornada existirá
*/
ListaLin* inicializaListaLink();

/* Insere um novo link no final da lista de links
*inputs: o ponteiro para a lista de links onde deseja-se fazer a operação, e o ponteiro do link que será inserido
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de links possuirá o novo link que foi passado
*/
void insereLink(ListaLin* l, Link* link);

/* Remove um determinado link da lista de links, liberando sua memória
*inputs: o ponteiro para a lista de links onde deseja-se fazer a operação, um char* com o nome da página de origem do link, e outro char* com nome da página de destino do link
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: caso o link com as informações passadas exista na lista de links, ele é removido da lista e seu espaço alocado é liberado 
*/
void removeLink(ListaLin* l, char* nomeOrigem, char* nomeDestino);

/* Realiza uma busca por um link que possui o nome da página de origem e página de destino passados como parâmetros
*inputs: o ponteiro para a lista de links onde deseja-se fazer a operação, e um char* com o nome da página de origem do link, e outro char* com nome da página de destino do link
*outpus: caso as informações do link passadas como parâmtros coincidam com algum link da lista de links, é retornado o ponteiro desse link, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de links não sofre alterações
*/
Link* buscaLink(ListaLin* l, char* nomeOrigem, char* nomeDestino);

/* Realiza uma busca por um link que possui o nome da página de destino passado como parâmetro
*inputs: o ponteiro para a lista de links onde deseja-se fazer a operação, e um char* sendo o nome da página de destino do link desejado
*outpus: caso o nome da página de destino pertença a algum link na lista, é retornado o ponteiro desse link, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de links não sofre alterações
*/
Link* buscaOrigemLink(ListaLin* l, char* nomeDestino);

/* Realiza uma busca pelo link que esteja em uma determinada posição na lista de links
*inputs: o ponteiro para a lista de links onde deseja-se fazer a operação, e um int sendo o index (posição na lista) que deseja-se obter o link
*outpus: caso o index seja uma posição válida na lista, é retornado o ponteiro do link que ocupa aquela posição, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de links não sofre alterações
*/
Link* buscaLinkIndex(ListaLin* l, int index);

/*Libera toda a memória alocada para a lista de links e para os links que estavam na lista
* inputs: a lista de links
* pre-condicao: lista de links existir
* pos-condicao: toda a memória alocada para a lista de links e para os links que estavam na lista foi liberada
*/
void destroiListaLink(ListaLin* l);

#endif
