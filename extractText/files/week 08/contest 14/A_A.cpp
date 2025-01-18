// https://codeforces.com/problemset/problem/1433/A

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
    string n;
    cin >> n;

    vs v;

    for (auto i = 1; i <= 9; i++)
    {
        int m = 1;
        for (auto j = 1; j <= 4; j++)
        {
            string s;

            for (auto k = 0; k < m; k++)
            {
                s.push_back(i + '0');
            }
            v.push_back(s);
            m++;

            if (m > 4) break;
        }
    }

    ll count = 0;

    for (auto& i : v)
    {
        count += i.size();

        if (i == n) break;
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