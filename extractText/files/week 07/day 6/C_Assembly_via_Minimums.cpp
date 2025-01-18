// https://codeforces.com/problemset/problem/1857/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vll v(n * (n - 1) / 2);

    for (auto& i : v)
    {
        cin >> i;
    }

    sort(all(v));
    vll ans;

    int j = n - 1;
    int i = 0;

    while (j > 0)
    {
        ans.push_back(v[i]);

        i += j;
        j--;
    }

    for (auto& i : ans)
    {
        cout << i << " ";
    }

    cout << ans.back();

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