import java.io.*;
import java.net.*;
import java.nio.ByteBuffer; //Para manejo de ByteBuffer

public class udp_cliente
    {
    public static void main(String args[])
    {
        DatagramSocket sock = null;
        int port = 7200;

        try
        {
            sock = new DatagramSocket();
            InetAddress host = InetAddress.getByName("localhost");

            final ByteBuffer buf = ByteBuffer.allocate(8); // Reserva 8 bytes para 2 enteros
            buf.putInt(-2147483648); //Mínimo valor entero
            buf.putInt(2147483647); //Máximo valor entero
            DatagramPacket dp = new DatagramPacket(buf.array() , buf.limit(), host , port);
            sock.send(dp);
        }
        catch(IOException e)
        {
            System.err.println("IOException " + e);
        }
    }
}