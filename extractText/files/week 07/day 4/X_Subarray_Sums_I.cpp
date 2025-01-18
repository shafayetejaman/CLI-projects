// https://cses.fi/problemset/task/1660

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<long long, long long> pii;
typedef vector<long long> vi;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
#define ll long long
#define ld long double
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
    int n, k;
    cin >> n >> k;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    int l = 0;
    int r = 0;
    ll sum = 0;

    int count = 0;

    while (r < n)
    {
        sum += v[r++];

        while (sum > k)
        {
            sum -= v[l++];
        }
        if (sum == k) count++;
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