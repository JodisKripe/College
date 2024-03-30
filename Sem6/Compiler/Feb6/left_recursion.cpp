#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("grammar.txt");
    ofstream outputFile("grammar_no_left_recursion.txt");
    string line = "";
    string output;
    vector<string> productions;
    char ch;
    if (inputFile.is_open() && outputFile.is_open())
    {
        while (inputFile.get(ch))
        {
            // cout<<ch;
            // cout<<line;
            if (ch == '\n')
            {
                outputFile << line << endl;
                // cout << line << endl;
                productions.push_back(line);
                line = "";
            }
            else
            {
                line += ch;
            }
        }
        inputFile.close();
        outputFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    for (int i = 0; i < productions.size(); i++)
    {
        string production = productions[i];
        // cout << production << endl;
        string nonTerminal = production.substr(0, 1);
        // cout << "Non Terminal: " << nonTerminal << endl;
        string rest = production.substr(4);
        cout << nonTerminal << endl;
        // cout << rest << endl;
        vector<string> restProductions;
        string temp = "";
        for (int j = 0; j < rest.size(); j++)
        {
            if (rest[j] == '|')
            {
                temp = temp.substr(1);
                restProductions.push_back(temp);
                temp = "";
            }
            else
            {
                temp += rest[j];
            }
        }
        restProductions.push_back(temp);
        for (int j = 0; j < restProductions.size(); j++)
        {
            // cout << restProductions[j] << endl;
        }
        vector<string> alpha;
        vector<string> beta;
        for (int j = 0; j < restProductions.size(); j++)
        {
            string restProduction = restProductions[j];
            if (restProduction[0] == nonTerminal[0])
            {
                alpha.push_back(restProduction.substr(1));
                cout << "Alpha:" << restProduction.substr(1) << endl;
            }
            else
            {
                cout << "Beta: " << restProduction << endl;
                beta.push_back(restProduction);
            }
        }
        if (alpha.size() == 0)
        {
            output += production + "\n";
        }
        else
        {
            output += nonTerminal + " -> ";
            for (int j = 0; j < beta.size(); j++)
            {
                output += beta[j] + nonTerminal + "'";
                if (j != beta.size() - 1)
                {
                    output += " | ";
                }
            }
            output += "\n";
            output += nonTerminal + "' -> ";
            for (int j = 0; j < alpha.size(); j++)
            {
                output += alpha[j] + nonTerminal + "'";
                if (j != alpha.size() - 1)
                {
                    output += " | ";
                }
            }
            output += "\n";
        }
        ofstream outfile = ofstream("grammar_no_left_recursion.txt");
        outfile << output;
        outfile.close();
    }
    return 0;
}