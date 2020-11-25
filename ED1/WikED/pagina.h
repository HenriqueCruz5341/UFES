#ifndef Pagina_H
#define Pagina_H

#include "listaCon.h"

typedef struct pagina Pagina;

#include "listaLin.h"

/* Inicializa uma nova página
*inputs: char* com o nome da página e outro com o nome do arquivo da página
*outpus: ponteiro para uma nova página inicializada
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a página de retorno existirá com exatamente os dados que foram passados
*/
Pagina* inicializaPagina(char* nome, char* arquivo);

/* Retorna o nome de uma página
*inputs: a página
*outputs: o nome da página é retornado
*pre-condicao: página existir
*pos-condicao: a página não sofre nenhuma alteração
*/
char* retornaNomePagina(Pagina* p);

/* Retorna o nome do arquivo de uma página
*inputs: a página
*outputs: o nome do arquivo da página é retornado
*pre-condicao: página existir
*pos-condicao: a página não sofre nenhuma alteração
*/
char* retornaArquivoPagina(Pagina* p);

/* Retorna a lista de contribuições de uma página
*inputs: a página
*outputs: o ponteiro para a lista de contribuições da página é retornado
*pre-condicao: página existir
*pos-condicao: a página não sofre nenhuma alteração
*/
ListaCon* retornaContribuicoesPagina(Pagina* p);

/* Retorna a lista de links de uma página
*inputs: a página
*outputs: o ponteiro para a lista de links da página é retornado
*pre-condicao: página existir
*pos-condicao: a página não sofre nenhuma alteração
*/
ListaLin* retornaLinksPagina(Pagina* p);

/*Libera toda a memória alocada para a página, inclusive a memória alocada para as listas de contribuições e links
* inputs: a página
* pre-condicao: página existir
* pos-condicao: toda a memória alocada para página foi liberada, inclusive a memória alocada para as listas de contribuições e links
*/
void destroiPagina(Pagina* p);

#endif
