import java.util.*;

class SensorData extends SensorObservable {
    private String pH;

    public String getPh(){
        return this.pH;
    }

    public void setPh(String pH){
        this.pH = pH;
    }

    public void setData(String pH) {
        setPh(pH);
        notifyObservers();
    }
}