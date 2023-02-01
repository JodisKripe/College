// code to read an array of votes and classify them as valid or invalid and assign a ballot number

import java.util.*

class election{
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of votes");
        n = sc.nextInt();
        int votes[] = new int[n];
        System.out.println("Enter the votes");
        for(int i=0;i<n;i++){
            votes[i] = sc.nextInt();
        }
        int valid=0,invalid=0;
        for(int i=0;i<n;i++){
            if(votes[i]>=1 && votes[i]<=5){
                valid++;
            }
            else{
                invalid++;
            }
        }
        System.out.println("The number of valid votes are: "+valid);
        System.out.println("The number of invalid votes are: "+invalid);
        System.out.println("The ballot numbers are: ");
        for(int i=0;i<n;i++){
            System.out.println(i+1);
        }
    }
}