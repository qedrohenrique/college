import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;


public class CircleList{
	
	public static void main(String[] args) {
		List circleList = new ArrayList();
		circleList.add(new Circle(0,0,5));
		circleList.add(new Circle(0,0,13));
		circleList.add(new Circle(0,0,1));
		
		ListIterator listNavigate = circleList.listIterator();
		
        while (listNavigate.hasNext())
            System.out.print(listNavigate.next() + " ");
        
    	
    	listNavigate.remove();
    	System.out.println("");
    	listNavigate = circleList.listIterator();
    	
        while (listNavigate.hasNext())
            System.out.print(listNavigate.next() + " ");
        System.out.println("");
        
        Circle[] myArray = new Circle[circleList.size()];
        circleList.toArray(myArray);

        for(int i=0; i<myArray.length; i++){
           System.out.println(myArray[i]);
        }
	}
}
