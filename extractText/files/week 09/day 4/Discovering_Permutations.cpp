// https://lightoj.com/problem/discovering-permutations

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
// "DEBUG_TEMPLATE.h"

void solve()
{
    int n, k;
    cin >> n >> k;


    string s, t;

    for (auto i = 'A'; i < n + 'A'; i++)
    {
        s.push_back(i);
    }

    do
    {
        cout << s << ln;
        k--;
    }
    while (k and next_permutation(all(s)));

    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    int c = 1;

    loop(t)
    {
        cout << "Case " << c++ << ":" << ln;
        solve();
    }

    return 0;
}