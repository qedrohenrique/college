import Handlers.*;
import ExternalCatalog.*;
import Users.*;

public class BookAvailabilityNotifier {
    public void notifyUser(User user, Notification notification) {
        System.out.println("Notification for user " + user.getName() + ": " + notification.getMessage());
    }
}
