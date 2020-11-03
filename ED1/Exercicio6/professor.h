#ifndef Professor_h
#define Professor_h

typedef struct professor Professor;

Professor *inicializaProfessor(int siape, char *nome, float salario);

void imprimeProfessor(Professor *p);

int retornaSiape(Professor *p);

char *retornaNomeProfessor(Professor *p);

float retornaSalario(Professor *p);

void destroiProfessor(Professor *p);

#endif