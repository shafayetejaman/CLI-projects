// https://codeforces.com/problemset/problem/1859/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vll;
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

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;
// "DEBUG_TEMPLATE.h"

void solve()
{
    int n;
    cin >> n;

    vll v1, v2;

    for (auto i = 1; i <= n; i++)
    {
        v1.push_back(i);
    }

    ll ans = INT_MIN;

    for (auto j = 0; j < n; j++)
    {
        ll sum = 0;
        ll m = INT_MIN;
        
        v2 = v1;
        reverse(v2.begin() + j, v2.end());

        for (auto i = 0; i < n; i++)
        {
            sum += v1[i] * v2[i];
            m = max(v1[i] * v2[i], m);
        }
        ans = max(ans, sum - m);
    }

    cout << ans << ln;

    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}