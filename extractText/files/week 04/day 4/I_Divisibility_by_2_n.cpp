// https://codeforces.com/problemset/problem/1744/D

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
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define endl cout << '\n'

// const int N = 1e5 + 1;

void solve()
{
    int n, count = 0;
    cin >> n;

    ll N = pow(2, n);

    vll v(n), ith;

    for (auto& i : v)
    {
        cin >> i;
    }

    for (auto i = 0; i < n; i++)
    {
        while (v[i] % 2 == 0)
        {
            v[i] /= 2;
            count++;
        }

        ll j = i + 1;
        int ithCount = 0;

        while (j % 2 == 0)
        {
            j /= 2;
            ithCount++;
        }
        ith.push_back(ithCount);
    }

    sort(all(ith));

    int ans = 0;

    for (int i = ith.size() - 1; i >= 0; i--)
    {
        if (count < n)
        {
            count += ith[i];
            ans++;
        }
        else break;
    }

    if (count >= n) cout << ans << ln;
    else cout << -1 << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}