// https://codeforces.com/problemset/problem/1768/C

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

typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
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
    int n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    map<ll, vi> m;

    for (ll i = 0; i < n; i++)
    {
        m[v[i]].push_back(i);
    }

    // ll maxFre = max_element(all(m), [](auto a, auto b) { return a.second.size() < b.second.size(); })->second.size();

    multiset<int> rem1, rem2;
    vll p1(n, -1), p2(n, -1);

    for (ll i = 1; i <= n; i++)
    {
        rem1.insert(i);
        rem2.insert(i);
    }

    bool flag = false;

    for (auto& [i, v] : m)
    {
        if (v.size() > 2) flag = true;

        if (v.size() == 1)
        {
            p1[v[0]] = i;
            rem1.erase(i);
        }
        else
        {
            p1[v[0]] = i;
            rem1.erase(i);

            p2[v[1]] = i;
            rem2.erase(i);
        }
    }

    // print(m);
    // print(p1);
    // print(p2);

    for (ll i = 0; i < n; i++)
    {
        if (p1[i] == -1 and p2[i] == -1) flag = true;

        else if (p1[i] == -1)
        {
            auto p = rem1.upper_bound(v[i]);

            if (p == rem1.begin() or rem1.empty()) flag = true;
            else
            {
                int num = *(--p);

                p1[i] = num;
                rem1.erase(num);
            }
        }
        else
        {
            auto p = rem2.upper_bound(v[i]);

            if (p == rem2.begin() or rem2.empty()) flag = true;
            else
            {
                int num = *(--p);

                p2[i] = num;
                rem2.erase(num);
            }
        }
    }

    if (flag) cout << "NO" << ln;
    else
    {
        cout << "YES" << ln;

        for (auto& i : p1)
        {
            cout << i << " ";
        }
        cout << ln;

        for (auto& i : p2)
        {
            cout << i << " ";
        }
        cout << ln;
    }

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