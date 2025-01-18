// https://www.spoj.com/problems/CSUMQ/en/

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
    int n;
    cin >> n;

    vll v(n), prev(n, 0), next(n, 0);

    for (auto& i : v)
    {
        cin >> i;
    }

    prev[0] = v[0];
    for (auto i = 1; i < n; i++)
    {
        prev[i] = prev[i - 1] + v[i];
    }

    next.back() = v.back();
    for (auto i = n - 2; i >= 0; i--)
    {
        next[i] = next[i + 1] + v[i];
    }

    ll sum = accumulate(all(v), (ll)0);

    int q;
    cin >> q;

    loop(q)
    {
        int a, b;
        cin >> a >> b;

        ll l, r;

        if (a == 0) l = 0;
        else l = prev[a-1];

        if (b == n-1) r = 0;
        else r = next[b+1];

        cout << sum - (l + r) << ln;
       
    }

}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}