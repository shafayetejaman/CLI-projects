// https://codeforces.com/problemset/problem/1881/D

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
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
    int n;
    cin >> n;
    
    vi v(n);
    
    for (auto& i : v)
    {
        cin >> i;
    }

    map<int, int> m;

    for (auto i = 0; i < n; i++)
    {
        int a = v[i];
        
        for (auto j = 2; j * j <= a; j++)
        {
            while (a%j ==0)
            {
                a /= j;
                m[j]++;
            }
            
        }

        if (a > 1) m[a]++;
    }

    for (auto& [f, s] : m)
    {
        if (s % n != 0)
        {
            cout << "NO" << ln;
            return;
        }
    }

    cout << "YES" << ln;

    // cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}