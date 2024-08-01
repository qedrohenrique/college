public class PushAdapter extends PushNotificador implements INotificador {
  public void enviar(Msg msg, Dest dest) {
    Device device = new Device(dest.destinatario);
    enviarPush(msg, device);
  }
}