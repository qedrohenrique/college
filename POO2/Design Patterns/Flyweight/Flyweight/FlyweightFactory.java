public class FlyweightFactory {
    
    private Flyweight[] algarismos = new Algarismo[10];

    public Flyweight getFlyweigth(int number) {
        if (algarismos[number] == null) {
            algarismos[number] = new Algarismo();
        }
        return algarismos[number];
    }
}