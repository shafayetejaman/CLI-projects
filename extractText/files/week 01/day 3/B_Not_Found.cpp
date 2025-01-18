// https://atcoder.jp/contests/abc071/tasks/abc071_b?lang=en

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
    vb v(26,false);

    string s;
    cin >> s;

    for (auto &i : s)
    {
        v[i - 'a'] = true;
    }

    bool flag = true;
    for (auto i = 0; i < v.size(); i++)
    {
        if (!v[i])
        {
            flag = false;
            cout << char(i + 'a');
            break;
        }
    }

    if (flag) cout << "None";

}

int main()
{
    fast_cin();
    int t = 1;
    //cin >> t;

    loop(t) solve();

    return 0;
}