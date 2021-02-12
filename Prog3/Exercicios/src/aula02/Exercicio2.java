package aula02;

public class Exercicio2 {
    public static void main(String[] args) {
        int abcd, ab, cd, ef;

        for (abcd = 1001; abcd < 9999; abcd++) {
            ab = abcd / 100;
            cd = abcd % 100;
            ef = ab + cd;
            if (ef * ef == abcd)
                System.out.println(abcd);
        }
    }
}