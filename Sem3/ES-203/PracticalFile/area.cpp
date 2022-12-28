#include <iostream>
#include <math.h>
using namespace std;

float area(float r){
    return 3.14*r*r;
}

float area(float l,float b){
    return l*b;
}

float area(float a,float b,float c){
    float s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    float r,le,br,a,b,c;
    cout<<"Enter radius: ";
    cin>>r;
    cout<<"Enter length: ";
    cin>>le;
    cout<<"Enter breadth: ";
    cin>>br;
    cout<<"Enter side 1: ";
    cin>>a;
    cout<<"Enter side 2: ";
    cin>>b;
    cout<<"Enter side 3: ";
    cin>>c;
    cout<<"Area of circle is "<<area(r)<<endl;
    cout<<"Area of rectangle is "<<area(le,br)<<endl;
    cout<<"Area of triangle is "<<area(a,b,c)<<endl;
    return 0;
}