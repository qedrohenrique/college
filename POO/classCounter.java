import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class classCounter {
	
	public static int CountCharacters(String a) throws IOException{
		int count = 0;
		Scanner s = null;
		File file = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula16\\src\\"+a+".txt");
		try {
			s = new Scanner(new BufferedReader(new FileReader(file)));
			while(s.hasNext()) {
				int i  = 0;
				String str = s.next();
				char[] myChar = str.toCharArray();
				while(i < myChar.length) {
					if(myChar[i] == 'a') count++;
					System.out.println(myChar[i]);
					i++;
				}
			}
		}finally {
			if(s != null) s.close();
		}
		
		return count;
	}
	public static void main(String[] args) {
		try {
			int i = classCounter.CountCharacters("file");
			System.out.println(i);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
