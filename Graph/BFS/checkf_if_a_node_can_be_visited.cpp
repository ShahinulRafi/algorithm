#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; // total nodes
bool vis[1005];             // same

void bfs(int src) // O(V+E)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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

    if (vis[des])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}