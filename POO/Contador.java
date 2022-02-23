public class Contador {

	private int count;
	
	public Contador() {
		this.count = 0;
	}
	
	public Contador(int a) {
		this.count = a;
	}
	
	public int dizerValorAtual() {
		return this.count;
	}
	
	public void incrementar() {
		this.count += 1;
	}
	public void incrementar(int a) {
			this.count += a;
	}
	public void decrementar() {
		this.count -= 1;
	}
	public void decrementar(int a) {
		this.count -= a;
	}
	public void visualizar() {
		System.out.printf("Contador = %d\n", count);
	}
}
