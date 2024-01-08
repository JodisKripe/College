#include <iostream>
#include <vector>
using namespace std;
struct Item
{
    int weight;
    int value;
};
int knapsack(vector<Item> &items, int W)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (items[i - 1].weight > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity: ";
    cin >> W;
    vector<Item> items(n);
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;
    }
    int maxValue = knapsack(items, W);
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    return 0;
}