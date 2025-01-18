// https://lightoj.com/problem/curious-robin-hood

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 1;
// const int M = 1e9 + 7;

vll tree(N);

void build(int node, int l, int r, vll& v)
{
    if (l == r)
    {
        tree[node] = v[r];
        return;
    }

    int mid = l + (r - l) / 2;
    int left = node * 2;
    int right = left + 1;

    build(left, l, mid, v);
    build(right, mid + 1, r, v);

    tree[node] = tree[left] + tree[right];

}

void update(int node, int l, int r, int idx, int val)
{
    if (idx > r or idx < l) return;

    if (idx == l and l == r)
    {
        tree[node] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    int left = node * 2;
    int right = left + 1;

    update(left, l, mid, idx, val);
    update(right, mid + 1, r, idx, val);

    tree[node] = tree[left] + tree[right];

}

int query(int node, int l, int r, int x, int y)
{
    if (x > r or y < l) return 0;

    if (x <= l and r <= y) return tree[node];

    int mid = l + (r - l) / 2;
    int left = node * 2;
    int right = left + 1;

    return query(left, l, mid, x, y) + query(right, mid + 1, r, x, y);
}


void solve()
{
    int n, q;
    cin >> n >> q;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    build(1, 0, n - 1, v);


    while (q--)
    {
        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int idx;
            cin >> idx;

            ll poor = query(1, 0, n - 1, idx, idx);
            update(1, 0, n - 1, idx, 0);

            cout << poor << ln;
        }
        else if (opt == 2)
        {
            int idx, val;
            cin >> idx >> val;

            update(1, 0, n - 1, idx, query(1, 0, n - 1, idx, idx) + val);
        }
        else
        {
            int a, b;
            cin >> a >> b;

            cout << query(1, 0, n - 1, a, b) << ln;
        }
    }

    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    for (auto i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << ln;
        solve();
    }

    return 0;
}