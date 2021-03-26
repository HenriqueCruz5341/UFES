package aula10;

import java.util.Formatter;

public class CDs extends Produto {
    private int numFaixas;

    public CDs(String nome, float preco, int numFaixas) {
        super(nome, preco);
        this.numFaixas = numFaixas;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("%s (R$ %.2f) - %d faixas", this.nome, this.preco, this.numFaixas);
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }

}
