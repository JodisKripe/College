#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<char, vector<string>> productions;
unordered_map<char, unordered_set<char>> firstSets;
unordered_map<char, unordered_set<char>> followSets;
unordered_set<char> nonTerminals;
unordered_set<char> terminals;

void calculateFirst(char nonTerminal);

void calculateFollow(char nonTerminal);

bool isTerminal(char symbol)
{
    return terminals.find(symbol) != terminals.end();
}

void calculateFirst(char nonTerminal)
{
    if (firstSets.find(nonTerminal) != firstSets.end())
    {
        // First set for this non-terminal is already calculated
        return;
    }

    for (const string &production : productions[nonTerminal])
    {
        char firstSymbol = production[0];
        if (isTerminal(firstSymbol))
        {
            firstSets[nonTerminal].insert(firstSymbol);
        }
        else
        {
            calculateFirst(firstSymbol);
            for (char symbol : firstSets[firstSymbol])
            {
                firstSets[nonTerminal].insert(symbol);
            }
        }
    }
}

void calculateFollow(char nonTerminal)
{
    if (followSets.find(nonTerminal) != followSets.end())
    {
        // Follow set for this non-terminal is already calculated
        return;
    }

    for (auto &entry : productions)
    {
        char A = entry.first;
        for (const string &production : entry.second)
        {
            size_t pos = production.find(nonTerminal);
            if (pos != string::npos)
            {
                if (pos == production.size() - 1)
                {
                    if (A != nonTerminal)
                    {
                        calculateFollow(A);
                        for (char symbol : followSets[A])
                        {
                            followSets[nonTerminal].insert(symbol);
                        }
                    }
                }
                else
                {
                    char nextSymbol = production[pos + 1];
                    if (isTerminal(nextSymbol))
                    {
                        followSets[nonTerminal].insert(nextSymbol);
                    }
                    else
                    {
                        calculateFirst(nextSymbol);
                        for (char symbol : firstSets[nextSymbol])
                        {
                            if (symbol != 'e')
                            {
                                followSets[nonTerminal].insert(symbol);
                            }
                        }
                        if (firstSets[nextSymbol].find('e') != firstSets[nextSymbol].end())
                        {
                            calculateFollow(nextSymbol);
                            for (char symbol : followSets[nextSymbol])
                            {
                                followSets[nonTerminal].insert(symbol);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    // Example grammar
    productions['S'] = {"aABc", "bBC"};
    productions['A'] = {"d"};
    productions['B'] = {"e"};
    productions['C'] = {"f"};

    nonTerminals = {'S', 'A', 'B', 'C'};
    terminals = {'a', 'b', 'c', 'd', 'e', 'f'};

    // Calculate First and Follow sets
    for (char nonTerminal : nonTerminals)
    {
        calculateFirst(nonTerminal);
        calculateFollow(nonTerminal);
    }

    // Print First sets
    cout << "First Sets:\n";
    for (char nonTerminal : nonTerminals)
    {
        cout << "First(" << nonTerminal << ") = { ";
        for (char symbol : firstSets[nonTerminal])
        {
            cout << symbol << " ";
        }
        cout << "}\n";
    }

    // Print Follow sets
    cout << "\nFollow Sets:\n";
    for (char nonTerminal : nonTerminals)
    {
        cout << "Follow(" << nonTerminal << ") = { ";
        for (char symbol : followSets[nonTerminal])
        {
            cout << symbol << " ";
        }
        cout << "}\n";
    }

    return 0;
}