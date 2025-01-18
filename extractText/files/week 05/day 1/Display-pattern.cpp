// https://www.hackerrank.com/contests/pattern/challenges/displaypattern

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

void print(int n)
{
    if (n == 1)
    {
        cout << '*';
    } 
    else if (n == 2)
    {
        cout << "* *";
    }
    else if (n == 4)
    {
        cout << "* *\n  *";
    }
}

void solve()
{
    int n;
    cin >> n;

    if (n <= 4)
    {
        print(n);
        return;
    }

    vvc mat(n, vc(n, ' '));

    int r = 0, c = 0;

    while (c < n)
    {
        mat[r][c] = '*';
        c++;
    }
    c--;
    while (r < n)
    {
        mat[r][c] = '*';
        r++;
    }
    r--;
    while (c >= 0)
    {
        mat[r][c] = '*';
        c--;
    }
    c++;
    while (r > 1)
    {
        mat[r][c] = '*';
        r--;
    }
    r++;

    int count = 4;

    while (true)
    {
        if (count == n) break;
        while (mat[r][c + 1] != '*')
        {
            mat[r][c] = '*';
            c++;
        }
        count++;
        c--;
        if (count == n) break;
        while (mat[r + 1][c] != '*')
        {
            mat[r][c] = '*';
            r++;
        }
        count++;
        r--;

        if (count == n) break;
        while (mat[r][c - 1] != '*')
        {
            mat[r][c] = '*';
            c--;
        }
        count++;
        c++;
        if (count == n) break;
        while (mat[r - 1][c] != '*')
        {
            mat[r][c] = '*';
            r--;
        }
        count++;
        r++;
    }

    for (auto& i : mat)
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << ln;
    }

}

int main()
{
    fast_cin();

    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}
