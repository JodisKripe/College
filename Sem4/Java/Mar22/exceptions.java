import java.util.*;


class exceptions{
    public static void main(String args[]){
        double a,b,c;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of a: ");
        a = sc.nextDouble();
        System.out.println("Enter the value of b: ");
        b = sc.nextDouble();
        System.out.println("Enter the value of c: ");
        c = sc.nextDouble();
        try{
            if(a==0){
                throw new ArithmeticException("a cannot be zero");
            }
            else{
                double d = (b*b) - (4*a*c);
                if(d<0){
                    throw new ArithmeticException("The roots are imaginary");
                }
                else{
                    double r1 = (-b + Math.sqrt(d))/(2*a);
                    double r2 = (-b - Math.sqrt(d))/(2*a);
                    System.out.println("The roots are: " + r1 + " and " + r2);
                }
            }
        }catch(ArithmeticException e){
            System.out.println(e);
        }
        System.out.println("End of program");
    }
}