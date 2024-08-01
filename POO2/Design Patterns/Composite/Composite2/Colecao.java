import java.util.ArrayList;

public class Colecao extends Publicacao{
  private ArrayList<Publicacao> artigos = new ArrayList();
  private String nome;

  public Colecao(String nome, int totalArtigos){
    this.nome = nome;
    for(int i = 0; i < totalArtigos; i++) artigos.add(new Artigo("teste", "autor"));
  }

  public void printInfo() { 
    System.out.println(this.nome);
    for(int i = 0; i < artigos.size(); i++)
       this.artigos.get(i).printInfo();
  }

  public int getArtigos() {
    int total = 0;
    for(int i = 0; i < artigos.size(); i++)
      total += artigos.get(i).getArtigos();
    return total;
  }
}