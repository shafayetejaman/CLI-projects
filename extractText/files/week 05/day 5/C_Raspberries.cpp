// https://codeforces.com/problemset/problem/1883/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
#define ln '\n'
#define loop(n) for(auto j = 0; j < (n); j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define ll long long

// const int N = 1e5 + 1;

void solve()
{
    int n, m;
    cin >> n >> m;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    int ans = INT_MAX;
    bool flag = false;

    for (auto& i : v)
    {
        if (i % m == 0)
        {
            ans = 0;
            flag = true;
            break;
        }
        else
        {
            ans = min(ans, (((i / m) + 1) * m) - i);
        }
    }

    if (!flag and m == 4)
    {
        int even = 0;

        for (auto& i : v)
        {
            if (even(i)) even++;
        }

        if (even >= 2) ans = min(ans, 0);
        else if (even == 1) ans = min(ans, 1);
        else if (even == 0) ans = min(ans, 2);

    }

    cout << ans << ln;

    // cout << '\n';
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}