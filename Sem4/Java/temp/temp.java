import java.util.*;

public class temp {
    public static void main(String args[]){
        String alzo;
        Scanner sc = new Scanner(System.in);
        alzo = sc.next();
        String ozla="";
        for(int i=alzo.length()-1;i>=0;i--){
            ozla+=alzo.charAt(i);
        }
        if(alzo.equals(ozla)){
            System.out.println("Palindrome!!!");
        }
        sc.close();
    }
}
