import java.util.List;

public abstract class Queue {
  public List list;

  public Queue(List list) {
    this.list = list;
  }

  public abstract void enqueue(int number);
  public abstract int dequeue();
  public abstract int size();
  public abstract boolean isEmpty();
}