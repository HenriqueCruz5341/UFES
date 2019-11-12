#ifndef USUARIO_H
#define USUARIO_H

typedef struct usuario Usuario;

Usuario* inicializaUsuario(char* nome, int tipo, char* senha, int* playlists);

Usuario* alocarUsuario(int qtd);

void modificaNomeUsuario(Usuario* usuario, char* nNome);

void modificaTipoUsuario(Usuario* usuario, int nTipo);

void modificaSenhaUsuario(Usuario* usuario, char* nSenha);

void modificaPlaylistsUsuario(Usuario* usuario, int* nPlaylists);

void modificaQtdPlaylistsUsuario(Usuario* usuario, int nQtdPlaylists);

int pegaIdUsuario(Usuario* usuario);

char* pegaNomeUsuario(Usuario* usuario);

int pegaTipoUsuario(Usuario* usuario);

char* pegaSenhaUsuario(Usuario* usuario);

int* pegaPlaylistsUsuario(Usuario* usuario);

int pegaQtdPlaylistsUsuario(Usuario* usuario);

Usuario* buscarUsuario(int idUsuario);

void imprimeUsuario(Usuario* usuario);

int listarTodosUsuarios();

void destroiUsuario(Usuario* usuario);

void salvarUsuarioArquivo(Usuario* usuario);

int pegaUltimoIdUsuarioCadastrado();

#endif /* USUARIO_H */

