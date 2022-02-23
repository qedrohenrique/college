public class ManipulacaoQuadrados {
	public static void main(String[] args) {
		Quadrado quad1 = new Quadrado(Math.random());
		Quadrado quad2 = new Quadrado(Math.random());
		Quadrado quad3 = new Quadrado(Math.random());
		Quadrado quad4 = new Quadrado(Math.random());
		Quadrado quad5 = new Quadrado(Math.random());
		Quadrado quad6 = new Quadrado(Math.random());
		Quadrado quad7 = new Quadrado(Math.random());
		Quadrado quad8 = new Quadrado(Math.random());
		Quadrado quad9 = new Quadrado(Math.random());
		Quadrado quad0 = new Quadrado(Math.random());
		
		double areaTotal = quad1.area() + quad2.area() + quad3.area() + 
						   quad4.area() + quad5.area() + quad6.area() + 
						   quad7.area() + quad8.area() + quad9.area() + quad0.area();	
		
		System.out.println(areaTotal);
	}
}
