import java.net.*;
import java.io.*;
import java.nio.ByteBuffer; //Para manejo de ByteBuffer
import java.nio.ByteOrder;

//Obtener los npoints de un poligono para reservar la memoria
//Mandar las cordenadas y, puesto que las x son obvias.
//graficar

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


        System.out.print("Datagrama recibido del host: " +
                           peticion.getAddress());
        System.out.println(" desde el puerto remoto: " +
                           peticion.getPort());

        // Construimos el DatagramPacket para enviar la respuesta
        DatagramPacket respuesta =
          new DatagramPacket(peticion.getData(), peticion.getLength(),
                             peticion.getAddress(), peticion.getPort());

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