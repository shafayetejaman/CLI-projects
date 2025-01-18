// 

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
typedef vector<vector<long long>> vvi;
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

int n, k;
vb vis(N, false);

void fun(vc v, int idx)
{
    if (!k) return;

    if (idx == v.size())
    {
        for (auto& i : v)
        {
            cout << i;
        }

        cout << ln;
        k--;

        return;
    }

    for (auto i = 0; i < v.size(); i++)
    {
        if (vis[i]) continue;

        v[idx] = i + 'A';
        vis[i] = true;

        fun(v, idx + 1);
        vis[i] = false;
    }
}

void solve()
{
    cin >> n >> k;

    vc v(n);

    fun(v, 0);

    // cout << ln;
}

int main()
{

#ifndef LOCAL
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

    int t = 1;
    cin >> t;

    for (auto i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << ln;

        solve();

        vis.clear();
    }

    return 0;
}