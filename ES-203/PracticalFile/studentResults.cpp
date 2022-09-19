#include <iostream>
using namespace std;

class Student{
    private:
        int roll;
        char name[20];
        int marks[5];
    public:
        void getDetails();
        void displayDetails();
};
