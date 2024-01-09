#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("abc.txt");
    ofstream outputFile("copy_abc.txt");
    char ch;
    int sepTokens = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        int count =1 ;
        char lastChar;
        while (inputFile.get(ch)) {
            char some = ch;
            cout<<ch;      
            if (some == '\"' && count){
                count =0;
            }
            else if (some == '\"' && !count){
                count =1;
            }      
            if (lastChar == '\n' || lastChar == ' ' || lastChar == '\t'){
                if(some == ' ' || some == '\n' || some == '\t'){
                    continue;
                }
            }
            if (some == ' ' || some == '\n' || some == '\t'){
                if(count){    
                    sepTokens++;
                }
                cout<<"TOKEN";
            }
            lastChar = ch;
            outputFile.put(ch);
        }
        sepTokens++;
        cout << "File copied successfully." << endl;
        cout<<"total tokens are " << sepTokens << endl;
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
