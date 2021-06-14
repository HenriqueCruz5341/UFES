#include "eleicao.h"

Eleicao::Eleicao(list<Candidato*> candidatos, list<Partido> partidos) {
    this->candidatos = candidatos;
    this->partidos = partidos;
    this->qtd_candidados = candidatos.size();
    this->qtd_partidos = partidos.size();
}

//Tentamos passar partidos como const, porém dava erro de compilação e não soubemos resolver
Partido Eleicao::retorna_partido_lista(list<Partido>& partidos, int num_partido) {
    Partido partido;

    for (Partido& p : partidos) {
        if (p.get_num_partido() == num_partido) {
            return p;

            break;
        }
    }
    return partido;
}

list<Candidato*> Eleicao::retorna_candidatos_eleitos() {
    list<Candidato*> candidatos_eleitos;
    int cont = 0;

    for (Candidato* c : this->candidatos) {
        if (c->get_situacao() == "Eleito") {
            candidatos_eleitos.push_back(c);
            cont++;
        }
    }

    this->qtd_eleitos = cont;

    return candidatos_eleitos;
}

list<Candidato*> Eleicao::retorna_candidatos_mais_votados() {
    list<Candidato*> candidatos_mais_votados;
    int cont = 0;

    for (Candidato* c : this->candidatos) {
        if (cont < this->qtd_eleitos) {
            candidatos_mais_votados.push_back(c);
            cont++;
        } else if (cont == this->qtd_eleitos)
            break;
    }

    return candidatos_mais_votados;
}

list<Candidato*> Eleicao::retorna_candidatos_seriam_eleitos(const list<Candidato*>& candidatos_mais_votados) {
    list<Candidato*> candidatos_seriam_eleitos;

    for (Candidato* cmv : candidatos_mais_votados) {
        if (cmv->get_situacao() == "Eleito")
            candidatos_seriam_eleitos.push_back(NULL);  // Coloca-se NULL, para que os candidatos preservem suas colocações
        else
            candidatos_seriam_eleitos.push_back(cmv);
    }

    return candidatos_seriam_eleitos;
}

list<Candidato*> Eleicao::retorna_candidatos_beneficiados(const list<Candidato*>& candidatos_mais_votados) {
    list<Candidato*> candidatos_beneficiados;
    bool encontrou;

    for (Candidato* c : this->candidatos) {
        encontrou = false;
        if (c->get_situacao() == "Eleito") {
            for (Candidato* cmv : candidatos_mais_votados) {
                if (c->get_numero() == cmv->get_numero()) {
                    encontrou = true;
                    break;
                }
            }
            if (encontrou)
                candidatos_beneficiados.push_back(NULL);  // Coloca-se NULL, para que os candidatos preservem suas colocações
            else
                candidatos_beneficiados.push_back(c);
        } else
            candidatos_beneficiados.push_back(NULL);  // Coloca-se NULL, para que os candidatos preservem suas colocações
    }

    return candidatos_beneficiados;
}

int* Eleicao::retorna_qtd_candidatos_eleitos_faixa_etaria(const list<Candidato*>& candidatos_eleitos) {
    int* qtd_candidatos_faixa_etaria = (int*)malloc(sizeof(int) * 5);
    int qtd;
    bool limite_idade;

    for (int i = 30, j = 0, k = 0; k < 5; i += 10, j = i - 10, k++) {
        qtd = 0;
        for (Candidato* ce : candidatos_eleitos) {
            limite_idade = (i > 60) ? true : (ce->get_idade() < i);
            if (ce->get_idade() >= j && limite_idade) {
                qtd++;
            }
        }
        qtd_candidatos_faixa_etaria[k] = qtd;
    }
    return qtd_candidatos_faixa_etaria;
}

//erroooooo
int* Eleicao::retorna_qtd_candidatos_sexo(const list<Candidato*>& candidatos_eleitos) {
    int mas = 0;
    int fem = 0;

    int* qtd_por_sexo = (int*)malloc(sizeof(int) * 2);

    for (Candidato* c : candidatos_eleitos) {
        if (c->get_sexo() == 'F')
            fem++;
        if (c->get_sexo() == 'M')
            mas++;
    }
    qtd_por_sexo[0] = fem;
    qtd_por_sexo[1] = mas;

    return qtd_por_sexo;
}

int Eleicao::get_qtd_eleitos() const {
    return this->qtd_eleitos;
}

list<Candidato*> Eleicao::get_candidatos() const {
    return this->candidatos;
}

list<Partido> Eleicao::get_partidos() const {
    return this->partidos;
}

int Eleicao::get_qtd_candidados() const {
    return this->qtd_candidados;
}

int Eleicao::get_qtd_partidos() const {
    return this->qtd_candidados;
}

Eleicao::~Eleicao() {
}