// https://www.codechef.com/problems/WARRIORCHEF

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
#define loop(n) for(auto j = 0; j < (n); j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;

bool win(int x, vi & v, int h)
{
    for (auto &i : v)
    {
        if (x >= i) continue;

        h -= i;
        if (h < 1) return false;
    }
    return h >= 1;
}

void solve()
{
    int n, h;
    cin >> n >> h;

    vi v(n);

    int x, l=0, r= INT_MIN;

    for (auto& i : v)
    {
        cin >> i;
        r = max(r,i);
    }

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (win(mid, v,h))
        {
            r = mid - 1;
            x = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << x << '\n';
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}