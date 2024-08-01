public class Client {
    public static void main(String[] args) {
        SensorData sData = new SensorData();

        for(int i = 0; i < 2; i++){
            ConcreteInstitute observer = new ConcreteInstitute();
            sData.addObserver(observer);
        }

        ConcreteInstitute i = (ConcreteInstitute)sData.observers.get(0);

        sData.setData("1");
        System.out.println("Current value:" + i.instData);

        sData.setData("12");
        System.out.println("Current value:" + i.instData);

        ConcreteInstitute observer = new ConcreteInstitute();
        sData.addObserver(observer);
        sData.setData("5");
        System.out.println("Current value:" + i.instData);
    }
}
