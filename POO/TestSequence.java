import java.util.Scanner;
public class TestSequence {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Escreva sua sequ�ncia: ");
		SequenceString str = new SequenceString(kb.nextLine());
		
		System.out.println("Sua sequ�ncia �: "+ str);
		System.out.println("A sua primeira letra �: "+ str.charAt(0));
		System.out.println("Ela tem tamanho: "+ str.length());
		System.out.println("Uma subsequ�ncia poss�vel �: "+ str.subSequence(3, 5));
		System.out.println("M�todo toString(): "+ str.toString());
	}
}
