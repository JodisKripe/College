//WAP to use inline operator
#include <iostream>
using namespace std;

inline int add(int x,int y){
    return x+y;
}
int main()
{
    int x=10;
    int y=20;
    cout<<x<<" "<<y<<endl;
    cout<<add(x,y)<<endl;
    return 0;
}