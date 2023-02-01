// WAP to input a string and output in alphabetical order
// STRING --> GINRTS

import java.io.*;

class stringrewrite{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a string");
        String str = br.readLine();
        int len = str.length();
        char ch[] = new char[len];
        for(int i=0;i<len;i++){
            ch[i] = str.charAt(i);
        }
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(ch[i]>ch[j]){
                    char temp = ch[i];
                    ch[i] = ch[j];
                    ch[j] = temp;
                }
            }
        }
        System.out.println("The string in alphabetical order is: ");
        for(int i=0;i<len;i++){
            System.out.print(ch[i]);
        }
    }
}