// https://codeforces.com/problemset/problem/1886/B

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#define ln '\n'
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;

double distance(int ax, int ay, int bx, int by)
{
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

bool inside(int ax, int ay, int bx, int by, double r)
{
    return r - distance(ax, ay, bx, by) > 1e-7;
}

void solve()
{
    int ax, ay, bx, by, px, py;
    cin >> px >> py >> ax >> ay >> bx >> by;

    double l = 0;
    double r = INT_MAX;
    double ans;

    while (r - l > 1e-7)
    {
        bool flag = false;

        double mid = ((r - l) / 2) + l;

        if (inside(ax, ay, 0, 0, mid) and
            inside(ax, ay, px, py, mid)) flag = true;
        else if (inside(bx, by, 0, 0, mid) and
                 inside(bx, by, px, py, mid)) flag = true;
        else if (inside(ax, ay, 0, 0, mid) and
                 inside(bx, by, px, py, mid) and
                 (2 * mid - distance(ax, ay, bx, by)) > 1e-7) flag = true;
        else if (inside(bx, by, 0, 0, mid) and
                 inside(ax, ay, px, py, mid) and
                 (2 * mid - distance(ax, ay, bx, by)) > 1e-7) flag = true;

        if (flag)
        {
            ans = mid;
            r = mid;
        }
        else l = mid;
    }

    cout << fixed << setprecision(10) << ans << ln;

    // cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}