// https://codeforces.com/problemset/problem/26/A

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

vi prime_generate(int n)
{
    vi v;

    for (auto i = 2; i <= n; i++)
    {
        bool flag = true;
        for (auto j = 2; j < i; j++)
        {
            if (div(i, j))
            {
                flag = false;
                break;
            }
        }
        if (flag) v.push_back(i);
    }

    return v;
}

void solve()
{
    int n, count = 0;
    cin >> n;

    vi primes = prime_generate(n);

    for (auto i = 2; i <= n; i++)
    {
        int c = 0;
        for (auto& j : primes)
        {
            if (div(i, j)) c++;
            if (c > 2) break;
        }
        if (c == 2) count++;
    }

    cout << count;
}


int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}