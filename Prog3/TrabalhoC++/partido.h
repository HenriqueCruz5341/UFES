#ifndef PARTIDO_H
#define PARTIDO_H
#include <list>
#include <string>

#include "candidato.h"

using namespace std;

/**
 * A classe Partido representa um partido na eleicao
 */
class Partido {
   private:
    int num_partido;
    int qtd_candidatos_eleitos;
    int votos_nominais;
    int votos_legenda;
    string nome_partido;
    string sigla_partido;
    list<Candidato*> candidatos;

    /**
     * Esse metodo percorre a lista de candidatos enviada como parametro e, retorna
     * uma lista de candidatos do mesmo partido.
     * 
     * @param candidatos lista de todos candidatos
     * @return lista de candidatos do mesmo partido
     */
    list<Candidato*> retorna_candidatos_partido(const list<Candidato*>& candidatos);

    /**
     * Esse metodo percorre a lista de candidatos local e retorna a quantidade de
     * candidatos eleitos desse partido.
     * 
     * @return quantidade de candidatos eleitos no partido
     */
    int retorna_qtd_eleitos() const;

    /**
     * Esse metodo percorre a lista de candidatos local e retorna o total de votos
     * nominais de segundo essa lista.
     * 
     * @return quantidade de votos nominais total de um partido
     */
    int retorna_qtd_votos_nominais() const;

   public:
    static int votos_legenda_total;

    Partido();
    Partido(int num_partido, int votos_legenda, const string& nome_partido,
            const string& sigla_partido, const list<Candidato*>& candidatos);

    int get_num_partido() const;
    int get_qtd_candidados_eleitos() const;
    int get_votos_legenda() const;
    string get_nome_partido() const;
    string get_sigla_partido() const;
    list<Candidato*> get_candidatos() const;
    static bool comparador_primeiro_candidato(const Partido& esq, const Partido& dir);
    bool operator<(const Partido& p) const;
    string to_string() const;
    string to_string_candidatos() const;

    ~Partido();
};

#endif  //PARTIDO_H
