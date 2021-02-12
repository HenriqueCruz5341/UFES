#ifndef CRIVOCHAR_H
#define CRIVOCHAR_H

typedef struct crivoChar CrivoChar;

CrivoChar* iniciaCrivoChar(int num);

char estaMarcadoCrivoChar(CrivoChar* crivoChar, int num);

void marcarPrimosCrivoChar(CrivoChar* crivoChar, int num);

void destruirCrivoChar(CrivoChar* crivoChar);

#endif