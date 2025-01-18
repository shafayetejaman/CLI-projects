// https://atcoder.jp/contests/abc214/tasks/abc214_b?lang=en

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
    int a, b, count = 0;
    cin >> a >> b;

    for (auto i = 0; i <= a; i++)
    {
        for (auto j = 0; j <= a; j++)
        {
            for (auto k = 0; k <= a; k++)
            {
                if (i + j + k <= a and i * j * k <= b) count++;
            }
        }
    }
    cout << count;
}

int main()
{
    fast_cin();
    int t = 1;
    //cin >> t;

    loop(t) solve();

    return 0;
}