// https://codeforces.com/problemset/problem/1585/C

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
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
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

    vll pos, neg;

    loop(n)
    {
        int temp;
        cin >> temp;

        if (temp < 0) neg.push_back(-temp);
        else pos.push_back(temp);
    }

    ll dis = 0;

    sort(all(pos), greater<>());
    sort(all(neg), greater<>());

    for (auto i = 0; i < neg.size(); i += k)
    {
        dis += 2 * neg[i];
    }

    for (auto i = 0; i < pos.size(); i += k)
    {
        dis += 2 * pos[i];
    }

    ll m = INT_MIN;

    if (!pos.empty()) m = max(m, pos[0]);
    if (!neg.empty()) m = max(m, neg[0]);

    cout << dis - m << ln;

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