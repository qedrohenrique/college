public class ManipulacaoRetangulos {

	public static void main(String[] args) {
		Retangulo retA = new Retangulo();
		Retangulo retB = new Retangulo();
		
		retA.altura = 10;
		retA.base = 5;
		retB.altura = 23;
		retB.base = 12;
		
		retA.area();
		retA.perimetro();
		retA.relacaoBaseAltura();
		retA.ehQuadrado();
		retA.imprimir();	
		
		retB.area();
		retB.perimetro();
		retB.relacaoBaseAltura();
		retB.ehQuadrado();
		retB.imprimir();
	}

}
