package aula10;

import java.util.Formatter;

public class Retangulos extends Quadrilateros {

    Retangulos(double base, double altura) {
        super.lado1 = base;
        super.lado2 = altura;
        super.lado3 = base;
        super.lado4 = altura;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("Retangulo de base %.2f e altura %.2f - %s", super.lado1, super.lado2, super.toString());
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }
}
