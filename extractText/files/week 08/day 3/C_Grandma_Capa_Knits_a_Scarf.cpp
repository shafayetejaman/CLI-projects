// https://codeforces.com/problemset/problem/1582/C

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

int result(string s, char c)
{
    int l = 0;
    int r = s.size() - 1;
    int count = 0;

    // cout << ln << s << ln;

    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++; r--;
        }
        else
        {
            if (s[l] == c)
            {
                count++;
                l++;
            }
            else if (s[r] == c)
            {
                count++;
                r--;
            }
            else return INT_MAX;
        }
    }

    return count;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++; r--;
        }
        else
        {
            int ansL = result(s.substr(l, (r - l) + 1), s[r]);
            int ansR = result(s.substr(l, (r - l) + 1), s[l]);

            if (ansL != INT_MAX or ansR != INT_MAX)
            {
                cout << min(ansL, ansR) << ln;
            }
            else cout << -1 << ln;

            return;
        }
    }

    cout << 0 << ln;

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