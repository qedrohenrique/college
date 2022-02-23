import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class Ex01 {

	static File myFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\File1.txt");
	
	public static String criptographMessage(String l, int k) {

		StringBuilder ms = new StringBuilder();
		char[] charArr = l.toCharArray();
		
		for(char i : charArr) {
			if((int)i + k > 127)i = (char) ((int) i + k - 127 + 32);
			else i = (char) ((int) i + k);
			ms.append(i);
		}
		
		return ms.toString();
	}
	public static void main(String[] args) {
		String l1 = new String();
		String l2 = new String();
		try {
			BufferedReader inputStream = new BufferedReader(new FileReader(myFile));
			l1 = inputStream.readLine();
			l2 = criptographMessage(l1, 3);
		}catch(IOException e){
			e.printStackTrace();
		}finally {
			System.out.println(l1);
			System.out.println(l2);
		}
	}
	
}
