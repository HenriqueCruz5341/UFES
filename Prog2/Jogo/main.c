#include <stdio.h>
#include "jogador.h"


jogo LerJogo(FILE* arq);
void ImprimirJogo(jogo jogo);

int main(int argc, char *argv[]) {
  jogo infJogo;

  FILE* arquivo = fopen(argv[1], "r");
  if (arquivo == NULL) {
    printf("Arquivo invalido.\n");
    return 0;
  }

  infJogo = LerJogo(arquivo);

  ImprimirJogo(infJogo);
  fclose(arquivo);

  return 0;
}

jogo LerJogo(FILE* arq){
  jogo jogo;

  fscanf(arq, "%d %f %d", &jogo.id, &jogo.tempoLim, &jogo.qtdJogadores);

  return jogo;
}

void ImprimirJogo(jogo jogo){
  printf("ID=%d, TempoLim=%f, QtdJogadores=%d\n", jogo.id, jogo.tempoLim, jogo.qtdJogadores);
}
