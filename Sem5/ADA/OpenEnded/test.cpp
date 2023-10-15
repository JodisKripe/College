#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int R, C, D, K;
    cin >> R >> C >> D >> K;

    vector<vector<int>> dp(R, vector<int>(C, INF));
    dp[0][0] = 0;

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int dragons = 0;
            char c;
            cin >> c;
            if (c == 'D') {
                dragons = 1;
            }

            int from_left = (j > 0) ? dp[i-1][j-1] : INF;
            int from_top = dp[i-1][j];
            int from_right = (j < C-1) ? dp[i-1][j+1] : INF;

            dp[i][j] = min({from_left, from_top, from_right}) + dragons;
        }
    }

    int ans = INF;
    for (int j = 0; j < C; j++) {
        ans = min(ans, dp[R-1][j]);
    }

    if (ans <= K) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
