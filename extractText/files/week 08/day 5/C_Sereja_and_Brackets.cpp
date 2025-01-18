// https://codeforces.com/problemset/problem/380/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("closeoll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

const int N = 3e6 + 1;
// const int M = 1e9 + 7;

class Node
{
public:
    int open;
    int close;
    int fre;

    Node(int open, int close, int fre)
    {
        this->open = open;
        this->close = close;
        this->fre = fre;
    }

    Node()
    {
        this->open = 0;
        this->close = 0;
        this->fre = 0;
    }
};

vector<Node> Tree(N);

Node merge(Node a, Node b)
{
    int n = min(a.open, b.close);

    int fre = a.fre + b.fre + n;

    int open = a.open + b.open - n;
    int close = a.close + b.close - n;

    Node c(open, close, fre);
    return c;
}

void build(int root, int l, int r, string& s)
{
    if (l == r)
    {
        if (s[r] == '(') Tree[root].open = 1;
        else Tree[root].close = 1;

        return;
    }

    int mid = l + (r - l) / 2;
    int left = root * 2;
    int right = left + 1;

    build(left, l, mid, s);
    build(right, mid + 1, r, s);

    Tree[root] = merge(Tree[left], Tree[right]);
}

Node query(int root, int l, int r, int x, int y)
{
    if (y < l or x > r) return {};

    if (l >= x and r <= y) return Tree[root];

    int mid = l + (r - l) / 2;
    int left = root * 2;
    int right = left + 1;

    return merge(query(left, l, mid, x, y), query(right, mid + 1, r, x, y));
}

void solve()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    build(1, 0, s.size() - 1, s);

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;

        cout << query(1, 0, s.size() - 1, x, y).fre * 2 << ln;
    }


    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}