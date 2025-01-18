// https://codeforces.com/problemset/problem/1864/B

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

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (even(k))
    {
        string ans = s;
        sort(all(ans));

        cout << ans << ln;
        return;
    }

    string t1, t2, ans;

    for (ll i = 0; i < n; i++)
    {
        if (even(i)) t1.push_back(s[i]);
        else t2.push_back(s[i]);
    }

    sort(all(t1));
    sort(all(t2));

    for (ll i = 0, j = 0, k = 0; i < n; i++)
    {
        if (even(i)) ans.push_back(t1[k++]);
        else ans.push_back(t2[j++]);
    }

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