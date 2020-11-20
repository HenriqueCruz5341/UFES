#include "editor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct editor {
    char* nome;
};

Editor* inicializaEditor(char* nome) {
    Editor* editor = (Editor*)malloc(sizeof(Editor));

    editor->nome = strdup(nome);

    return editor;
}

char* retornaNomeEditor(Editor* e) {
    return e->nome;
}

void destroiEditor(Editor* e) {
    if (e) {
        if (e->nome) free(e->nome);
        free(e);
    }
}
