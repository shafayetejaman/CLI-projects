// https://codeforces.com/problemset/problem/1234/B2

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pii;
typedef vector<long long> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
#define ln '\n'
#define loop(n) for(auto j = 0; j < (n); j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define int long long

// const int N = 1e5 + 1;

void solve()
{
    int n, k;
    cin >> n >> k;

    vi v(n);
    deque<int> dq;
    map<int, int> m;

    for (auto& i : v)
    {
        cin >> i;
    }

    for (auto& i : v)
    {
        if (m[i] > 0) continue;

        if (dq.size() == k)
        {
            m[dq.back()]--;
            dq.pop_back();
        }

        m[i]++;
        dq.push_front(i);
    }
    
    cout << dq.size() << ln;

    for (auto i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }

    cout << '\n';
}

signed main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}