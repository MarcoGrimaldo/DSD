import java.io.*;
import java.net.*;
import java.nio.ByteBuffer; //Para manejo de ByteBuffer
import java.nio.ByteOrder;

public class udp_cliente
    {
    public static void main(String args[])
    {
        DatagramSocket sock = null;
        int port = 7200;

        //Viendo los valores maximos
        System.out.println("Tipo\tMínimo\tMáximo");
        System.out.println("byte\t" + Byte.MIN_VALUE + "\t" + Byte.MAX_VALUE);
        System.out.println("short\t" + Short.MIN_VALUE + "\t" + Short.MAX_VALUE);
        System.out.println("int\t" + Integer.MIN_VALUE + "\t" + Integer.MAX_VALUE);
        System.out.println("long\t" + Long.MIN_VALUE + "\t" + Long.MAX_VALUE);
        System.out.println("float\t" + Float.MIN_VALUE + "\t" + Float.MAX_VALUE);
        System.out.println("double\t" + Double.MIN_VALUE + "\t" + Double.MAX_VALUE);

        try
        {
            sock = new DatagramSocket();
            InetAddress host = InetAddress.getByName("localhost");

            final ByteBuffer buf = ByteBuffer.allocate(24); // Reserva 8 bytes para 2 enteros
            buf.order(ByteOrder.LITTLE_ENDIAN);
            buf.putInt(-2147483648); //Mínimo valor entero
            buf.putInt(2147483647); //Máximo valor entero
            buf.putDouble(4.9E-324);
            buf.putDouble(4.9E-324);
            DatagramPacket dp = new DatagramPacket(buf.array() , buf.limit(), host , port);
            sock.send(dp);
        }
        catch(IOException e)
        {
            System.err.println("IOException " + e);
        }
    }
}