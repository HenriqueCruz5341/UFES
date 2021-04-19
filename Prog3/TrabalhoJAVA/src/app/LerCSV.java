package app;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class LerCSV {
    /**
     * Esse metodo le as entradas de um arquivo no formato CSV, cria e retorna uma
     * lista candidatos com base nas informacoes da entrada
     * 
     * @param diretorioArquivo string do caminho para o arquivo de entrada
     * @param date             data da eleicao no formato LocalDate
     * @return lista de candidatos
     */
    public static List<Candidato> lerCandidatos(String diretorioArquivo, LocalDate date) {
        List<Candidato> candidatos = new ArrayList<Candidato>();
        BufferedReader buffRead;
        int numCandidato, votosNominais, numPartido;
        String situacao, nomeCandidato, nomeUrna, destinoVoto;
        char sexo;
        LocalDate dataNasc = LocalDate.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        try {
            buffRead = new BufferedReader(new FileReader(diretorioArquivo));
            String linha = buffRead.readLine();

            while (true) {
                linha = buffRead.readLine();
                if (linha != null) {
                    String[] values = linha.split(",");
                    if (values[7].compareTo("Válido") != 0 || values.length < 9) {
                        continue;
                    }
                    numCandidato = Integer.parseInt(values[0]);
                    votosNominais = Integer.parseInt(values[1]);
                    situacao = values[2];
                    nomeCandidato = values[3];
                    nomeUrna = values[4];
                    sexo = values[5].charAt(0);
                    dataNasc = LocalDate.parse(values[6], formatter);
                    destinoVoto = values[7];
                    numPartido = Integer.parseInt(values[8]);
                    Candidato c = new Candidato(numCandidato, votosNominais, situacao, nomeCandidato, nomeUrna, sexo,
                            dataNasc, destinoVoto, numPartido, date);
                    candidatos.add(c);
                } else
                    break;
            }
            buffRead.close();

            return candidatos;

        } catch (FileNotFoundException e) {
            System.out.println("Arquivo de candidatos não encontrado");
            System.exit(0);
        } catch (IOException e) {
            System.out.println("Erro de IO no arquivo de candidato");
            System.exit(0);
        }

        return null;
    }

    /**
     * Esse metodo le as entradas de um arquivo no formato CSV, cria e retorna uma
     * lista de partidos com base nas informacoes da entrada
     * 
     * @param diretorioArquivo string do caminho para o arquivo de entrada
     * @param candidatos       lista com os candidatos da eleicao
     * @return lista de partidos
     */
    public static List<Partido> lerPartidos(String diretorioArquivo, List<Candidato> candidatos) {
        List<Partido> partidos = new ArrayList<Partido>();
        BufferedReader buffRead;
        int numPartido, votosLegenda;
        String nomePartido, siglaPartido;

        try {
            buffRead = new BufferedReader(new FileReader(diretorioArquivo));
            String linha = buffRead.readLine();

            while (true) {
                linha = buffRead.readLine();
                if (linha != null) {
                    String[] values = linha.split(",");
                    if (values.length < 4) {
                        continue;
                    }
                    numPartido = Integer.parseInt(values[0]);
                    votosLegenda = Integer.parseInt(values[1]);
                    nomePartido = values[2];
                    siglaPartido = values[3];
                    Partido p = new Partido(numPartido, votosLegenda, nomePartido, siglaPartido, candidatos);
                    partidos.add(p);
                } else
                    break;
            }
            buffRead.close();

            return partidos;

        } catch (FileNotFoundException e) {
            System.out.println("Arquivo de candidatos não encontrado");
            System.exit(0);
        } catch (IOException e) {
            System.out.println("Erro de IO no arquivo de candidato");
            System.exit(0);
        }

        return null;
    }
}
