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

typedef vector<long long> vll;
typedef vector<int> vi;
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
    int n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    int count = 0;

    stack<int> st1, st2;
    set<int> s;

    for (auto i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            st1.push(i);
        }
        else
        {
            if (!st1.empty())
            {
                s.insert(i);
                s.insert(st1.top());

                st1.pop();
                count++;
            }
        }
    }

    for (auto i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            if (!s.count(i)) st2.push(i);
        }
        else
        {
            if (!st2.empty() && !s.count(i))
            {
                st2.pop();
                count++;

            }
        }
    }


    cout << count << ln;

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