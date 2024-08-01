import java.util.List;

public class VectorQueue extends FifoQueue {
  private int size;

  public VectorQueue(List l){
    super(l);
    this.size = 0;
  }

  public void enqueue(int number){
    size++;
    list.add(number);
    System.out.println("VectorQueue enqueue() with " + number);
  }

  public int dequeue(){
    list.remove(size-1);
    size--;
    System.out.println("VectorQueue dequeue()");
    return 1;
  }

  public int size(){
    System.out.println("VectorQueue size() with " + this.size);
    return size;
  }

  public boolean isEmpty(){
    if(size == 0)
      System.out.println("VectorQueue isEmpty() with true");
    else
      System.out.println("VectorQueue isEmpty() with false");
    return true;
  }
 }