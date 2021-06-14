#include "lerCSV.h"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "FileNotFoundException.h"

LerCSV::LerCSV() {
}

list<Candidato*> LerCSV::ler_candidatos(const string& diretorio_arquivo, const Date& date) {
    list<Candidato*> candidatos;
    int num_candidato, votos_nominais, num_partido;
    string situacao, nome_candidato, nome_urna, destino_voto;
    char sexo;
    string linha;
    Date data_nasc;
    string values[9];

    try {
        ifstream in(diretorio_arquivo);
        if (!in) throw FileNotFoundException(diretorio_arquivo);
        getline(in, linha);
        while (getline(in, linha)) {
            if (!linha.empty()) {
                stringstream check1(linha);
                string intermediate;
                for (int i = 0; getline(check1, intermediate, ','); i++)
                    values[i] = intermediate;

                num_candidato = stoi(values[0]);
                votos_nominais = stoi(values[1]);
                situacao = values[2];
                nome_candidato = values[3];
                nome_urna = values[4];
                sexo = values[5][0];
                data_nasc = Date(values[6]);
                destino_voto = values[7];
                if (destino_voto != "Válido")
                    continue;
                num_partido = stoi(values[8]);
                // cout << "Candidato " << count << ": " << num_candidato << " " << votos_nominais << " " << situacao << " " << nome_candidato << " " << nome_urna << " " << sexo << " " << data_nasc.to_string() << " " << destino_voto << " " << num_partido << endl;
                Candidato* c = new Candidato(num_candidato, votos_nominais, situacao, nome_candidato, nome_urna, sexo,
                                             data_nasc, destino_voto, num_partido, date);
                candidatos.push_back(c);
            } else
                break;
        }
        in.close();
    } catch (FileNotFoundException e) {
        cout << "Arquivo " << e.get_message() << " não encontrado" << endl;
        exit(1);
    }

    return candidatos;
}

list<Partido> LerCSV::ler_partidos(const string& diretorio_arquivo, const list<Candidato*>& candidatos) {
    list<Partido> partidos;
    int num_partido, votos_legenda;
    string nome_partido, sigla_partido;
    string linha;
    string values[4];

    try {
        ifstream in(diretorio_arquivo);
        if (!in) throw FileNotFoundException(diretorio_arquivo);
        getline(in, linha);
        while (getline(in, linha)) {
            if (!linha.empty()) {
                stringstream check1(linha);
                string intermediate;
                for (int i = 0; getline(check1, intermediate, ','); i++)
                    values[i] = intermediate;

                num_partido = stoi(values[0]);
                votos_legenda = stoi(values[1]);
                nome_partido = values[2];
                sigla_partido = values[3];
                // cout << "Partido " << count << ": " << num_partido << " " << votos_legenda << " " << nome_partido << " " << sigla_partido << endl;
                Partido p = Partido(num_partido, votos_legenda, nome_partido, sigla_partido, candidatos);
                partidos.push_back(p);
            } else
                break;
        }
        in.close();
    } catch (FileNotFoundException e) {
        cout << "Arquivo " << e.get_message() << " não encontrado" << endl;
        exit(1);
    }
    return partidos;
}

LerCSV::~LerCSV() {
}
