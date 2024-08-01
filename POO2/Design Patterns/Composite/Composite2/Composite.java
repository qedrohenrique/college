import java.util.*;

public class Composite {
  ArrayList<Publicacao> publicacoes;

  public Composite(ArrayList<Publicacao> publicacoes){
    this.publicacoes = publicacoes;
  }

  public void printStrings() {
    for(int i = 0; i < this.publicacoes.size(); i++){
      this.publicacoes.get(i).printInfo();
    }
  }

  public int totalArtigos() { 
    int total = 0;
    for(int i = 0; i < this.publicacoes.size(); i++){
      total += this.publicacoes.get(i).getArtigos();
    }
    return total;
  }
}