package aula10;

public class Produto implements Comparable<Produto> {
    protected String nome;
    protected float preco;

    public Produto(String nome, float preco) {
        this.nome = nome;
        this.preco = preco;
    }

    @Override
    public int compareTo(Produto p) {
        if (this.preco < p.preco)
            return 1;
        else if (this.preco > p.preco)
            return -1;
        else {
            return this.nome.compareTo(p.nome);
        }
    }
}
