package aula10;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Exercicio1 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String linha;
        String[] dados;

        int qtd = Integer.parseInt(scan.nextLine());
        List<Produto> produtos = new ArrayList<Produto>();

        for (int i = 0; i < qtd; i++) {
            linha = scan.nextLine();
            System.out.print(linha);
            dados = linha.split(",");
            if (dados[0].charAt(0) == 'C')
                produtos.add(new CDs(dados[1], Float.parseFloat(dados[2]), Integer.parseInt(dados[3])));
            else if (dados[0].charAt(0) == 'D')
                produtos.add(new DVDs(dados[1], Float.parseFloat(dados[2]), Integer.parseInt(dados[3])));
            else
                produtos.add(new Livros(dados[1], Float.parseFloat(dados[2]), dados[3]));
        }

        Collections.sort(produtos);

        for (Produto p : produtos)
            System.out.println(p.toString());

        scan.close();
    }
}