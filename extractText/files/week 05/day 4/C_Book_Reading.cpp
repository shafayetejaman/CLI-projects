// https://codeforces.com/problemset/problem/1213/C

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
#define loop(n) for(auto j = 0; j < (n); j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;

void solve()
{
    ll n, m;
    cin >> n >> m;

    vi p;
    for (auto i = m;; i += m)
    {
        p.push_back(i % 10);
        
        if (i % 10 == 0) break;
    }
    ll sum = 0;
    for (auto& i : p)
    {
        sum += i;
    }

    ll div = (n / m) / p.size();
    ll rem = (n / m) % p.size();
    sum *= div;

    for (auto& i : p)
    {
        if (!rem--) break;
        sum += i;
    }

    cout << sum << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}