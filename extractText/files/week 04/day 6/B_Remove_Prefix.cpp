// https://codeforces.com/problemset/problem/1714/B

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
    unordered_map<int, ll> m;
    ll dup = 0;

    ll n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
        m[i]++;
        if (m[i] > 1) dup++;
    }
    reverse(all(v));

    auto i = 0;

    for (; i < n - 1; i++)
    {
        if (dup)
        {
            int last = v.back();
            v.pop_back();

            if (m[last] > 1)
            {
                m[last]--;
                dup--;
            }
            else m.erase(last);
        }
        else break;
    }

    cout << i << '\n';
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}