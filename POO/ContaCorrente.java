public class ContaCorrente extends Conta{
	
	private double lim;

	public ContaCorrente(int a, double d) {
		super(a);
		lim = d;
	}
	
	public double getLim() {
		return lim;
	}
	
}