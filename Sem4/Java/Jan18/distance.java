import java.util.*;

class distance{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int temp;
        boolean choice = true;
        float a,u,t2,netTime=0,distance;
        while(choice){
            System.out.println("Enter the value of a and u");
            a = sc.nextFloat();
            u = sc.nextFloat();
            System.out.println("Enter the time interval");
            t2 = sc.nextFloat();
            netTime=t2;
            while (netTime<=50){        
                distance = u*netTime + (a*netTime*netTime)/2;           
                System.out.println(netTime + "seconds : " +distance);
                netTime+=t2;
            }
            System.out.println("Do you want to continue? 1 for yes and 0 for no");
            temp = sc.nextInt();
            choice = (temp==1)?true:false;
        }
        sc.close();
    }
}