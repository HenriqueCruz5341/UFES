#ifndef Contribuicao_H
#define Contribuicao_H

#include "editor.h"

typedef struct contribuicao Contribuicao;

Contribuicao* inicializaContribuicao(Editor* editor, char* arquivo);

void imprimeContribuicao(Contribuicao* c);

Editor* retornaEditorContribuicao(Contribuicao* c);

char* retornaArquivoContribuicao(Contribuicao* c);

int retornaRetiradaContribuicao(Contribuicao* c);

void setaRetiradaContribuicao(Contribuicao* c, int retirada);

void destroiContribuicao(Contribuicao* c);

#endif
