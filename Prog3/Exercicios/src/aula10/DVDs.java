package aula10;

import java.util.Formatter;

public class DVDs extends Produto {
    private int minutos;

    public DVDs(String nome, float preco, int minutos) {
        super(nome, preco);
        this.minutos = minutos;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("%s (R$ %.2f) - %d minutos", this.nome, this.preco, this.minutos);
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }

}
