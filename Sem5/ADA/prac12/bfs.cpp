#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

int adj[MAX][MAX], visited[MAX], n;

void bfs(int start)
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 1; v <= n; v++)
        {
            if (adj[u][v] && !visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int start;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
        }
    }
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "BFS Traversal: ";
    bfs(start);
    cout << endl;
    return 0;
}
