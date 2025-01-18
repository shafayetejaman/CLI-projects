// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#ifdef LOCAL
#include "DEBUG_TEMPLATE.h"
#else
#define line
#define print(args...)
#endif

using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 1;
// const int M = 1e9 + 7;

class WormHole
{
public:
    int si, sj, di, dj, c;

    WormHole() {}
};

vb vis(N);
ll ans;
int n;
int si, sj, di, dj;

void fun(vector<WormHole>& graph, vi& v, int idx)
{

    int pi = si;
    int pj = sj;

    ll sum = 0;

    for (auto& i : v)
    {
        sum += abs(pi - graph[i].si) + abs(pj - graph[i].sj) + graph[i].c;

        pi = graph[i].di;
        pj = graph[i].dj;
    }

    sum += abs(pi - di) + abs(pj - dj);

    ans = min(ans, sum);

    pi = si;
    pj = sj;

    sum = 0;

    for (auto& i : v)
    {
        sum += abs(pi - graph[i].di) + abs(pj - graph[i].dj) + graph[i].c;

        pi = graph[i].si;
        pj = graph[i].sj;
    }

    sum += abs(pi - di) + abs(pj - dj);

    ans = min(ans, sum);


    for (auto i = 1; i <= n; i++)
    {
        if (vis[i]) continue;

        vis[i] = true;
        v.push_back(i);

        fun(graph, v, idx + 1);

        v.pop_back();
        vis[i] = false;
    }
}

void solve()
{
    ans = INT_MAX;
    fill(all(vis), false);

    cin >> n >> si >> sj >> di >> dj;

    vector<WormHole> graph(n + 1);

    for (auto i = 1; i <= n; i++)
    {
        cin >> graph[i].si;
        cin >> graph[i].sj;
        cin >> graph[i].di;
        cin >> graph[i].dj;
        cin >> graph[i].c;
    }

    vi v;
    fun(graph, v, 0);

    cout << ans << ln;

    // cout << ln;
}

int main()
{

#ifndef LOCAL
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}