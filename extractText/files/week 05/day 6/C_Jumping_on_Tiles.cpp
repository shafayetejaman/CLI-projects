// https://codeforces.com/problemset/problem/1729/C

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
    string s;
    cin >> s;

    vi ans;
    ll count = 0;

    set<int> st;
    for (auto i = min(s.front(), s.back()); i <= max(s.front(), s.back()); i++)
    {
        st.insert((i - 'a') + 1);
    }

    vp v;
    for (auto i = 0; i < s.size(); i++)
    {
        if (!st.count((s[i] - 'a') + 1)) continue;

        v.push_back({(s[i] - 'a') + 1, i + 1});
    }

    bool flag = false;

    if (v.front().first > v.back().first)
    {
        reverse(all(v));
        flag = true;
    }

    if (v.size() > 2) sort(v.begin() + 1, v.end() - 1);

    for (auto i = 0; i < v.size(); i++)
    {
        ans.push_back(v[i].second);

        if (i != 0) count += abs(v[i - 1].first - v[i].first);
    }

    cout << count << " " << ans.size() << ln;

    if (flag) reverse(all(ans));

    for (auto& i : ans)
    {
        cout << i << ' ';
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}