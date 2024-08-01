public class Artigo extends Publicacao{
  private String nome;
  private String autor;

  public Artigo(String nome, String autor){
    this.nome = nome;
    this.autor = autor;
  }

  public int getArtigos() {
    return 1;
  };

  public void printInfo(){
    System.out.println("nome: " +this.nome);
    System.out.println("autor: " + this.autor);
  }
}