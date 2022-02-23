public class Triangulo {

	private double ladoA, ladoB, ladoC;
	
	public Triangulo() {
		this.ladoA = 3;
		this.ladoB = 4;
		this.ladoC = 5;
	}
	
	public Triangulo(double ladoA, double ladoB, double ladoC) {
		this.ladoA = ladoA;
		this.ladoB = ladoB;
		this.ladoC = ladoC;
	}
	
	public void area(){
		
		// Calculado apartir da fórmula de Heron.
		
		double A, p, aux;
		
		p = (ladoA+ladoB+ladoC) / 3;
		aux = p*(p-ladoA)*(p-ladoB)*(p-ladoC);
		A = Math.sqrt(aux);
		
		System.out.printf("Área = %f\n", A);
	}

	public void mostra() {
		System.out.printf("Esse triângulo possui os seguintes atributos:\n"
				+ "ladoA (Comprimento do lado A): %.2f.\n"
				+ "ladoB (Comprimento do lado B): %.2f.\n"
				+ "ladoC (Comprimento do lado C): %.2f.\n", ladoA, ladoB, ladoC);
	}
	
	public double getLadoA() {
		return ladoA;
	}
	public double getLadoB() {
		return ladoB;
	}
	public double getLadoC() {
		return ladoC;
	}
	
	public void setLadoA(double ladoA) {
		this.ladoA = ladoA;
	}
	public void setLadoB(double ladoB) {
		this.ladoB = ladoB;
	}
	public void setLadoC(double ladoC) {
		this.ladoC = ladoC;
	}
	
	
}
