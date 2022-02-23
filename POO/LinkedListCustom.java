
public class LinkedListCustom {
	
	private Node head;
	private int listSize;
	
	public void insertNode(int new_data) {
		Node new_node = new Node(new_data);
		
		if(listSize == 0) {
			head = new_node;
			listSize++;
		}else{
			Node p = head;
			while(p.getNext() != null) p = p.getNext();
			p.setNext(new_node);
			listSize++;
		}
	}

    public void push(int new_data){	   
        Node new_node = new Node(new_data);
		if(listSize == 0) {
			head = new_node;
			listSize++;
		}else{
	        new_node.setNext(head);
	        head = new_node;
	        listSize++;
		}
    }	

	public Node searchNode(int data) {
		Node p = head;
		while(p != null) {
			if(p.getData() == data) return p;
			p = p.getNext();
		}
		return null;
	}
	
    void deleteNode(int key){

        Node temp = head, prev = null;
 
        if (temp != null && temp.getData() == key) {
            head = temp.getNext();
            listSize--;
            return;
        }
 
        while (temp != null && temp.getData() != key) {
            prev = temp;
            temp = temp.getNext();
        }

        if (temp == null)
            return;

        prev.setNext(temp.getNext());
        listSize--;
    }
    
    public void deepCopy(LinkedListCustom sourceList) {
    	Node currentNode = sourceList.head;
    
    	while(currentNode != null) {
    		this.push(currentNode.getData());
    		currentNode = currentNode.getNext();
    	}
    }
    
    public int sum() {
    	Node p = head;
    	int sum = 0;
    	while(p != null) {
    		sum += p.getData();
    		p = p.getNext();
    	}
    	return sum;
    }
    
    public void printList() {
    	Node p = head;
    	while(p != null) {
    		System.out.println(p.getData());
    		p = p.getNext();
    	}
    }
    
    public static void main(String[] args) {
		LinkedListCustom myList = new LinkedListCustom();
		LinkedListCustom copyList = new LinkedListCustom();
		
		myList.insertNode(1);
		myList.insertNode(2);
		myList.insertNode(3);
		
		copyList.deepCopy(myList);
		
		myList.deleteNode(2);
		copyList.deleteNode(3);
		
		myList.printList();
		copyList.printList();
	}

}
