// https://codeforces.com/problemset/problem/1790/D

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
    int n;
    cin >> n;
    
    vi v(n);
    map<int, int> m;
    int count = 0;

    for (auto &i : v)
    {
        cin >> i;
        m[i]++;
    }

    sort(all(v));

    for (auto i = 0; i < n; i++)
    {
        int j = v[i];
        bool flag = false;

        while (m.count(j))  
        {
            if (m[j] == 1) m.erase(j);
            else m[j]--;
            j++;
            flag = true;
        }
        if (flag) count++;
    }
    cout << count << ln;
   
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}