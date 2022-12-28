#include <iostream>
using namespace std;

class Student{
    private:
        int roll;
        char name[20];
    public:
        void getDetails(){
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter name: ";
            cin >> name;
        }
        void displayDetails(){
            cout << "Roll number: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << endl;
        }
};

class Exam:public Student{
    public:
        int sub1,sub2,sub3,sub4,sub5,sub6;
        void getMarks(){
            cout<<"Enter marks of 6 subjects: ";
            cin>>sub1>>sub2>>sub3>>sub4>>sub5>>sub6;
        }
        void displayMarks(){
            cout<<"Marks of 6 subjects: "<<sub1<<" "<<sub2<<" "<<sub3<<" "<<sub4<<" "<<sub5<<" "<<sub6<<endl;
        }
};

class Result:public Exam{
    public:
        int total = 0; //sub1+sub2+sub3+sub4+sub5+sub6;
        float avg=0; //total/6;
        void displayResult(){
            total=sub1+sub2+sub3+sub4+sub5+sub6;
            avg=total/6;
            cout<<"Total marks: "<<total<<endl;
            if(avg>=91){
                cout<<"A"<<endl;
            }
            else if(avg>=81){
                cout<<"B"<<endl;
            }
            else if(avg>=71){
                cout<<"C"<<endl;
            }
            else if(avg>=61){
                cout<<"D"<<endl;
            }
            else{
                cout<<"F"<<endl;
            }
        }
};

int main(){
    Result r;
    r.getDetails();
    r.getMarks();
    r.displayDetails();
    r.displayMarks();
    r.displayResult();
    return 0;
}
