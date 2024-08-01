import java.util.*;

public class Congresso {

  ArrayList<Participante> participantes;

  public Congresso(ArrayList<Participante> participantes){
    this.participantes = participantes;
  }

  public int totalParticipantes() {
    return participantes.size();
  }

  public int totalAssentos() { 
    int total = 0;
    for(int i = 0; i < this.participantes.size(); i++){
      total += this.participantes.get(i).getAssento();
    }
    return total;
  }
}