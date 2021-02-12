#ifndef CRIVOINT_H
#define CRIVOINT_H

typedef struct crivoInt CrivoInt;

CrivoInt* iniciaCrivoInt(int num);

char estaMarcadoCrivoInt(CrivoInt* crivoInt, int num);

void marcarPrimosCrivoInt(CrivoInt* crivoInt, int num);

void destruirCrivoInt(CrivoInt* crivoInt);
#endif