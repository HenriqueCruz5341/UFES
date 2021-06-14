#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

#include "Date.h"
#include "NumberUtils.h"
#include "candidato.h"
#include "eleicao.h"
#include "lerCSV.h"
#include "partido.h"

using namespace std;

static void imprime_candidato_formatado(const list<Candidato*>& candidatos);

static void imprime_partido_formatado(const list<Partido>& partidos);

static void imprime_primeiro_ultimo_formatado(const list<Partido>& partidos);

static void imprime_faixa_etaria_terminal(int* val, int qtdEleitos);

static void imprime_sexo_candidato_terminal(int* val, int qtdEleitos);

static void imprime_relatorio_10();

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Falta de argumentos!\n");
        exit(1);
    }

    Date now = Date(argv[3]);
    list<Candidato*> candidatos;
    list<Partido> partidos;

    candidatos = LerCSV::ler_candidatos(argv[1], now);
    candidatos.sort(Candidato::comparador);

    partidos = LerCSV::ler_partidos(argv[2], candidatos);
    partidos.sort();

    for (Candidato* c : candidatos) {
        Partido p = Eleicao::retorna_partido_lista(partidos, c->get_num_partido());
        c->set_sigla_partido(p.get_sigla_partido());
    }

    Eleicao eleicao = Eleicao(candidatos, partidos);

    list<Candidato*> candidatos_eleitos = eleicao.retorna_candidatos_eleitos();
    list<Candidato*> candidatos_mais_votados = eleicao.retorna_candidatos_mais_votados();
    list<Candidato*> candidatos_seriam_eleitos = eleicao.retorna_candidatos_seriam_eleitos(candidatos_mais_votados);
    list<Candidato*> candidatos_beneficiados = eleicao.retorna_candidatos_beneficiados(candidatos_mais_votados);

    //relatorio 1
    int qtd_eleitos = eleicao.get_qtd_eleitos();
    cout << "Número de vagas: " << qtd_eleitos << endl
         << endl;

    //relatorio 2
    cout << "Vereadores eleitos:" << endl;
    imprime_candidato_formatado(candidatos_eleitos);
    cout << endl;

    //relatorio 3
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    imprime_candidato_formatado(candidatos_mais_votados);
    cout << endl;

    //relatorio 4
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    imprime_candidato_formatado(candidatos_seriam_eleitos);
    cout << endl;

    //relatorio 5
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    imprime_candidato_formatado(candidatos_beneficiados);
    cout << endl;

    //relatorio 6
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
    imprime_partido_formatado(partidos);
    cout << endl;

    //relatorio 7
    partidos.sort(Partido::comparador_primeiro_candidato);
    cout << "Primeiro e último colocados de cada partido:" << endl;
    imprime_primeiro_ultimo_formatado(partidos);
    cout << endl;

    // relatorio 8
    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
    int* tabela = eleicao.retorna_qtd_candidatos_eleitos_faixa_etaria(candidatos_eleitos);
    imprime_faixa_etaria_terminal(tabela, eleicao.get_qtd_eleitos());
    free(tabela);
    cout << endl;

    //relatorio 9
    cout << "Eleitos, por sexo:" << endl;
    int* tabela2 = eleicao.retorna_qtd_candidatos_sexo(candidatos_eleitos);
    imprime_sexo_candidato_terminal(tabela2, eleicao.get_qtd_eleitos());
    free(tabela2);
    cout << endl;

    // relatorio 10
    imprime_relatorio_10();
    cout << endl;

    //liberar memoria
    for (Candidato* c : candidatos) {
        delete c;
    }
}

static void imprime_candidato_formatado(const list<Candidato*>& candidatos) {
    int cont = 0;
    for (Candidato* c : candidatos) {
        cont++;
        if (c != NULL) {
            cout << cont << " - " << c->to_string() << endl;
        }
    }
}

static void imprime_partido_formatado(const list<Partido>& partidos) {
    int cont = 0;
    for (Partido p : partidos) {
        cont++;
        cout << cont << " - " << p.to_string() << endl;
    }
}

static void imprime_primeiro_ultimo_formatado(const list<Partido>& partidos) {
    int cont = 0;
    for (Partido p : partidos) {
        string descricao = p.to_string_candidatos();
        if (descricao != "") {
            cont++;
            cout << cont << " - " << descricao << endl;
        }
    }
}

static void imprime_faixa_etaria_terminal(int* val, int qtdEleitos) {
    cout << "      Idade < 30: " << val[0] << " (" << formatDouble(((double)val[0] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
    cout << "30 <= Idade < 40: " << val[1] << " (" << formatDouble(((double)val[1] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
    cout << "40 <= Idade < 50: " << val[2] << " (" << formatDouble(((double)val[2] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
    cout << "50 <= Idade < 60: " << val[3] << " (" << formatDouble(((double)val[3] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
    cout << "60 <= Idade     : " << val[4] << " (" << formatDouble(((double)val[4] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
}

static void imprime_sexo_candidato_terminal(int* val, int qtdEleitos) {
    cout << "Feminino:  " << val[0] << " (" << formatDouble(((double)val[0] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
    cout << "Masculino: " << val[1] << " (" << formatDouble(((double)val[1] / qtdEleitos) * 100, LOCALE_PT_BR) << "%)" << endl;
}

static void imprime_relatorio_10() {
    int votos_nominais_total = Candidato::votos_nominais_total;
    int votos_legenda_total = Partido::votos_legenda_total;
    int votos_validos = votos_legenda_total + votos_nominais_total;

    cout << "Total de votos válidos:    " << votos_validos << endl;
    cout << "Total de votos nominais:   " << votos_nominais_total << " (" << formatDouble(((double)votos_nominais_total / votos_validos) * 100, LOCALE_PT_BR) << "%)" << endl;
    cout << "Total de votos de Legenda: " << votos_legenda_total << " (" << formatDouble(((double)votos_legenda_total / votos_validos) * 100, LOCALE_PT_BR) << "%)" << endl;
}