import java.util.Scanner;
public class TestSequence {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Escreva sua sequência: ");
		SequenceString str = new SequenceString(kb.nextLine());
		
		System.out.println("Sua sequência é: "+ str);
		System.out.println("A sua primeira letra é: "+ str.charAt(0));
		System.out.println("Ela tem tamanho: "+ str.length());
		System.out.println("Uma subsequência possível é: "+ str.subSequence(3, 5));
		System.out.println("Método toString(): "+ str.toString());
	}
}
