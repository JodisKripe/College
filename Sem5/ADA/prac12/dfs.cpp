#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
bool visited[MAX];

void dfs(int start, int n)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

int main()
{
    memset(visited, false, sizeof(visited));

    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges: \n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "DFS Traversal: ";
    dfs(0, n);

    return 0;
}

// Test Case:
// Input:
// Enter the number of vertices: 5
// Enter the number of edges: 4
// Enter the edges:
// 0 1
// 0 2
// 1 3
// 2 4
// Output:
// DFS Traversal: 0 2 4 1 3
