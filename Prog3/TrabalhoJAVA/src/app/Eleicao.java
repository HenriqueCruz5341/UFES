package app;

import java.util.ArrayList;
import java.util.List;

/**
 * A classe Eleição representa um evento de seleção, é responsável por gerar os
 * relatórios e tem todas as informações necessárias para isso
 */
public class Eleicao {
    private int qtdEleitos;
    private List<Candidato> candidatos;
    private List<Partido> partidos;
    private int qtdCandidados;
    private int qtdPartidos;

    Eleicao(List<Candidato> candidatos, List<Partido> partidos) {
        this.candidatos = candidatos;
        this.partidos = partidos;
        this.qtdCandidados = candidatos.size();
        this.qtdPartidos = partidos.size();
    }

    /**
     * Essa função serve para procurar um partido dentro de uma lista de partidos
     *
     * @param partidos   A lista de partidos onde deseja-se realizar a busca
     * @param numPartido O número do partido que está sendo buscado
     * @return Caso o partido seja encontrado dentro da lista, ele é retornado, caso
     *         contrário, é retornado um ponteiro NULL
     */
    public static Partido retornaPartidoLista(List<Partido> partidos, int numPartido) {
        Partido partido = null;

        for (Partido p : partidos) {
            if (p.getNumPartido() == numPartido) {
                partido = p;
                break;
            }
        }
        return partido;
    }

    /**
     * Essa função serve para encontrar os candidados eleitos daquela eleição, além
     * disso ela atualiza o atributo de qtdEleitos de Eleição
     * 
     * @return Retorna uma lista dos candidados eleitos
     */
    public List<Candidato> retornaCandidatosEleitos() {
        List<Candidato> candidatosEleitos = new ArrayList<Candidato>();
        int cont = 0;

        for (Candidato c : this.candidatos) {
            if (c.getSituacao().compareTo("Eleito") == 0) {
                candidatosEleitos.add(c);
                cont++;
            }
        }

        this.qtdEleitos = cont;

        return candidatosEleitos;
    }

    /**
     * Essa função serve para encontrar os N (N = qtdEleitos), candidatos mais
     * votados
     * 
     * @return Retorna uma lista dos candidados mais votados
     */
    public List<Candidato> retornaCandidatosMaisVotados() {
        List<Candidato> candidatosMaisVotados = new ArrayList<Candidato>();
        int cont = 0;

        for (Candidato c : this.candidatos) {
            if (cont < this.qtdEleitos) {
                candidatosMaisVotados.add(c);
                cont++;
            } else if (cont == this.qtdEleitos)
                break;
        }

        return candidatosMaisVotados;
    }

    /**
     * Essa função serve para encontrar os candidatos que seriam eleitos caso o
     * sistema de votação levasse em conta apenas os votos nominais
     * 
     * @param candidatosMaisVotados Lista dos candidados mais votados
     * @return Retorna uma lista com os candidados que seriam eleitos caso o sistema
     *         levasse em conta apenas os votos nominais
     */
    public List<Candidato> retornaCandidatosSeriamEleitos(List<Candidato> candidatosMaisVotados) {
        List<Candidato> candidatosSeriamEleitos = new ArrayList<Candidato>();

        for (Candidato cmv : candidatosMaisVotados) {
            if (cmv.getSituacao().compareTo("Eleito") == 0)
                candidatosSeriamEleitos.add(null); // Coloca-se NULL, para que os cantidatos preservem suas colocações
            else
                candidatosSeriamEleitos.add(cmv);
        }

        return candidatosSeriamEleitos;
    }

    /**
     * Essa função serve para encontrar os candidatos que foram eleitos se
     * beneficiando do sistema proporcional
     * 
     * @param candidatosMaisVotados Lista dos candidados mais votados
     * @return Retorna uma lista com os candidados que não estão na lista de mais
     *         votados, mas foram eleitos graças ao sistema proporcional
     */
    public List<Candidato> retornaCandidatosBeneficiados(List<Candidato> candidatosMaisVotados) {
        List<Candidato> candidatosBeneficiados = new ArrayList<Candidato>();
        boolean encontrou;

        for (Candidato c : candidatos) {
            encontrou = false;
            if (c.getSituacao().compareTo("Eleito") == 0) {
                for (Candidato cmv : candidatosMaisVotados) {
                    if (c.getNumero() == cmv.getNumero()) {
                        encontrou = true;
                        break;
                    }
                }
                if (encontrou)
                    candidatosBeneficiados.add(null);// Coloca-se NULL, para que os cantidatos preservem suas colocações
                else
                    candidatosBeneficiados.add(c);
            } else
                candidatosBeneficiados.add(null);// Coloca-se NULL, para que os cantidatos preservem suas colocações
        }

        return candidatosBeneficiados;
    }

    /**
     * Essa função serve para calcular as quantidades de candidatos eleitos por
     * faixa etária
     * 
     * @param candidatosEleitos Lista dos candidados eleitos
     * @return retorna um vetor de inteiros com a quantidade de candidatos eleitos
     *         em cada intervalo de faixa etária, ou seja, a posição 0 são
     *         candidados entre 30 e 40 anos, a posição 1 de 40 a 50 e assim por
     *         diante
     * 
     */
    public int[] retornaQtdCandidatosEleitosFaixaEtaria(List<Candidato> candidatosEleitos) {
        int[] qtdCandidatosFaixaEtaria = new int[5];
        int qtd;
        boolean limiteIdade;

        for (int i = 30, j = 0, k = 0; k < 5; i += 10, j = i - 10, k++) {
            qtd = 0;
            for (Candidato ce : candidatosEleitos) {
                limiteIdade = (i > 60) ? true : (ce.getIdade() < i);
                if (ce.getIdade() >= j && limiteIdade) {
                    qtd++;
                }
            }
            qtdCandidatosFaixaEtaria[k] = qtd;
        }
        return qtdCandidatosFaixaEtaria;
    }

    /**
     * Essa função serve para calcular as quantidades de candidatos eleitos por sexo
     * 
     * @param candidatosEleitos Lista dos candidados eleitos
     * @return retorna um vetor de inteiros com a quantidade de candidatos eleitos
     *         do sexo masculino e feminino, sendo a posição 0 do vetor o sexo
     *         feminino e a posição 1 o sexo masculino
     * 
     */
    public int[] retornaQtdCandidatosSexo(List<Candidato> candidatosEleitos) {
        int mas = 0;
        int fem = 0;

        int[] qtdPorSexo = new int[2];

        for (Candidato c : candidatosEleitos) {
            if (c.getSexo() == 'F')
                fem++;
            if (c.getSexo() == 'M')
                mas++;
        }
        qtdPorSexo[0] = fem;
        qtdPorSexo[1] = mas;

        return qtdPorSexo;
    }

    public int getQtdEleitos() {
        return this.qtdEleitos;
    }

    public List<Candidato> getCandidatos() {
        return candidatos;
    }

    public List<Partido> getPartidos() {
        return partidos;
    }

    public int getQtdCandidados() {
        return qtdCandidados;
    }

    public int getQtdPartidos() {
        return qtdPartidos;
    }
}
