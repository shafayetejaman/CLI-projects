// https://codeforces.com/problemset/problem/1702/D

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
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)

// const int N = 1e5 + 1;

void solve()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    string temp = s;

    sort(all(temp));

    ll sum = 0;

    for (auto& i : temp)
    {
        sum += (i - 'a') + 1;
    }

    map<char, int> m;

    while (sum > k and !temp.empty())
    {
        char c = temp.back();
        sum -= (c - 'a') + 1;

        m[c]++;

        temp.pop_back();
    }

    string ans;

    for (auto& i : s)
    {
        if (m.count(i) and m[i] > 0)
        {
            m[i]--;
            continue;
        }

        ans.push_back(i);
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