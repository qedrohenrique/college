public class Quadrado {

	double l;
	
	public Quadrado(double lado) {
		this.l = lado;
	}
	
	public void aumentar(double inc) {
		this.l += inc;
	}
	
	public double area() {
		return l*l;
	}
	
}
