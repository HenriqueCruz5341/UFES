#include <stdio.h>
#include <string.h>

#include "impressao.h"
#include "listaCon.h"
#include "listaEdi.h"
#include "listaLin.h"
#include "listaPag.h"

void adicionaPagina(ListaPag* l, char* nomePagina, char* nomeArquivo);
void retiraPagina(ListaPag* l, char* nomePagina);
void adicionaEditor(ListaEdi* l, char* nomeEditor);
void adicionaContribuicao(ListaPag* lp, ListaEdi* le, char* nomePagina, char* nomeEditor, char* nomeArquivo);
void retiraContribuicao(ListaPag* lp, ListaEdi* le, char* nomePagina, char* nomeEditor, char* nomeArquivo);
void adicionaLink(ListaPag* l, char* origem, char* destino);
void retiraLink(ListaPag* l, char* origem, char* destino);
void caminho(ListaPag* l, char* origem, char* destino);
void imprimeListaHistoricoConArquivo(ListaCon* l, FILE* arq);
void copiaTextoContribuicao(char* arqOrigem, FILE* arqDestino);
void imprimeListaTextoConArquivo(ListaCon* l, FILE* arq);
void imprimeListaLinksArquivo(ListaLin* l, FILE* arq);
void imprimePaginaArquivo(Pagina* pagina);
void imprimeWiked(ListaPag* l);

int main(int argc, char* argv[]) {
    char comando[20], param1[20], param2[20], param3[20];
    ListaPag* listaPagina = inicializaListaPagina();
    ListaEdi* listaEditor = inicializaListaEditor();

    FILE* arq = fopen(argv[1], "r");
    if (arq == NULL) {
        imprimeLog("ERRO: arquivo de entrada invalido.", NULL);
        return 0;
    }

    fscanf(arq, "%*[^A-Z]");  //Lê os caracteres "lixo" do início

    do {
        fscanf(arq, "%s", comando);

        if (!strcmp(comando, "FIM"))
            break;

        if (!strcmp(comando, "INSEREPAGINA")) {
            fscanf(arq, "%s", param1);
            fscanf(arq, "%s\n", param2);
            adicionaPagina(listaPagina, param1, param2);
        } else if (!strcmp(comando, "RETIRAPAGINA")) {
            fscanf(arq, "%s\n", param1);
            retiraPagina(listaPagina, param1);
        } else if (!strcmp(comando, "INSEREEDITOR")) {
            fscanf(arq, "%s\n", param1);
            adicionaEditor(listaEditor, param1);
        } else if (!strcmp(comando, "INSERECONTRIBUICAO")) {
            fscanf(arq, "%s", param1);
            fscanf(arq, "%s", param2);
            fscanf(arq, "%s\n", param3);
            adicionaContribuicao(listaPagina, listaEditor, param1, param2, param3);
        } else if (!strcmp(comando, "RETIRACONTRIBUICAO")) {
            fscanf(arq, "%s", param1);
            fscanf(arq, "%s", param2);
            fscanf(arq, "%s\n", param3);
            retiraContribuicao(listaPagina, listaEditor, param1, param2, param3);
        } else if (!strcmp(comando, "INSERELINK")) {
            fscanf(arq, "%s", param1);
            fscanf(arq, "%s\n", param2);
            adicionaLink(listaPagina, param1, param2);
        } else if (!strcmp(comando, "RETIRALINK")) {
            fscanf(arq, "%s", param1);
            fscanf(arq, "%s\n", param2);
            retiraLink(listaPagina, param1, param2);
        } else if (!strcmp(comando, "CAMINHO")) {
            fscanf(arq, "%s", param1);
            fscanf(arq, "%s\n", param2);
            caminho(listaPagina, param1, param2);
        } else if (!strcmp(comando, "IMPRIMEPAGINA")) {
            fscanf(arq, "%s\n", param1);
            imprimePaginaArquivo(buscaPagina(listaPagina, param1));
        } else if (!strcmp(comando, "IMPRIMEWIKED")) {
            imprimeWiked(listaPagina);
        }
    } while (strcmp(comando, "FIM"));

    destroiListaPagina(listaPagina, 1);
    destroiListaEditor(listaEditor);
    fclose(arq);

    return 0;
}

void adicionaPagina(ListaPag* l, char* nomePagina, char* nomeArquivo) {
    Pagina* nova = inicializaPagina(nomePagina, nomeArquivo);
    inserePagina(l, nova);
}

void retiraPagina(ListaPag* l, char* nomePagina) {
    removePagina(l, nomePagina);
}

void adicionaEditor(ListaEdi* l, char* nomeEditor) {
    Editor* novo = inicializaEditor(nomeEditor);

    insereEditor(l, novo);
}

void adicionaContribuicao(ListaPag* lp, ListaEdi* le, char* nomePagina, char* nomeEditor, char* nomeArquivo) {
    Editor* editor = buscaEditor(le, nomeEditor);
    if (!editor) {
        imprimeLog("ERRO: não existe o editor ", nomeEditor);
        return;
    }
    Contribuicao* nova = inicializaContribuicao(editor, nomeArquivo);
    Pagina* pagina = buscaPagina(lp, nomePagina);
    ListaCon* listaCon = retornaContribuicoesPagina(pagina);
    insereContribuicao(listaCon, nova);
}

void retiraContribuicao(ListaPag* lp, ListaEdi* le, char* nomePagina, char* nomeEditor, char* nomeArquivo) {
    if (!buscaEditor(le, nomeEditor)) {
        imprimeLog("ERRO: não existe o editor ", nomeEditor);
        return;
    }
    Pagina* pagina = buscaPagina(lp, nomePagina);
    ListaCon* listaCon = retornaContribuicoesPagina(pagina);
    removeContribuicao(listaCon, nomeEditor, nomeArquivo);
}

void adicionaLink(ListaPag* l, char* origem, char* destino) {
    Pagina* pgOrigem = buscaPagina(l, origem);
    if (!pgOrigem) {
        imprimeLog("ERRO: não existe a pagina ", origem);
        return;
    }

    Pagina* pgDestino = buscaPagina(l, destino);
    if (!pgDestino) {
        imprimeLog("ERRO: não existe a pagina ", destino);
        return;
    }

    Link* novo = inicializaLink(pgOrigem, pgDestino);

    ListaLin* listaLin = retornaLinksPagina(pgOrigem);
    insereLink(listaLin, novo);
}

void retiraLink(ListaPag* l, char* origem, char* destino) {
    Pagina* pagina = buscaPagina(l, origem);
    ListaLin* listaLin = retornaLinksPagina(pagina);
    removeLink(listaLin, origem, destino);
}

void caminho(ListaPag* l, char* origem, char* destino) {
    Pagina* pgOrigem = buscaPagina(l, origem);
    if (!pgOrigem) {
        imprimeLog("ERRO: não existe a pagina ", origem);
        return;
    }

    Pagina* pgDestino = buscaPagina(l, destino);
    if (!pgDestino) {
        imprimeLog("ERRO: não existe a pagina ", destino);
        return;
    }

    int existe = verificaCaminho(pgOrigem, pgDestino);

    FILE* arq = fopen("log.txt", "a");
    if (arq == NULL) {
        printf("Arquivo invalido.\n");
        return;
    }

    if (existe)
        fprintf(arq, "HA CAMINHO DA PAGINA %s PARA %s\n", origem, destino);
    else
        fprintf(arq, "NAO HA CAMINHO DA PAGINA %s PARA %s\n", origem, destino);

    fclose(arq);
}

void imprimeListaHistoricoConArquivo(ListaCon* l, FILE* arq) {
    Contribuicao* contribuicao;
    int i = 0;

    for (contribuicao = buscaContribuicaoIndex(l, i); contribuicao; i++,
        contribuicao = buscaContribuicaoIndex(l, i)) {
        char* editor = retornaNomeEditor(retornaEditorContribuicao(contribuicao));
        char* nomeArquivo = retornaArquivoContribuicao(contribuicao);
        if (retornaRetiradaContribuicao(contribuicao))
            fprintf(arq, "%s %s <<retirada>>\n", editor, nomeArquivo);
        else
            fprintf(arq, "%s %s\n", editor, nomeArquivo);
    }
}

void copiaTextoContribuicao(char* arqOrigem, FILE* arqDestino) {
    char carac;

    FILE* arq = fopen(arqOrigem, "r");
    if (arq == NULL) {
        imprimeLog("ERRO: arquivo de contribuicao invalido ", arqOrigem);
        return;
    }

    while (fscanf(arq, "%c", &carac) == 1)
        fprintf(arqDestino, "%c", carac);

    fclose(arq);
}

void imprimeListaTextoConArquivo(ListaCon* l, FILE* arq) {
    Contribuicao* contribuicao;
    int i = 0;

    for (contribuicao = buscaContribuicaoIndex(l, i); contribuicao; i++,
        contribuicao = buscaContribuicaoIndex(l, i)) {
        if (!retornaRetiradaContribuicao(contribuicao)) {
            char* editor = retornaNomeEditor(retornaEditorContribuicao(contribuicao));
            char* nomeArquivo = retornaArquivoContribuicao(contribuicao);
            fprintf(arq, "-------- %s (%s) --------\n", nomeArquivo, editor);
            fprintf(arq, "\n");
            copiaTextoContribuicao(nomeArquivo, arq);
            fprintf(arq, "\n\n");
        }
    }
}

void imprimeListaLinksArquivo(ListaLin* l, FILE* arq) {
    Link* link;
    int i = 0;

    for (link = buscaLinkIndex(l, i); link; i++,
        link = buscaLinkIndex(l, i)) {
        Pagina* destino = retornaDestinoLink(link);
        char* nomePagina = retornaNomePagina(destino);
        char* nomeArquivo = retornaArquivoPagina(destino);
        fprintf(arq, "%s %s\n", nomePagina, nomeArquivo);
    }
}

void imprimePaginaArquivo(Pagina* pagina) {
    ListaCon* listaCon = retornaContribuicoesPagina(pagina);
    ListaLin* listaLin = retornaLinksPagina(pagina);

    FILE* arq = fopen(retornaArquivoPagina(pagina), "w");
    if (arq == NULL) {
        imprimeLog("ERRO: arquivo de pagina invalido ", retornaArquivoPagina(pagina));
        return;
    }

    fprintf(arq, "%s\n\n", retornaNomePagina(pagina));
    fprintf(arq, "--> Historico de contribuicoes\n");
    imprimeListaHistoricoConArquivo(listaCon, arq);
    fprintf(arq, "\n");
    fprintf(arq, "--> Links\n");
    imprimeListaLinksArquivo(listaLin, arq);
    fprintf(arq, "\n");
    fprintf(arq, "--> Textos\n\n");
    imprimeListaTextoConArquivo(listaCon, arq);

    fclose(arq);
}

void imprimeWiked(ListaPag* l) {
    Pagina* pagina;
    int i = 0;

    for (pagina = buscaPaginaIndex(l, i); pagina; i++,
        pagina = buscaPaginaIndex(l, i)) {
        imprimePaginaArquivo(pagina);
    }
}
