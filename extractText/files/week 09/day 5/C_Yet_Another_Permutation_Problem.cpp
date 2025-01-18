// https://codeforces.com/problemset/problem/1858/C

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
// #include "DEBUG_TEMPLATE.h"

void solve()
{
    int n;
    cin >> n;

    vll v(n);

    for (auto i = 1; i <= n; i++)
    {
        v[i - 1] = i;
    }

    set<int> se;
    vll ans;

    for (auto i = 2; i < n; i++)
    {
        ll k = i;

        while (k <= n)
        {
            if (!se.count(k))
            {
                se.insert(k);
                ans.push_back(k);
            }

            k *= 2;
        }
    }

    for (auto& i : v)
    {
        if (!se.count(i)) ans.push_back(i);
    }

    for (auto& i : ans)
    {
        cout << i << " ";
    }

    cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}