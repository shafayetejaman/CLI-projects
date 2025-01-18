// https://codeforces.com/problemset/problem/1766/C

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

bool fun(vector<vc>& v, int i, int j, int count)
{
    int n = v[0].size();
    vector<vb> vis(2, vb(n, false));

    while (j < n and count > 0)
    {
        vis[i][j] = true;
        count--;

        if (i == 0)
        {
            if (v[1][j] == 'B' and !vis[1][j])
            {
                i = 1;
            }
            else if (j < n - 1 and v[i][j + 1] == 'B' and !vis[i][j + 1])
            {
                j++;
            }
            else break;
        }
        else
        {
            if (v[0][j] == 'B' and !vis[0][j])
            {
                i = 0;
            }
            else if (j < n - 1 and v[i][j + 1] == 'B' and !vis[i][j + 1])
            {
                j++;
            }
            else break;
        }
    }

    if (count == 0) return true;
    else return false;
}

void solve()
{
    int n;
    cin >> n;

    ll count = 0;

    vector<vc> v(2, vc(n));

    for (auto& i : v)
    {
        for (auto& j : i)
        {
            cin >> j;
            if (j == 'B') count++;
        }
    }

    bool flag = false;

    for (auto i = 0; i < n; i++)
    {
        if (v[0][i] == 'B' and v[1][i] == 'B')
        {
            flag = fun(v, 0, i, count) or fun(v, 1, i, count);
            break;
        }
        else if (v[0][i] == 'B')
        {
            flag = fun(v, 0, i, count);
            break;
        }
        else if (v[1][i] == 'B')
        {
            flag = fun(v, 1, i, count);
            break;
        }
    }

    if (flag) cout << "YES" << ln;
    else cout << "NO" << ln;

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
