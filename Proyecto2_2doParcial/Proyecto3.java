/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyecto3;

import java.awt.BorderLayout;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Proyecto3 extends JFrame {

public Proyecto3() {
    setLayout(new BorderLayout());
    add(new DrawSine(), BorderLayout.CENTER);
}

public static void main(String[] args) {
    Proyecto3 frame = new Proyecto3();
    frame.setSize(800, 650);
    frame.setTitle("Proyecto3");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);

}

class DrawSine extends JPanel {

    public DrawSine()
    {
        this.setBackground(Color.white);
    }
    
    double f(double x) {
        return Math.sin(x);
    }

    double gCos(double y) {
        return Math.cos(y);
    }
    
    double deToRad(double n)
    {
        return (n / 100.0) *  Math.PI/1.96;
    }

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
            
        g.drawLine(0, 300, 800, 300);
        
        //meter en el aquí en el poligono las cordenadas
        Polygon p = new Polygon();
        
        //Coordenadas de prueba
       for (int x = 0; x <= 800; x++) {
            p.addPoint(x, 300 -(int) (300 * f( deToRad(x) )));
        }
       
        g.setColor(Color.red);
        g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
    }
 }
}
