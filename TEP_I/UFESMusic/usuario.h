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

void excluirUsuarioArquivo(Usuario* usuario);

int quantidadeUsuariosCadastrados();

void atualizarArquivoUsuarios(Usuario* usuario);

void listarUsuariosFiltro(int tipoFiltro, char* string, int numero);
/* tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - tipo
string, serve para receber uma string, caso queira pesquisar pelo nome do usuario
numero, serve para receber um numero, caso queira pesquisar pelo tipo do usuario
*/ 

#endif /* USUARIO_H */

