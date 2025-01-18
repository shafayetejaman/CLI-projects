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

    string s;
    cin >> s;

    int valid = 0;

    for (auto& i : s)
    {
        if (i == '(') valid++;
        else valid--;
    }

    if (valid != 0)
    {
        cout << -1 << ln;
        return;
    }

    stack<int> st;
    vll ans(n, 1);
    bool flag = false;

    for (auto i = 0; i < n; i++)
    {
        if (st.empty())
        {
            if (s[i] == '(') st.push(i);
            else
            {
                flag = true;
                break;
            }
        }
        else
        {
            if (s[i] == ')')
            {
                ans[i] = 2;
                ans[st.top()] = 2;

                st.pop();
            }
            else st.push(i);
        }
    }


    if (flag)
    {
        while (!st.empty()) st.pop();
        ans.assign(n, 1);

        for (auto i = 0; i < n; i++)
        {
            if (st.empty())
            {
                if (s[i] == ')') st.push(i);
            }
            else
            {
                if (s[i] == '(')
                {
                    ans[i] = 2;
                    ans[st.top()] = 2;

                    st.pop();
                }
                else st.push(i);
            }
        }
    }


    if (find(all(ans), 1) != ans.end() and find(all(ans), 2) != ans.end())
    {
        cout << 2 << ln;

        for (auto& i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << 1 << ln;

        for (auto i = 0; i < n; i++)
        {
            cout << "1 ";
        }
    }

    cout << ln;
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