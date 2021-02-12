package aula02;

import java.util.Scanner;

public class Exercicio4 {
	public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num, a = 0, b = 1, seq;

        num = scan.nextInt();
        scan.close();

        if (num >= 0) {
            System.out.print(a + " ");
            if (num > 1) {
                System.out.print(b + " ");
                for (int i = 2; i < num; i++) {
                    seq = a + b;
                    a = b;
                    b = seq;
                    System.out.print(seq + " ");
                }
            }
            System.out.println("");
        }
    }
}
