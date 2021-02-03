#ifndef AVR_H
#define AVR_H

typedef struct arv Arv;

/* Cria uma nova árvore de expressões
*inputs: uma string com a expressão bem formatada
*outpus: ponteiro para uma nova árvore de expressões inicializada e preenchida
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a árvore de expressões retornada existirá e estará devidamente organizada
*/
Arv* arvCria(char* info);

/* Calcula o valor da expressão que a árvore armazena
*inputs: o ponteiro para a árvore de expressões
*outpus: o resultado em float da expressão que a árvore armazena
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a árvore de expressões não sofre alterações
*/
float arvCalculaExpressao(Arv* a);

/* Imprime a árvore de expressões formatada
*inputs: o ponteiro para a árvore de expressões
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a árvore de expressões não sofre alterações
*/
void arvImprime(Arv* a);

/*Libera toda a memória alocada para a árvore de expressões
* inputs: a árvore de expressões
* pre-condicao: árvore de expressões passada deve existir  
* pos-condicao: toda a memória alocada para a árvore de expressões foi liberada
*/
Arv* arvLibera(Arv* a);

#endif