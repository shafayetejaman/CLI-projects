// https://codeforces.com/problemset/problem/1721/C

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

    vll a(n);

    for (auto& i : a)
    {
        cin >> i;
    }

    vll b(n);

    for (auto& i : b)
    {
        cin >> i;
    }

    vll dmin, dmax;

    for (auto i = 0, j = 0; i < n and j < n; i++)
    {
        while (j < n and a[i] > b[j]) j++;

        dmin.push_back(b[j] - a[i]);
    }

    for (int i = n - 1, j = n - 1; i >= 0; i--)
    {
        dmax.push_back(b[j] - a[i]);

        if (a[i] > b[i - 1]) j = i - 1;
    }

    reverse(all(dmax));

    for (auto& i : dmin)
    {
        cout << i << " ";
    }

    cout << ln;

    for (auto& i : dmax)
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