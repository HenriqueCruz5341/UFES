package aula10;

import java.util.Formatter;

public class Quadrados extends Quadrilateros {

    Quadrados(double lado) {
        super.lado1 = lado;
        super.lado2 = lado;
        super.lado3 = lado;
        super.lado4 = lado;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("Quadrado de lado %.2f - %s", super.lado1, super.toString());
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }
}
