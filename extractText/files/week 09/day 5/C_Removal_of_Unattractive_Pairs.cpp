// 

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

    string s;
    cin >> s;

    map<char, ll> m;

    for (auto& i : s)
    {
        m[i]++;
    }

    ll un = 0;
    vector<ll> v;

    for (auto& [f, s] : m)
    {
        if (s == 1) un++;
        else v.push_back(s);
    }

    for (auto& i : v)
    {
        ll r = min(i, un);
        if (i <= r-1) 
        i -= r - 1;
        un -= r - 1;
    }


    for (auto i = 0; i < v.size(); i++)
    {
        for (auto j = i + 1; j < v.size(); j++)
        {
            ll r = min(v[i], v[j]);

            v[i] -= r;
            v[j] -= r;
        }
    }

    ll count = 0;

    for (auto& i : v)
    {
        count += i;
    }

    cout << count << ln;
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