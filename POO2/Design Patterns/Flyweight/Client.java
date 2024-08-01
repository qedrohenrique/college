public class Client {
    public static void main(String[] args) {
        FlyweightFactory factory = new FlyweightFactory();
        Flyweight[] flyweight = new Flyweight[20];

        for(int i = 0; i < 20; i++) {
            flyweight[i] = factory.getFlyweigth(i % 2);
        }

        for(int i = 0; i < 20; i++) {
            System.out.println(flyweight[i].getImutableState() + " " + flyweight[i]);
        }
    }
}