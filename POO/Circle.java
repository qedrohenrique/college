import java.lang.Comparable;
import java.util.Arrays;
import java.util.Vector;
public class Circle implements Comparable{

	public Circle(int x, int y, int radius) {
		super();
		this.x = x;
		this.y = y;
		this.radius = radius;
	}


	int x, y, radius;
	
	public boolean equals(Circle circleOne, Circle circleTwo) {
		if(circleOne.x == circleTwo.x &&
				circleOne.y == circleTwo.y &&
				circleOne.radius == circleTwo.radius) return true;
		return false;
	}
	
	public String toString() {
		return this.getClass().getName() + '@' + Integer.toHexString(hashCode ()) +
				": x = " + this.x + " y = " + this.y + " radius = " + this.radius;
	}
	
	@Override
	public int compareTo(Object arg0) {
		Circle circleAux = (Circle) arg0;
		if(this.radius < circleAux.radius) return -1;
		if(this.radius > circleAux.radius) return 1;
		if(this.radius == circleAux.radius) return 0;
		return 0;
	}

	public static String circleArrayToString(Circle[] arrayCircle) {
		int i = 0;
		Vector<String> vectorResponse = new Vector<String>(arrayCircle.length);
		while(i < arrayCircle.length) {
			vectorResponse.add(arrayCircle[i].toString());
			i++;
		}
		return vectorResponse.toString();
	}
	
	public static void main(String[] args) {
		Circle[] arrayCircles = {new Circle(0, 0, 75), new Circle(0, 0, 11), new Circle(0, 0, 3),
								new Circle(0, 0, 4), new Circle(0, 0, 22), new Circle(0, 0, 6),
								new Circle(0, 0, 3), new Circle(0, 0, 14), new Circle(0, 0, 9), new Circle(0, 0, 10),};
		Arrays.sort(arrayCircles);
		System.out.println(circleArrayToString(arrayCircles));
	}
}
