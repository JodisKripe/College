#include <iostream>

// Wap to implement prims algorithm

using namespace std;

class prims
{
    int n, i, j, k, u, v, min, mincost, ne, parent[10], a[10][10];

public:
    void read();
    void find();
};  

void prims::read()
{
    cout << "Enter the no. of vertices: ";
    cin >> n;
    cout << "Enter the cost matrix: ";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
}

void prims::find()
{
    ne = 1;
    mincost = 0;
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] < min)
                {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];
        if (u != v)
        {
            cout << "Edge " << ne++ << " : (" << u << ", " << v << ") cost: " << min << endl;
            mincost += min;
            parent[v] = u;
        }
        a[u][v] = a[v][u] = 999;
    }
    cout << "Minimum cost = " << mincost << endl;
}

int main()
{
    prims p;
    p.read();
    p.find();
    return 0;
}
