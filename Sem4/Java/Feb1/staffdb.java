import java.util.*;

abstract class Staff{
    String code,name;
    Staff(String Code , String Name){
        code = Code;
        name = Name;
    }
    abstract void display();
}

class Teacher extends Staff{
    String subject;
    int publication;
    Teacher(String Code, String Name, String Subject, int Publication){
        super(Code,Name);
        subject=Subject;
        publication=Publication;
    }
    void display(){
        System.out.println("Code: " + code + "\nName: " + name + "\nSubject: " + subject + "\nPublication: " + publication);
    }
}

abstract class Typist extends Staff{
    int speed;
    Typist(String Code, String Name, int Speed){
        super(Code,Name);
        speed=Speed;
    }
}

class Regular extends Typist{
    int salary;
    Regular(String Code, String Name, int Speed, int Salary){
        super(Code,Name,Speed);
        salary=Salary;
    }
    void display(){
        System.out.println("Code: " + code + "\nName: " + name + "\nSpeed: " + speed + "\nSalary: " + salary);
    }
}

class Casual extends Typist{
    int dailywage;
    Casual(String Code, String Name, int Speed, int Dailywage){
        super(Code,Name,Speed);
        dailywage=Dailywage;
    }
    void display(){
        System.out.println("Code: " + code + "\nName: " + name + "\nSpeed: " + speed + "\nDailywage: " + dailywage);
    }
}

class Officer extends Staff{
    String grade;
    Officer(String Code, String Name, String Grade){
        super(Code,Name);
        grade=Grade;
    }
    void display(){
        System.out.println("Code: " + code + "\nName: " + name + "\nGrade: " + grade);
    }
}

class staffdb{
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of staffs");
        n = sc.nextInt();
        Staff s[] = new Staff[n];
        for(int i=0;i<n;i++){
            System.out.println("Enter the type of staff");
            String type = sc.next();
            if(type.equals("Teacher")){
                System.out.println("Enter the code");
                String code = sc.next();
                System.out.println("Enter the name");
                String name = sc.next();
                System.out.println("Enter the subject");
                String subject = sc.next();
                System.out.println("Enter the publication");
                int publication = sc.nextInt();
                s[i] = new Teacher(code,name,subject,publication);
            }
            else if(type.equals("Regular")){
                System.out.println("Enter the code");
                String code = sc.next();
                System.out.println("Enter the name");
                String name = sc.next();
                System.out.println("Enter the speed");
                int speed = sc.nextInt();
                System.out.println("Enter the salary");
                int salary = sc.nextInt();
                s[i] = new Regular(code,name,speed,salary);
            }
            else if(type.equals("Casual")){
                System.out.println("Enter the code");
                String code = sc.next();
                System.out.println("Enter the name");
                String name = sc.next();
                System.out.println("Enter the speed");
                int speed = sc.nextInt();
                System.out.println("Enter the dailywage");
                int dailywage = sc.nextInt();
                s[i] = new Casual(code,name,speed,dailywage);
            }
            else if(type.equals("Officer")){
                System.out.println("Enter the code");
                String code = sc.next();
                System.out.println("Enter the name");
                String name = sc.next();
                System.out.println("Enter the grade");
                String grade = sc.next();
                s[i] = new Officer(code,name,grade);
            }
        }
        for(int i=0;i<n;i++){
            s[i].display();
            System.out.println();
        }
    }
}