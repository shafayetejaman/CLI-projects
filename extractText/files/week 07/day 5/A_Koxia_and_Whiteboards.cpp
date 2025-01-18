// https://codeforces.com/problemset/problem/1770/A

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
#define ld long double
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    // int n;
    // cin >> n;

    vll v1(n);

    for (auto& i : v1)
    {
        cin >> i;
    }

    // int n;
    // cin >> n;

    vll v2(m);

    for (auto& i : v2)
    {
        cin >> i;
    }


    for (auto i = 0; i < m; i++)
    {
        sort(all(v1));
        v1[0] = v2[i];
    }

    cout << accumulate(all(v1), LL 0) << ln;

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