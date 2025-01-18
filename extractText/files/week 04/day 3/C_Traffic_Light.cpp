// https://codeforces.com/problemset/problem/1744/C

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
#define odd(n) (n % 2 != 0)
#define endl cout << '\n'

// const int N = 1e5 + 1;

void solve()
{
    int n;
    cin >> n;

    char st;
    string s, temp;
    cin >> st >> s;

    int i = 0;

    vi v;
    bool flag = true;
    for (int j = 0; j < n; j++)
    {
        if (s[j] == 'g') flag = true;
        if (s[j] == st and flag)
        {
            v.push_back(j);
            flag = false;
        }
    }

    while (s[i] != 'g') temp.push_back(s[i++]);

    s.append(temp + 'g');

    int ans = INT_MIN;

    for (auto& k : v)
    {
        int j = k;
        int count = 0;
        while (j < s.size() and s[j] != 'g')
        {
            count++;
            j++;
        }
  
        ans = max(ans, count);
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