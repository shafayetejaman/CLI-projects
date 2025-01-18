// https://codeforces.com/problemset/problem/1433/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    bool flag = false;

    for (auto i = 0; i < n - 1; i++)
    {
        if (v[i] != v[i + 1])
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        cout << -1 << ln;
        return;
    }

    int idx = -1;
    ll m = INT_MIN;

    for (auto& i : v)
    {
        m = max(m, i);
    }

    for (auto i = 0; i < n; i++)
    {
        if (v[i] != m) continue;

        if (i == 0 and v[i + 1] != m) idx = i + 1;

        else if (i == n - 1 and v[i - 1] != m) idx = i + 1;

        else if ((i > 0 and i < n - 1) and (v[i + 1] != m or v[i - 1] != m)) idx = i + 1;
    }

    cout << idx << ln;

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