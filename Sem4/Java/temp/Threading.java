class ExtendingThread extends Thread{
    String name;
    int timeout;
    Thread t;
    Callme target;
    ExtendingThread(String name,int timeout,Callme target){
        super(name);
        this.name=name;
        this.timeout=timeout;
        this.target = target;
        this.start();
    }
    public void run(){
        try{
            System.out.println("Thread "+name+" has Started");
            synchronized(target){
                target.callme(name,timeout);
            }
        } catch(InterruptedException e){
            System.out.println(name + " was interrupted and killed");
        }
    }
    public void bye(){
        System.out.println("GoodBye " + name);
    }
}

class Callme{
    void callme(String Text, int timeout) throws InterruptedException{
        try{
            System.out.println(Text + " is in the critical section.");
            Thread.sleep(timeout);
            System.out.println(Text + " has exited");
        } catch(InterruptedException e){
            System.out.println("Exception caught.");
        }
    }
}

public class Threading{
    public static void main(String args[])
    {   
        Callme target = new Callme();
        ExtendingThread thr = new ExtendingThread("thr",4000,target);
        ExtendingThread hopr = new ExtendingThread("hopr", 5000,target);
        System.out.println(hopr.isAlive());
        System.out.println(thr.isAlive());
        try{
            thr.join();
            System.out.println(thr.isAlive());
            hopr.join();
        } catch(InterruptedException e){
            System.out.println("Someone died");
        }
        thr.bye();
        hopr.bye();
    }
}