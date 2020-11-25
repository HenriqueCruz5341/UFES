#ifndef Editor_H
#define Editor_H

typedef struct editor Editor;

/* Inicializa um novo editor
*inputs: char* com o nome do editor
*outpus: ponteiro para um novo editor inicializado
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: o editor de retorno existirá com exatamente os dados que foram passados
*/
Editor* inicializaEditor(char* nome);

/* Retorna o nome de um editor
*inputs: o editor
*outputs: o nome do editor é retornado
*pre-condicao: editor existir
*pos-condicao: o editor não sofre nenhuma alteração
*/
char* retornaNomeEditor(Editor* e);

/*Libera toda a memória alocada para o editor
* inputs: o editor
* pre-condicao: editor existir  
* pos-condicao: toda a memória alocada para editor foi liberada
*/
void destroiEditor(Editor* e);

#endif
