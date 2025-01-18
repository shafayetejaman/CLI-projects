// https://codeforces.com/problemset/problem/1843/D

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
typedef long long ll;
#define ln '\n'
#define loop(n) for(auto j = 0; j < (n); j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;

vvi input(int n)
{
    vvi graph(n + 1);

    loop(n-1)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

void dfs(int u, vll& vis, vvi& graph, vll& count)
{
    vis[u] = true;

    bool flag = false;

    for (auto& v : graph[u])
    {
        if (vis[v]) continue;
        flag = true;

        dfs(v, vis, graph, count);

        count[u] += count[v];
    }

    if (!flag) count[u]++;
}

void solve()
{
    int n;
    cin >> n;

    auto graph = input(n);

    vll vis(n + 1, false);
    vll count(n + 1, 0);

    dfs(1, vis, graph, count);

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << count[a] * count[b] << ln;
    }
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}