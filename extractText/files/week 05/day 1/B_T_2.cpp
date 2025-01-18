// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define ln '\n'
#define ll long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        string a, b;

        auto itL = lower_bound(v.begin(), v.end(), n);
        auto itR = upper_bound(v.begin(), v.end(), n);

        if (itL == v.end()) a = to_string(v.back());
        else
        {
            if (itL == v.begin()) a = 'X';
            else a = to_string(*(itL - 1));
        }

        if (itR == v.end()) b = 'X';
        else b = to_string(*itR);

        cout << a << " " << b << "\n";
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