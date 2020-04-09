import java.net.*;
import java.io.*;
import java.nio.ByteBuffer; //Para manejo de ByteBuffer
import java.nio.ByteOrder;

public class server {

  public static void main (String args[]) {

    try {

      DatagramSocket socketUDP = new DatagramSocket(7200);
      final ByteBuffer bufer = ByteBuffer.allocate(40); //8 bytes de double x 5 en el array

      while (true) {
        // Construimos el DatagramPacket para recibir peticiones
        DatagramPacket peticion =
          new DatagramPacket(bufer.array(), bufer.limit());

        // Leemos una petición del DatagramSocket
        socketUDP.receive(peticion);

        byte[] data = peticion.getData();
        ByteBuffer buf = ByteBuffer.wrap(data);
        buf.order(ByteOrder.LITTLE_ENDIAN);

        double[] arrDouble = new double[10];

        for(int i = 0; i< 5;i++)
            arrDouble[i] = buf.getDouble();

        for(int i = 0; i< 5;i++)
            System.out.println("Double en "+i+": "+arrDouble[i]);
        

        /*int entero1 = buf.getInt();
        int entero2 = buf.getInt();
        System.out.println("int MIN = " + entero1 + " int MAX = " + entero2);


        /*int[] arrInt = new int[10];
        int cont;
        byte[] num = new byte [4];
        for(int i = 0; i < data.length ; i++)
        {
            for(int j = 0; j < 5 ; j++)
            {
                 

                cont++;
            }
        //}*/


        System.out.print("Datagrama recibido del host: " +
                           peticion.getAddress());
        System.out.println(" desde el puerto remoto: " +
                           peticion.getPort());

        // Construimos el DatagramPacket para enviar la respuesta
        DatagramPacket respuesta =
          new DatagramPacket(peticion.getData(), peticion.getLength(),
                             peticion.getAddress(), peticion.getPort());

        
        //System.out.println("Datos: "+buf.getInt()+"\nTamanio: "+data.length);

        // Enviamos la respuesta, que es un eco
        socketUDP.send(respuesta);
      }

    } catch (SocketException e) {
      System.out.println("Socket: " + e.getMessage());
    } catch (IOException e) {
      System.out.println("IO: " + e.getMessage());
    }
  }

}