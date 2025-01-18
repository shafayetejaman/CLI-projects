// https://codeforces.com/problemset/problem/1894/B

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;\

void solve()
{
    int n;
    cin >> n;

    vll v(n);
    map<int, int> m;

    for (auto& i : v)
    {
        cin >> i;
        m[i]++;
    }

    int one = -1;
    int two = -1;
    int f;

    for (auto i = 0; i < n; i++)
    {
        if (one == -1 and m[v[i]] >= 2)
        {
            one = i;
            f = v[i];
        }
        else if (one != -1 and v[i] != f and m[v[i]] >= 2)
        {
            two = i;
            break;
        }
    }

    if (one != -1 and two != -1)
    {
        for (auto i = 0; i < n; i++)
        {
            if (i == one) cout << "2 ";
            else if (i == two) cout << "3 ";
            else cout << "1 ";  
        }
    }
    else cout << -1;

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