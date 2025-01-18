// https://codeforces.com/problemset/problem/1676/D

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
typedef long long ll;
#define ln '\n'
#define loop(n) for(auto j = 0; j < n; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define div(n, k) (n % k == 0)
#define even(n) (n % 2 == 0)

// const int N = 1e5 + 1;

void solve()
{
    int n, m;
    cin >> n >> m;

    vvi v(n, vi(m));

    for (auto &i : v)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    int ans = INT_MIN;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            int ci = i;
            int cj = j;
            int sum = 0;

            while (ci < n and ci >= 0 and cj >= 0 and cj < m)
            {
                sum += v[ci++][cj++];
            }
            ci = i+1;
            cj = j-1;
            while (ci < n and ci >= 0 and cj >= 0 and cj < m)
            {
                sum += v[ci++][cj--];
            }
            ci = i-1;
            cj = j+1;
            while (ci < n and ci >= 0 and cj >= 0 and cj < m)
            {
                sum += v[ci--][cj++];
            }
            ci = i-1;
            cj = j-1;
            while (ci < n and ci >= 0 and cj >= 0 and cj < m)
            {
                sum += v[ci--][cj--];
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}