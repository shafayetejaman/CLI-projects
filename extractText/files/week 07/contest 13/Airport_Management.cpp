// https://www.codechef.com/problems/AIRM

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
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
#define ll long long
#define ld long double
#define LL (long long)
#define LD (long double)
#define ln '\n'
#define all(x) (x).begin(), (x).end()
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    map<int, int> m;

    loop(n)
    {
        int a, b;
        cin >> a >> b;

        m[a]++;
        m[b]++;
    }

    int count = 1;

    for (auto& [f, s] : m)
    {
        count = max(count, s);
    }

    cout << count << ln;

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