// https://codeforces.com/problemset/problem/1800/B

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
#define loop(n) for(auto j = 0; j < n; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define div(n, k) (n % k == 0)
#define even(n) (n % 2 == 0)
#define endl cout << '\n'

// const int N = 1e5 + 1;

void solve()
{
    int n, k, ans = 0;
    cin >> n >> k;

    map<char, int> m;
    string s;
    cin >> s;

    for (auto& i : s)
    {
        m[i]++;
    }

    for (auto& [c, count] : m)
    {
        char c2;

        if (islower(c)) c2 = toupper(c);
        else c2 = tolower(c);

        if (m[c2] != 0)
        {
            int b = min(m[c], m[c2]);

            ans += b;
            
            m[c] -= b;
            m[c2] -= b;
        }
        if (count >= 2)
        {
            int dup = count / 2;
            if (dup == 0) dup++;

            int b = min(dup, k);

            ans += b;
            count -= b * 2;
            k -= b;
        }
    }

    cout << ans << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}