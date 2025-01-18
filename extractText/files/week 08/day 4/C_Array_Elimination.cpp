// https://codeforces.com/problemset/problem/1602/C

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

string dtob(ll n)
{
    string s(32, '0');

    for (auto i = 0; i < s.size(); i++)
    {
        if ((n & (1 << i)) != 0) s[i] = '1';
    }
    reverse(all(s));
    return s;
}

void solve()
{
    int n;
    cin >> n;

    vll v(n);
    map<int, int> m;

    for (auto& i : v)
    {
        cin >> i;
    }

    for (auto& i : v)
    {
        string s = dtob(i);

        for (auto j = 0; j < 32; j++)
        {
            if (s[j] == '1') m[j]++;
        }
    }

    vll ans;

    for (auto k = 1; k <= n; k++)
    {
        bool flag = true;

        for (auto& [f, s] : m)
        {
            if (s % k != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag) ans.push_back(k);
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