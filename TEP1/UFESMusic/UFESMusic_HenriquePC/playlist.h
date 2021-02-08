#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "midia.h"

typedef struct playlist Playlist;

/* Inicializa uma nova playlist
*inputs: nome da playlist, privacidade da playlist (0 - individual, 1 - compartilhada), IDs dos usuarios que são contribuintes (max 2, indice 0 é o dono,
e 1 é o contribuinte)
*outpus: ponteiro para uma nova playlist inicializada
*pre-condicao: os parametros devem estar devidamente preenchidos
*pos-condicao: a playlist de retorno existirá com exatamente os dados que foram passados
*/
Playlist* inicializaPlaylist(char* nome, int privacidade, int* contribuintes);

/* Aloca um espaço na memoria para uma quantidade qtd de playlists sejam armazenadas
*inputs: a quantidade de espaços para playlists que serao alocados
*outpus: o ponteiro para o começo desse espaço para playlists na memoria
*pre-condicao: qtd deve ser diferente de 0
*pos-condicao: o espaço requisitado terá sido alocado
*/
Playlist* alocarPlaylist(int qtd);

/* Modifica o nome de uma playlist
*inputs: a playlist, e o novo nome para a playlist
*pre-condicao: playlist existir
*pos-condicao: o nome da playlist tera sido modificado
*/
void modificaNomePlaylist(Playlist* playlist, char* nNome);

/* Modifica a privacidade de uma playlist
*inputs: a playlist, e a nova privacidade (0 - individual, 1 - compartilhada) para a playlist
*pre-condicao: playlist existir
*pos-condicao: a privaciade da playlist tera sido modificada
*/
void modificaPrivacidadePlaylist(Playlist* playlist, int nPrivacidade);

/* Modifica o contribuinte de uma playlist
*inputs: a playlist, e o ID do novo contribuinte da playlist
*pre-condicao: playlist existir
*pos-condicao: contribuinte da playlist tera sido modificado
*/
void modificaContribuintePlaylist(Playlist* playlist, int nContribuinte);

/* Modifica a quantidade de midias de uma playlist
*inputs: a playlist, e a nova quantidade de midias para a playlist
*pre-condicao: playlist existir
*pos-condicao: a quantidade de midias da playlist tera sido modificado
*/
void modificaQtdMidiasPlaylist(Playlist* playlist, int nQtdMidias);

/* Retorna o ID da playlist
*inputs: a playlist
*outputs: o ID da playlist retornada
*pre-condicao: playlist existir
*pos-condicao: playlist não é modificada
*/
int pegaIdPlaylist(Playlist* playlist);

/* Retorna o nome da playlist
*inputs: a playlist
*outputs: o nome da playlist retornada
*pre-condicao: playlist existir
*pos-condicao: playlist não é modificada
*/
char* pegaNomePlaylist(Playlist* playlist);

/* Retorna a privacidade da playlist
*inputs: a playlist
*outputs: a privacidade da playlist retornada
*pre-condicao: playlist existir
*pos-condicao: playlist não é modificada
*/
int pegaPrivacidadePlaylist(Playlist* playlist);

/* Retorna o dono e o contribuinte da playlist
*inputs: a playlist
*outputs: o dono e o contribuinte da playlist retornada
*pre-condicao: playlist existir
*pos-condicao: playlist não é modificada
*/
int* pegaContribuintesPlaylist(Playlist* playlist);

/* Retorna as midias da playlist
*inputs: a playlist
*outputs: as midias da playlist retornada
*pre-condicao: playlist existir
*pos-condicao: playlist não é modificada
*/
int* pegaMidiaPlaylist(Playlist* playlist);

/* Retorna quantidade de midias da playlist
*inputs: a playlist
*outputs: a quantidade de midias da playlist retornada
*pre-condicao: playlist existir
*pos-condicao: playlist não é modificada
*/
int pegaQtdMidiasPlaylist(Playlist* playlist);

/* Imprime os atributos de uma playlist com uma determinada formatação
*inputs: a playlist
*pre-condicao: playlist existir
*/
void imprimePlaylist(Playlist* playlist);

/*Libera memória alocada para a playlist
* inputs: a playlist
* pre-condicao: playlist existir  
* pos-condicao: toda a memória alocada para a playlist foi liberada
*/
void destroiPlaylist(Playlist* playlist);

/* Pega o ID da ultima playlist cadastrada no arquivo de playlists
*outputs: o ID da ultima playlist cadastrada
*pre-condicao: alguma playlist ter sido cadastrada
*pos-condicao: o ID da ultima playlist cadastrada terá sido retornado
*/
int pegaUltimoIdPlaylistCadastrada();

/* Salva a playlist passada no arquivo de playlists
*inputs: a playlist
*pre-condicao: playlist existir
*pos-condicao: a playlist terá sido salvo no arquivo de playlists
*/
void salvarPlaylistArquivo(Playlist* playlist);

/* Busca o ID de uma playlist cadastrada no arquivo de playlists
*inputs: o ID da playlist desejada
*outputs: a playlist que possui o ID passado
*pre-condicao: ser um ID de uma playlist cadastrada
*pos-condicao: a playlist com aquele determinado ID terá sido retornado
*/
Playlist* buscarPlaylist(int idPlaylist);

/* Imprime todas as playlists cadastradas
*outputs: retorna 1 caso tenha conseguido listar, e 0 caso não tenha conseguido
*pre-condicao: alguma playlist ter sido cadastrada
*/
int listarTodasPlaylists();

/* Atualiza o arquivo de playlists pois alguma playlist sofreu alteração
*inputs: a playlist cadastrada que sofreu alteração
*pre-condicao: playlist existir, e já ter sido cadastrada no arquivo
*pos-condicao: o arquivo de playlists terá sido atualizado
*/
void atualizarArquivoPlaylists(Playlist* playlist);

/* Adiciona uma dada midia em uma dada playlist
*inputs: a playlist que deseja-se adicionar uma midia e a propria midia
*pre-condicao: a midia e playlist passadas devem existir
*pos-condicao: a playlist terá a midia adicionada a ela e o arquivo de playlists terá sido atualizado
*/
void adicionarMidiaPlaylist(Playlist* playlist, Midia* midia);

/* Remove uma dada midia em uma dada playlist
*inputs: a playlist que deseja-se remover uma midia e a propria midia
*pre-condicao: a midia e playlist passadas devem existir, e a midia deve estar na playlist
*pos-condicao: a playlist terá a midia removida dela e o arquivo de playlist terá sido atualizado
*/
void removerMidiaPlaylist(Playlist* playlist, Midia* midia);

/* Imprime todas as midias pertencentes à playlist
*inputs: a playlist que se deseja imprimir as midias
*pre-condicao: playlist existir, e já ter sido cadastrada no arquivo de playlists
*pos-condicao: as midias que playlist possui terão sido impressas
*/
void listarMidiasPlaylist(Playlist* playlist);

/* Troca a posicao de uma midia que esta em uma playlist
*inputs: a playlist, a midia que se deseja alterar a posiçao e a nova posição da midia na playlist
*pre-condicao: playlist e a midia existirem, e a midia estar na playlist
*pos-condicao: a midia estará na posiçao pos, todas as midias que estavam depois serão movidas para baixo ou para cima na lista da playlist, e o arquivo de playlist será atualizado
*/
void trocarPosicaoMidiaPlaylist(Playlist* playlist, Midia* midia, int pos);

/* Exclui uma playlist do arquivo de playlists
*inputs: a playlist que deseja excluir do arquivo
*pre-condicao: playlist existir, e já ter sido cadastrada no arquivo
*pos-condicao: a playlist terá sido removida do arquivo, e tera sido removida das listas de playlists seguidas de todos os usuarios q a seguiam
*/
void excluirPlaylistArquivo(Playlist* playlist);

/* Conta quantas playlists foram cadastradas até o momento no arquivo de playlists
*outputs: a quantidade de playlists cadastradas no arquivo de playlists
*pre-condicao: existir um arquivo de playlists
*pos-condicao: a quantidade de playlists cadastradas terá sido retornada
*/
int quantidadePlaylistsCadastradas();

/* Lista as playlists de acordo com o tipo de filtro selecionado
*inputs: tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - nome dono
string, serve para receber uma string, caso queira pesquisar pelo nome da playlist ou dono
*pre-condicao: alguma playlist ter sido cadastrada e o tipo de filtro ser uma opção valida
*pos-condicao: as playlists que satisfazem a consição do filtro serão listadas
*/
void listarPlaylistsFiltro(int tipoFiltro, char* string);

/* Remove uma midia de todas as playlists que ela está
*inputs: o ID da midia que se deseja remover
*pre-condicao: alguma playlist ter sido cadastrada
*pos-condicao: as playlists que possuem o ID da midia nelas, terão essa midia removida, o arquivo de playlists sera atualizado
*/
void removerMidiaTodasPLaylists(int idMidia);

#endif /* PLAYLIST_H */

