#include <iostream>

// WAP to implement fractional knapsack problem using greedy method

using namespace std;

int main()
{
    int n, i, j, temp, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
    float temp10, temp11, temp12, temp13, temp14, temp15, temp16, temp17, temp18, temp19;
    cout << "Enter the number of items: ";
    cin >> n;
    int weight[n], profit[n];
    float ratio[n];
    cout << "Enter the weight and profit of each item: ";
    for (i = 0; i < n; i++)
    {
        cin >> weight[i] >> profit[i];
        ratio[i] = (float)profit[i] / weight[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
                temp1 = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp1;
                temp2 = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp2;
            }
        }
    }
    cout << "The sorted ratio is: ";
    for (i = 0; i < n; i++)
    {
        cout << ratio[i] << " ";
    }
    cout << endl;
    cout << "The sorted weight is: ";
    for (i = 0; i < n; i++)
    {
        cout << weight[i] << " ";
    }
    cout << endl;
    cout << "The sorted profit is: ";
    for (i = 0; i < n; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;
    int capacity; 
    float totalprofit = 0;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            capacity = capacity - weight[i];
            totalprofit = totalprofit + profit[i];
        }
        else
        {
            totalprofit = totalprofit + (ratio[i] * capacity);
            break;
        }
    }
    cout << "The total profit is: " << totalprofit << endl;
    return 0;
}
