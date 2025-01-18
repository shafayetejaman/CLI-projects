// https://www.codechef.com/problems/CONCUSSIVE

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

bool valid(vll& ans)
{
    for (auto i = 1; i < ans.size() - 1; i++)
    {
        if (!((ans[i] > ans[i - 1] and ans[i] > ans[i + 1]) or (ans[i] < ans[i + 1] and ans[i] < ans[i - 1])))
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    sort(all(v));

    vll temp1(n), temp2(n);

    int idx = 0;

    for (auto i = 0; i < n; i++)
    {
        if (idx >= n)
        {
            idx = 1;
        }
        temp1[idx] = v[i];
        idx += 2;
    }

    idx = 1;
    for (auto i = 0; i < n; i++)
    {
        if (idx >= n)
        {
            idx = 0;
        }
        temp2[idx] = v[i];
        idx += 2;
    }

    if (valid(temp1))
    {
        for (auto& i : temp1)
        {
            cout << i << " ";
        }
    }
    else if (valid(temp2))
    {
        for (auto& i : temp2)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1 << " ";
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