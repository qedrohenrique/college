public class Retangulo {

	public int base, altura;
	
	public void area() {
		System.out.printf("Área: %d\n", base*altura);
	}
	public void perimetro() {
		System.out.printf("Perímetro: %d\n", (2*base)+(2*altura));
	}
	public void relacaoBaseAltura() {
		System.out.printf("A relação base/altura: %d/%d = %.2f\n", base, altura, (float)base/altura);
	}
	public void ehQuadrado() {
		if(altura == base) System.out.printf("O retângulo é também quadrado.\n");
		else System.out.printf("O retângulo não é	 quadrado.\n");
	}
	public void imprimir() {
		System.out.printf("Este retângulo tem as dimensões(Base x Altura): %d x %d\n", base, altura);
	}
}
