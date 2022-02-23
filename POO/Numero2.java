public class Numero2 {
	
	public static double mediaDouble(double[] a) {
		
		double sum = 0;
		
		for(int i = 0; i < a.length; i++) {
			sum += a[i]; 
		}
		
		return sum/a.length;
	}
	
	public static void main(String[] args) {
		double[] myArray = {1.5, 3.3, 102.3, 5.1};
		System.out.println(Numero2.mediaDouble(myArray));
	}
}

