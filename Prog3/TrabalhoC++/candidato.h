#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <time.h>

#include <list>
#include <string>

#include "Date.h"

using namespace std;

/**
 * A classe Candidato representa um vereador na votacao
 */
class Candidato {
   private:
    int numero;
    int votos_nominais;
    string situacao;
    string nome;
    string nome_urna;
    char sexo;
    int idade;
    string destino_voto;
    int num_partido;
    Date data_nasc;
    string sigla_partido;

   public:
    static int votos_nominais_total;

    Candidato();

    Candidato(bool valid);

    Candidato(const Candidato& c);

    Candidato(int numero, int votos_nominais, const string& situacao, const string& nome, const string& nome_urna, char sexo,
              const Date& data_nasc, const string& destino_voto, int num_partido, const Date& data);

    int get_numero() const;

    int get_idade() const;

    int get_num_partido() const;

    string get_situacao() const;

    int get_votos_nominais() const;

    char get_sexo() const;

    string get_nome_urna() const;

    void set_sigla_partido(const string& sigla_partido);

    string get_sigla_partido();

    Candidato& operator=(const Candidato& c);

    static bool comparador(const Candidato* esq, const Candidato* dir);

    bool valido() const;

    string to_string() const;

    ~Candidato();
};

#endif  //CANDIDATO_H