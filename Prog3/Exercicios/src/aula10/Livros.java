package aula10;

import java.util.Formatter;

public class Livros extends Produto {
    private String autor;

    public Livros(String nome, float preco, String autor) {
        super(nome, preco);
        this.autor = autor;
    }

    @Override
    public String toString() {
        Formatter fmt = new Formatter();
        fmt.format("%s (R$ %.2f) - %s", this.nome, this.preco, this.autor);
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }

}
