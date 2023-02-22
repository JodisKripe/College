// WAP to check if two floating point numbers are the same upto 3 decimal places

import java.util.*;
import java.lang.*;

class threeDigitAccuracy{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first number");
        double a = sc.nextDouble();
        System.out.println("Enter the second number");
        double b = sc.nextDouble();
        if(Math.abs(a-b)<0.001){
            System.out.println("The numbers are the same upto 3 decimal places");
        }
        else{
            System.out.println("The numbers are not the same upto 3 decimal places");
        }
    }
}