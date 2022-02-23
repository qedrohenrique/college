public class Reta implements Relacao{
	
	double p, q, length;
	
	public Reta(double p, double q) {
		this.p = p;
		this.q = q;
		if(p>q) this.length = p-q;
		else this.length = q-p;
	}
	
	public boolean maiorQue(Object b) {
		Reta x = (Reta) b;
		if(x.length > this.length) return false;
		else return true;
	}

	
	public boolean menorQue(Object b) {
		Reta x = (Reta) b;
		if(x.length > this.length) return true;
		else return false;
	}


	public boolean igualA(Object b) {
		Reta x = (Reta) b;
		if(x.length == this.length) return true;
		else return false;
	}
	
}
