package app;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Collections;
import java.util.List;
import java.util.Locale;

public class Seb {
    public static void main(String[] args) {
        // verifica se todos os argumentos nescessarios foram passados
        if (args.length < 3) {
            System.out.println("Poucos argumentos!");
            System.exit(0);
        }

        // cria o formato de data usual do Brasil
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        List<Candidato> candidatos = LerCSV.lerCandidatos(args[0], LocalDate.parse(args[2], formatter));
        List<Partido> partidos = LerCSV.lerPartidos(args[1], candidatos);

        /*
         * configura a localidade para o Brasil para imprimir numeros flutuantes
         * separados por virgula
         */
        Locale locale = new Locale("pt", "BR");

        // ordena a lista de candidatos e partidos
        Collections.sort(candidatos);
        Collections.sort(partidos);

        Eleicao eleicao = new Eleicao(candidatos, partidos);
        List<Candidato> candidatosEleitos = eleicao.retornaCandidatosEleitos();
        List<Candidato> candidatosMaisVotados = eleicao.retornaCandidatosMaisVotados();
        List<Candidato> candidatosSeriamEleitos = eleicao.retornaCandidatosSeriamEleitos(candidatosMaisVotados);
        List<Candidato> candidatosBeneficiados = eleicao.retornaCandidatosBeneficiados(candidatosMaisVotados);

        // relatorio 1
        System.out.println("Número de vagas: " + eleicao.getQtdEleitos() + "\n");

        // relatorio 2
        System.out.println("Vereadores eleitos:");
        imprimeCandidatoFormatado(candidatosEleitos, partidos);

        // relatorio 3
        System.out
                .println("\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
        imprimeCandidatoFormatado(candidatosMaisVotados, partidos);

        // relatorio 4
        System.out.println("\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:");
        System.out.println("(com sua posição no ranking de mais votados)");
        imprimeCandidatoFormatado(candidatosSeriamEleitos, partidos);

        // relatorio 5
        System.out.println("\nEleitos, que se beneficiaram do sistema proporcional:");
        System.out.println("(com sua posição no ranking de mais votados)");
        imprimeCandidatoFormatado(candidatosBeneficiados, partidos);

        // relatorio 6
        System.out.println("\nVotação dos partidos e número de candidatos eleitos:");
        imprimePartidoFormatado(partidos);

        // relatorio 7
        Collections.sort(partidos, new ComparadorPrimeiroCandidato());
        System.out.println("\nPrimeiro e último colocados de cada partido:");
        imprimePrimeiroUltimoFormatado(partidos);

        // relatorio 8
        System.out.println("\nEleitos, por faixa etária (na data da eleição):");
        imprimeFaixaEtaria(locale, eleicao.retornaQtdCandidatosEleitosFaixaEtaria(candidatosEleitos),
                eleicao.getQtdEleitos());

        // relatorio 9
        System.out.println("\nEleitos, por sexo:");
        imprimeSexoCandidato(locale, eleicao.retornaQtdCandidatosSexo(candidatosEleitos), eleicao.getQtdEleitos());

        int votosNominaisTotal = Candidato.votosNominaisTotal;
        int votosLegendaTotal = Partido.votosLegendaTotal;
        int votosValidos = votosLegendaTotal + votosNominaisTotal;

        // relatorio 10
        System.out.printf(locale, "\nTotal de votos válidos:    %d\n", votosValidos);
        System.out.printf(locale, "Total de votos nominais:   %d (%.2f%%)\n", votosNominaisTotal,
                ((float) votosNominaisTotal / votosValidos) * 100);
        System.out.printf(locale, "Total de votos de Legenda: %d (%.2f%%)\n", votosLegendaTotal,
                ((float) votosLegendaTotal / votosValidos) * 100);
    }

    static void imprimeCandidatoFormatado(List<Candidato> candidatos, List<Partido> partidos) {
        int cont = 0;
        for (Candidato c : candidatos) {
            cont++;
            if (c != null) {
                System.out.printf("%d - ", cont);
                System.out.println(c.toString(partidos));
            }
        }
    }

    static void imprimePartidoFormatado(List<Partido> partidos) {
        int cont = 0;
        for (Partido p : partidos) {
            cont++;
            if (p != null) {
                System.out.printf("%d - ", cont);
                System.out.println(p.toString());
            }
        }
    }

    static void imprimePrimeiroUltimoFormatado(List<Partido> partidos) {
        int cont = 0;
        for (Partido p : partidos) {
            cont++;
            if (p != null) {
                String descricao = p.toStringCandidatos();
                if (descricao != null) {
                    System.out.printf("%d - ", cont);
                    System.out.println(descricao);
                }
            }
        }
    }

    static void imprimeFaixaEtaria(Locale local, int[] val, int qtdEleitos) {
        System.out.printf(local, "      Idade < 30: %d (%.2f%%)\n", val[0], ((float) val[0] / qtdEleitos) * 100);
        System.out.printf(local, "30 <= Idade < 40: %d (%.2f%%)\n", val[1], ((float) val[1] / qtdEleitos) * 100);
        System.out.printf(local, "40 <= Idade < 50: %d (%.2f%%)\n", val[2], ((float) val[2] / qtdEleitos) * 100);
        System.out.printf(local, "50 <= Idade < 60: %d (%.2f%%)\n", val[3], ((float) val[3] / qtdEleitos) * 100);
        System.out.printf(local, "60 <= Idade     : %d (%.2f%%)\n", val[4], ((float) val[4] / qtdEleitos) * 100);
    }

    static void imprimeSexoCandidato(Locale local, int[] val, int qtdEleitos) {
        System.out.printf(local, "Feminino:  %d (%.2f%%)\n", val[0], ((float) val[0] / qtdEleitos) * 100);
        System.out.printf(local, "Masculino: %d (%.2f%%)\n", val[1], ((float) val[1] / qtdEleitos) * 100);
    }
}