// https://codeforces.com/problemset/problem/1692/D

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

// const int N = 1e5 + 1;

bool palindrome(string& s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i <j)
    {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

void solve()
{
    string s1, s2;
    int n, count = 0;

    cin >> s1 >> n;

    int h = stoi(s1.substr(0, 2));
    int m = stoi(s1.substr(3));


    while (true)
    {
        if (s1 == s2) break;

        int sum = (h * 60) + m + n;

        h = sum / 60;
        m = sum - (h * 60);

        h %= 24;

        if (h > 9) s2 = to_string(h);
        else
        {
            s2 = '0';
            s2 += to_string(h);
        }
        s2 += ':';
        if (m > 9) s2 += to_string(m);
        else
        {
            s2 += '0';
            s2 += to_string(m);
        }

        if (palindrome(s2)) count++;
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