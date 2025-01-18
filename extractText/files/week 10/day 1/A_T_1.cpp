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

ll ans = INT_MAX;
ll sum;
vb vis(N, false);

void fun(vi& v, int idx, ll s1)
{
    if (idx == v.size()) return;

    ll s2 = sum - s1;
    ans = min(ans, abs(s1 - s2));

    for (auto i = idx; i < v.size(); i++)
    {
        if (vis[i]) continue;

        vis[i] = true;
        fun(v, i + 1, s1 + v[i]);
        vis[i] = false;
    }
}

void solve()
{
    int n;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    sum = accumulate(all(v), 0);

    fun(v, 0, 0);

    cout << ans << ln;

    // cout << ln;
}

int main()
{

#ifndef LOCAL
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}