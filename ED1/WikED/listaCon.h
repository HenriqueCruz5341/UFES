#ifndef ListaCon_H
#define ListaCon_H

#include "contribuicao.h"

typedef struct listaCon ListaCon;

/* Inicializa uma nova lista de contribuições
*outpus: ponteiro para uma nova lista de contribuições inicializada
*pos-condicao: a lista de contribuições retornada existirá
*/
ListaCon* inicializaListaContribuicao();

/* Insere uma nova contribuição no final da lista de contribuições
*inputs: o ponteiro para a lista de contribuições onde deseja-se fazer a operação, e o ponteiro da contribuição que será inserida
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de contribuições possuirá a nova contribuição que foi passada
*/
void insereContribuicao(ListaCon* l, Contribuicao* c);

/* Marca a contribuição desejada como removida da lista de contribuições, apesar de não ser efetivamente removida, ela não aparecerá mais no arquivo da página quando for impresso. 
*inputs: o ponteiro para a lista de contribuições onde deseja-se fazer a operação, um char* com o nome do editor que está fazendo a operação, e outro char* com nome do arquivo da contribuição que será retirada.
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: caso o editor seja o responsável pela contribuição, ela é marcada como removida, caso contrário, a lista de contribuições não sofre nenhum 
*/
void removeContribuicao(ListaCon* l, char* nomeEditor, char* nomeArquivo);

/* Realiza uma busca pela contribuição que esteja em uma determinada posição na lista de contribuições
*inputs: o ponteiro para a lista de contribuições onde deseja-se fazer a operação, e um int sendo o index (posição na lista) que deseja-se obter a contribuição
*outpus: caso o index seja uma posição válida na lista, é retornado o ponteiro da contribuição que ocupa aquela posição, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de contribuições não sofre alterações
*/
Contribuicao* buscaContribuicaoIndex(ListaCon* l, int index);

/*Libera toda a memória alocada para a lista de contribuições e para as contribuições que estavam na lista
* inputs: a lista de contribuições
* pre-condicao: lista de contribuições existir  
* pos-condicao: toda a memória alocada para a lista de contribuições e para as contribuições que estavam na lista foi liberada
*/
void destroiListaContribuicao(ListaCon* l);

#endif
