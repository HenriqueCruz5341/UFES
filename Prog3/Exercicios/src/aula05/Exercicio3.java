package aula05;

import java.util.Scanner;

public class Exercicio3 {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String string;

        do {
            string = scan.nextLine();
            Cliente cliente = new Cliente(string);
            do {
                string = scan.nextLine();
                cliente.setCpf(string);
            } while (string.compareTo("+") != 0 && string.compareTo(".") != 0);
            System.out.println(cliente.getNome() + " " + (cliente.getCpf() != null ? cliente.getCpf() : ""));
        } while (string.compareTo("+") == 0);

        scan.close();
    }

}
