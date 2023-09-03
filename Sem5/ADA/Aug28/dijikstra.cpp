#include <iostream>

//WAP to implement Dijikstra's algorithm

using namespace std;

int main()
{
    int n, i, j, k, min, mincost = 0, src;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int cost[n][n], dist[n], visited[n], path[n];
    cout << "Enter the cost matrix: ";
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter the elements of row " << i + 1 << ": ";
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    cout << "\nEnter the source node: ";
    cin >> src;
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
        path[i] = src;
    }
    dist[src] = 0;
    visited[src] = 1;
    for (i = 0; i < n; i++)
    {
        min = 999;
        for (j = 0; j < n; j++)
        {
            if (min > dist[j] && visited[j] == 0)
            {
                min = dist[j];
                k = j;
            }
        }
        visited[k] = 1;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                if (dist[j] > dist[k] + cost[k][j])
                {
                    dist[j] = dist[k] + cost[k][j];
                    path[j] = k;
                }
            }
        }
    }
    cout << "\nThe shortest path from source node " << src << " to all other nodes is: ";
    for (i = 0; i < n; i++)
    {
        if (i != src)
        {
            cout << "\nDistance of node " << i << " from source node " << src << " is " << dist[i];
            cout << "\nPath: " << i;
            j = i;
            do
            {
                j = path[j];
                cout << " <- " << j;
            } while (j != src);
        }
    }
    cout << "\n";
    return 0;
}