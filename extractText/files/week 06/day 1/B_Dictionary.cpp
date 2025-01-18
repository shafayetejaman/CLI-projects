// https://codeforces.com/problemset/problem/1674/B

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
typedef vector<vector<char>> vvc;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
#define ll long long
#define ld long double
#define ln '\n'
#define loop(n) for(auto j = 0; j < (n); j++)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;

void solve()
{
    string s;
    cin >> s;

    map<string, int> m;

    string p = "ab";
    int idx = 1;

    loop(650)
    {
        if (p[0] == p[1])
        {
            if (p[1] == 'z')
            {
                p[0]++;
                p[1] = 'a';
            }
            else p[1]++;
        }

        m[p] = idx;
        idx++;

        if (p[1] == 'z')
        {
            p[0]++;
            p[1] = 'a';
        }
        else p[1]++;
    }

    cout << m[s] << ln;

    // for (auto &[f, s] : m)
    // {
    //     cout << f << s << ln;
    // }

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