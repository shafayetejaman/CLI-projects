// https://codeforces.com/problemset/problem/1805/A

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
typedef long long ll;
#define ln '\n'
#define loop(n) for(auto j = 0; j < n; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define div(n, k) (n % k == 0)
#define even(n) (n % 2 == 0)
#define endl cout << '\n'

// const int N = 1e5 + 1;

void solve()
{
    int x = 0;
    int n;
    cin >> n;

    loop(n)
    {
        int a;
        cin >> a;
        x ^= a;
    }

    if (even(n))
    {
        if (x == 0) cout << 0;
        else cout << -1;
    }
    else cout << x;
    endl;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}