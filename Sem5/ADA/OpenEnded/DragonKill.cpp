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

int find_shortest_path(int row ,int col, int dragons_left, int matrix[MAXN][MAXN]) {
    //cout << dragons_left << endl;    
    if(dragons_left == 0) {
        return path_length;
    }
    while(dragons_left > 0) {
        if (row >= R || col >= C) {
            return INT_MAX;
        }
        if ( dragons_left > R - row) {
            return INT_MAX;
        }
        int dragons_before = dragons_left;
        int temp_path_length = path_length;
        for(int i = col; i < C; i++) {
            path_length++;
            if(matrix[row][i] == 1) {
                dragons_left--;
                cout << "Killed a dragon at " << row << " " << i << endl;
                matrix[row][i] = 0;
                col = i;
                break;
            }
        }
        if(dragons_before = dragons_left){
            path_length = temp_path_length;
        }
        for(int i = col; i >= 0; i--) {
            path_length++;
            if(matrix[row][i] == 1) {
                dragons_left--;
                cout << "Killed dragon at " << row << " " << i << endl;
                matrix[row][i] = 0;
                col = i;
                break;
            }
        }
        if(dragons_before == dragons_left) {
            find_shortest_path(row + 1, col, dragons_left, matrix);
        }
        row++;
        find_shortest_path(row, col, dragons_left, matrix);
    }
    return INT_MAX;

}

// void solve() {
//     // Find the shortest path to kill all dragons
//     for (int i = 0; i < C; i++) {
//         fill(path_lengths, path_lengths + C, -1);
//         dfs(0, i, 0, 0);
//         find_shortest_path(i, 0);
//     }

//     if (shortest_path == INT_MAX) {
//         cout << "It is impossible to kill all the dragons!" << endl;
//     } else {
//         cout << "The shortest path to kill all dragons is: " << shortest_path << endl;
//     }
// }

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
    int shortest_path = INT_MAX;
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
        int path = find_shortest_path(row + i, col, dragons_left, temp_matrix);
        cout << "Path Length:" << path << endl;
        if(path < shortest_path) {
            shortest_path = path;
        }
    }

    return 0;
}
