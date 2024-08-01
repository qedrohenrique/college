public class Client {
  public static void main(String args[]) {
    INotificador[] notificadores = new INotificador[3];

    notificadores[0] = new EmailNotificador();
    notificadores[1] = new SMSAdapter();
    notificadores[2] = new PushAdapter();

    Msg msg = new Msg("Minha mensagem");
    Dest dest = new Dest("Meu destinatário");

    notificadores[0].enviar(msg, dest);
    notificadores[1].enviar(msg, dest);
    notificadores[2].enviar(msg, dest);
  }
}