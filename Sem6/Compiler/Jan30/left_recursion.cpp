#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("grammar.txt");
    ofstream outputFile("grammar_no_left_recursion.txt");
    string line;
    string output;
    char ch;
    if (inputFile.is_open() && outputFile.is_open()) {
        while(inputFile.get(ch)) {
            if(ch == '\n') {
                outputFile << line << endl;
                line = "";
            } else {
                line += ch;
            }
        }
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Unable to open file";
    }
    return 0;
}