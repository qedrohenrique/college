
public class MyException extends Exception{
	String errorMessage = new String();
	
	public MyException() {
	}
	
	public MyException(String a) {
		super(a);
		errorMessage = a;
	}
	
	public String getMessage() {
		return this.errorMessage;
	}
	
	public static void main(String[] args) throws Exception{
		try {
			MyClass.MyMethod();
		} catch (Exception e) {
			e = new MyException("Error custom");
			System.out.println(e.getMessage());
			throw e;
		}finally {
			System.out.println("I was here");
		}
	}
}
