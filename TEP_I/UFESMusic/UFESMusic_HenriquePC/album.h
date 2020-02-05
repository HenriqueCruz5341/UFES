#ifndef ALBUM_H
#define ALBUM_H
#include "midia.h"

typedef struct album Album;

/* Inicializa um novo album
*inputs: nome do album, matriz de participantes(max 3 linhas), data de lançamento do album
*outpus: ponteiro para um novo album inicializado
*pre-condicao: os parametros devem estar devidamente preenchidos
*pos-condicao: o album de retorno existirá com exatamente os dados que foram passados
*/
Album* inicializaAlbum(char* nome, char participantes[][50], char* dataLancamento);

/* Aloca um espaço na memoria para uma quantidade qtd de albuns sejam armazenadas
*inputs: a quantidade de espaços para albuns que serao alocados
*outpus: o ponteiro para o começo desse espaço para albuns na memoria
*pre-condicao: qtd deve ser diferente de 0
*pos-condicao: o espaço requisitado terá sido alocado
*/
Album* alocarAlbum(int qtd);

/* Modifica o nome de um album
*inputs: o album, e o novo nome para o album
*pre-condicao: album existir
*pos-condicao: o nome do album tera sido modificado
*/
void modificaNomeAlbum(Album* album, char* nNome);

/* Modifica um determinado participante de um album
*inputs: o album, o indice do participante do album, e o novo nome para esse participante
*pre-condicao: album existir, e o indice do participante ser valido
*pos-condicao: um determinado participante do album tera sido modificado
*/
void modificaParticipantesAlbum(Album* album, char* nParticipantes, int pos);

/* Modifica a data de lançamento de um album
*inputs: o album e a nova data de lançamento para esse album
*pre-condicao: album existir
*pos-condicao: a data de lançamento do album tera sido modificada
*/
void modificaDataLancamentoAlbum(Album* album, char* nDataLancamento);

/* Modifica a quantidade de midias de um album
*inputs: o album e a nova quantidade de midias para esse album
*pre-condicao: album existir
*pos-condicao: a quantidade de midias do album tera sido modificada
*/
void modificaQtdMidias(Album* album, int nQtdMidias);

/* Retorna o nome do album
*inputs: o album
*outputs: o nome do album é retornado 
*pre-condicao: album existir
*pos-condicao: o nome do album tera sido modificado
*/
char* pegaNomeAlbum(Album* album);

/* Retorna um determinado participante do album
*inputs: o album, e o indice do participante desejado
*outputs: o nome do participante 'pos' do album
*pre-condicao: album existir
*pos-condicao: album nao é modificado
*/
char* pegaParticipantesAlbum(Album* album, int pos);

/* Retorna a data de lançamento do album
*inputs: o album
*outputs: a data de lançamento do album é retornada
*pre-condicao: album existir
*pos-condicao: album não é modificado
*/
char* pegaDataLancamentoAlbum(Album* album);

/* Retorna a quantidade de midias do album
*inputs: o album
*outputs: a quantidade de midias do album é retornada 
*pre-condicao: album existir
*pos-condicao: album não é modificado
*/
int pegaQtdMidiasAlbum(Album* album);

/* Retorna o ID do album
*inputs: o album
*outputs: o ID do album é retornado 
*pre-condicao: album existir
*pos-condicao: album não é modificado
*/
int pegaIdAlbum(Album* album);

/* Retorna o vetor de IDs das midias que o album possui
*inputs: o album
*outputs: a data de lançamento do album é retornado 
*pre-condicao: album existir
*pos-condicao: album não é modificado
*/
int* pegaMidiaAlbum(Album* album);

/* Imprime os atributos de um album com uma determinada formatação
*inputs: o album
*pre-condicao: album existir
*/
void imprimeAlbum(Album* album);

/*Libera memória alocada para o album
* inputs: o album
* pre-condicao: album existir  
* pos-condicao: toda a memória alocada para o album foi liberada
*/
void destroiAlbum(Album* album);

/* Imprime todos os albuns cadastrados
*outputs: retorna 1 caso tenha conseguido listar, e 0 caso não tenha conseguido
*pre-condicao: algum album ter sido cadastrado
*/
int listarTodosAlbuns();

/* Busca o ID de um album cadastrado no arquivo de albuns
*inputs: o ID do album desejado
*outputs: o album que possui o ID passado
*pre-condicao: ser um ID de um album cadastrado
*pos-condicao: o album com aquele determinado ID terá sido retornado
*/
Album* buscarAlbum(int idAlbum);

/* Salva o album passado no arquivo de albuns
*inputs: o album
*pre-condicao: album existir
*pos-condicao: o album terá sido salvo no arquivo de albuns
*/
void salvarAlbumArquivo(Album* album);

/* Conta quantos albuns foram cadastrados até o momento no arquivo de albuns
*outputs: a quantidade de albuns cadastrados no arquivo de albuns
*pre-condicao: existir um arquivo de albuns
*pos-condicao: a quantidade de albuns cadastrados terá sido retornada
*/
int quantidadeAlbunsCadastrados();

/* Adiciona uma dada midia em um dado album
*inputs: o album que deseja-se adicionar uma midia e a propria midia
*pre-condicao: a midia e album passados devem existir
*pos-condicao: o album terá a midia adicionada a ele e o arquivo de albuns terá sido atualizado
*/
void adicionarMidiasAlbum(Album* album, Midia* midia);

/* Remove uma dada midia em um dado album
*inputs: o album que deseja-se remover uma midia e a propria midia
*pre-condicao: a midia e album passados devem existir, e a midia deve estar no album
*pos-condicao: o album terá a midia removida dele e o arquivo de albuns terá sido atualizado
*/
void removeMidiaAlbum(Album* album, Midia* midia);

/* Atualiza o arquivo de albuns pois algum album sofreu alteração
*inputs: o album cadastrado que sofreu alteração
*pre-condicao: album existir, e já ter sido cadastrado no arquivo
*pos-condicao: o arquivo de albuns terá sido atualizado
*/
void atualizarArquivoAlbuns(Album* album);

/* Imprime todas as midias pertencentes ao album
*inputs: o album que se deseja imprimir as midias
*pre-condicao: album existir, e já ter sido cadastrado no arquivo
*pos-condicao: as midias que o album possui terão sido impressas
*/
void imprimirMidiasAlbum(Album* album);

/* Exclui um album do arquivo de albuns
*inputs: o album que deseja excluir
*pre-condicao: album existir, e já ter sido cadastrado no arquivo
*pos-condicao: o album terá sido removido do arquivo, assim como todas as midias que ele possuia
*/
void excluirAlbumArquivo(Album* album);

/* Pega o  ID do ultimo album cadastrado no arquivo de albuns
*outputs: o ID do ultimo album cadastrado
*pre-condicao: algum album ter sido cadastrado
*pos-condicao: o ID do ultimo album cadastrado terá sido retornado
*/
int pegaUltimoIdAlbumCadastrado();

/* Lista os albuns de acordo com o tipo de filtro selecionado
*inputs: tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - participante, 3 - data de lancamento
string, serve para receber uma string, caso queira pesquisar pelo nome do album por exemplo
*pre-condicao: algum album ter sido cadastrado e o tipo de filtro ser uma opção valida
*pos-condicao: os albuns que satisfazem a condição do filtro serão listados
*/
void listarAlbunsFiltro(int tipoFiltro, char* string);

#endif /* ALBUM_H */

