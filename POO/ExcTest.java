public class ExcTest {
	
	public static void main(String[] args) throws Exception {
		try {
			int[] arr = new int[10];
			arr[11] = 3;
		} catch (Exception e) {
			e = new Exception("Erro");
			System.out.println(e.getMessage());
			throw e;
		}finally {
			System.out.println("I was here");
		}
	}
}