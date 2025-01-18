// https://codeforces.com/problemset/problem/1741/C

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

void solve()
{
    int n;
    cin >> n;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    ll sum = 0;
    int ans = INT_MAX;

    for (auto i = 0; i < n; i++) //  55 45 30 30 40 100
    {
        sum += v[i];
        vi seg;

        seg.push_back(i + 1);

        ll s = 0;
        int j = i + 1;
        int count = 0;

        while (j < n)
        {
            s += v[j];
            count++;

            if (s == sum)
            {
                s = 0;
                seg.push_back(count);
                count = 0;

                if (j == n - 1)
                {
                    int m = INT_MIN;
                    for (auto& k : seg)
                    {
                        m = max(m, k);
                    }
                    ans = min(m, ans);
                }
            }
            j++;
        }
    }

    if (ans == INT_MAX) cout << n << ln;
    else cout << ans << ln;


    // cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}