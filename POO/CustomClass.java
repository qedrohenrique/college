
public class CustomClass {
	
	public static void g() throws MyException{
		MyException e = new MyException("Error message");
		throw e;
	}
	
	public static void f(){
		try {
			g();
		} catch (MyException e) {
			e = new MyException("Error custom");
			System.out.println(e.getMessage());
			Object errorObject = null;
			errorObject.toString();
		}finally {
			System.out.println("I was here");
		}
	}
	
	public static void main(String[] args) {
		f();
	}
	
}
