import java.util.*;

public class input{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String newString = sc.nextLine();
        System.out.println("You entered: " + newString);
        sc.close();
    }
}