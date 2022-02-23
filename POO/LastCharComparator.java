import java.util.Arrays;
import java.util.Comparator;

public class LastCharComparator implements Comparator {

	@Override
	public int compare(Object arg0, Object arg1) {
		String sOne = (String) arg0;
		String sTwo = (String) arg1;
		if(sOne.charAt(sOne.length()-1) < sTwo.charAt(sTwo.length()-1)) return -1;
		if(sOne.charAt(sOne.length()-1) > sTwo.charAt(sTwo.length()-1)) return 1;
		if(sOne.charAt(sOne.length()-1) == sTwo.charAt(sTwo.length()-1)) return 0;
		return 0;
	}
	
	public static void printArray(String[] arrayString) {
		int i = 0;
		for(i = 0; i < arrayString.length; i++) System.out.printf("%s ", arrayString[i]);
		System.out.printf("\n");
	}
	
	public static void main(String[] args) {
		String[] dictionary = {"zzB", "zzE", "zzA", "zzE", "zzD"};
		printArray(dictionary);
		Arrays.sort(dictionary);
		printArray(dictionary);
	}

}
