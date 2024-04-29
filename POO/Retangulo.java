public class Retangulo {

	public int base, altura;
	
	public void area() {
		System.out.printf("�rea: %d\n", base*altura);
	}
	public void perimetro() {
		System.out.printf("Per�metro: %d\n", (2*base)+(2*altura));
	}
	public void relacaoBaseAltura() {
		System.out.printf("A rela��o base/altura: %d/%d = %.2f\n", base, altura, (float)base/altura);
	}
	public void ehQuadrado() {
		if(altura == base) System.out.printf("O ret�ngulo � tamb�m quadrado.\n");
		else System.out.printf("O ret�ngulo n�o �	 quadrado.\n");
	}
	public void imprimir() {
		System.out.printf("Este ret�ngulo tem as dimens�es(Base x Altura): %d x %d\n", base, altura);
	}
}
