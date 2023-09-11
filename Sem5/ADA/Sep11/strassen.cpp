#include <iostream>
using namespace std;

//Write a program to implement Strassen's Matrix Multiplication

int main()
{
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    int a[n][n], b[n][n], c[n][n];
    cout << "Enter the elements of the first matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << "Enter the elements of the second matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    int p1, p2, p3, p4, p5, p6, p7;
    p1 = a[0][0] * (b[0][1] - b[1][1]);
    p2 = (a[0][0] + a[0][1]) * b[1][1];
    p3 = (a[1][0] + a[1][1]) * b[0][0];
    p4 = a[1][1] * (b[1][0] - b[0][0]);
    p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);
    c[0][0] = p5 + p4 - p2 + p6;
    c[0][1] = p1 + p2;
    c[1][0] = p3 + p4;
    c[1][1] = p1 + p5 - p3 - p7;
    cout << "The resultant matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
    }
    return  0;
}