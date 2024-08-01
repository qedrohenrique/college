public class SMSNotificador {
  public void enviarSms(Msg message, Phone number) {
    System.out.println("SMS: ");
    System.out.println(message.message);
    System.out.println(number.phone);
  }
}