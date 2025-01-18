// https://codeforces.com/problemset/problem/1592/B

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
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;


    vll v(n);

    for (auto i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll s(all(v));

    sort(all(s));

    for (auto i = 0; i < n; i++)
    {
        if (s[i] != v[i])
        {
            if (i < k and i + k >= n)
            {
                // cout << i << " " << n - i << ln;
                cout << "NO" << ln;
                return;
            }
        }
    }

    cout << "YES" << ln;

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