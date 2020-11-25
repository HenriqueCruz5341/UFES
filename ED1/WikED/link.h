#ifndef Link_H
#define Link_H

typedef struct link Link;

#include "pagina.h"

/* Inicializa um novo link
*inputs: o ponteiro para a página de origem, e outro para a página de destino
*outpus: ponteiro para um novo link inicializado
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: o link de retorno existirá com exatamente os dados que foram passados
*/
Link* inicializaLink(Pagina* origem, Pagina* destino);

/* Retorna a página de origem de um link
*inputs: o link
*outputs: o ponteiro da página de origem do link
*pre-condicao: link existir
*pos-condicao: o link não sofre nenhum alteração
*/
Pagina* retornaOrigemLink(Link* l);

/* Retorna a página de destino de um link
*inputs: o link
*outputs: o ponteiro da página de destino do link
*pre-condicao: link existir
*pos-condicao: o link não sofre nenhum alteração
*/
Pagina* retornaDestinoLink(Link* l);

/*Libera toda o memória alocada para o link
* inputs: o link
* pre-condicao: link existir  
* pos-condicao: toda a memória alocada para o link foi liberada
*/
void destroiLink(Link* l);

#endif
