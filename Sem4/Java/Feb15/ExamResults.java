import java.util.*;

// Given the annual examination Results of 10 students. Write a program to read the data and determine total marks, highest marks in each subject and roll number of the student who scored it.

// 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 0 0 0 10 2 3 4

class Results{
    int rollno;
    int marks1,marks2,marks3;
    int total;
    static int maxmarks1,maxmarks2,maxmarks3;
    static int totalmax;
    static int rollmax1,rollmax2,rollmax3,rollmax;
    Results(int rollno,int marks1,int marks2,int marks3){
        this.rollno = rollno;
        this.marks1 = marks1;
        this.marks2 = marks2;
        this.marks3 = marks3;
        total = marks1+marks2+marks3;
        if(marks1>maxmarks1){
            maxmarks1 = marks1;
            rollmax1 = rollno;
        }
        if(marks2>maxmarks2){
            maxmarks2 = marks2;
            rollmax2 = rollno;
        }
        if(marks3>maxmarks3){
            maxmarks3 = marks3;
            rollmax3 = rollno;
        }
        if(total>totalmax){
            totalmax = total;
            rollmax = rollno;
        }
    }
}

class ExamResults{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Results[] r = new Results[10];
        for(int i=0;i<10;i++){
            System.out.println("Enter the roll number of the student");
            int rollno = sc.nextInt();
            System.out.println("Enter the marks of the student in 3 subjects");
            int marks1 = sc.nextInt();
            int marks2 = sc.nextInt();
            int marks3 = sc.nextInt();
            r[i] = new Results(rollno,marks1,marks2,marks3);
        }
        System.out.println("The total marks of each student are: ");
        for(int i=0;i<10;i++){
            System.out.println("The total marks of student "+r[i].rollno+" are "+r[i].total);
        }
        System.out.println("The highest marks in each subject are: ");
        System.out.println("The highest marks in subject 1 are "+Results.maxmarks1+" scored by student "+Results.rollmax1);
        System.out.println("The highest marks in subject 2 are "+Results.maxmarks2+" scored by student "+Results.rollmax2);
        System.out.println("The highest marks in subject 3 are "+Results.maxmarks3+" scored by student "+Results.rollmax3);
        System.out.println("The highest total marks are "+Results.totalmax+" scored by student "+Results.rollmax);
    }
}