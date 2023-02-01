import java.util.*;

class largest{
    public static void main(String args[]){
        int a,b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of a");
        a = sc.nextInt();
        System.out.println("Enter the value of b");
        b = sc.nextInt();
        Compare c = new Compare(a,b);
        c.compare();
    }
}

class Compare{
    int x,y;
    Compare(int a,int b){
        x = a;
        y = b;
    }
    void compare(){
        if(x>y){
            System.out.println("The largest number is a: "+x);
        }
        else if(y>x){
            System.out.println("The largest number is b: "+y);
        }
        else{
            System.out.println("Both the numbers are equal");
        }
    }
}