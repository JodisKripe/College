class printer extends Thread{
    synchronized int print(String name, int number){
        int no=number;
        if(number%2==0 && name=="odds"){
            System.out.println(++no);
        }
        else if(number%2==1 && name=="evens"){
            System.out.println(++no);
        }
        return no;
    }
}    


class thr extends Thread{
    printer target;
    static int number;
    String name;
    thr(printer target,String name){
        this.target=target;
        number=0;
        this.name=name;
        this.start();
    }
    public void run(){
        while(number <10){
            synchronized(target){
                if(number<10){number=target.print(this.name,number);}
            }
        }
    }
}

public class Threadprintoddandeven {
    public static void main(String args[]){    
        printer P = new printer();
        thr t1= new thr(P,"odds");
        thr t2= new thr(P,"evens");
        try{
            t1.join();
            t2.join();
        }catch(InterruptedException e){
            System.out.println("ded");
        }
    }
    
}
