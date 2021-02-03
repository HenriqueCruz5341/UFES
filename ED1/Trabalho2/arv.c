#include "arv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A estrutura da árvore armazena
struct arv {
    char op;
    int num;
    Arv* esq;
    Arv* dir;
};

//Função auxiliar que serve apenas para transformar um número que está em umna string em um inteiro
int transformaInteiro(char* str) {
    int i, num;

    for (i = 0; i < strlen(str); i++) {
        if (i == 0)
            num = str[i] - '0';
        else
            num = num * 10 + (str[i] - '0');
    }

    return num;
}

/*A lógica por trás dessa função é contar a quantidade de parênteses até achar a última operação que será realizada,
quando esssa operação é encontrada, a string da expressão é "quebrada" em duas partes, a parte esquerda da operação, e a
parte da direita, e ai a função é chamada recursivamente para quebrar a subexpressão, até que chegue em algo como (5).
Então, considerando a expressão: (((10)+(5))*(2)), a última operação a ser realizada é *, a expressão é dividida em 
((10)+(5)) na parte da esquerda e (2) na parte da direita, com isso, a parte da esquerda irá chamar a função novamente
para ser "quebrada", e a parte da direita (2), já foi "quebrada" ao máximo, então ele é criado como um nó folha.
*/
Arv* arvCria(char* expressao) {
    //Vericando se a expressão já foi "quebrada" ao máximo, algo como (2), se sim, é criado um nó folha com esse número
    if (expressao[1] != '(') {
        Arv* arv = (Arv*)malloc(sizeof(Arv));
        arv->esq = NULL;
        arv->dir = NULL;
        char* aux = expressao + 1;
        aux[strlen(aux) - 1] = '\0';
        arv->num = transformaInteiro(aux);
        arv->op = '\0';

        return arv;
    }

    int i;
    int count = 0, flag = 0;
    /* Caminha na expressão até encontrar a última operação a ser realizada, para isso ele vai contando a quantidade de 
    parênteses que são abertos e fechados. */
    for (i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(')
            count++;
        else if (expressao[i] == ')')
            count--;

        if (count == 1) {
            if (flag)
                break;
            flag = 1;
        }
    }

    char operador;
    char* esq;
    char* dir;

    //pega exatamente o operador da última operação
    operador = *(expressao + i + 1);

    //pega somente a expressão da esquerda e a deixa devidamente formatada
    esq = strdup(expressao + 1);
    esq[i] = '\0';

    //pega somente a expressão da direita e a deixa devidamente formatada
    dir = strdup(expressao + i + 2);
    dir[strlen(dir) - 1] = '\0';

    //cria o nó da árvore referente à atual ultima operação
    Arv* arv = (Arv*)malloc(sizeof(Arv));
    arv->op = operador;
    arv->num = '\0';
    arv->esq = arvCria(esq);
    arv->dir = arvCria(dir);

    free(esq);
    free(dir);

    return arv;
}

//Função auxiliar que serve apenas para realizar a operação matemática de acordo com com char operador
float calculadora(float num1, float num2, char op) {
    if (op == '+')
        return num1 + num2;
    if (op == '-')
        return num1 - num2;
    if (op == '*')
        return num1 * num2;
    if (op == '/')
        return num1 / num2;
}

/* Caminha na árvore como se fosse imprimí-la, quando chega em um nó folha, que no caso é um número, esse número é retornado
para ser utilizado na operação, e é pego o operador da primeira operação que deve ser realizada.
*/
float arvCalculaExpressao(Arv* a) {
    float resultado = 0;
    float num1 = 0, num2 = 0, i;
    float info;
    char op;

    //verifica se chegou no nó folha da esquerda
    if (!a->esq)
        return a->num;
    else {
        info = arvCalculaExpressao(a->esq);
        op = a->op;
    }

    num1 = info;

    //verifica se chegou no nó folha da direita
    if (!a->dir)
        return a->num;
    else {
        info = arvCalculaExpressao(a->dir);
        op = a->op;
    }

    num2 = info;

    resultado = calculadora(num1, num2, op);

    return resultado;
}

Arv* arvLibera(Arv* a) {
    if (a) {
        arvLibera(a->esq);
        arvLibera(a->dir);
        free(a);
    }
    return NULL;
}

void arvImprime(Arv* a) {
    printf("(");
    if (a) {
        if (a->num)
            printf("%d", a->num);
        else
            printf("%c", a->op);
        arvImprime(a->esq);
        arvImprime(a->dir);
    }
    printf(")");
}
