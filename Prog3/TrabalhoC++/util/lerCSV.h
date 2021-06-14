#ifndef LERCSV_H
#define LERCSV_H

#include <time.h>

#include <list>
#include <string>

#include "../candidato.h"
#include "../partido.h"
#include "Date.h"

using namespace std;

class LerCSV {
   public:
    LerCSV();

    /**
     * Esse metodo le as entradas de um arquivo no formato CSV, cria e retorna uma
     * lista candidatos com base nas informacoes da entrada
     * 
     * @param diretorioArquivo string do caminho para o arquivo de entrada
     * @param date             data da eleicao no formato Date
     * @return lista de candidatos
     */
    static list<Candidato*> ler_candidatos(const string& diretorio_arquivo, const Date& date);

    /**
     * Esse metodo le as entradas de um arquivo no formato CSV, cria e retorna uma
     * lista de partidos com base nas informacoes da entrada
     * 
     * @param diretorioArquivo string do caminho para o arquivo de entrada
     * @param candidatos       lista com os candidatos da eleicao
     * @return lista de partidos
     */
    static list<Partido> ler_partidos(const string& diretorio_arquivo, const list<Candidato*>& candidatos);

    ~LerCSV();
};

#endif  //LERCSV_H