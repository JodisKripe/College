import java.util.*;

// for i in {1..310};do echo $i;done | tr "\n" " " | xclip -selection clipboard

class temperatureCatalog{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of cities");
        int n = 10;
        int Temperature[][] = new int[31][10];
        for(int i=0;i<31;i++){
            for(int j=0;j<n;j++){
                System.out.println("Enter the temperature of city "+(j+1)+" on day "+(i+1));
                Temperature[i][j] = sc.nextInt();
            }
        }
        int max = Temperature[0][0];
        int min = Temperature[0][0];
        int maxcity = 0;
        int mincity = 0;
        int maxday = 0;
        int minday = 0;
        for(int i=0;i<31;i++){
            for(int j=0;j<n;j++){
                if(Temperature[i][j]>max){
                    max = Temperature[i][j];
                    maxcity = j;
                    maxday = i;
                }
                if(Temperature[i][j]<min){
                    min = Temperature[i][j];
                    mincity = j;
                    minday = i;
                }
            }
        }
        System.out.println("The maximum temperature is "+max+" on day "+(maxday+1)+" in city "+(maxcity+1));
        System.out.println("The minimum temperature is "+min+" on day "+(minday+1)+" in city "+(mincity+1));

    }
}