package aula02;

import java.util.Scanner;

public class Exercicio3 {
	public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num1, num2, dif;

        num1 = scan.nextInt();
        num2 = scan.nextInt();
        
        scan.close();
        
        if (num1 == num2) {
            System.out.println(num1);
        } else if (num1 > num2 && num1 - num2 < num2) {
            dif = num1 - num2;
            for (; dif > 0; dif--)
                if (num1 % dif == 0 && num2 % dif == 0)
                    break;
            System.out.println(dif);
        } else {
            int i;
            for (i = num1; i > 0; i--)
                if (num1 % i == 0 && num2 % i == 0)
                    break;
            System.out.println(i);
        }

        
    }
}
