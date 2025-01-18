// https://codeforces.com/problemset/problem/1604/A

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
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

//const int N = 1e5 + 1;

void solve()
{
    int n, ans = 0;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    for (auto i = 0; i < n; i++)
    {
        int dif = v[i] - (i + 1) - ans;
        if (dif > 0)
        {
            ans += dif;
        }
    }
    cout << ans << ln;

}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}