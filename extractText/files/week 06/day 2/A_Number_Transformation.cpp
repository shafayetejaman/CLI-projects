// https://codeforces.com/problemset/problem/1674/A

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
    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 1 << " " << 1 << ln;
        return;
    }
    else if (a > b or b % a != 0)
    {
            cout << 0 << " " << 0 << ln;
            return;       
    }
    else
    {
        cout << 1 << " "<< b / a;
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}