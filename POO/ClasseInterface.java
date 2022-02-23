import java.util.*;
public class ClasseInterface {
	public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		System.out.printf("Você deseja um quadrado ou um triângulo?\n[1] Quadrado;\n[2] Triângulo;\n");
		int obj = keyboard.nextInt();

		
		if(obj != 1 && obj != 2) {
			System.out.println("Opção inválida... Desligando o programa.");
			System.exit(0);
		}
		
		if(obj == 1) {
			System.out.println("Quais o tamanho do lado do seu quadrado?");
			Quadrado sq = new Quadrado(keyboard.nextDouble());
			System.out.println("Área do quadrado: "+sq.area());
			System.out.println("Perímetro do quadrado: "+sq.l*4);
		}else {
			System.out.println("Quais as medidas A, B e C do seu triângulo, respectivamente?");
			System.out.println("Separe os valores com um espaço. Ex: 3 4 5.");
			Triangulo tr = new Triangulo(keyboard.nextDouble(), keyboard.nextDouble(), keyboard.nextDouble());	
			if(tr.getLadoA() == tr.getLadoB() && tr.getLadoA() == tr.getLadoC()) {
				System.out.println("Equilátero.");
			}else if(tr.getLadoA() != tr.getLadoB() && tr.getLadoB() != tr.getLadoC() && tr.getLadoA() != tr.getLadoC()) {
				System.out.println("Escaleno.");
			}else {
				System.out.println("Isósceles.");
			}
		}
		
		keyboard.close();
	}
}
