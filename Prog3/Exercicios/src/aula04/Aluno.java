package aula04;

public class Aluno {
    String nome;
    double[] notas;

    public String getNome() {
        return nome;
    }

    public double[] getNotas() {
        return notas;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNotas(double[] notas) {
        this.notas = notas;
    }

    double calculaMedia() {
        double total = 0;
        for (double n : this.notas)
            total += n;

        return total / 3;
    }
}
