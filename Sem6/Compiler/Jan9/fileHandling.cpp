#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("abc.txt");
    ofstream outputFile("copy_abc.txt");
    char ch;
    int tokens = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        int count =1 ;
        while (inputFile.get(ch)) {
            outputFile.put(ch);
            char some = ch;
            cout<<ch;            
            if (some == ' ' || some == '\n'){
                if(count){    
                    tokens++;
                }
                cout<<"TOKEN";
            }

            outputFile.put(ch);
        }
        cout << "File copied successfully." << endl;
        cout<<"total tokens are " << tokens << endl;
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
