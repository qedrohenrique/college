import java.util.Arrays;
import java.util.Scanner;

public class NumeroUm {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		int number = 1, i = 0;
		int[] numberArray = new int[100];
		
		Arrays.fill(numberArray, -1);
		
		while(number != 0) {
			number = kb.nextInt();
			numberArray[i] = number;
			i++;
		}
		
		Arrays.sort(numberArray);
		
		for(i = 0; i < numberArray.length; i++) {
			if(numberArray[i] > 0) System.out.println(numberArray[i]);
		}
		
	}
}

