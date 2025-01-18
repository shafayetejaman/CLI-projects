// https://www.spoj.com/problems/AGGRCOW/en/

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

bool valid(int diff, vi v, int c)
{
    int count = 1;
    int last = v.front();

    for (auto i = 1; i < v.size(); i++)
    {
        if (abs(last - v[i]) >= diff)
        {
            count++;
            last = v[i];
        }
    }
    return count >= c;
}

void solve()
{
    int n, c;
    cin >> n >> c;

    int l = 0, r = INT_MAX;

    vi v(n);

    for (auto& i : v)
    {
        cin >> i;
    }
    
    sort(all(v));
    int ans;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (valid(mid, v, c))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans <<'\n';
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}