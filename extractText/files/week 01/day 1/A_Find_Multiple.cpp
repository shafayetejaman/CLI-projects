// https://atcoder.jp/contests/abc220/tasks/abc220_a?lang=en

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
#define loop(n) for(auto j = 0; j < n; j++)

//const int N = 1e5 + 1;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;

    return 0;
}
