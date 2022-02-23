
public class SequenceString implements CharSequence{
	private String str;
	
	//Construtor
	public SequenceString(String s) {
		str = s;
	}
	
	//Implementacoes
	public char charAt(int index) {
	    return str.charAt(index);
	}


	public int length() {
		return str.length();
	}


	public CharSequence subSequence(int start, int end) {
		return new SequenceString(str.substring(start, end));
	}
	
	public String toString() {
		return str.toString();
	}
	
}
