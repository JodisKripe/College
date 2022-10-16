#include <iostream>
using namespace std;

class Media{
    public:
        char title[30];
        char publication[30];
        virtual void read(){
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter publication: ";
            cin >> publication;
        }
        virtual void show(){
            cout << "Title: " << title << endl;
            cout << "Publication: " << publication << endl;
        }
};

class book:public Media{
    public:
        int pages;
        void read(){
            cout<<"Enter title: ";
            cin>>title;
            cout<<"Enter publication: ";
            cin>>publication;
            cout<<"Enter pages: ";
            cin>>pages;
        }
        void show(){
            cout<<"Title: "<<title<<endl;
            cout<<"Publication: "<<publication<<endl;
            cout<<"Pages: "<<pages<<endl;
        }
};

class tape:public Media{
    public:
        int minutes;
        void read(){
            cout<<"Enter title: ";
            cin>>title;
            cout<<"Enter publication: ";
            cin>>publication;
            cout<<"Enter minutes: ";
            cin>>minutes;
        }
        void show(){
            cout<<"Title: "<<title<<endl;
            cout<<"Publication: "<<publication<<endl;
            cout<<"Minutes: "<<minutes<<endl;
        }
};

int main(){
    book b;
    tape t;
    b.read();
    t.read();
    cout<<"\n\n\n";
    b.show();
    t.show();
    return 0;
}