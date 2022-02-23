import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;

public class fileMap {
	public static void insertMap(String a, HashMap map) throws IOException{

		Scanner s = null;
		File file = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula16\\src\\"+a+".txt");
		
		try {
			s = new Scanner(new BufferedReader(new FileReader(file)));
			String str = null;
			int key = 0;
			while(s.hasNextLine()) {
				str = s.next();
				key = s.nextInt();
				map.put(key, str);
			}
		}finally {
			if(s != null) s.close();
		}
	}
	
	@SuppressWarnings("unchecked")
	public static void writeMap(String a, HashMap myMap) throws IOException{
  
        HashMap<Integer, String> map = myMap;
  
        File file = new File("C:\\Users\\Pichau\\eclipse-workspace\\Aula16\\src\\"+a+".txt");
        BufferedWriter bf = null;
  
        try{
            bf = new BufferedWriter(new FileWriter(file));
            for (Map.Entry<Integer, String> entry : map.entrySet()) {
                bf.write(entry.getKey() + " "  + entry.getValue());
                bf.newLine();
            }
  
            bf.flush();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        finally {
                bf.close();
        }
	}
	
	public static void main(String[] args) {
		HashMap<String, String> myMap = new HashMap<String, String>();
		try {
			fileMap.insertMap("myfile", myMap);
			System.out.println(myMap.get(3));
			fileMap.writeMap("myMapOutput", myMap);
	
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
