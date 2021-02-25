package aula05;

public class Exercicio1 {

    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            Aleatorio aleatorio = new Aleatorio();
            System.out.printf("%d ", aleatorio.getNumeroGerado());
        }
        for (int i = 0; i < 5; i++) {
            Aleatorio aleatorio = new Aleatorio();
            System.out.printf("%d", aleatorio.getNumeroGerado());
            if (i < 4)
                System.out.printf(" ");
        }
        System.out.println();
    }
}
