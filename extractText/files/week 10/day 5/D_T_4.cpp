// 

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#ifdef LOCAL
#include "DEBUG_TEMPLATE.h"
#else
#define line
#define print(args...)
#endif

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 1;
// const int M = 1e9 + 7;

ll n;
vector<bool> vis(N, false);
vector<string> per;

void fun(string& v, int idx, string temp)
{
    if (idx == v.size())
    {
        per.push_back(temp);
        return;
    }

    set<char> se;

    for (auto i = 0; i < v.size(); i++)
    {
        if (vis[i] or se.count(v[i])) continue;

        se.insert(v[i]);

        temp.push_back(v[i]);
        vis[i] = true;

        fun(v, idx + 1, temp);

        temp.pop_back();
        vis[i] = false;
    }
}

void solve()
{
    fill(all(vis), false);
    per.clear();

    string s;
    cin >> s;

    cin >> n;

    sort(all(s));

    fun(s, 0, {});

    // print(per);

    cout << per[n] << ln;

    // cout << ln;
}

int main()
{

#ifndef LOCAL
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

    int t = 1;
    cin >> t;

    while (t--) solve();


    return 0;
}