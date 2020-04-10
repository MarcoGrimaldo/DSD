import java.net.*;
import java.io.*;
import java.nio.ByteBuffer; //Para manejo de ByteBuffer
import java.nio.ByteOrder;
import java.awt.BorderLayout;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JPanel;

//Obtener los npoints de un poligono para reservar la memoria
//Mandar las cordenadas y, puesto que las x son obvias.
//graficar

public class Servidor extends JFrame {
    private DrawSine ventana;
    private double ptsY[];

    public Servidor() {
        ptsY = new double[785];
        for(int i = 0;i<785;i++)
            ptsY[i] = 0;
        setLayout(new BorderLayout());
        ventana = new DrawSine(ptsY);
        add(ventana, BorderLayout.CENTER);
    }

    public DrawSine getVentana()
    {
        return ventana;
    }

    public double[] getPtsY()
    {
        return ptsY;
    }

    public void setPtsY(double[] y)
    {
        ptsY = y;
    }
        
    class DrawSine extends JPanel {

        //private double ptsY[] = new double[785];
    
        public DrawSine(double y[])
        {
            this.setBackground(Color.white);
            //ptsY = y;
        }
    
        public void paintComponent(Graphics g) 
        {
            super.paintComponent(g);
                
            g.drawLine(0, 300, 800, 300);
            
            //meter en el aquí en el poligono las cordenadas
            Polygon p = new Polygon();
            
            //Coordenadas de prueba
           for (int x = 0; x <= 784; x++) {

                p.addPoint(x, 300 - (int) ( 300 * ptsY[x]));
            }
    
            g.setColor(Color.red);
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
        }
     }
  public static void main (String args[]) {
    
    Servidor frame = new Servidor();
    frame.setSize(800, 650);
    frame.setTitle("Proyecto3");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);

    try {
      DatagramSocket socketUDP = new DatagramSocket(7200);
      final ByteBuffer bufer = ByteBuffer.allocate(6280); //8 bytes de int x 785 en el array

      while (true) {
        // Construimos el DatagramPacket para recibir peticiones
        DatagramPacket peticion =
          new DatagramPacket(bufer.array(), bufer.limit());

        // Leemos una petición del DatagramSocket
        socketUDP.receive(peticion);

        byte[] data = peticion.getData();
        ByteBuffer buf = ByteBuffer.wrap(data);
        buf.order(ByteOrder.LITTLE_ENDIAN);

       double[] arrDouble = new double[785];
       arrDouble = frame.getPtsY();

        for(int i = 0; i < 785;i++)
        {
            arrDouble[i] = buf.getDouble();
        }
        
        frame.setPtsY(arrDouble);
        frame.getVentana().repaint();
        frame.getVentana().revalidate();


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