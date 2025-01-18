// https://codeforces.com/problemset/problem/762/A

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#define ld long double
#define ll long long
#define LL (long long)
#define LD (long double)
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);

            if ((n / i) != i) v.push_back(n / i);
        }
    }

    sort(all(v));

    if (v.size() < k) cout << -1 << ln;
    else cout << v[k - 1] << ln;

    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}