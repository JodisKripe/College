import java.util.*;

// Create a Result class that implements a sports interface and extends a Test class which extends a student class

class Student{
    int rollno;
    void putno(int R){
        rollno=R;
    }
    void getno(){
        System.out.println(rollno);
    }
}

class Test extends Student{
    int M1,M2;
    void putmarks(int m1, int m2){
        M1=m1;M2=m2;
    }
    void getmarks(){
        System.out.println("M1: "+M1+"\nM2: "+M2);
    }
}

interface Sports{
    final static int sportswt=60;
    abstract void putwt(int WT);
}

class Result extends Test implements Sports{
    float total;
    int wt;
    public void putwt(int WT){
        wt=WT;
    }
    void display(){
        float display = (M1 + M2 + wt);
        System.out.println(rollno+" : "+display);
    }
}

class Exam{
    public static void main(String args[]){
        Result R1= new Result();
        Scanner sc = new Scanner(System.in);
        int R,m1,m2,wt;
        R=sc.nextInt();
        m1=sc.nextInt();
        m2=sc.nextInt();
        wt=sc.nextInt();
        R1.putno(R);
        R1.putmarks(m1,m2);
        R1.putwt(wt);
        R1.display();
    }
}