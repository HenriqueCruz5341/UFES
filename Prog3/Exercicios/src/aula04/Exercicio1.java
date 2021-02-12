package aula04;

import java.util.Scanner;

public class Exercicio1 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Ponto[] pontos = new Ponto[3];
		Triangulo triangulo = new Triangulo();
		double x, y, perimetro;

		for (int i = 0; i < 3; i++) {
			x = scan.nextDouble();
			y = scan.nextDouble();
			Ponto ponto = new Ponto();
			ponto.setX(x);
			ponto.setY(y);
			pontos[i] = ponto;
		}

		triangulo.setPontos(pontos);

		perimetro = triangulo.calculaPerimetro();

		System.out.printf("%.5f\n", perimetro);

		scan.close();
	}
}
