package app;

import java.time.LocalDate;
import java.time.Period;
import java.util.Formatter;
import java.util.List;

/**
 * A classe Candidato representa um vereador na votacao
 */
public class Candidato implements Comparable<Candidato> {
    static int votosNominaisTotal;

    private int numero;
    private int votosNominais;
    private String situacao;
    private String nome;
    private String nomeUrna;
    private char sexo;
    private int idade;
    private String destinoVoto;
    private int numPartido;
    private LocalDate dataNasc;

    static {
        votosNominaisTotal = 0;
    }

    Candidato(int numero, int votosNominais, String situacao, String nome, String nomeUrna, char sexo,
            LocalDate dataNasc, String destinoVoto, int numPartido, LocalDate data) {
        this.numero = numero;
        this.votosNominais = votosNominais;
        this.situacao = situacao;
        this.nome = nome;
        this.nomeUrna = nomeUrna;
        this.sexo = sexo;
        this.dataNasc = dataNasc;
        this.idade = Period.between(dataNasc, data).getYears();
        this.destinoVoto = destinoVoto;
        this.numPartido = numPartido;
        votosNominaisTotal += votosNominais;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public int getVotosNominais() {
        return votosNominais;
    }

    public void setVotosNominais(int votosNominais) {
        this.votosNominais = votosNominais;
    }

    public String getSituacao() {
        return situacao;
    }

    public void setSituacao(String situacao) {
        this.situacao = situacao;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNomeUrna() {
        return nomeUrna;
    }

    public void setNomeUrna(String nomeUrna) {
        this.nomeUrna = nomeUrna;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public LocalDate getDataNasc() {
        return this.dataNasc;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getDestinoVoto() {
        return destinoVoto;
    }

    public void setDestinoVoto(String destinoVoto) {
        this.destinoVoto = destinoVoto;
    }

    public int getnumPartido() {
        return numPartido;
    }

    public void setnumPartido(int numPartido) {
        this.numPartido = numPartido;
    }

    @Override
    public int compareTo(Candidato c) {
        int difVotos = c.votosNominais - this.votosNominais;
        if (difVotos == 0)
            return this.dataNasc.compareTo(c.dataNasc);
        return difVotos;
    }

    public String toString(List<Partido> partidos) {
        Formatter fmt = new Formatter();
        fmt.format("%s / %s (%s, %d %s)", this.nome, this.nomeUrna,
                Eleicao.retornaPartidoLista(partidos, this.numPartido).getSiglaPartido(), this.votosNominais,
                this.votosNominais <= 1 ? "voto" : "votos");
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }
}