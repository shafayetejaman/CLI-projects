// https://codeforces.com/problemset/problem/1873/F

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

    vll a(n);

    for (auto& i : a)
    {
        cin >> i;
    }

    vll h(n);

    for (auto& i : h)
    {
        cin >> i;
    }

    int l = 0;
    int r = 0;

    ll sum = 0;
    int ans = 0;

    while (r < n)
    {
        sum += a[r];

        while (sum > k)
        {
            sum -= a[l++];
        }

        ans = max(ans, (r - l) + 1);

        if (r < n - 1 and h[r] % h[r + 1] != 0)
        {
            sum = 0;
            l = r + 1;
        }
        r++;
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