// Java applet code to implement event handling using one label and one button
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class eventHandling extends Applet implements ActionListener{
    Label l,l2;
    Button b;
    int ch=0;
    String lal = "Off";
    public void paint(Graphics g){
        g.drawString(lal,100,100);
    }
    public void init(){
        l = new Label("Click the button to change the text");
        b = new Button("Click me");
        // l2 = new Label("uwu");
        // l2.setBounds(150,150,100,100);
        add(l);
        add(b);
        //add(l2);
        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
     if(ch==0){
        lal = "On";
        ch =1;
     } else{
        lal = "Off";
        ch=0;
     }
     repaint();
    }
}
/*
<applet code="eventHandling.class" width="250" height="100">
</applet>
*/