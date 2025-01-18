// https://atcoder.jp/contests/abc209/tasks/abc209_a?lang=en

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
#define endl '\n'
#define ll long long
#define range(n) for(auto j = 0; j < n; j++)

const int N = 1e5 + 1;

int main()
{
    int x, y;
    cin >> x >> y;

    if (x < y) cout << y - x + 1;
    else cout << 0;

    return 0;
}