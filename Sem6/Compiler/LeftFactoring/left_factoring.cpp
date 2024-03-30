#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ifstream inputFile("grammar.txt");
    ofstream outputFile("grammar_no_left_factoring.txt");
    string line = "";
    string output;
    vector<string> productions;

    string inputProduction = "";
    inputFile >> inputProduction;
    // cout << inputProduction << endl;
    string nonTerminal = inputProduction.substr(0, 1);
    string rest = inputProduction.substr(3);
    // cout << nonTerminal << endl;
    // cout << rest << endl;
    vector<string> restProductions;

    for (int i = 0; i < rest.size(); i++)
    {
        if (rest[i] == '|')
        {
            restProductions.push_back(line);
            // cout << line << endl;
            line = "";
        }
        else
        {
            line += rest[i];
        }
    }
    restProductions.push_back(line);
    map<string, vector<string>> commonPrefixes;
    for (int i = 0; i < restProductions.size(); i++)
    {
        vector<string> tempProductions;
        for (int j = 0; j < restProductions.size(); j++)
        {
            if (restProductions[i] != restProductions[j])
            {
                tempProductions.push_back(restProductions[j]);
                // cout << restProductions[j] << endl;
            }
        }
        string commonPrefix = "";
        for (int j = 0; j < tempProductions.size(); j++)
        {
            // cout << "Judging " + restProductions[i] + " with " + tempProductions[j] << endl;
            for (int k = 0; k < restProductions[i].size(); k++)
            {
                if (tempProductions[j].size() >= k && restProductions[i].substr(0, k) == tempProductions[j].substr(0, k))
                {
                    // cout << restProductions[i].substr(0, k) << endl;
                    commonPrefix = restProductions[i].substr(0, k);
                }
            }
            // cout << "Common Prefix: " << commonPrefix << endl;
            if (commonPrefix != "")
            {
                commonPrefixes[commonPrefix].push_back(tempProductions[j]);
            }
        }
    }
    // cout << "Common Prefixes: " << endl;
    for (auto it = commonPrefixes.begin(); it != commonPrefixes.end(); it++)
    {
        for (int i = 0; i < it->second.size(); i++)
        {
            for (int j = 0; j < restProductions.size(); j++)
            {
                if (it->second[i] == restProductions[j])
                {
                    restProductions.erase(restProductions.begin() + j);
                }
            }
        }
        cout << nonTerminal << " -> " << it->first << nonTerminal + "'"
             << "|";
        for (int p = 0; p < restProductions.size(); p++)
        {
            cout << restProductions[p] + " " << endl;
        }
        cout << nonTerminal + "'"
             << " -> ";
        for (int i = 0; i < it->second.size(); i++)
        {
            int substrSize = it->second[i].size() - it->first.size();
            cout << it->second[i].substr(it->first.size()) << "|";
        }
    }
    cout << endl;

    return 0;
}