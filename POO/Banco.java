import java.util.*;
public class Banco {
	
	Scanner kb = new Scanner(System.in);
	Conta[] vet = {
		new Conta(1),
		new ContaCorrente(2, 100.0),
		new ContaPoupanca(3, 50.0)
	};
	int[] n = new int[3];
	
	public void attContas() {
		int i;
		for(i = 0; i < 3; i++) {
			if(vet[i].getClass().getName() == "ContaCorrente") {
				if(vet[i].getSaldo() >=  ((ContaCorrente) vet[i]).getLim()) System.out.println("Limite excedido.");
			}
			if(vet[i].getClass().getName() == "ContaPoupanca") {
				((ContaPoupanca) vet[i]).addJuros(kb.nextDouble());
			}
		}	
	}
		
	public void abrirConta() {
		int aux, i, t;
		System.out.println("Digite um número para sua conta: ");
		aux = kb.nextInt();
		System.out.println("Digite o tipo de sua conta (1) -> Corrente (2) -> Poupanca: ");
		t = kb.nextInt();
		if(t>2 || t<1) System.exit(0);
		for(i = 0; i < 3; i++) {
			if(aux == n[i]) System.out.println("Número já utilizado. Reinicie a operação.");
			else {
				if(t == 1) {
					n[i] = aux;
					vet[i] = new ContaCorrente(aux, 100.0);
					System.out.println("Conta criada.");
				}
				if(t == 2) {
					n[i] = aux;
					vet[i] = new ContaPoupanca(aux, 50.0);
					System.out.println("Conta criada.");
				}
			}	
		}
	}

	public void fecharConta() {
		int i, aux;
		System.out.println("Digite o número da sua conta: ");
		aux = kb.nextInt();
		for(i = 0; i < 3; i++) {
			if(aux == n[i]) {
				n[i] = -1;
				vet[i] = new Conta(-1);
				System.out.println("Conta fechada.");
				}
			}
		}
	
	public void pagarDividendos(int numConta, double quantPagar){
		int i;
		for(i=0;i>3;i++) {
			if(numConta == vet[i].getNumero()) {
				vet[i].debita(quantPagar);
			}
		}
	}
}
	
