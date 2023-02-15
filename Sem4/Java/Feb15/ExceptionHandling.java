import java.util.*;

// Write a code to throw and catch NullPointerException and ArrayIndexOutOfBoundsException

class ExceptionHandling{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int[] a = new int[5];
        for(int i=0;i<5;i++){
            try{
                System.out.println("Enter the index of the array");
                int index = sc.nextInt();
                System.out.println("Enter the value to be stored at index "+index);
                int value = sc.nextInt();
                a[index] = value;
            }
            catch(ArrayIndexOutOfBoundsException e){
                System.out.println("The index is out of bounds");
                i--;
            }
        }
        for(int i=0;i<5;i++){
            System.out.print(a[i] + " ");
        }
    }
}