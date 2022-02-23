
public class Funcionario {
	private String sobreNome;
	private String nome;
	private double salarioHora;
	private int anosNaEmpresa;
	
	public void buscaFuncionario(Funcionario[] empregados, int anos) {
		for(int i = 0; i < empregados.length; i++) {
			if(empregados[i].anosNaEmpresa >= anos) {
				System.out.println(empregados[i].nome);
				System.out.println(empregados[i].sobreNome);
				System.out.println(empregados[i].salarioHora);
			}
		}
	}
}
