// https://www.codechef.com/problems/DICENUM?tab=statement

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

// const int N = 1e5 + 1;

void solve()
{
    vi v1(3), v2(3);

    for (auto& i : v1)
    {
        cin >> i;
    }
    for (auto& i : v2)
    {
        cin >> i;
    }
    sort(all(v1));
    sort(all(v2));

    for (auto i = 3; i >= 0; i--)
    {
        if (v1[i] < v2[i])
        {
            cout << "Bob" << ln;
            return;
        }
        if (v1[i] > v2[i])
        {
            cout << "Alice" << ln;
            return;
        }
    }
    cout << "Tie" << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}