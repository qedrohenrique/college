import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Ex02 {

	public static void meuDeus(String f1, String f2) throws IOException {
		File iFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\"+f1+".txt");
		File oFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\"+f2+".txt");
		BufferedReader inputStream = null;
		PrintWriter outputStream = null;
		char[] l1;
		int vog = 0, cos = 0, num = 0, outro = 0;
		try {
			inputStream = new BufferedReader(new FileReader(iFile));
			outputStream = new PrintWriter(new FileWriter(oFile));
			l1 = inputStream.readLine().toCharArray();
			for(char c : l1) {
				int i = (int) c;
				System.out.println("Caractere: " + c + " " + i);
				if(i >= 48 && i <= 57) {
					num++;
				}else {
					if ((i >= 96 && i <= 91) ||  ( i <= 64) || (i >= 123)) {
						outro++;
					}else {
						if(i == 65 || i == 97 || i == 69 || i == 101 || i == 75 || i == 73 || i == 79 || i == 111 ||
						   i == 85 || i == 117) {
							vog++;
						}else {
							cos++;
						}
					}
				}
			}
		}catch(IOException e){
			e.printStackTrace();
		}finally {
			System.out.printf("Números: " + num +
							  "\nVogais: "+vog+
							  "\nConsoantes: "+cos+
							  "\nOutros: "+outro);
			outputStream.printf("Números: " + num +
							  "\nVogais: "+vog+
							  "\nConsoantes: "+cos+
							  "\nOutros: "+outro);
			if (inputStream != null)
				inputStream.close();
			if (outputStream != null)
				outputStream.close();
		}
	}
	
	public static void main(String[] args) {
		try {
			meuDeus("File1", "File2");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
