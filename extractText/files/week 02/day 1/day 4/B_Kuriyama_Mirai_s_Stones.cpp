// https://codeforces.com/problemset/problem/433/B

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

    vll v(n), prev(n, 0), sprev(n, 0);

    for (auto& i : v)
    {
        cin >> i;
    }

    prev[0] = v[0];
    for (auto i = 1; i < n; i++)
    {
        prev[i] = prev[i - 1] + v[i];
    }

    vll sv = v;

    sort(all(sv));
    // sorted
    sprev[0] = sv[0];
    for (auto i = 1; i < n; i++)
    {
        sprev[i] = sprev[i - 1] + sv[i];
    }

    int q;
    cin >> q;

    loop(q)
    {
        int op, a, b;
        cin >> op >> a >> b;

        ll res;

        if (op == 1)
        {
            if (a == 1) res = prev[b - 1];
            else res = prev[b - 1] - prev[a - 2];
        }
        else
        {
            if (a == 1) res = sprev[b - 1];
            else res = sprev[b - 1] - sprev[a - 2];
        }

        cout << res << ln;
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