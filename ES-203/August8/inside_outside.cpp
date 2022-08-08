// WAP to use access specifiers
#include <iostream>
using namespace std;

int x=20;

class inside
{
public:
    int x;
    int func();
    void display()
    {
        cout << x << endl;
    }
};

int inside::func(){
    x=12;
    return x;
}


int main()
{
    int x=40;
    cout<<::x<<" "<<x<<endl;
    inside obj;
    obj.func();
    obj.display();
    return 0;
}

