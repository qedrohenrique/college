public class SMSAdapter extends SMSNotificador implements INotificador {
  public void enviar(Msg msg, Dest dest) {
    Phone phone = new Phone(dest.destinatario);
    enviarSms(msg, phone);
  }
}