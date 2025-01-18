// https://codeforces.com/problemset/problem/1095/B

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

// const int N = 1e5 + 1;

void solve()
{
    int n, ma1 = INT_MIN, ma2 = INT_MIN, mi1 = INT_MAX, mi2 = INT_MAX;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;

        ma1 = max(ma1, i);
        mi1 = min(mi1, i);
    }

    bool flag1 = true;
    bool flag2 = true;

    for (auto& i : v)
    {
        if (flag1 and i == ma1)
        {
            i = -1;
            flag1 = false;
        }
        if (flag2 and i == mi1)
        {
            i = -1;
            flag2 = false;
        }
        if (!flag1 and !flag2) break;
    }

    for (auto& i : v)
    {
        ma2 = max(ma2, i);
        if (i != -1)
            mi2 = min(mi2, i);
    }
    if (n == 2) cout << 0;
    else
        cout << min(ma2 - mi1, ma1 - mi2);

}


int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}