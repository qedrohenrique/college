import java.util.Random;

public class Algarismo implements Flyweight{

    private int number;

    public Algarismo() {
        this.number = new Random().nextInt(10   );
    }

    public void operacao(int mutableState) {}

    public int getImutableState() {
        return this.number;
    }

}