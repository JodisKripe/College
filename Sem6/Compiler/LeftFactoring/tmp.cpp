#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to check if a given character is a terminal symbol
bool isTerminal(char ch)
{
    return islower(ch) || ch == '[' || ch == ']';
}

// Function to left factor the given grammar
void leftFactorGrammar(const vector<string> &productions)
{
    vector<string> newProductions;
    for (const string &production : productions)
    {
        stringstream ss(production);
        string nonTerminal;
        ss >> nonTerminal;
        string currProduction;
        while (ss >> currProduction)
        {
            if (currProduction[0] == '|')
            {
                newProductions.push_back(nonTerminal + " -> " + currProduction.substr(1));
            }
            else
            {
                newProductions.push_back(nonTerminal + " -> " + currProduction);
            }
        }
    }

    // Finding the longest common prefix
    string commonPrefix = "";
    bool foundCommon = false;
    for (size_t i = 0; i < newProductions.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < newProductions.size(); ++j)
        {
            string prod1 = newProductions[i].substr(newProductions[i].find("->") + 3);
            string prod2 = newProductions[j].substr(newProductions[j].find("->") + 3);
            size_t k = 0;
            while (k < prod1.size() && k < prod2.size() && prod1[k] == prod2[k])
            {
                if (!isTerminal(prod1[k]))
                {
                    commonPrefix += prod1[k];
                    foundCommon = true;
                }
                ++k;
            }
            if (foundCommon)
            {
                break;
            }
        }
        if (foundCommon)
        {
            break;
        }
    }

    // If a common prefix is found, print the transformed grammar
    if (foundCommon)
    {
        cout << newProductions[0].substr(0, newProductions[0].find("->") + 3) << commonPrefix << "A'" << endl;
        cout << "A' -> ";
        for (const string &production : newProductions)
        {
            string prod = production.substr(production.find("->") + 3);
            if (prod.substr(0, commonPrefix.size()) == commonPrefix)
            {
                if (prod.size() == commonPrefix.size())
                {
                    cout << "e|";
                }
                else
                {
                    cout << prod.substr(commonPrefix.size()) << "|";
                }
            }
        }
        cout << endl;
        cout << commonPrefix << "A''"
             << " -> ";
        for (const string &production : newProductions)
        {
            string prod = production.substr(production.find("->") + 3);
            if (prod.substr(0, commonPrefix.size()) == commonPrefix)
            {
                if (prod.size() > commonPrefix.size())
                {
                    cout << prod.substr(commonPrefix.size()) << "|";
                }
                else
                {
                    cout << "]|";
                }
            }
        }
        cout << endl;
    }
    else
    {
        // If no common prefix found, output the original grammar
        for (const string &production : productions)
        {
            cout << production << endl;
        }
    }
}

int main()
{
    vector<string> productions = {"A -> id|id[]|id[c]"};
    leftFactorGrammar(productions);
    return 0;
}
