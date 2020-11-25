#ifndef ListaPag_H
#define ListaPag_H

#include "pagina.h"

typedef struct listaPag ListaPag;

/* Inicializa uma nova lista de páginas
*outpus: ponteiro para uma nova lista de páginas inicializada
*pos-condicao: a lista de páginas retornada existirá
*/
ListaPag* inicializaListaPagina();

/* Insere uma nova página no final da lista de páginas
*inputs: o ponteiro para a lista de páginas onde deseja-se fazer a operação, e o ponteiro da página que será inserida
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de páginas possuirá o nova página que foi passada
*/
void inserePagina(ListaPag* l, Pagina* p);

/* Remove uma determinada página da lista de páginas, liberando sua memória
*inputs: o ponteiro para a lista de páginas onde deseja-se fazer a operação, um char* com o nome da página
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: caso a página com as informações passadas exista na lista de páginas, ela é removida da lista e seu espaço alocado é liberado 
*/
void removePagina(ListaPag* l, char* nomePagina);

/* Realiza uma busca por uma página que possui o nome passado como parâmetro
*inputs: o ponteiro para a lista de páginas onde deseja-se fazer a operação, e uma char* com o nome da página
*outpus: caso as informações da página passadas como parâmtros coincidam com algum página da lista de páginas, é retornado o ponteiro desse página, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de páginas não sofre alterações
*/
Pagina* buscaPagina(ListaPag* l, char* nomePagina);

/* Realiza uma busca pela página que esteja em uma determinada posição na lista de páginas
*inputs: o ponteiro para a lista de páginas onde deseja-se fazer a operação, e uma int sendo o index (posição na lista) que deseja-se obter a página
*outpus: caso o index seja uma posição válida na lista, é retornado o ponteiro da página que ocupa aquela posição, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de páginas não sofre alterações
*/
Pagina* buscaPaginaIndex(ListaPag* l, int index);

/* Verifica se a partir de uma certa página de origem é possível chegar à uma página de destino apenas explorando os links da página de destino
*inputs: o ponteiro para a página de origem e outro para a página de destino
*outpus: caso exista um caminho entre a página de origem ate a página de destino, é retornado 1, caso contrário, é retornado 0
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de páginas e as páginas não sofrem alterações
*/
int verificaCaminho(Pagina* origem, Pagina* destino);

/*Libera toda a memória alocada para a lista de páginas e caso o parametro tudo seja diferente de 0, todas as páginas na lista de páginas são liberadas também
* inputs: a lista de páginas e um inteiro que simboliza se todas as páginas serão liberadas ou não
* pre-condicao: lista de páginas existir
* pos-condicao: toda a memória alocada para a lista de páginas foi liberada, e caso tudo seja diferente de 0, as páginas serão liberadas também, caso contrario, elas não sofrem alteração
*/
void destroiListaPagina(ListaPag* l, int tudo);

#endif
