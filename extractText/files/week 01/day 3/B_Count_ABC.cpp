// https://atcoder.jp/contests/abc150/tasks/abc150_b?lang=en

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
    int n, count = 0;

    string s;
    cin >> n >> s;

    for (auto i = 0; i != -1;)
    {
        i = s.find("ABC", i);
        if (i != -1)
        {
            count++;
            i++;
        }
    }

    cout << count;
}

int main()
{
    fast_cin();
    int t = 1;
    //cin >> t;

    loop (t) solve();

    return 0;
}