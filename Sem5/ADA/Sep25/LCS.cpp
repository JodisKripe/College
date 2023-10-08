#include <iostream>
using namespace std;

//Write a program to implement Longest Common Subsequence

int main()
{
    int n, m;
    cout << "Enter the size of the first string: ";
    cin >> n;
    cout << "Enter the size of the second string: ";
    cin >> m;
    char a[n], b[m];
    cout << "Enter the first string: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the second string: ";
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int c[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        c[i][0] = 0;
    for (int i = 0; i <= m; i++)
        c[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    cout << "The length of the longest common subsequence is: " << c[n][m] << endl;
    cout << "The longest common subsequence is: ";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            cout << a[i - 1];
            i--;
            j--;
        }
        else if (c[i - 1][j] > c[i][j - 1])
            i--;
        else
            j--;
    }
    return 0;
}