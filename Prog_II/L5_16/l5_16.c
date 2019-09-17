 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
void OrdenaCrescente(tCandidato * vet, int qtd);
void OrdenaIdade(tCandidato * vet, int qtd);
void OrdenaCodigo(tCandidato *vet, int qtd);

int main() {
    int qtdCand, i = 0, j;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++) {
        candidatos[i] = LeCandidato();
    }
    OrdenaCrescente(candidatos, qtdCand);
    for (i = 0; i < qtdCand; i++) {
        ImprimeCandidato(candidatos[i]);
    }
    return 0;
}

tCandidato LeCandidato() {
    tCandidato candidato;

    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]");
    scanf("%*c");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
            candidato.codigo, candidato.nome,
            candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente(tCandidato * vet, int qtd) {
    int i, j;
    tCandidato aux;

    for (i = 0; i < qtd; i++) {
        for (j = i; j < qtd; j++) {
            if (vet[i].nota < vet[j].nota) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    OrdenaIdade(vet, qtd);
    OrdenaCodigo(vet, qtd);
}

void OrdenaIdade(tCandidato * vet, int qtd) {
    int i, j;
    tCandidato aux;

    for (i = 0; i < qtd; i++) {
        for (j = i; j < qtd; j++) {
            if (vet[i].idade > vet[j].idade && vet[i].nota == vet[j].nota) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void OrdenaCodigo(tCandidato *vet, int qtd) {
    int i, j;
    tCandidato aux;

    for (i = 0; i < qtd; i++) {
        for (j = i; j < qtd; j++) {
            if (vet[i].codigo > vet[j].codigo && vet[i].nota == vet[j].nota && vet[i].idade == vet[j].idade) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}
