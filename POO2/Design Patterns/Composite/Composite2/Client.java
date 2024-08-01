import java.util.*;

public class Client {
  public static void main(String[] args){ 
    ArrayList<Publicacao> publicacoes = new ArrayList();

    publicacoes.add(new Colecao("teste", 5));
    publicacoes.add(new Colecao("teste", 12));
    publicacoes.add(new Artigo("a", "a"));
    publicacoes.add(new Artigo("a", "a"));
    publicacoes.add(new Artigo("a", "a"));
    publicacoes.add(new Artigo("a", "a"));

    Composite publicacoesComposite = new Composite(publicacoes);

    publicacoesComposite.printStrings();
    System.out.println(publicacoesComposite.totalArtigos());
  }
}