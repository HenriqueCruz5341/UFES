package aula04;

public class Empresa {
    String nome;
    String cnpj;
    Departamento[] departamentos;

    public String getNome() {
        return nome;
    }

    public String getCnpj() {
        return cnpj;
    }

    public Departamento[] getDepartamentos() {
        return departamentos;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    public void setDepartamentos(Departamento[] departamentos) {
        this.departamentos = departamentos;
    }
}
