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

//La clase servidor hereda de JFrame
public class Servidor extends JFrame {
    //Ventana y ptsY, son objetos que vamos a utilizar en diferentes metodos.
    private DrawSine ventana;
    private double ptsY[];
    public boolean borra;

    //Llenamos de 0 para el constructor y no se mostrará nada (?)
    public Servidor() {
        ptsY = new double[785];
        for(int i = 0;i<785;i++)
            ptsY[i] = 0;
        //Borde
        setLayout(new BorderLayout());
        //Creamos un objeto de la clase DrawSine que herede de JPanel
        ventana = new DrawSine();
        //Agregamos el JPanel al JFrame
        add(ventana, BorderLayout.CENTER);
        borra = false;
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
    
    //Clase que dibuja en un JPanel
    class DrawSine extends JPanel {    
        public DrawSine()
        {
            this.setBackground(Color.white);
        }
    
        public void pintar() 
        {
            Graphics g = this.getGraphics();
            //super.paintComponent(g);

            //Linea negra de referencia
            g.drawLine(0, 300, 800, 300);
            
            //meteremos aqui en el poligono las cordenadas que mande el cliente
            Polygon p = new Polygon();
            
            //784 Son las coordenadas a dibujar en el ancho (eje x) de la ventana
           for (int x = 0; x <= 784; x++) {
                //Agregamos los puntos de Y que recibimos del cliente
                p.addPoint(x, 300 - (int) ( 300 * ptsY[x]));
            }

            //Banderas (?)
            if(borra)
              g.setColor(Color.white);
            else
              g.setColor(Color.red);
            
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
        }
     }
  public static void main (String args[]) {
    
    //Creamos el objeto Servidor que a su vez es un JFrame
    Servidor frame = new Servidor();
    frame.setSize(800, 650);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);
    frame.setTitle("Proyecto3");
    frame.setResizable(false);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    try {
      DatagramSocket socketUDP = new DatagramSocket(7200);
      final ByteBuffer bufer = ByteBuffer.allocate(6281); //8 bytes de int x 785 en el array + 1 de bandera

      while (true) {
        // Construimos el DatagramPacket para recibir peticiones
        DatagramPacket peticion =
          new DatagramPacket(bufer.array(), bufer.limit());

        // Leemos una petición del DatagramSocket
        socketUDP.receive(peticion);

        //Convertimos los bytes en LITTLE_ENDIAN para interpretarlos adecuadamente
        byte[] data = peticion.getData();
        ByteBuffer buf = ByteBuffer.wrap(data);
        buf.order(ByteOrder.LITTLE_ENDIAN);

       //Creamos un arreglo de 785 datos pues son los pixeles a dibujar
       double[] arrDouble = new double[785];
       //arrDouble = frame.getPtsY();

       //El primer double del datagrama es una bandera
        double bandera = 0;
        bandera = buf.getDouble();

        //Los demas son cordenadas que obtenemos
        for(int i = 0; i < 784;i++)
        {
            arrDouble[i] = buf.getDouble();
        }
        
        //Actualizamos la lista de coordenadas a dibujar
        frame.setPtsY(arrDouble);
        //Las dibujamos
        frame.getVentana().pintar();
        frame.getVentana().revalidate();

        System.out.print("Borra?");
        //Banderas
        if(bandera == 0)
        {
            System.out.println(" NO");
            frame.borra = false;
        }
        else
        {
            System.out.println(" SI");
            frame.borra = true;
        }

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