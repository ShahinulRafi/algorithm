#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; // total nodes
bool vis[1005];             // same
bool level[1005];
int parent[1005];

void bfs(int src) // O(V+E)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty()) // O(N) or O(Vertices)
    {
        int par = q.front();
        q.pop();

        cout << par << " ";

        for (auto child : adj_list[par]) // O(Edge)
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    memset(adj_list, 0, sizeof(adj_list));
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src, des;
    cin >> src >> des;
    bfs(src);

    vector<int> path;
    int node = des;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << " ";
    }

    return 0;
}