#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

int x, y, k, n, e;

vvi input()
{
    cin >> n >> e;
    vvi graph(n);

    for (auto i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> x >> y >> k;
    return graph;
}

auto graph = input();
vi dis(n, -1);

bool bfs(int st)
{
    vi vis(n, false);
    queue<int> que;
    que.push(st);

    vis[st] = true;
    dis[st] = 0;

    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        for (auto& v : graph[u])
        {
            if (vis[v] or dis[u] >= k) continue;

            if (dis[v] != -1) return true;

            dis[v] = dis[u] + 1;
            vis[v] = true;
            que.push(v);
        }
    }
    return false;

}

int main()
{
    bfs(x);

    if (bfs(y)) cout << "YES";
    else cout << "NO";

    return 0;
}