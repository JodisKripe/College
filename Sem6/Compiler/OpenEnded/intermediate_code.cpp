#include <iostream>
#include <fstream>

/*
Write code to take input from a file and generate intermediate three address code for inputs like:
a = b + ( c + d )

The output should be:
AND

t1 = c + d
t2 = b + t1
a = t2

respectively

precedence of operators is as follows:
1. ( and ) - highest precedence
2. + and -

*/

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    fin >> s;
    int t = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            fout << "t" << t << " = ";
            t++;
        }
        else if (s[i] == ')')
        {
            t--;
            fout << "t" << t << " = ";
            t--;
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            fout << "t" << t << " " << s[i] << " ";
        }
        else
        {
            fout << s[i];
        }
    }
    return 0;
}