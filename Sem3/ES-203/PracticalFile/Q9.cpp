#include <iostream>
#include <string>

using namespace std;
int main()
{
    string S1("Amity");
    string S2("University");
    string S3,S4;
    int x=0;
    cout<<"S1="<<S1<<endl;
    cout<<"S2="<<S2<<endl;
    S3=S1;
    cout<<"S3="<<S3<<endl;
    S4=S2.substr(0,4);
    cout<<"The substring of S2 is "<<S4<<endl;
    x=S1.compare(S2);
    cout<<"On comparing strings S1 and S2: ";
    if(x==0)
    {
        cout<<"S1=S2"<<endl;
    }
    else if(x>0)
    {
        cout<<"S1>S2"<<endl;
    }
    else
    {
        cout<<"S1<S2"<<endl;
    }
    return 0;
    }