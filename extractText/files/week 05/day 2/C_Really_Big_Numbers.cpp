// https://codeforces.com/problemset/problem/817/C

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

bool is_big(ll n, ll s)
{
    ll sum = 0;
    string str = to_string(n);

    for (auto& i : str)
    {
        sum += i - '0';
    }

    return abs(sum - n) >= s;
}

void solve()
{
    ll n, s;
    cin >> n >> s;

    ll l = 1, r = n;

    ll ans = 0;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (is_big(mid, s))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (ans == 0)cout << 0 << ln;
    else cout << n - ans + 1 << ln;

}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}