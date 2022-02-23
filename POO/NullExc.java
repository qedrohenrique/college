
public class NullExc {
	public static void main(String[] args) throws NullPointerException{
		Object myObject = null;
		
		try {
			myObject.toString();
		}catch(NullPointerException e) {
			System.out.println(e.getMessage());
			throw e;
		}
		
	}
}
