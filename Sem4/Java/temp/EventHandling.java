import java.awt.*;
import java.awt.event.*;


import java.applet.*;

class Handler implements ActionListener{
    public void actionPerformed(ActionEvent e){
        System.out.println("Et Voila");
    }
    
}

public class EventHandling extends Applet implements ActionListener,TextListener {
    Label l1,l2;
    Button b;
    Button b2;
    int ch=0;
    String lal="Off";
    Handler h1;
    int mX =0 , mY =0;
    TextField TXT;
    public void paint(Graphics g){
        g.drawString(lal,10,20);
    }
    public void init(){
        l1 = new Label("Click the button to change the Label");
        b = new Button("Click Me");
        b2 = new Button("I am Clickai");
        h1 = new Handler();
        TXT = new TextField(10);
        TXT.addTextListener(this);
        add(TXT);
        add(l1);
        //add(b);
        add(b2);
        b2.addActionListener(h1);
        b.addActionListener(this);
    }
    public void textValueChanged(TextEvent te){
        System.out.println(TXT.getText());
    }
    public void actionPerformed(ActionEvent e){
        if(ch==0){
            lal = "On";
            ch=1;
        } else{
            lal = "Off";
            ch =0;
        }
        repaint();
    }
    
}
/*
<applet code="EventHandling.class" width="250" height="100">
</applet>
*/