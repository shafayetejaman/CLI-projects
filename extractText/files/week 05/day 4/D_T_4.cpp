// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2408

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define ln '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;

bool valid(vector<int>& v, int c, int max)
{
    int count = 1;
    int cap = max;

    for (auto& i : v)
    {
        if (i > max) return false;

        if (i > cap)
        {
            if (count == c) return false;

            count++;
            cap = max;
        }

        cap -= i;
    }
    return true;
}

void solve()
{
    int n, c;

    while (cin >> n >> c)
    {
        int l = 0, r = INT_MAX;

        vector<int> v(n);

        for (auto& i : v)
        {
            cin >> i;
        }

        int ans;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (valid(v, c, mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << '\n';

        // if (cin.eof()) break;
    }

}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}