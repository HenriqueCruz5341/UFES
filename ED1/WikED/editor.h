#ifndef Editor_H
#define Editor_H

typedef struct editor Editor;

Editor* inicializaEditor(char* nome);

char* retornaNomeEditor(Editor* e);

void destroiEditor(Editor* e);

#endif
