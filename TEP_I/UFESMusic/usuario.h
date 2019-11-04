#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario Usuario;

Usuario* inicializaUsuario(char* nome, int tipo, char* senha);

void modificaNomeUsuario(Usuario* usuario, char* nNome);

void modificaTipoUsuario(Usuario* usuario, int nTipo);

void modificaSenhaUsuario(Usuario* usuario, char* senha);

char* pegaNomeUsuario(Usuario* usuario);

int pegaTipoUsuario(Usuario* usuario);

char* pegaSenhaUsuario(Usuario* usuario);

void imprimeUsuario(Usuario* usuario);

void destroiUsuario(Usuario* usuario);


#endif /* USUARIO_H */

