// 

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
// #include "DEBUG_TEMPLATE.h"

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    stack<pair<char, int>> up, lo;

    for (auto i = 0; i < n; i++)
    {
        if (s[i] == 'b' and !lo.empty()) lo.pop();
        if (s[i] == 'B' and !up.empty()) up.pop();

        if (s[i] == 'b' or s[i] == 'B') continue;

        if (isupper(s[i])) up.push({s[i], i});
        else lo.push({s[i], i});
    }

    vector<char> v(n, '~');

    while (!up.empty())
    {
        v[up.top().second] = up.top().first;
        up.pop();
    }

    while (!lo.empty())
    {
        v[lo.top().second] = lo.top().first;
        lo.pop();
    }

    for (auto& i : v)
    {
        if (i == '~') continue;
        cout << i;
    }

    cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}