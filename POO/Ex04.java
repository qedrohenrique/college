import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Ex04 {
	
	static File aFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\File1.txt");
	static File bFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\File2.txt");
	
	public static boolean searchForSequence(String a, String b) {
		
		String aAux = null;
		String bAux = null;
		
		int min = (a.length() < b.length()) ? a.length() : b.length();
		int max = (a.length() > b.length()) ? a.length() : b.length();
		String minStr = (a.length() < b.length()) ? a : b;
		String maxStr = (a.length() > b.length()) ? a : b;
		System.out.println(a);
		System.out.println(b);
		
		if(min < 5) return false;
		else {
			for(int i = 0; (i + 5 - 1) < min; i++) {
				aAux = minStr.substring(i, i+5);
				System.out.println(aAux);
				for(int j = 0; (j + 5 - 1) < max; j++) {
					bAux = maxStr.substring(j, j+5);
					System.out.println(bAux);
					if(aAux.compareTo(bAux) == 0) return true;
				}
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		try {
			BufferedReader aStream = new BufferedReader(new FileReader(aFile));
			BufferedReader bStream = new BufferedReader(new FileReader(bFile));
			String l1 = aStream.readLine();
			String l2 = bStream.readLine();
			boolean resp = searchForSequence(l1, l2);
			if(resp) System.out.println("True");
			else System.out.println("False");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
