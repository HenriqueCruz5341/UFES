#ifndef ELEICAO_H
#define ELEICAO_H

#include "candidato.h"
#include "list"
#include "partido.h"

using namespace std;

/**
 * A classe Eleição representa um evento de seleção, é responsável por gerar os
 * relatórios e tem todas as informações necessárias para isso
 */
class Eleicao {
   private:
    int qtd_eleitos;
    list<Candidato*> candidatos;
    list<Partido> partidos;
    int qtd_candidados;
    int qtd_partidos;

   public:
    Eleicao(list<Candidato*> candidatos, list<Partido> partidos);

    /**
     * Essa função serve para procurar um partido dentro de uma lista de partidos
     *
     * @param partidos   A lista de partidos onde deseja-se realizar a busca
     * @param numPartido O número do partido que está sendo buscado
     * @return Caso o partido seja encontrado dentro da lista, ele é retornado, caso
     *         contrário, é retornado um ponteiro NULL
     */
    static Partido retorna_partido_lista(list<Partido>& partidos, int num_partido);

    /**
     * Essa função serve para encontrar os candidados eleitos daquela eleição, além
     * disso ela atualiza o atributo de qtdEleitos de Eleição
     * 
     * @return Retorna uma lista dos candidados eleitos
     */
    list<Candidato*> retorna_candidatos_eleitos();

    /**
     * Essa função serve para encontrar os N (N = qtdEleitos), candidatos mais
     * votados
     * 
     * @return Retorna uma lista dos candidados mais votados
     */
    list<Candidato*> retorna_candidatos_mais_votados();

    /**
     * Essa função serve para encontrar os candidatos que seriam eleitos caso o
     * sistema de votação levasse em conta apenas os votos nominais
     * 
     * @param candidatosMaisVotados Lista dos candidados mais votados
     * @return Retorna uma lista com os candidados que seriam eleitos caso o sistema
     *         levasse em conta apenas os votos nominais
     */
    list<Candidato*> retorna_candidatos_seriam_eleitos(const list<Candidato*>& candidatos_mais_votados);

    /**
     * Essa função serve para encontrar os candidatos que foram eleitos se
     * beneficiando do sistema proporcional
     * 
     * @param candidatosMaisVotados Lista dos candidados mais votados
     * @return Retorna uma lista com os candidados que não estão na lista de mais
     *         votados, mas foram eleitos graças ao sistema proporcional
     */
    list<Candidato*> retorna_candidatos_beneficiados(const list<Candidato*>& candidatos_mais_votados);

    /**
     * Essa função serve para calcular as quantidades de candidatos eleitos por
     * faixa etária
     * 
     * @param candidatosEleitos Lista dos candidados eleitos
     * @return retorna um vetor de inteiros com a quantidade de candidatos eleitos
     *         em cada intervalo de faixa etária, ou seja, a posição 0 são
     *         candidados entre 30 e 40 anos, a posição 1 de 40 a 50 e assim por
     *         diante
     * 
     */
    int* retorna_qtd_candidatos_eleitos_faixa_etaria(const list<Candidato*>& candidatos_eleitos);

    /**
     * Essa função serve para calcular as quantidades de candidatos eleitos por sexo
     * 
     * @param candidatosEleitos Lista dos candidados eleitos
     * @return retorna um vetor de inteiros com a quantidade de candidatos eleitos
     *         do sexo masculino e feminino, sendo a posição 0 do vetor o sexo
     *         feminino e a posição 1 o sexo masculino
     * 
     */
    int* retorna_qtd_candidatos_sexo(const list<Candidato*>& candidatos_eleitos);

    int get_qtd_eleitos() const;

    list<Candidato*> get_candidatos() const;

    list<Partido> get_partidos() const;

    int get_qtd_candidados() const;

    int get_qtd_partidos() const;

    ~Eleicao();
};

#endif  //ELEICAO_H