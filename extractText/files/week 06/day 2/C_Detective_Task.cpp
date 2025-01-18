// https://codeforces.com/problemset/problem/1675/C

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

    int n = s.size();

    int zero = -1;
    int one = -1;

    for (auto i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero = i;
            break;
        }
    }
    for (auto i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            one = i;
            break;
        }
    }

    if (one == -1 and zero != -1) cout << zero + 1;

    else if (one != -1 and zero == -1) cout << n - one;

    else if (one == -1 and zero == -1) cout << n;
    
    else cout << (zero - one) + 1;


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