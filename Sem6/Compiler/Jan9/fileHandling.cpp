#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("abc.txt");
    ofstream outputFile("copy_abc.txt");
    char ch;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (inputFile.get(ch)) {
            outputFile.put(ch);
        }
        cout << "File copied successfully." << endl;
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
