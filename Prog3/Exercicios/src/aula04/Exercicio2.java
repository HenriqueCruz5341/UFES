package aula04;

import java.util.Scanner;
import java.util.Locale;

public class Exercicio2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Locale locale = new Locale("pt", "BR");
        Empresa empresa = new Empresa();
        String nome, cnpj, dataAdmissao;
        int qtdDpto, qtdFunc;
        double salario;

        nome = scan.next();
        cnpj = scan.next();
        qtdDpto = scan.nextInt();

        empresa.setNome(nome);
        empresa.setCnpj(cnpj);

        Departamento[] departamentos = new Departamento[qtdDpto];

        for (int i = 0; i < qtdDpto; i++) {
            nome = scan.next();
            qtdFunc = scan.nextInt();
            Departamento departamento = new Departamento();
            departamento.setNome(nome);

            Funcionario[] funcionarios = new Funcionario[qtdFunc];

            for (int j = 0; j < qtdFunc; j++) {
                nome = scan.next();
                salario = scan.nextDouble();
                dataAdmissao = scan.next();
                Funcionario funcionario = new Funcionario();
                funcionario.setNome(nome);
                funcionario.setSalario(salario);
                funcionario.setDataAdmissao(dataAdmissao);
                funcionarios[j] = funcionario;
            }

            departamento.setFuncionarios(funcionarios);
            departamentos[i] = departamento;
        }

        empresa.setDepartamentos(departamentos);

        Funcionario[] funcionariosDpto = empresa.getDepartamentos()[0].getFuncionarios();
        for (Funcionario f : funcionariosDpto)
            f.setSalario(f.getSalario() * 1.1);

        Funcionario funcionarioTransferido = empresa.getDepartamentos()[0].getFuncionarios()[0];

        Funcionario[] funcionarios = new Funcionario[funcionariosDpto.length - 1];
        for (int i = 1; i < funcionariosDpto.length; i++)
            funcionarios[i - 1] = funcionariosDpto[i];
        empresa.getDepartamentos()[0].setFuncionarios(funcionarios);

        funcionariosDpto = empresa.getDepartamentos()[1].getFuncionarios();
        funcionarios = new Funcionario[funcionariosDpto.length + 1];
        for (int i = 0; i < funcionariosDpto.length + 1; i++) {
            if (i == funcionariosDpto.length)
                funcionarios[i] = funcionarioTransferido;
            else
                funcionarios[i] = funcionariosDpto[i];
        }
        empresa.getDepartamentos()[1].setFuncionarios(funcionarios);

        for (Departamento d : empresa.getDepartamentos()) {
            double salarioFuncionarios = d.calculaSalarioFuncionarios();
            System.out.printf(locale, "%s R$ %.2f\n", d.getNome(), salarioFuncionarios);
        }

        scan.close();
    }
}
