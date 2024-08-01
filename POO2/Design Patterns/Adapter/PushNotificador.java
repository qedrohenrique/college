public class PushNotificador {
  public void enviarPush(Msg message, Device device) {
    System.out.println("Push: ");
    System.out.println(message.message);
    System.out.println(device.id);
  }
}