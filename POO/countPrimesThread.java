
public class countPrimesThread implements Runnable{

	private int firstNumber, lastNumber;
	
	countPrimesThread(int f, int l){
		firstNumber = f;
		lastNumber = l;
	}
	
	public void run() {
		System.out.println("Nova Thread");
		int resp = 0;
		int a = firstNumber, b = lastNumber;
		while(a != b + 1) {
			if(checkIfPrime(a)) resp++;
			a++;
		}
		System.out.printf("Entre %d e %d, existem %d primos.\n\n", 
				firstNumber, lastNumber, resp);
	}
	
	private boolean checkIfPrime(int number) {
		if(number <= 1) return false;
		else {
			for(int i = 2; i < number; i++) {
				if(number % i == 0) return false;
			}
			System.out.printf("%d Prime\n", number);
			return true;
		}
	}

}
