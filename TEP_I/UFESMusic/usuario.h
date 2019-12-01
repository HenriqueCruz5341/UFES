#ifndef USUARIO_H
#define USUARIO_H
#include "playlist.h"

typedef struct usuario Usuario;


/* Inicializa um novo usuario
*inputs: nome do usuario, o tipo (0 - normal, 1 - admin), senha, e um vetor de playlists (20 posiçoes), vazio
*outpus: ponteiro para um novo usuario inicializado
*pre-condicao: os parametros devem estar devidamente preenchidos
*pos-condicao: o usuario de retorno existirá com exatamente os dados que foram passados
*/
Usuario* inicializaUsuario(char* nome, int tipo, char* senha, int* playlists);

/* Aloca um espaço na memoria para uma quantidade qtd de usuarios sejam armazenadas
*inputs: a quantidade de espaços para usuarios que serao alocados
*outpus: o ponteiro para o começo desse espaço para usuarios na memoria
*pre-condicao: qtd deve ser diferente de 0
*pos-condicao: o espaço requisitado terá sido alocado
*/
Usuario* alocarUsuario(int qtd);

/* Modifica o nome de um usuario
*inputs: o usuario, e o novo nome para o usuario
*pre-condicao: usuario existir
*pos-condicao: o nome do usuario tera sido modificado
*/
void modificaNomeUsuario(Usuario* usuario, char* nNome);

/* Modifica o tipo de um usuario
*inputs: o usuario, e o novo tipo para o usuario
*pre-condicao: usuario existir
*pos-condicao: o nome do usuario tera sido modificado
*/
void modificaTipoUsuario(Usuario* usuario, int nTipo);

/* Modifica a senha de um usuario
*inputs: o usuario, e a nova senha para o usuario
*pre-condicao: usuario existir
*pos-condicao: a senha do usuario tera sido modificada
*/
void modificaSenhaUsuario(Usuario* usuario, char* nSenha);

/* Modifica a quantidade de playlists de um usuario
*inputs: o usuario, e a nova quantidade de playlists para o usuario
*pre-condicao: usuario existir
*pos-condicao: a quantidade de playlistis do usuario tera sido modificado
*/
void modificaQtdPlaylistsUsuario(Usuario* usuario, int nQtdPlaylists);

/* Retorna o ID do usuario
*inputs: o usuario
*outputs: o ID do usuario é retornado 
*pre-condicao: usuario existir
*pos-condicao: usuario não é modificado
*/
int pegaIdUsuario(Usuario* usuario);

/* Retorna o nome do usuario
*inputs: o usuario
*outputs: o nome do usuario é retornado 
*pre-condicao: usuario existir
*pos-condicao: o nome do usuario tera sido modificado
*/
char* pegaNomeUsuario(Usuario* usuario);

/* Retorna o tipo do usuario
*inputs: o usuario
*outputs: o tipo do usuario é retornado 
*pre-condicao: usuario existir
*pos-condicao: usuario não é modificado
*/
int pegaTipoUsuario(Usuario* usuario);

/* Retorna a senha do usuario
*inputs: o usuario
*outputs: a senha do usuario é retornada
*pre-condicao: usuario existir
*pos-condicao: usuario não é modificado
*/
char* pegaSenhaUsuario(Usuario* usuario);

/* Retorna o vetor com os IDs de playlist que o usuario possui
*inputs: o usuario
*outputs: o vetor com os IDs de playlists do usuario é retornado 
*pre-condicao: usuario existir
*pos-condicao: usuario não é modificado
*/
int* pegaPlaylistsUsuario(Usuario* usuario);

/* Retorna a quantidade de playlists do usuario
*inputs: o usuario
*outputs: a quantidade de playlists do usuario é retornada 
*pre-condicao: usuario existir
*pos-condicao: usuario não é modificado
*/
int pegaQtdPlaylistsUsuario(Usuario* usuario);

/* Busca o ID de um usuario cadastrado no arquivo de usuarios
*inputs: o ID do usuario desejado
*outputs: o usuario que possui o ID passado
*pre-condicao: ser um ID de um usuario cadastrado
*pos-condicao: o usuario com aquele determinado ID terá sido retornado
*/
Usuario* buscarUsuario(int idUsuario);

/* Imprime os atributos de um usuario com uma determinada formatação
*inputs: o usuario
*pre-condicao: usuario existir
*/
void imprimeUsuario(Usuario* usuario);

/* Imprime todos os usuarios cadastrados
*outputs: retorna 1 caso tenha conseguido listar, e 0 caso não tenha conseguido
*pre-condicao: algum usuario ter sido cadastrado
*/
int listarTodosUsuarios();

/*Libera memória alocada para o usuario
* inputs: o usuario
* pre-condicao: usuario existir  
* pos-condicao: toda a memória alocada para o usuario foi liberada
*/
void destroiUsuario(Usuario* usuario);

/* Salva o usuario passado no arquivo de usuarios
*inputs: o usuario
*pre-condicao: usuario existir
*pos-condicao: o usuario terá sido salvo no arquivo de usuarios
*/
void salvarUsuarioArquivo(Usuario* usuario);

/* Pega o ID do ultimo usuario cadastrado no arquivo de usuarios
*outputs: o ID do ultimo usuario cadastrado
*pre-condicao: algum usuario ter sido cadastrado
*pos-condicao: o ID do ultimo usuario cadastrado terá sido retornado
*/
int pegaUltimoIdUsuarioCadastrado();

/* Exclui um usuario do arquivo de usuarios
*inputs: o usuario que deseja excluir
*pre-condicao: usuario existir, e já ter sido cadastrado no arquivo
*pos-condicao: o usuaro terá sido removido do arquivo, assim como todas as playlists que ele era dono
*/
void excluirUsuarioArquivo(Usuario* usuario);

/* Conta quantos usuarios foram cadastrados até o momento no arquivo de usuarios
*outputs: a quantidade de usuarios cadastrados no arquivo de usuarios
*pre-condicao: existir um arquivo de usuarios
*pos-condicao: a quantidade de usuarios cadastrados terá sido retornada
*/
int quantidadeUsuariosCadastrados();

/* Atualiza o arquivo de usuarios pois algum usuario sofreu alteração
*inputs: o usuario cadastrado que sofreu alteração
*pre-condicao: usuario existir, e já ter sido cadastrado no arquivo
*pos-condicao: o arquivo de usuarios terá sido atualizado
*/
void atualizarArquivoUsuarios(Usuario* usuario);

/* Lista os usuarios de acordo com o tipo de filtro selecionado
*inputs: tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - tipo
string, serve para receber uma string, caso queira pesquisar pelo nome do usuario
numero, serve para receber um numero, caso queira pesquisar pelo tipo do usuario
*pre-condicao: algum usuario ter sido cadastrado e o tipo de filtro ser uma opção valida
*pos-condicao: os usuarios que satisfazem a condição do filtro serão listados
*/
void listarUsuariosFiltro(int tipoFiltro, char* string, int numero);

/* Verifica se o nome e senha passado por parametro são de algum usuario cadastrado
*inputs: string de nome e outra de senha
*outputs: o usuario que possui aquela senha e nome
*pre-condicao: algum usuario deve ter sido cadastrado
*pos-condicao: será retornado o usuario que possui tal nome e senha ou nulo caso nenhum usuario tenha sido encontrado
*/
Usuario* autenticarUsuario(char* nome, char* senha);

/* Imprime todas as playlists pertencentes ao usuario, seja ele dono, contribuinte ou seguidor
*inputs: o usuario que se deseja imprimir as playlists
*pre-condicao: usuario existir, e já ter sido cadastrado no arquivo
*pos-condicao: as playlists que o usuario possui terão sido impressas
*/
void listarPlaylistsUsuario(Usuario* usuario);

/* Adiciona uma dada playlist em um dado usuario
*inputs: o usuario que deseja-se adicionar uma playlist e a propria playlist
*pre-condicao: o usuario e a playlist passadas devem existir
*pos-condicao: o usuario terá a playlist adicionada a ele e o arquivo de usuarios terá sido atualizado
*/
void adicionarPlaylistUsuario(Usuario* usuario, Playlist* playlist);

/* Remove uma dada playlist de todos os usuarios
*inputs: o ID da playlist que se deseja remover
*pre-condicao: a playlist deve exitir e estar cadastrada no arquivo de playlists
*pos-condicao: a playlist que possui tal ID será removida da lista de playlists de todos os usuarios 
que possuíam essa playlist salva
*/

void removerPlaylistTodosUsuario(int idPlaylist);

/* Remove todas as playlists de um usuario
*inputs: a lista de playlists salvas desse usuario, e o ID do proprio usuario que se deseja excluir as playlists
*pre-condicao: o ID de usuario pertencer a algum usuario cadastrado no arquivo de usuarios
*pos-condicao: o usuario com tal ID tera todas as suas playlists removidas, e caso ele seja dono de alguma dessas playlists
os usuarios que seguiam essa playlist terão a mesma excluida de suas playlists salvas
*/
void removerTodasPlaylistsUsuario(int* playlists, int idUsuario);

#endif /* USUARIO_H */