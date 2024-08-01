import java.util.ArrayList;

public class Instituicao extends Participante{
  private int totalMembros;
  private Individuo[] membros;

  public Instituicao(int total){
    this.totalMembros = total;
    this.membros = new Individuo[total];
    for(int i = 0; i < totalMembros; i++) membros[i] = new Individuo();
  }

  public Individuo[] getMembros() { 
    return membros;
  }

  public int getAssento() {
    int total = 0;
    for(int i = 0; i < totalMembros; i++)
      total += membros[i].getAssento();
    return total;
  }
}