#include <iostream>
using namespace std;

class Shape {
    public:
        float radius=0,width=0,length=0,perimeter=0;
        Shape(float r){
            radius = r;
        }
        Shape(float w,float l){
            width = w;
            length = l;
        }
        void setPerimeter(){

            if(radius==0){
                perimeter = 2*(width+length);
            }else if (width==0 && length==0){
                perimeter = 2*3.14*radius;
            }else{
                cout<<"No data found";
            }
        }
        void display(){
            cout<<"Perimeter is "<<perimeter<<endl;
        }
        ~Shape(){
            cout<<"Destructor called"<<endl;
        }
};

int main(){
    Shape s1(5);
    Shape s2(5,6);
    s1.setPerimeter();
    s1.display();
    s2.setPerimeter();
    s2.display();
    return 0;
}
        