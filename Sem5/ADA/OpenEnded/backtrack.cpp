#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int R, C;
int matrix[MAXN][MAXN];
int num_dragons, dragons_required;
int path_length=0;
int shortest_path = INT_MAX;

int moveLeft(int,int,int[MAXN][MAXN],int,int);
int moveDown(int,int,int[MAXN][MAXN],int,int);
int moveRight(int,int,int[MAXN][MAXN],int,int);

int moveLeft(int row, int col, int temp_matrix[MAXN][MAXN], int dragons_left, int path_length){
    if(col == 0){
        return INT_MAX;
    }
    if(temp_matrix[row][col-1] == 1){
        temp_matrix[row][col-1] = 0;
        dragons_left--;
    }
    path_length++;
    if(dragons_left == 0){
        return path_length;
    }
    int path1 = moveLeft(row, col-1, temp_matrix, dragons_left, path_length);
    int path2 = moveDown(row, col-1, temp_matrix, dragons_left, path_length);
    return min(path1,path2);
}

int moveDown(int row, int col, int temp_matrix[MAXN][MAXN], int dragons_left, int path_length){
    if(row == R-1){
        return INT_MAX;
    }
    if(temp_matrix[row+1][col] == 1){
        temp_matrix[row+1][col] = 0;
        dragons_left--;
    }
    path_length++;
    if(dragons_left == 0){
        return path_length;
    }
    int path1 = moveLeft(row+1, col, temp_matrix, dragons_left, path_length);
    int path2 = moveDown(row+1, col, temp_matrix, dragons_left, path_length);
    int path3 = moveRight(row+1, col, temp_matrix, dragons_left, path_length);
    return min(path1, min(path2, path3));
}

int moveRight(int row, int col, int temp_matrix[MAXN][MAXN], int dragons_left, int path_length){
    if(col == C-1){
        return INT_MAX;
    }
    if(temp_matrix[row][col+1] == 1){
        temp_matrix[row][col+1] = 0;
        dragons_left--;
    }
    path_length++;
    if(dragons_left == 0){
        return path_length;
    }
    int path1 = moveDown(row, col+1, temp_matrix, dragons_left, path_length);
    int path2 = moveRight(row, col+1, temp_matrix, dragons_left, path_length);
    return min(path1, path2);
}

int main() {
    cout << "Enter the number of rows: ";
    cin >> R;
    cout << "Enter the number of columns: ";
    cin >> C;

    // Fill the matrix with zeroes
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            matrix[i][j] = 0;
        }
    }

    cout << "Enter the number of dragons: ";
    cin >> num_dragons;
    if(num_dragons > R){
        cout << "You cannot have more dragons than rows!" << endl;
        return 0;
    }
    cout << "Enter the number of dragons required to kill: ";
    cin >> dragons_required;
    if(dragons_required > num_dragons) {
        cout << "You cannot kill more dragons than there are!" << endl;
        return 0;
    }

    // Place dragons randomly across the grid
    srand(time(NULL)); // Seed the random number generator
    int dragons_placed = 0;
    while (dragons_placed < num_dragons) {
        int row = rand() % R;
        bool valid_placement = true;
        for (int i = 0; i < C; i++) {
            if (matrix[row][i] == 1) {
                valid_placement = false;
                break;
            }
        }
        if (valid_placement) {
            int col = rand() % C;
            matrix[row][col] = 1; // Place a dragon
            dragons_placed++;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int dragons_left = dragons_required;
    int row = 0;
    int col = 0;
    for(int i=0; i < R; i++){
        int temp_matrix[MAXN][MAXN];
        for(int j=0; j < R; j++){
            for(int k=0; k < C; k++){
                temp_matrix[j][k] = matrix[j][k];
            }
        }
        for(int j=0; j < R; j++){
            for(int k=0; k < C; k++){
                temp_matrix[j][k] = matrix[j][k];
                cout << temp_matrix[j][k] << " ";
            }
            cout << endl;
        }
        int path1 = moveLeft(row, col, temp_matrix, dragons_left, 0);
        int path2 = moveRight(row, col, temp_matrix, dragons_left, 0);
        int path3 = moveDown(row, col, temp_matrix, dragons_left, 0);
        int smallest_path = min(path1, min(path2, path3));
        if(smallest_path < shortest_path) {
            shortest_path = smallest_path;
        }
        cout << "Shortest path: " << shortest_path << endl;
    }
    return 0;
}

