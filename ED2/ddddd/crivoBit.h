#ifndef CRIVOBIT_H
#define CRIVOBIT_H

typedef struct crivoBit CrivoBit;

CrivoBit* iniciaCrivoBit(int num);

char estaMarcado(CrivoBit* crivoBit, int num);

void marcarPrimosCrivoBit(CrivoBit* crivoBit, int num);

void destruirCrivoBit(CrivoBit* crivoBit);

#endif