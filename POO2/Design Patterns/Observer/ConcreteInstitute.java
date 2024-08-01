public class ConcreteInstitute implements InstituteObserver {
  public String instData;

  public void update(SensorObservable data) {
    this.instData = data.getPh();
    System.out.println(this.instData);
  }
}