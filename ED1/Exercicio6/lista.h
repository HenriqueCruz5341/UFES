#ifndef Lista_h
#define Lista_h

typedef struct lista Lista;

Lista* inicializaLista();

void insereItem(Lista* l, void* item, int tipo);

void imprimeLista(Lista* l);

float valorChurrasco(Lista* l);

void destroiLista(Lista* l);

#endif