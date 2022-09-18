#include <iostream>
using namespace std;

class A;

class B{
    private:
    public:
        int b;
        B(int x){
            b = x;
        }
        void display(){
            cout<<"b = "<<b<<endl;
        }
        friend void swap(A , B );

};

class A{
    private:
    public:
        int a;
        A(int x){
            a = x;
        }
        void display(){
            cout<<"a = "<<a<<endl;
        }
        friend void swap(A , B );
};

void swap(A *first, B *second){
    int temp = first->a;
    first->a = second->b;
    second->b = temp;
    }

int main(){
    A first(250);
    B second(20);
    swap(&first, &second);
    cout<< "After swapping: "<<endl;
    cout<< "First: "<<endl;
    first.display();
    cout<< "Second: "<<endl;
    second.display();
    return 0;
}