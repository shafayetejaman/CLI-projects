// https://codeforces.com/problemset/problem/1097/B

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
    int n;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    for (auto i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (auto j = 0; j < n; j++)
        {
            if ((i & (1 << j)) == 0)
                sum -= v[j];
            else
                sum += v[j];
        }
        if (sum % 360 == 0)
        {
            cout << "YES" << ln;
            return;
        }
    }
    cout << "NO" << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}