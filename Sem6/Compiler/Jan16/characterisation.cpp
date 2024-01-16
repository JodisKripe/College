#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string all_keywords[] = {"void","int","endl","using","char"};

int main() {
    ifstream inputFile("abc.txt");
    ofstream outputFile("copy_abc.txt");
    char ch;
    int sepTokens = 0;
    string buffer = "";
    
    if (inputFile.is_open() && outputFile.is_open()) {
        int count =1 ;
        int keywords = 0;
        char lastChar;
        int functions = 0;
        string buffer ;
        while (inputFile.get(ch)) {
            outputFile.put(ch);
            char some = ch;
            //cout << ch;      
            if(ch != ' ' && ch != '\n' && ch != '\t'){buffer += ch;}
            //cout << buffer << endl;
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
            if (some == '('){
                if(count){    
                    functions++;
                }
                //cout<<"TOKEN\n";
            }
            if (some == ' ' || some == '\n' || some == '\t'){
                if(count){    
                    sepTokens++;
                    //cout << buffer << " " << endl;
                    for(int i = 0; i < 5; i++){
                        if(!buffer.compare(all_keywords[i])){
                            //cout<<"KEYWORD";
                            keywords++;
                            buffer = "";
                        }
                    }
                    buffer = "";
                }
                //cout<<"TOKEN\n";
            }
            lastChar = ch;
            
        }
        sepTokens++;
        cout << "File copied successfully." << endl ;
        cout<<"total tokens are " << sepTokens << endl ;
        cout<<"total keywords are " << keywords << endl ;
        cout << "total functions are " << functions << endl ;
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Failed to open the file." << endl ;
    }

    return 0;
}
