import java.util.Scanner;

public class counterPrimes {
	public static void main(String[] args) throws InterruptedException {
		
		// Intervalo 
		
		int firstNumber = 1;
		int lastNumber = 10;
		
		// Número de Threads
		
		Scanner sc = new Scanner(System.in);
		int numThread = sc.nextInt();
		int offset = lastNumber / numThread;
		
		//
		
		if(numThread == 0 || numThread > 5) {
			System.out.println("Número inválido");
			System.exit(0);
		}

		int a = firstNumber;
		int b = a + offset - 1;
		Thread myThread = null;
		
		for(int i = 0; i < numThread; i++) {

			myThread = new Thread(new countPrimesThread(a, b));
			myThread.start();
			myThread.join();
			a = b + 1;
			if(i == numThread-2) b = lastNumber;
			else b = a + offset - 1;
			
			
		}
	}
}
