#ifndef Contribuicao_H
#define Contribuicao_H

#include "editor.h"

typedef struct contribuicao Contribuicao;

/* Inicializa uma nova contribuição
*inputs: um editor e char* com o nome do arquivo da contribuição
*outpus: ponteiro para uma nova contribuição inicializada
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a contribuição de retorno existirá com exatamente os dados que foram passados
*/
Contribuicao* inicializaContribuicao(Editor* editor, char* arquivo);

/* Retorna o editor de uma contribuição
*inputs: a contribuição
*outputs: o editor da contribuição é retornado
*pre-condicao: contribuição existir
*pos-condicao: a contribuição não sofre nenhuma alteração
*/
Editor* retornaEditorContribuicao(Contribuicao* c);

/* Retorna o nome do arquivo de uma contribuição
*inputs: a contribuição
*outputs: o nome do arquivo da contribuição é retornado
*pre-condicao: contribuição existir
*pos-condicao: a contribuição não sofre nenhuma alteração
*/
char* retornaArquivoContribuicao(Contribuicao* c);

/* Retorna se uma contribuição foi retirada ou não
*inputs: a contribuição
*outputs: é retornado 1 se a contribuição foi retirada, ou 0, caso contrário
*pre-condicao: contribuição existir
*pos-condicao: a contribuição não sofre nenhuma alteração
*/
int retornaRetiradaContribuicao(Contribuicao* c);

/* Modifica o status de retirada de uma contribuição
*inputs: a contribuição e o novo status de retirada de uma contribuição
*pre-condicao: contribuição existir
*pos-condicao: o status de retirada da contribuição é alterado
*/
void setaRetiradaContribuicao(Contribuicao* c, int retirada);

/*Libera toda a memória alocada para a contribuição
* inputs: a contribuição
* pre-condicao: contribuição existir  
* pos-condicao: toda a memória alocada para contribuição foi liberada
*/
void destroiContribuicao(Contribuicao* c);

#endif
