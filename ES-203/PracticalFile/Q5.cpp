#include <iostream>
using namespace std;

class length{
    public:
        int feet;
        int inches;
        void getLength(){
            cout << "Enter feet: ";
            cin >> feet;
            cout << "Enter inches: ";
            cin >> inches;
        }
        void displayLength(){
            cout << "Length is " << feet << " feet and " << inches << " inches." << endl;
        }
        length operator +(length l){
            length temp;
            temp.feet = feet + l.feet;
            temp.inches = inches + l.inches;
            if(temp.inches >= 12){
                temp.feet++;
                temp.inches -= 12;
            }
            return temp;
        }
        bool operator ==(length l){
            if(feet == l.feet && inches == l.inches){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator <(length l){
            if(feet < l.feet){
                return true;
            }
            else if(feet == l.feet && inches < l.inches){
                return true;
            }
            else{
                return false;
            }
        }
        void operator *=(int n){
            feet *= n;
            inches *= n;
        }
};

int main(){
    length l1, l2, l3;
    cout<<"Getting l1"<<endl;
    l1.getLength();
    cout<<"Getting l2"<<endl;
    l2.getLength();
    cout<<"Adding l1 and l2"<<endl;
    l3 = l1 + l2;
    l3.displayLength();
    cout<<"Comparing l1 and l2"<<endl;
    if(l1 == l2){
        cout << "Lengths are equal." << endl;
    }
    else{
        cout << "Lengths are not equal." << endl;
    }
    if(l1 < l2){
        cout << "Length 1 is smaller than length 2." << endl;
    }
    else{
        cout << "Length 1 is not smaller than length 2." << endl;
    }
    cout<<"Multiplying l1 by 2"<<endl;
    l1 *= 2;
    l1.displayLength();
    return 0;
}