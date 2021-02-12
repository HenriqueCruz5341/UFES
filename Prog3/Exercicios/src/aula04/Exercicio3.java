package aula04;

import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;

public class Exercicio3 {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        Locale locale = new Locale("en", "US");
        String nome;

        int qtdAlunos = scan.nextInt();
        Aluno[] alunos = new Aluno[qtdAlunos];

        for (int i = 0; i < qtdAlunos; i++) {
            double[] notas = new double[3];
            nome = scan.next();
            notas[0] = scan.nextDouble();
            notas[1] = scan.nextDouble();
            notas[2] = scan.nextDouble();
            Aluno aluno = new Aluno();
            aluno.setNome(nome);
            aluno.setNotas(notas);
            alunos[i] = aluno;
        }

        double mediaTurma;
        double total = 0;
        for (Aluno a : alunos)
            total += a.calculaMedia();
        mediaTurma = total / qtdAlunos;

        FileWriter arq = new FileWriter("relatorio.csv");
        PrintWriter gravarArq = new PrintWriter(arq);

        gravarArq.println("Nome,Nota,Situacao,Media");
        for (Aluno a : alunos) {
            double mediaAluno = a.calculaMedia();
            if (mediaAluno > 7) {
                if (mediaAluno < mediaTurma) {
                    gravarArq.printf(locale, "%s,%.1f,Aprovado,Abaixo\n", a.getNome(), mediaAluno);
                } else if (mediaAluno == mediaTurma) {
                    gravarArq.printf(locale, "%s,%.1f,Aprovado,Na media\n", a.getNome(), mediaAluno);
                } else {
                    gravarArq.printf(locale, "%s,%.1f,Aprovado,Acima\n", a.getNome(), mediaAluno);
                }
            } else {
                if (mediaAluno < mediaTurma) {
                    gravarArq.printf(locale, "%s,%.1f,Prova Final,Abaixo\n", a.getNome(), mediaAluno);
                } else if (mediaAluno == mediaTurma) {
                    gravarArq.printf(locale, "%s,%.1f,Prova Final,Na media\n", a.getNome(), mediaAluno);
                } else {
                    gravarArq.printf(locale, "%s,%.1f,Prova Final,Acima\n", a.getNome(), mediaAluno);
                }
            }
        }
        arq.close();
        scan.close();
    }
}