#include <iostream>

using namespace std;

class student{
    int rno;
    public:
    void getnumber()
    {
        cout<<"Enter Roll number";
        cin>>rno;
    }
    void putnumber()
    {
        cout<<"Roll no. "<<rno<<"\n";
    }
};

class test : virtual public student{
    public:
    int part1, part2;
    void getmarks()
    {
        cout<<"Enter marks ";
        cout<<"Part 1- ";
        cin>>part1;
        cout<<"Part 2- ";
        cin>>part2;
    }
    
    void putmarks()
    {
        cout<<"Marks obtained ";
        cout<<"part 1- "<<part1;
        cout<<"part 2- "<<part2;
    }
};

class sports : public virtual student{
    public:
    int score;
    void getscore()
    {
        cout<<"Enter sport score- ";
        cin>>score;
    }
    void putscore()
    {
        cout<<"sport score- "<<score;
    }
};
    class result: public test, public sports{
        int total;
        public:
        void display()
        {
            total= part1 + part2 + score;
            putnumber();
            putmarks();
            putscore();
            cout<<"Total Score- "<<total;
        }
    };
    
int main()
{
    result obj;
    obj.getnumber();
    obj.getmarks();
    obj.getscore();
    obj.display();
    return 0;
}