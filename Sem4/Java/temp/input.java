import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class input {
    public static void main(String args[]){
        InputStreamReader sr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(sr);
        try{
            String abcd = br.readLine();
            System.out.println(abcd);
        }catch(IOException ioe){
            System.out.println(ioe);
        }

        Scanner sc = new Scanner(System.in);
        String elem = sc.nextLine();
        System.out.println(elem);

        String bcde = System.console().readLine();
        System.out.println(bcde);

        String lmao = args[0];
        System.out.println(lmao);
    }
}
