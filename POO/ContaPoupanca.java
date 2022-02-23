public class ContaPoupanca extends Conta {
	
	private double juros;

	public ContaPoupanca(int a, double j) {
		super(a);
		juros = j;
	}
	
	public void addJuros(double a) {
		this.juros += a;
	}
	
	public double getJuros() {
		return juros;
	}
	
}

