import java.lang.Math;
import java.util.Vector;

public class Vetores {
	
	public static int factorialInt(int n) {
		int fact = 1;
	    for (int i = 2; i <= n; i++) {
	        fact = fact * i;
	    }
	    return fact;
	}
	
	public static void fillWithSequence(int[] arrayInt) {
		int i = 0;
		while(i < arrayInt.length) {
			arrayInt[i] = i * 2;
			i++;
		}
	}
	
	public static void fillWithExponentialSerie(int[] arrayInt) {
		int i = 0;
		while(i < arrayInt.length) {
			arrayInt[i] = (int) Math.pow(i, 2);
			i++;
		}
	}
	
	public static void printArray(int[] arrayInt) {
		int i = 0;
		for(i = 0; i < arrayInt.length; i++) System.out.printf("%d ", arrayInt[i]);
		System.out.printf("\n");
	}
	
	public static String intArrayToString(int[] arrayInt) {
		int i = 0;
		Vector<Integer> vectorResponse = new Vector<Integer>(5);
		while(i < arrayInt.length) {
			vectorResponse.add(arrayInt[i]);
			i++;
		}
		return vectorResponse.toString();
	}
	
	public static void main(String[] args) {
		int[] arrayOne = new int[10];
		int[] arrayTwo = new int[20];
		int[] arrayAux = new int[1];
		
		fillWithSequence(arrayOne);
		fillWithExponentialSerie(arrayTwo);
		
		printArray(arrayOne);
		printArray(arrayTwo);
		
		System.out.println(intArrayToString(arrayOne));
		System.out.println(intArrayToString(arrayTwo));
		
		arrayAux = arrayOne;
		arrayOne = arrayTwo;
		arrayTwo = arrayAux;
		
		printArray(arrayOne);
		printArray(arrayTwo);
	}
	
}
