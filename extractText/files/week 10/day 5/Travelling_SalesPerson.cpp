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

vb vis(N);
ll ans;
int n;

void fun(vvi& graph, vi v, int idx)
{
    if (idx == n - 1)
    {
        int prev = 0;
        ll sum = 0;

        for (auto& i : v)
        {
            sum += graph[prev][i];
            prev = i;
        }

        sum += graph[prev][0];

        ans = min(ans, sum);

        return;
    }

    for (auto i = 1; i < n; i++)
    {
        if (vis[i]) continue;

        v.push_back(i);
        vis[i] = true;

        fun(graph, v, idx + 1);

        v.pop_back();
        vis[i] = false;
    }
}

void solve()
{
    ans = INT_MAX;
    fill(all(vis), false);

    cin >> n;

    vvi graph(n, vi(n));

    for (auto& i : graph)
    {
        for (auto& j : i)
        {
            cin >> j;
        }
    }

    fun(graph, {}, 0);

    cout << ans << ln;

    // cout << ln;
}

int main()
{

#ifndef LOCAL
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}