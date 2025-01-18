// https://codeforces.com/problemset/gymProblem/102961/ZC?locale=en

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#define ld long double
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    map<ll, ll> m;

    ll sum = 0;
    ll count = 0;

    m[0]++;

    for (auto& i : v)
    {
        sum += i;

        count += m[(((sum % n) + n) % n)];

        m[((sum % n) + n) % n]++;
    }

    cout << count << ln;

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