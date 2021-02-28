package aula05;

import java.util.Random;
import java.util.Scanner;

public class Aleatorio {
    static Random rand;
    private int VALOR_MAXIMO_DEFAULT;
    private int numeroGerado;

    static {
        Scanner scan = new Scanner(System.in);
        long seed = scan.nextLong();
        rand = new Random(seed);
    }

    Aleatorio() {
        this.VALOR_MAXIMO_DEFAULT = 100;
        this.numeroGerado = rand.nextInt(this.VALOR_MAXIMO_DEFAULT);
    }

    Aleatorio(int max) {
        this.VALOR_MAXIMO_DEFAULT = max;
        this.numeroGerado = rand.nextInt(this.VALOR_MAXIMO_DEFAULT);
    }

    public void renovar() {
        this.numeroGerado = rand.nextInt(this.VALOR_MAXIMO_DEFAULT);
    }

    public int getNumeroGerado() {
        return numeroGerado;
    }
}
