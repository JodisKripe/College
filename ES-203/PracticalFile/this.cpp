#include <iostream>

using namespace std;

class holder{
    public:
        int counter;
        holder(){
            counter = 0;
        }
    void add(holder h1, holder h2){
        this->counter=h1.counter+h2.counter;
    }
};

int main(){
    holder h1, h2, h3;
    cout<<"Enter counter for h1: ";
    cin>>h1.counter;
    cout<<"Enter counter for h2: ";
    cin>>h2.counter;
    h3.add(h1, h2);
    cout << "\nThe counter for h3 is: "<<h3.counter << endl;
    return 0;
}