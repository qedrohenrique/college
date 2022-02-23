import java.util.Collection;
import java.util.List;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.TreeMap;

public class ItemMercado {

	String key;
	String value;
	
	ItemMercado(String a, String b){
		this.key = a;
		this.value = b;
	}
	
	public static ItemMercado transformIntoObject(String line) {
		char[] charLine = line.toCharArray();
		
		StringBuilder sb = new StringBuilder();
		for(char i : charLine) {
			if(i == '\\') break;
			else sb.append(i);
		}
		String instKey = sb.toString();
		
		sb = new StringBuilder();
		for(char i : charLine) {
			if(i == '\n') break;
			else sb.append(i);
		}
		String instValue = sb.toString();
		
		return new ItemMercado(instKey, instValue);
	}
	
	public static void main(String[] args) throws IOException {
		
		Charset charset = StandardCharsets.UTF_8;
		
		File aFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\itens1.txt");
		File bFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\itens2.txt");
		
		File cFile = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula17\\src\\itens3.txt");
		try {
			cFile.createNewFile();
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		
		PrintWriter cFileWriter = new PrintWriter(new FileWriter(cFile));
		
		TreeMap newItemList = new TreeMap();
		ItemMercado itMerc = null;

		try {
			Path filePath = aFile.toPath();
			List<String> lines = Files.readAllLines(filePath, charset);
            for(String line: lines) {
                itMerc = transformIntoObject(line);
                newItemList.put(itMerc.key, itMerc.value);
            }
            
            filePath = bFile.toPath();
            lines = Files.readAllLines(filePath, charset);
            for(String line: lines) {
                itMerc = transformIntoObject(line);
                newItemList.put(itMerc.key, itMerc.value);
            }
            Collection <String> values = newItemList.values();
            for(String value : values) {
            	cFileWriter.printf(value+"\n");
            	System.out.println(value);
            }
		} catch (IOException e) {
			e.printStackTrace();
		}finally {
			cFileWriter.close();
		}
	}
}
