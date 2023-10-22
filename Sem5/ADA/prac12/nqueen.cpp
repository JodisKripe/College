#include <iostream>
using namespace std;

void printChessboard(char **chessboard, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, char **chessboard, int N)
{
    for (int c = 0; c < col; ++c)
    {
        if (chessboard[row][c] == 'Q')
        {
            return false;
        }
    }
    for (int r = row, c = col; r >= 0 && c >= 0; --r, --c)
    {
        if (chessboard[r][c] == 'Q')
        {
            return false;
        }
    }
    // Check the lower-left diagonal
    for (int r = row, c = col; r < N && c >= 0; ++r, --c)
    {
        if (chessboard[r][c] == 'Q')
        {
            return false;
        }
    }
    return true;
}

bool findFirstSolution(int col, int N, char **chessboard, int *solution)
{
    if (col == N)
    {
        solution = new int[N];
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (chessboard[i][j] == 'Q')
                {
                    solution[i] = j;
                    break;
                }
            }
        }
        return true;
    }
    for (int row = 0; row < N; ++row)
    {
        if (isSafe(row, col, chessboard, N))
        {
            chessboard[row][col] = 'Q';
            if (findFirstSolution(col + 1, N, chessboard, solution))
            {
                return true;
            }
            chessboard[row][col] = '.';
        }
    }
    return false;
}

int main()
{
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;
    char **chessboard = new char *[N];
    for (int i = 0; i < N; ++i)
    {
        chessboard[i] = new char[N];
        for (int j = 0; j < N; ++j)
        {
            chessboard[i][j] = '.';
        }
    }
    int *solution;
    if (findFirstSolution(0, N, chessboard, solution))
    {
        cout << "First solution found:" << endl;
        printChessboard(chessboard, N);
        cout << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }
    return 0;
}