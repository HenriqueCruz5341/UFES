package aula04;

class Departamento {
    String nome;
    Funcionario[] funcionarios;

    public String getNome() {
        return nome;
    }

    public Funcionario[] getFuncionarios() {
        return funcionarios;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setFuncionarios(Funcionario[] funcionarios) {
        this.funcionarios = funcionarios;
    }

    double calculaSalarioFuncionarios() {
        double total = 0;

        for (Funcionario f : this.funcionarios)
            total += f.getSalario();

        return total;
    }
}
