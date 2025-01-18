// https://codeforces.com/problemset/problem/1594/B

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
const int M = 1e9 + 7;

ll pow(ll n, ll i)
{
    ll ans = 1;

    while (i > 0)
    {
        if (i & 1) ans = (ans * n) % M;
        n = (n * n) % M;
        i >>= 1;
    }
    
    return ans;
}


void solve()
{
    ll n, k;
    cin >> n >> k;

    vll v;
    ll c = 0;

    while (k)
    {
        if (k & 1 != 0) v.push_back(c);
        k >>= 1;
        c++;
    }

    ll ans = 0;

    for (auto& i : v)
    {
        ans = (ans + (pow(n, i) % M)) % M;
    }

    cout << ans % M << ln;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}