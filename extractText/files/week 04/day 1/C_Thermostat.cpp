// https://codeforces.com/problemset/problem/1759/C

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
    int l, r, x;
    cin >> l >> r >> x;

    int a, b, count;
    cin >> a >> b;

    if (a == b) count = 0;
    else if (a < b)
    {
        if (abs(a - b) >= x) count = 1;
        else if (abs(a - r) >= x and abs(r - b) >= x) count = 2;
        else if (abs(a - l) >= x and abs(l - b) >= x) count = 2;
        else if (abs(a - r) >= x and abs(r - l) >= x and abs(l - b) >= x) count = 3;
        else count = -1;
    }
    else
    {
        if (abs(a - b) >= x) count = 1;
        else if (abs(a - l) >= x and abs(l - b) >= x) count = 2;
        else if (abs(a - r) >= x and abs(r - b) >= x) count = 2;
        else if (abs(a - l) >= x and abs(l - r) >= x and abs(r - b) >= x) count = 3;
        else count = -1;
    }

    cout << count << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}