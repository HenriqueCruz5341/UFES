#include "partido.h"

#include <iostream>

int Partido::votos_legenda_total = 0;

Partido::Partido() {
}

Partido::Partido(int num_partido, int votos_legenda, const string& nome_partido,
                 const string& sigla_partido, const list<Candidato*>& candidatos) {
    this->num_partido = num_partido;
    this->votos_legenda = votos_legenda;
    this->nome_partido = nome_partido;
    this->sigla_partido = sigla_partido;
    this->candidatos = retorna_candidatos_partido(candidatos);
    this->qtd_candidatos_eleitos = retorna_qtd_eleitos();
    this->votos_nominais = retorna_qtd_votos_nominais();
    votos_legenda_total += votos_legenda;
}

//lembrar de arruamr referencia no final do trabalho
list<Candidato*> Partido::retorna_candidatos_partido(const list<Candidato*>& candidatos) {
    list<Candidato*> candidatos_partido;

    for (Candidato* c : candidatos) {
        if (c->get_num_partido() == this->num_partido)
            candidatos_partido.push_back(c);
    }

    return candidatos_partido;
}

int Partido::retorna_qtd_eleitos() const {
    int cont = 0;
    for (Candidato* c : this->candidatos) {
        if (!c->get_situacao().compare("Eleito"))
            cont++;
    }

    return cont;
}

int Partido::retorna_qtd_votos_nominais() const {
    int qtd = 0;
    for (Candidato* c : this->candidatos) {
        qtd += c->get_votos_nominais();
    }

    return qtd;
}

int Partido::get_num_partido() const {
    return this->num_partido;
}

int Partido::get_qtd_candidados_eleitos() const {
    return this->qtd_candidatos_eleitos;
}

int Partido::get_votos_legenda() const {
    return this->votos_legenda;
}

string Partido::get_nome_partido() const {
    return this->nome_partido;
}

string Partido::get_sigla_partido() const {
    return this->sigla_partido;
}

list<Candidato*> Partido::get_candidatos() const {
    return this->candidatos;
}

bool Partido::comparador_primeiro_candidato(const Partido& esq, const Partido& dir) {
    int tam_lista_candidatos_partido1 = esq.get_candidatos().size();
    int tam_lista_candidatos_partido2 = dir.get_candidatos().size();

    if (tam_lista_candidatos_partido1 > 0 && tam_lista_candidatos_partido2 > 0) {
        Candidato* primeiro_p1 = esq.get_candidatos().front();
        Candidato* primeiro_p2 = dir.get_candidatos().front();

        int comp = primeiro_p2->get_votos_nominais() - primeiro_p1->get_votos_nominais();
        if (comp == 0) {
            return esq.get_num_partido() < dir.get_num_partido();
        }
        return primeiro_p2->get_votos_nominais() < primeiro_p1->get_votos_nominais();
    } else if (tam_lista_candidatos_partido1 > 0 && !(tam_lista_candidatos_partido2 > 0)) {
        return false;
    }
    return true;
}

bool Partido::operator<(const Partido& p) const {
    int total_votos_this = this->votos_nominais + this->votos_legenda;
    int total_votos_outro = p.votos_nominais + p.votos_legenda;
    if (total_votos_outro - total_votos_this == 0) {
        return this->num_partido < p.num_partido;
    }
    return total_votos_outro < total_votos_this;
}

string Partido::to_string() const {
    int votos_totais = this->votos_legenda + this->votos_nominais;
    string sub1 = this->sigla_partido + " - " + std::to_string(this->num_partido) + ",";
    string sub2 = " " + std::to_string(votos_totais) + " " + (votos_totais <= 1 ? "voto" : "votos");
    string sub3 = " (" + std::to_string(this->votos_nominais) + " " + (this->votos_nominais <= 1 ? "nominal" : "nominais");
    string sub4 = " e " + std::to_string(this->votos_legenda) + " de legenda),";
    string sub5 = " " + std::to_string(this->qtd_candidatos_eleitos) + (this->qtd_candidatos_eleitos <= 1 ? " candidato eleito" : " candidatos eleitos");
    string saida = sub1 + sub2 + sub3 + sub4 + sub5;

    return saida;
}

string Partido::to_string_candidatos() const {
    if (this->candidatos.size() <= 0)
        return "";

    Candidato* primeiro = this->candidatos.front();
    Candidato* ultimo = this->candidatos.back();

    string str1 = this->sigla_partido + " - " + std::to_string(this->num_partido) + ", " + primeiro->get_nome_urna();
    string str2 = " (" + std::to_string(primeiro->get_numero()) + ", " + std::to_string(primeiro->get_votos_nominais());
    string str3 = (primeiro->get_votos_nominais() <= 1 ? (" voto) / ") : (" votos) / ")) + ultimo->get_nome_urna();
    string str4 = " (" + std::to_string(ultimo->get_numero()) + ", " + std::to_string(ultimo->get_votos_nominais());
    string str5 = (ultimo->get_votos_nominais() <= 1 ? " voto)" : " votos)");
    string saida = str1 + str2 + str3 + str4 + str5;

    return saida;
}

Partido::~Partido() {
}