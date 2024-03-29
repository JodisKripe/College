#include <iostream>
#include <fstream>
#include "lexical.h"
#include <string.h>

using namespace std;

int main()
{
    string inputString = "";
    ifstream fin("input.txt");
    // set the input string to the string in the file
    fin >> inputString;
    // call the lexical function
    lexical(inputString);
    return 0;
}