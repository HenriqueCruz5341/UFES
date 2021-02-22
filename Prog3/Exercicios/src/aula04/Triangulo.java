package aula04;

class Triangulo {
	Ponto[] pontos;

	public Ponto[] getPontos() {
		return pontos;
	}

	public void setPontos(Ponto[] pontos) {
		this.pontos = pontos;
	}

	double calculaPerimetro() {
		if (this.pontos != null && this.pontos.length == 3) {
			double aresta1 = this.pontos[0].calculaDistancia(this.pontos[1]);
			double aresta2 = this.pontos[1].calculaDistancia(this.pontos[2]);
			double aresta3 = this.pontos[2].calculaDistancia(this.pontos[0]);

			return aresta1 + aresta2 + aresta3;
		}

		return 0;
	}

}
