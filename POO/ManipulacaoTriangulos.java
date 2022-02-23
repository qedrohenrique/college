public class ManipulacaoTriangulos {

	public static void main(String[] args) {
		
		Triangulo trianguloA = new Triangulo();
		Triangulo trianguloB = new Triangulo(6, 8, 10);
		
		double aA = trianguloA.getLadoA(),
		aB = trianguloA.getLadoB(),
		aC =trianguloA.getLadoC(),
		bA =trianguloB.getLadoA(),
		bB =trianguloB.getLadoB(),
		bC =trianguloB.getLadoC();
		
		trianguloA.mostra();
		trianguloB.mostra();
		System.out.printf("(A) ");
		trianguloA.area();
		System.out.printf("(B) ");
		trianguloB.area();
		
		trianguloA.setLadoA(6);
		trianguloA.setLadoB(6);
		trianguloA.setLadoC(6);		
		trianguloB.setLadoA(12);
		trianguloB.setLadoB(12);
		trianguloB.setLadoC(3);
		
		trianguloA.mostra();
		trianguloB.mostra();
		System.out.printf("(A) ");
		trianguloA.area();
		System.out.printf("(B) ");
		trianguloB.area();
		
		System.out.printf("Dados salvos com os métodos getters:\n"
				+ "aA: %.2f		bA: %.2f\n"
				+ "aB: %.2f		bB: %.2f\n"
				+ "aC: %.2f		bC: %.2f", aA, bA, aB, bB, aC, bC);

	}
}