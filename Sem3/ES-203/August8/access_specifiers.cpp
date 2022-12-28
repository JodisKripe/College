// WAP to use access specifiers
#include <iostream>
#include <string.h>
using namespace std;

int x=20;

class student{
    private:
        int id;
    public:
        void setid(int new_id){
            id=new_id;
        }
        int rollno;
        char name[25]=""; 
        void display(){
         cout<<id<<endl<<name<<endl<<rollno<<endl;
        }
};

int main()
{
    student std1;
    char nm[]="John";
    for(int i=0;i<strlen(nm);i++){
        std1.name[i]=nm[i];
    }
    std1.rollno=7;
    std1.setid(1);
    std1.display();

}
