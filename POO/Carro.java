public class Carro {

	private int velCarro = 0;
	private String marcaCarro;
	private String modeloCarro;
	private String placaCarro;
	private boolean isOn = false;
	public Contador vezesAcelerou = new Contador();
	public Contador vezesFreou = new Contador();
	public Contador vezesLigou = new Contador();
	
	public Carro(String marca, String modelo, String placa) {
		this.marcaCarro = marca;
		this.modeloCarro = modelo;
		this.placaCarro = placa;
	}
	
	public void acelerar(int velocidade) {
		if(isOn) {
			velCarro += velocidade;
			vezesAcelerou.incrementar();
			System.out.printf("Acelerando o carro %s para %d km/h.\n", this.modeloCarro, velCarro);
		}else {
			System.out.printf("O carro está desligado\n");	
		}
	}
	
	public void frear() {
		if(isOn) {
			System.out.printf("Freando o carro.\n");
			vezesFreou.incrementar();
			this.velCarro = 0;
		}else {
			System.out.printf("O carro está desligado\n");	
		}
	}
	
	public void ligar() {
		if(!isOn) {
			isOn = true;
			vezesLigou.incrementar();
			System.out.printf("Ligando o motor...\n");
		}else {
			System.out.printf("Já está ligado.\n");
		}
	}
	
	public void desligar() {
		if(isOn) {
			frear();
			isOn = false;
			System.out.printf("Desligando o motor...\n");
		}else {
			System.out.printf("Já esta desligado.\n");
		}
	}
	
}
