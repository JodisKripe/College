#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string all_keywords[] = {"void","int","endl","using","char"};
vector<string> user_functions = {"om"};
vector<string> predefined_functions = {"main("};
int pred =0;
int vars= 0;
int comming = 0 ;
int multicomming = 0;

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
        int comments = 0;
        string buffer ;
        int varFlag = 0;
        while (inputFile.get(ch)) {
            
            
            char some = ch;
            //cout << ch;
            if(!buffer.compare("int") || !buffer.compare("char") || !buffer.compare("float") || !buffer.compare("double") ){
                varFlag = 1;
            }

            if(varFlag){
                if(ch == ',' || ch == ';'){
                    vars++;
                    if(ch == ';'){
                        varFlag = 0;
                    }
                }
            }

            if(ch == '/' && lastChar == '/'){
                comming = 1;
            }
            if(ch == '*' && lastChar == '/' && !comming){
                multicomming = 1;
            }
            if (ch == '\n' && comming){
                comming = 0;
                comments++;
            }
            if(ch == '/' && lastChar == '*' && multicomming){
                multicomming = 0;
                comments++;
            }
            if (comming || multicomming ){
                lastChar = ch;
                continue;
            }
            if(!(comming || multicomming)){
                outputFile.put(ch);
            }
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
                    //cout << buffer;
                    int flag = 1;
                    for(int i = 0; i < user_functions.size(); i++){
                        if(!buffer.compare(user_functions[i])){
                            break;
                        }
                    }
                    for(int i = 0; i < predefined_functions.size(); i++){
                        if(!buffer.compare(predefined_functions[i])){
                            pred++;
                            break;
                        }
                    }
                    functions++;
                    cout << buffer;
                    user_functions.push_back(buffer);
                    // for (int i = 0; i < user_functions.size(); i++){
                    //     cout << user_functions[i] << endl;
                    // }
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
        cout << "\t predefined functions are " << pred << endl ;
        cout << "\t user defined functions are " << functions - pred << endl ;
        cout << "total variables are " << vars << endl ;
        cout << "total comments are " << comments << endl ;
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Failed to open the file." << endl ;
    }

    return 0;
}
