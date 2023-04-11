// Write a method called delete( String str, int m) that returns the input string with the mth element removed

import java.util.*;

public class DeleteMthElement{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string");
        String str = sc.nextLine();
        System.out.println("Enter the index");
        int m = sc.nextInt();
        System.out.println(delete(str,m));
    }
    public static String delete(String str, int m){
        String str2 = "";
        for(int i=0;i<str.length();i++){
            if(i!=m-1){
                str2 = str2 + str.charAt(i);
            }
        }
        return str2;
    }
}