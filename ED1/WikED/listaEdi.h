#ifndef ListaEdi_H
#define ListaEdi_H

#include "editor.h"

typedef struct listaEdi ListaEdi;

/* Inicializa uma nova lista de editores
*outpus: ponteiro para uma nova lista de editores inicializada
*pos-condicao: a lista de editores retornada existirá
*/
ListaEdi* inicializaListaEditor();

/* Insere um novo editor no final da lista de editores
*inputs: o ponteiro para a lista de editores onde deseja-se fazer a operação, e o ponteiro do editor que será inserido
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de editores possuirá o novo editor que foi passado
*/
void insereEditor(ListaEdi* l, Editor* e);

/* Realiza uma busca por um editor que possui o nome passado como parâmetro
*inputs: o ponteiro para a lista de editores onde deseja-se fazer a operação, e um char* sendo o nome do editor desejado
*outpus: caso o nome do editor pertença a algum editor na lista, é retornado o ponteiro desse editor, caso contrário, é retornado um ponteiro NULL
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a lista de editores não sofre alterações
*/
Editor* buscaEditor(ListaEdi* l, char* nomeEditor);

/*Libera toda a memória alocada para a lista de editores e para os editores que estavam na lista
* inputs: a lista de editores
* pre-condicao: lista de editores existir  
* pos-condicao: toda a memória alocada para a lista de editores e para os editores que estavam na lista foi liberada
*/
void destroiListaEditor(ListaEdi* l);

#endif
