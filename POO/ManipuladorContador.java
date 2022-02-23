public class ManipuladorContador {

	public static void main(String[] args) {
		Contador count1 = new Contador();
		Contador count2 = new Contador(5);
		
		count1.visualizar();
		count2.visualizar();
		
		count1.incrementar(3);
		count2.incrementar();
		count1.visualizar();
		count2.visualizar();
		
		count1.decrementar(2);
		count2.decrementar();
		count1.visualizar();
		count2.visualizar();
		
	}
}
