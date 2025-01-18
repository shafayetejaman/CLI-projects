// https://codeforces.com/problemset/problem/1669/C

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
    int n;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    int first = v[0];
    int second = v[1];
    bool flag = false;

    for (auto i = 2; i < v.size(); i += 2)
    {
        if (first % 2 == 0 and v[i] % 2 != 0) flag = true;
        if (first % 2 != 0 and v[i] % 2 == 0) flag = true;
    }

    for (auto i = 3; i < v.size(); i += 2)
    {
        if (second % 2 == 0 and v[i] % 2 != 0) flag = true;
        if (second % 2 != 0 and v[i] % 2 == 0) flag = true;
    }

    if (flag) cout << "NO" << ln;
    else cout << "YES" << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}