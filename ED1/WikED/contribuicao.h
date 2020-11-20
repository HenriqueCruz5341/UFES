#ifndef Contribuicao_H
#define Contribuicao_H

#include "editor.h"

typedef struct contribuicao Contribuicao;

/* Inicializa um novo album
*inputs: nome do album, matriz de participantes(max 3 linhas), data de lançamento do album
*outpus: ponteiro para um novo album inicializado
*pre-condicao: os parametros devem estar devidamente preenchidos
*pos-condicao: o album de retorno existirá com exatamente os dados que foram passados
*/
Contribuicao* inicializaContribuicao(Editor* editor, char* arquivo);

Editor* retornaEditorContribuicao(Contribuicao* c);

char* retornaArquivoContribuicao(Contribuicao* c);

int retornaRetiradaContribuicao(Contribuicao* c);

void setaRetiradaContribuicao(Contribuicao* c, int retirada);

void destroiContribuicao(Contribuicao* c);

#endif
