import java.util.*;

abstract class SensorObservable {
    public List<InstituteObserver> observers = new ArrayList<>();

    public void addObserver(InstituteObserver observer) {
        observers.add(observer);
    }

    protected void notifyObservers() {
        for (InstituteObserver observer : observers) {
            observer.update(this);
        }
    }

    public abstract String getPh();
}