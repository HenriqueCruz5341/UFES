package aula10;

import java.util.Formatter;

public abstract class Quadrilateros implements Formas {
    protected double lado1;
    protected double lado2;
    protected double lado3;
    protected double lado4;

    @Override
    public double calcularPerimetro() {
        return this.lado1 + this.lado2 + this.lado3 + this.lado4;
    }

    @Override
    public double calcularArea() {
        return this.lado1 * this.lado2;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("perimetro: %.2f; area: %.2f.", this.calcularPerimetro(), this.calcularArea());
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }

}
