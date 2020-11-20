#include "contribuicao.h"

#include <stdlib.h>
#include <string.h>

struct contribuicao {
    Editor* editor;
    char* arquivo;
    int retirada;
};

Contribuicao* inicializaContribuicao(Editor* editor, char* arquivo) {
    Contribuicao* contribuicao = (Contribuicao*)malloc(sizeof(Contribuicao));

    contribuicao->editor = editor;
    contribuicao->arquivo = strdup(arquivo);
    contribuicao->retirada = 0;

    return contribuicao;
}

Editor* retornaEditorContribuicao(Contribuicao* c) {
    return c->editor;
}

char* retornaArquivoContribuicao(Contribuicao* c) {
    return c->arquivo;
}

int retornaRetiradaContribuicao(Contribuicao* c) {
    return c->retirada;
}

void setaRetiradaContribuicao(Contribuicao* c, int retirada) {
    c->retirada = retirada;
}

void destroiContribuicao(Contribuicao* c) {
    if (c) {
        if (c->arquivo) free(c->arquivo);
        free(c);
    }
}
