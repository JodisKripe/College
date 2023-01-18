import java.util.*;

class pattern{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int temp,counter=1;
        boolean choice = true;
        int n;
        while(choice){
            System.out.println("Enter the value of n");
            n = sc.nextInt();
            System.out.println("\n\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    System.out.print(counter++ + " ");
                }
                System.out.println();
            }
            counter=1;
            System.out.println("\n\nDo you want to continue? 1 for yes and 0 for no");
            temp = sc.nextInt();
            choice = (temp==1)?true:false;
        }
        sc.close();
    }
}