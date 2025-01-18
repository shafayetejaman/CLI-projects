// https://codeforces.com/problemset/problem/1669/A

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
    int x;
    cin >> x;
    //     For Division 1: 1900≤rating
    //     For Division 2 : 1600≤rating≤1899
    //     For Division 3 : 1400≤rating≤1599
    //     For Division 4 : rating≤1399

    if (x >= 1900) cout << "Division 1" << ln;
    else if (x >= 1600 and x <= 1899) cout << "Division 2" << ln;
    else if (x >= 1400 and x <= 1599) cout << "Division 3" << ln;
    else if (x <= 1999) cout << "Division 4" << ln;
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop (t) solve();

    return 0;
}