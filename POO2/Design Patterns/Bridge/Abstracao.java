import java.util.ArrayList;
import java.util.List;

public class Abstracao {
  List l = new ArrayList();
  Queue q = new ArrayListQueue(l);

  public void operacao(){
    q.enqueue(1);
    q.size();
    q.dequeue();
    q.isEmpty();
  }
}