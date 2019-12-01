#ifndef MIDIA_H
#define MIDIA_H

typedef struct midia Midia;

/* Inicializa uma nova midia
*inputs: nome da midia, tipo da midia(0 musica, 1 video), nomes dos compositoes e artistas (no maximo 3 de cada), genero da midia, gravadora da midia, duracao da midia,
identificador do album que a midia pertence
*outpus: ponteiro para uma midia inicializada
*pre-condicao: os parametros devem estar devidamente preenchidos
*pos-condicao: a midia de retorno existirá com exatamente os dados que foram passados
*/
Midia* inicializaMidia(char* nome, int tipo, char compositores[][50], 
    char artistas[][50], char* genero, char* gravadora, char* duracao, int idAlbum);

/* Aloca um espaço na memoria para uma quantidade qtd de midias sejam armazenadas
*inputs: a quantidade de espaços para midias que serao alocadas
*outpus: o ponteiro para o começo desse espaço para midias na memoria
*pre-condicao: qtd deve ser diferente de 0
*pos-condicao: o espaço requisitado terá sido alocado
*/
Midia* alocarMidia(int qtd);

/* Modifica o nome de uma midia
*inputs: a midia, e o novo nome para a midia passada
*pre-condicao: midia existir
*pos-condicao: o nome da midia tera sido modificado
*/
void modificaNomeMidia(Midia* midia, char* nNome);

/* Modifica o tipo de uma midia
*inputs: a midia, e um inteiro que represanta o novo tipo da midia
*pre-condicao: midia existir
*pos-condicao: o tipo da midia tera sido modificado
*/
void modificaTipoMidia(Midia* midia, int nTipo);

/* Modifica um determinado compositor de uma midia
*inputs: a midia, o indice do compositor da midia, e o novo nome para esse compisitor
*pre-condicao: midia existir, e o indice do compositor ser valido
*pos-condicao: um determinado compositor da midia tera sido modificado
*/
void modificaCompositoresMidia(Midia* midia, char* nCompositor, int pos);

/* Modifica um determinado artista de uma midia
*inputs: a midia, o indice do artista da midia, e o novo nome para esse artista
*pre-condicao: midia existir, e o indice do artista ser valido
*pos-condicao: um determinado artista da midia tera sido modificado
*/
void modificaArtistasMidia(Midia* midia, char* nArtista, int pos);

/* Modifica o genero de uma midia
*inputs: a midia e o novo genero da midia
*pre-condicao: midia existir
*pos-condicao: o genero da midia tera sido modificado
*/
void modificaGeneroMidia(Midia* midia, char* nGenero);

/* Modifica a gravadora de uma midia
*inputs: a midia e a nova gravadora da midia
*pre-condicao: midia existir
*pos-condicao: a gravadora da midia tera sido modificado
*/
void modificaGravadoraMidia(Midia* midia, char* nGravadora);

/* Modifica a duração de uma midia
*inputs: a midia e a nova duração da midia
*pre-condicao: midia existir
*pos-condicao: a duração da midia tera sido modificado
*/
void modificaDuracaoMidia(Midia* midia, char* nDuracao);

/* Retorna o nome da midia
*inputs: a midia
*outputs: o nome da midia é retornado
*pre-condicao: midia existir
*pos-condicao: o nome da midia tera sido modificado
*/
char* pegaNomeMidia(Midia* midia);

/* Retorna o tipo da midia
*inputs: a midia
*outputs: o nome da midia é retornado 
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
int pegaTipoMidia(Midia* midia);

/* Retorna um determinado compositor da midia
*inputs: a midia, e o indice do compositor desejado
*outputs: o nome do compositor 'pos' da midia
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
char* pegaCompositoresMidia(Midia* midia, int pos);

/* Retorna um determinado artista da midia
*inputs: a midia, e o indice do artista desejado
*outputs: o nome do artista 'pos' da midia
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
char* pegaArtistasMidia(Midia* midia, int pos);

/* Retorna o genero da midia
*inputs: a midia
*outputs: o genero da midia é retornado
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
char* pegaGeneroMidia(Midia* midia);

/* Retorna a gravadora da midia
*inputs: a midia
*outputs: a gravadora da midia é retornada 
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
char* pegaGravadoraMidia(Midia* midia);

/* Retorna a duracao da midia
*inputs: a midia
*outputs: a duracao da midia é retornada 
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
char* pegaDuracaoMidia(Midia* midia);

/* Retorna o ID da midia
*inputs: a midia
*outputs: o ID da midia é retornado
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
int pegaIdMidia(Midia* midia);

/* Retorna o ID do album que a midia pertence
*inputs: a midia
*outputs: o ID do album que a midia pertence 
*pre-condicao: midia existir
*pos-condicao: midia nao é modificada
*/
int pegaAlbumMidia(Midia *midia);

/* Imprime os atributos de uma midia com uma determinada formatação
*inputs: a midia
*pre-condicao: midia existir
*/
void imprimeMidia(Midia* midia);

/*Libera memória alocada para a midia
* inputs: a midia
* pre-condicao: midia existir  
* pos-condicao: toda a memória alocada para midia foi liberada
*/
void destroiMidia(Midia* midia);

/* Imprime todas as midias cadastradas
*outputs: retorna 1 caso tenha conseguido listar, e 0 caso não tenha conseguido
*pre-condicao: alguma midia ter sido cadastrada
*/
int listarTodasMidias();

/* Buscar o ID de uma midia cadastrada no arquivo de midias
*inputs: o ID da midia desejada
*outputs: a midia que possui o ID passado
*pre-condicao: ser um ID de uma midia cadastrada
*pos-condicao: a midia com aquele determinado ID terá sido retornada
*/
Midia* buscarMidia(int idMidia);

/* Salva a midia passada no arquivo de midias
*inputs: a midia
*pre-condicao: midia existir
*pos-condicao: a midia terá sido salva no arquivo de midias
*/
void salvarMidiaArquivo(Midia* midia);

/* Conta quantas midias foram cadastradas até o momento no arquivo de midias
*outputs: a quantidade de midias cadastradas no arquivo de midias
*pre-condicao: existir um arquivo de midias
*pos-condicao: a quantidade de midias cadastradas terá sido retornada
*/
int quantidadeMidiasCadastradas();

/* Atualiza o arquivo de midias pois alguma midia sofreu alteração
*inputs: a midia cadastrada que sofreu alteração
*pre-condicao: midia existir, e já ter sido cadastrada no arquivo
*pos-condicao: o arquivo de midias terá sido atualizado
*/
void atualizarArquivoMidias(Midia* midia);

/* Exclui uma midia do arquivo de midias
*inputs: a midia que deseja excluir, e se essa exclusão esta sendo por excluir um album inteiro, ou apenas a midia desejada
*pre-condicao: midia existir, e já ter sido cadastrada no arquivo
*pos-condicao: a midia terá sido removida do arquivo, e todas as playlist que possuiam a midia, terão a midia removida
*/
void excluirMidiaArquivo(Midia* midia, int excluindoAlbum);

/* Pega o  ID da ultima midia cadastrado no arquivo de midias
*outputs: o ID da ultima midia cadastrada
*pre-condicao: alguma midia ter sido cadastrada
*pos-condicao: o ID da ultima midia cadastrada terá sido retornado
*/
int pegaUltimoIdMidiaCadastrado();

/* Lista as midias de acordo com o tipo de filtro selecionado
*inputs: tipoFiltro, serve para escolhe pelo que filtrar, 1 - nome, 2 - tipo, 3 - compositor, 4 - artista, 5 - genero, 6 - gravadora, 7 - nome do album
string, serve para receber uma string, caso queira pesquisar pelo nome da midia por exemplo
numero, serve para receber um numero, caso queira pesquisar pelo tipo da midia
*pre-condicao: alguma midia ter sido cadastrada e o tipo de filtro ser uma opção valida
*pos-condicao: as midias que satisfazem a consição do filtro serão listadas
*/
void listarMidiasFiltro(int tipoFiltro, char* string, int numero);

#endif /* MIDIA_H */

