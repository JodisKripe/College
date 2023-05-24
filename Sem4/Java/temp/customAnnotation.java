@interface Smartphone{
    String os() default "Android";
    int ver() default 1;
}

@Smartphone(os="Android",ver=4)
class Nokia{
    String model = "a45";
    int size =6;
    Nokia(){
        System.out.println(model+size);
    }
}

public class customAnnotation {
    public static void main(String args[]){
        Nokia n1 = new Nokia();
    }
}
