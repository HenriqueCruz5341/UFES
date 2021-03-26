package aula10;

import java.util.Formatter;

public class Circulos implements Formas {
    private double raio;

    Circulos(double raio) {
        this.raio = raio;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * 3.1415 * this.raio;
    }

    @Override
    public double calcularArea() {
        return 3.1415 * this.raio * this.raio;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("Circulo de raio %.2f - perimetro: %.2f; area: %.2f.", this.raio, this.calcularPerimetro(),
                this.calcularArea());
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }

}
