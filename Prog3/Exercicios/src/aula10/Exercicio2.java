package aula10;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Exercicio2 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String linha;
        String[] dados;

        int qtd = Integer.parseInt(scan.nextLine());
        List<Formas> formas = new ArrayList<Formas>();

        for (int i = 0; i < qtd; i++) {
            linha = scan.nextLine();
            System.out.print(linha);
            dados = linha.split(",");
            if (dados[0].charAt(0) == 'R')
                formas.add(new Retangulos(Double.parseDouble(dados[1]), Double.parseDouble(dados[2])));
            else if (dados[0].charAt(0) == 'C')
                formas.add(new Circulos(Double.parseDouble(dados[1])));
            else
                formas.add(new Quadrados(Double.parseDouble(dados[1])));
        }

        for (Formas f : formas)
            System.out.println(f.toString());

        scan.close();
    }
}