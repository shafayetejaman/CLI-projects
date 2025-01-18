// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415

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

void solve()
{
    int i = 1;
    while (true)
    {
        int n, q;
        cin >> n >> q;

        if (n == 0 or q == 0) break;

        vi v(n);

        for (auto& i : v)
        {
            cin >> i;
        }
        sort(all(v));

        cout << "CASE# " << i << ":" << ln;
        i++;

        while (q--)
        {
            int tar;
            cin >> tar;


            int l = 0, r = n - 1;
            int ans = -1;

            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if (v[mid] == tar)
                {
                    ans = mid + 1;
                    r = mid - 1;
                }
                else if (v[mid] < tar)
                {
                    l = mid + 1;
                }
                else r = mid - 1;
            }

            if (ans == -1) cout << tar << " not found" << ln;
            else cout << tar << " found at " << ans << ln;
        }
    }
}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}