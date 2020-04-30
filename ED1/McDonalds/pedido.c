#include "pedido.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"

typedef struct celula Celula;

struct celula {
    TProduto* produto;
    Celula* prox;
};

struct pedido {
    char* dono;
    Celula* ini;
    Celula* fim;
};

Celula* BuscaElemento(TPedido* pedido, TProduto* prod);

TPedido* InicPedido(char* dono) {
    TPedido* pedido = (TPedido*)malloc(sizeof(TPedido));
    pedido->ini = NULL;
    pedido->fim = NULL;
    pedido->dono = strdup(dono);

    return pedido;
}

void IncluiProdutoPedido(TPedido* pedido, TProduto* prod) {
    Celula* novaCel = (Celula*)malloc(sizeof(Celula));

    novaCel->produto = prod;
    novaCel->prox = NULL;

    if (pedido->ini != NULL) {
        if (BuscaElemento(pedido, prod)) {
            printf("Produto já existe no pedido\n");
            return;
        }
        pedido->fim->prox = novaCel;
        pedido->fim = novaCel;
        return;
    }
    pedido->ini = novaCel;
    pedido->fim = novaCel;
}

void ImprimePedido(TPedido* pedido) {
    Celula* cel;

    printf("\nDono(a): %s", pedido->dono);
    if (pedido->ini == NULL) {
        printf("Nao ha produtos neste pedido!\n");
        return;
    }

    for (cel = pedido->ini; cel != NULL; cel = cel->prox)
        ImprimeIngredientes(cel->produto);
}

void RetiraProdutoPedido(TPedido* pedido, char* prod) {
    Celula* cel = pedido->ini;
    Celula* ant;

    while (cel != NULL && strcmp(RetornaNome(cel->produto), prod)) {
        ant = cel;
        cel = cel->prox;
    }
    if (cel == NULL) return;

    if (pedido->ini == cel && pedido->fim == cel) {
        pedido->ini = NULL;
        pedido->fim = NULL;
    } else if (pedido->ini == cel) {
        pedido->ini = cel->prox;
    } else if (pedido->fim == cel) {
        pedido->fim = ant;
        ant->prox = NULL;
    } else {
        ant->prox = cel->prox;
    }

    free(cel);
}

int EnviaPedido(TPedido* pedido, int restricao_calorica, char* restricao_alimentar) {
    Celula* cel;
    int calorias = 0;

    for (cel = pedido->ini; cel != NULL; cel = cel->prox) {
        if (VerificaIngrediente(cel->produto, restricao_alimentar)) {
            printf("\nPedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(cel->produto));
            return 0;
        }
        calorias += Calorias(cel->produto);
    }

    if (calorias > restricao_calorica) {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    Celula* prox;
    cel = pedido->ini;

    while (cel != NULL) {
        prox = cel->prox;
        free(cel);
        cel = prox;
    }

    free(pedido->dono);
    free(pedido);

    return 1;
}

Celula* BuscaElemento(TPedido* pedido, TProduto* prod) {
    Celula* cel = pedido->ini;

    while (cel != NULL) {
        if (!strcmp(RetornaNome(cel->produto), RetornaNome(prod)))
            return cel;

        cel = cel->prox;
    }

    return NULL;
}
