#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
        char name[64];
        int age;
        char address[64];
        float salary;
        inline void compare(Person p1, Person p2){(p1.salary>p2.salary)?cout<<p1.name<<" has more salary than "<<p2.name<<endl:cout<<p2.name<<" has more salary than "<<p1.name<<endl;}
        Person(){};
        Person(char n[],int a,char ad[],float s){
            strcpy(name,n);
            age = a;
            strcpy(address,ad);
            salary = s;
            cout<<"\nSalary Slip:\n\n"<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"Address: "<<address<<endl<<"Salary: "<<salary<<endl;
        }
};

int main(){
    Person employees[10];
    for(int i=0;i<10;i++){
        float salary;
        char name[64],address[64];
        int age;
        cout<<"\n\nEnter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter address: ";
        cin>>address;
        cout<<"Enter salary: ";
        cin>>salary;
        employees[i] = Person(name,age,address,salary);
    }
    Person result;
    result.compare(employees[0],employees[1]);
}