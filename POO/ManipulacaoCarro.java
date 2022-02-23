public class ManipulacaoCarro {
	
	public static void main(String[] args) {
		
		Carro car = new Carro("Porsche", "Boxster Spyder", "KDA-4014");
		
		car.ligar();
		
		car.acelerar(120);
		car.frear();
		car.acelerar(50);
		car.frear();
		car.acelerar(50);
		car.acelerar(50);
		
		car.desligar();
		
		car.ligar();
		car.acelerar(10);
		car.desligar();
		
	}
	
}
