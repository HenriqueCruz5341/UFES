#include "candidato.h"

#include "eleicao.h"

using namespace std;

int Candidato::votos_nominais_total = 0;

Candidato::Candidato() {
    this->numero = -1;
}

Candidato::Candidato(const Candidato& c) {
    this->numero = c.numero;
    this->votos_nominais = c.votos_nominais;
    this->situacao = c.situacao;
    this->nome = c.nome;
    this->nome_urna = c.nome_urna;
    this->sexo = c.sexo;
    this->data_nasc = c.data_nasc;
    this->idade = c.idade;
    this->destino_voto = c.destino_voto;
    this->num_partido = c.num_partido;
    this->sigla_partido = c.sigla_partido;
}

Candidato::Candidato(int numero, int votos_nominais, const string& situacao,
                     const string& nome, const string& nome_urna, char sexo,
                     const Date& data_nasc, const string& destino_voto, int num_partido,
                     const Date& data) {
    this->numero = numero;
    this->votos_nominais = votos_nominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nome_urna = nome_urna;
    this->sexo = sexo;
    this->data_nasc = data_nasc;
    this->idade = data_nasc.calc_age(data_nasc, data);
    this->destino_voto = destino_voto;
    this->num_partido = num_partido;
    this->sigla_partido = "";
    votos_nominais_total += votos_nominais;
}

int Candidato::get_numero() const {
    return this->numero;
}

int Candidato::get_idade() const {
    return this->idade;
}

int Candidato::get_num_partido() const {
    return this->num_partido;
}

string Candidato::get_situacao() const {
    return this->situacao;
}

char Candidato::get_sexo() const {
    return this->sexo;
}

string Candidato::get_nome_urna() const {
    return this->nome_urna;
}

int Candidato::get_votos_nominais() const {
    return this->votos_nominais;
}

void Candidato::set_sigla_partido(const string& sigla_partido) {
    this->sigla_partido = sigla_partido;
}

string Candidato::get_sigla_partido() {
    return this->sigla_partido;
}

Candidato& Candidato::operator=(const Candidato& c) {
    this->numero = c.numero;
    this->votos_nominais = c.votos_nominais;
    this->situacao = c.situacao;
    this->nome = c.nome;
    this->nome_urna = c.nome_urna;
    this->sexo = c.sexo;
    this->data_nasc = c.data_nasc;
    this->idade = c.idade;
    this->destino_voto = c.destino_voto;
    this->num_partido = c.num_partido;
    this->sigla_partido = c.sigla_partido;

    return *this;
}

bool Candidato::comparador(const Candidato* esq, const Candidato* dir) {
    int dif_votos = dir->votos_nominais - esq->votos_nominais;
    if (dif_votos == 0)
        return esq->data_nasc < dir->data_nasc;
    return dif_votos < 0;
}

bool Candidato::valido() const {
    return this->numero >= 0 ? true : false;
}

string Candidato::to_string() const {
    string str1 = this->nome + " / " + this->nome_urna + " (";
    string votos_nominais = std::to_string(this->votos_nominais);
    string str2 = this->sigla_partido + ", " + votos_nominais + " ";
    string str3 = this->votos_nominais <= 1 ? "voto)" : "votos)";
    string saida = str1 + str2 + str3;

    return saida;
}

Candidato::~Candidato() {
}
