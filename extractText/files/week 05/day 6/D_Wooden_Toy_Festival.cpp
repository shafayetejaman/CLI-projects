// https://codeforces.com/problemset/problem/1840/D

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
#define ll long long
#define ld long double
#define ln '\n'
#define loop(n) for(auto j = 0; j < (n); j++)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;

bool valid(int diff, vi& v)
{
    int count = 1;

    int l = 0;
    int r = 1;

    while (r < v.size() and l < v.size())
    {
        int x = v[l] + diff;

        if (abs(x - v[r]) <= diff) r++;
        else
        {
            l = r;
            count++;
        }
    }

    return count <= 3;
}

void solve()
{
    int n;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    sort(all(v));

    int l = 0, r = INT_MAX;

    int ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (valid(mid, v))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << ln;
    // cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}