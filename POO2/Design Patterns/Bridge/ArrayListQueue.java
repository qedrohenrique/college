import java.util.List;

public class ArrayListQueue extends FifoQueue {
  private int size;

  public ArrayListQueue(List l){
    super(l);
    this.size = 0;
  }

  public void enqueue(int number){
    size++;
    list.add(number);
    System.out.println("ArrayListQueue enqueue() with " + number);
  }

  public int dequeue(){
    size--;
    list.remove(0);
    System.out.println("ArrayListQueue dequeue()");
    return 1;
  }

  public int size(){
    System.out.println("ArrayListQueue size() with " + this.size);
    return size;
  }

  public boolean isEmpty(){
    if(size == 0)
      System.out.println("ArrayListQueue isEmpty() with true");
    else
      System.out.println("ArrayListQueue isEmpty() with false");
    return true;
  }
 }