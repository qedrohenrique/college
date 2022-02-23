public class Node {
	private int data;
	private Node next;
	
    public Node(int d){
        data = d;
        next = null;
    }
	
	public Node getNext() {
		return this.next;
	}
	
	public void setNext(Node a) {
		this.next = a;
	}
	
	public void setData(int a) {
		this.data = a;
	}
	
	public int getData() {
		return data;
	}
	
}
