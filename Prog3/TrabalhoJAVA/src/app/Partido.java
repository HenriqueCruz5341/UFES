package app;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Formatter;
import java.util.List;

/**
 * A classe Partido representa um partido na eleicao
 */
public class Partido implements Comparable<Partido> {
    static int votosLegendaTotal;

    private int numPartido;
    private int qtdCandidatosEleitos;
    private int votosNominais;
    private int votosLegenda;
    private String nomePartido;
    private String siglaPartido;
    private List<Candidato> candidatos;

    Partido(int numPartido, int votosLegenda, String nomePartido, String siglaPartido, List<Candidato> candidatos) {
        this.numPartido = numPartido;
        this.votosLegenda = votosLegenda;
        this.nomePartido = nomePartido;
        this.siglaPartido = siglaPartido;
        this.candidatos = retornaCandidatosPartido(candidatos);
        this.qtdCandidatosEleitos = retornaQtdEleitos();
        this.votosNominais = retornaQtdVotosNominais();
        votosLegendaTotal += votosLegenda;
    }

    static {
        votosLegendaTotal = 0;
    }

    /**
     * Esse metodo percorre a lista de candidatos enviada como parametro e, retorna
     * uma lista de candidatos do mesmo partido.
     * 
     * @param candidatos lista de todos candidatos
     * @return lista de candidatos do mesmo partido
     */
    private List<Candidato> retornaCandidatosPartido(List<Candidato> candidatos) {
        List<Candidato> candidatosPartido = new ArrayList<Candidato>();

        for (Candidato c : candidatos) {
            if (c.getnumPartido() == this.numPartido)
                candidatosPartido.add(c);
        }

        Collections.sort(candidatosPartido);

        return candidatosPartido;
    }

    /**
     * Esse metodo percorre a lista de candidatos local e retorna a quantidade de
     * candidatos eleitos desse partido.
     * 
     * @return quantidade de candidatos eleitos no partido
     */
    private int retornaQtdEleitos() {
        int cont = 0;
        for (Candidato c : this.candidatos) {
            if (c.getSituacao().compareTo("Eleito") == 0)
                cont++;
        }

        return cont;
    }

    /**
     * Esse metodo percorre a lista de candidatos local e retorna o total de votos
     * nominais de um partido.
     * 
     * @return quantidade de votos nominais total de um partido
     */
    private int retornaQtdVotosNominais() {
        int qtd = 0;
        for (Candidato c : this.candidatos) {
            qtd += c.getVotosNominais();
        }

        return qtd;
    }

    public int getNumPartido() {
        return numPartido;
    }

    public int getQtdCandidadosEleitos() {
        return qtdCandidatosEleitos;
    }

    public int getVotosLegenda() {
        return votosLegenda;
    }

    public String getNomePartido() {
        return nomePartido;
    }

    public String getSiglaPartido() {
        return siglaPartido;
    }

    public List<Candidato> getCandidatos() {
        return this.candidatos;
    }

    public void setNumPartido(int numPartido) {
        this.numPartido = numPartido;
    }

    public void setVotosLegenda(int votosLegenda) {
        this.votosLegenda = votosLegenda;
    }

    public void setNomePartido(String nomePartido) {
        this.nomePartido = nomePartido;
    }

    public void setSiglaPartido(String siglaPartido) {
        this.siglaPartido = siglaPartido;
    }

    @Override
    public int compareTo(Partido p) {
        int totalVotosThis = this.votosNominais + this.votosLegenda;
        int totalVotosOutro = p.votosNominais + p.votosLegenda;
        if (totalVotosOutro - totalVotosThis == 0) {
            return this.numPartido - p.numPartido;
        }
        return totalVotosOutro - totalVotosThis;
    }

    @Override
    public String toString() {
        int votosTotais = this.votosLegenda + this.votosNominais;
        Formatter fmt = new Formatter();
        fmt.format("%s - %d, %d %s (%d %s e %d de legenda), %d %s", this.siglaPartido, this.numPartido, votosTotais,
                votosTotais <= 1 ? "voto" : "votos", this.votosNominais,
                this.votosNominais <= 1 ? "nominal" : "nominais", this.votosLegenda, this.qtdCandidatosEleitos,
                this.qtdCandidatosEleitos <= 1 ? "candidato eleito" : "candidatos eleitos");
        String s = fmt.out().toString();
        fmt.close();
        return s;
    }

    public String toStringCandidatos() {
        if (this.candidatos.size() <= 0)
            return null;

        Candidato primeiro = this.candidatos.get(0);
        Candidato ultimo = this.candidatos.get(this.candidatos.size() - 1);

        Formatter fmt = new Formatter();
        fmt.format("%s - %d, %s (%d, %d %s) / %s (%d, %d %s)", this.siglaPartido, this.numPartido,
                primeiro.getNomeUrna(), primeiro.getNumero(), primeiro.getVotosNominais(),
                primeiro.getVotosNominais() <= 1 ? "voto" : "votos", ultimo.getNomeUrna(), ultimo.getNumero(),
                ultimo.getVotosNominais(), ultimo.getVotosNominais() <= 1 ? "voto" : "votos");
        String s = fmt.out().toString();
        fmt.close();

        return s;
    }

}

class ComparadorPrimeiroCandidato implements Comparator<Partido> {
    @Override
    public int compare(Partido partido1, Partido partido2) {
        int tamListaCandidatosPartido1 = partido1.getCandidatos().size();
        int tamListaCandidatosPartido2 = partido2.getCandidatos().size();

        if (tamListaCandidatosPartido1 > 0 && tamListaCandidatosPartido2 > 0) {
            Candidato primeiroP1 = partido1.getCandidatos().get(0);
            Candidato primeiroP2 = partido2.getCandidatos().get(0);

            int comp = primeiroP2.getVotosNominais() - primeiroP1.getVotosNominais();
            if (comp == 0) {
                return partido1.getNumPartido() - partido2.getNumPartido();
            }
            return comp;
        } else if (tamListaCandidatosPartido1 > 0 && !(tamListaCandidatosPartido2 > 0)) {
            return -1;
        }
        return 1;
    }
}