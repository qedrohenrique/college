public class Carro {
	
	public int velCarro;
	public String marcaCarro;
	public String modeloCarro;
	public String placaCarro;
	private boolean isOn = false;
	
	public void acelerar(int velocidade) {
		if(isOn) {
			velCarro += velocidade;
			System.out.printf("Acelerando o carro %s para %d km/h.\n", this.modeloCarro, velCarro);
		}else {
			System.out.printf("O carro está desligado\n");	
		}
	}
	
	public void frear() {
		if(isOn) {
			System.out.printf("Freando o carro.\n");
			this.velCarro = 0;
		}else {
			System.out.printf("O carro está desligado\n");	
		}
	}
	
	public void ligar() {
		isOn = true;
		System.out.printf("Ligando o motor...\n");
	}
	
	public void desligar() {
		isOn = false;
		System.out.printf("Desligando o motor...\n");
	}
	
	public static void main(String[] args) {
		Carro meuCarro = new Carro();
		
		meuCarro.velCarro = 60;
		meuCarro.marcaCarro = "Bugatti";
		meuCarro.modeloCarro = "Centodieci";
		meuCarro.placaCarro = "ABC-1234";
		
		meuCarro.ligar();
		meuCarro.acelerar(60);
		meuCarro.frear();
		meuCarro.acelerar(20);
		meuCarro.desligar();
		
		Carro meuOutroCarro = new Carro();
		
		meuOutroCarro.velCarro = 0;
		meuOutroCarro.marcaCarro = "Ford";
		meuOutroCarro.modeloCarro = "Mustang";
		meuOutroCarro.placaCarro = "DEF-5678";
		
		meuOutroCarro.acelerar(200);
		meuOutroCarro.frear();
		
	}
}
