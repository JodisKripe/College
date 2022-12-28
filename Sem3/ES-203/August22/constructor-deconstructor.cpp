#include <iostream>
using namespace std;

class Element
{
    private:
        int atomicNum;
        string name;
        string symbol;
    public:
        Element(int A, string B, string C)
        {
            atomicNum = A;
            name = B;
            symbol = C;
            cout << "Constructor Invoked." << endl;
        }
        Element()
        {
            atomicNum = 92;
            name = "Uranium";
            symbol = "U";
            cout << "Default Constructor Invoked" << endl;
        }
        ~Element()
        {
            cout << "Destructor Invoked." << endl;
        }
};

int main()
{
    Element E1(2, "Helium", "He");
    {
        Element E2(10, "Neon", "Ne");
    }
    Element E3;

    return 0;
}