package ConfigurationManager;

public class Properties {
    private String version;

    public Properties(){
      this.version = "1.1";
    }

    public String getProperty(String key){
      return this.version;
    }
}