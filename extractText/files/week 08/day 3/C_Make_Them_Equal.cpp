// https://codeforces.com/problemset/problem/1594/C

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
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    char c;
    cin >> c;

    string s;
    cin >> s;

    int count = 0;

    for (auto i = 0; i < n; i++)
    {
        if (s[i] != c) count++;
    }

    if (!count) cout << 0 << ln;
    else
    {
        if (s.back() == c) cout << 1 << ln << n << ln;
        else
        {
            for (auto i = 2; i <= n; i++)
            {
                bool div = true;

                for (auto j = i; j <= n; j += i)
                {
                    if (s[j - 1] != c)
                    {
                        div = false;
                        break;
                    }
                }

                if (div)
                {
                    cout << 1 << ln << i << ln;
                    return;
                }
            }

            cout << 2 << ln << n - 1 << " " << n << ln;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}