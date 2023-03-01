import java.util.*;

class Alpha extends Thread{
    int Sec;
    Alpha(int sec){
        Sec = sec;
    }
    public void run(){
        try{
            Thread.sleep(Sec);
            System.out.println("Thread Type 1 finished after " + Sec + " milliseconds");
        }catch(InterruptedException e){
            System.out.println("Thread type 1 interrupted");
        }
    }
}

class Beta extends Thread{
    public void run(){
        try{
            Thread.sleep(2000);
            System.out.println("Thread Type 2 finished after 2000 milliseconds");
        }catch(InterruptedException e){
            System.out.println("Thread Type 2 interrupted");
        }
    }
}

class MultiThreading{
    public static void main(String args[]){
        Alpha t1 = new Alpha(5000);
        Beta t2 = new Beta();
        Alpha t3 = new Alpha(10000);
        t1.start();
        t2.start();
        t3.start();
    }
}