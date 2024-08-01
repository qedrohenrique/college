public class EmailNotificador implements INotificador {
  public void enviar(Msg message, Dest destinatario) {
    System.out.println("Email: ");
    System.out.println(message.message);
    System.out.println(destinatario.destinatario);
  }
}