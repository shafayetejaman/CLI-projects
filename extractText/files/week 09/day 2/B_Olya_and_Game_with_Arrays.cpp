// https://codeforces.com/problemset/problem/1859/B

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

    vvi v;

    loop(n)
    {
        v.push_back({});
        int m;
        cin >> m;

        for (auto i = 0; i < m; i++)
        {
            int a;
            cin >> a;

            v.back().push_back(a);
        }
    }

    for (auto i = 0; i < n; i++)
    {
        sort(all(v[i]));
    }

    ll sum = 0;

    for (auto i = 0; i < n; i++)
    {
        sum += v[i][1];
    }

    int m = INT_MAX;

    for (auto i = 0; i < n; i++)
    {
        m = min(m, v[i][0]);
    }

    ll ans = 0;

    for (auto i = 0; i < n; i++)
    {
        ans = max(ans, (sum - v[i][1]) + m);

        // cout << ans << " " << sum << " " << v[i][1] << ln;
    }

    cout << ans << ln;


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