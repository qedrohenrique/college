import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class copyContent {
	public static void copyFileContent(String inputFile, String outputFile) throws IOException{
		FileReader inputStream = null;
		FileWriter outputStream = null;
		inputFile = "C:\\Users\\Pichau\\eclipse-workspace\\Aula16\\src\\"+inputFile;
		outputFile = "C:\\Users\\Pichau\\eclipse-workspace\\Aula16\\src\\"+outputFile;
		try {
			int c;
			inputStream = new FileReader(inputFile);
			outputStream = new FileWriter(outputFile);
			while ((c = inputStream.read()) != -1) {
				outputStream.write((char) c);
				System.out.println((char)c);
			}
		}finally {
			if(inputStream != null) inputStream.close();
			else outputStream.close();
		}
	}
	
	public static void main(String[] args) {
		try {
			copyContent.copyFileContent("input.txt", "output.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
