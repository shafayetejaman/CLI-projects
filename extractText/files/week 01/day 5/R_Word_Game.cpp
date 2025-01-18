// https://codeforces.com/problemset/problem/1722/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
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

//const int N = 1e5 + 1;

void solve()
{
    int n;
    cin >> n;

   unordered_map<string, vi> m;

    vi ans(3);

    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            string s;
            cin >> s;

            m[s].push_back(i);
        }
    }
    for (auto& i : m)
    {
        vi& v = i.second;

        for (auto &j : v)
        {
            if (v.size() == 1)  ans[j] += 3;
            
            else if (v.size() == 2) ans[j] += 1;
                 
        }

    }
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << ln;

}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}