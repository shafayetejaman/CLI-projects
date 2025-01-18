#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

const int N = 1e5 + 1;

class edge
{
public:
    int u, v, w;
};

bool cmp(edge &a, edge &b)
{
    return a.w < b.w;
}

int n, e;
vector<edge> ed;
int par[N];

int find(int u)
{
    if (par[u] == u) return u;
    return find(par[u]);
}

void input()
{
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed.push_back({u, v, w});
    }
}

int main()
{
    input();

    sort(ed.begin(), ed.end(), cmp);

    int c = 0;
    long long sum = 0;

    for (auto &v : ed)
    {
        int a = find(v.u);
        int b = find(v.v);
        
        if (a != b)
        {
            par[a] = b;
            c++;
            sum += v.w;
        }
    }

    if (c != n - 1) cout << "Not Possible" << endl;
    else cout << e - c << " " << sum << endl;

    return 0;
}
