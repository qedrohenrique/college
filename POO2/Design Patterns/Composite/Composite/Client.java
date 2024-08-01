import java.util.*;

public class Client {
  public static void main(String[] args){ 
    ArrayList<Participante> participantes = new ArrayList();

    participantes.add(new Instituicao(10));
    participantes.add(new Instituicao(5));
    participantes.add(new Individuo());
    participantes.add(new Individuo());
    participantes.add(new Individuo());

    Congresso congresso = new Congresso(participantes);

    System.out.println(congresso.totalAssentos());
    System.out.println(congresso.totalParticipantes());
  }
}