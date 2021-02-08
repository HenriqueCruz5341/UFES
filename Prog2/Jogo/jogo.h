#ifndef JOGO_H
#define JOGO_H
#include "jogador.h"

typedef struct{
  int id;
  float tempoLim;
  int qtdJogadores;
  jogador vencedor;
  jogador perdedor;
  jogador pior;
}jogo;

#endif
