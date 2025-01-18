#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
#define endl '\n';
#define ll = long long;

const int N = 1e5 + 1;

int fun(vi& s, int n)
{
    if (n < 3) return 1;

    if ((s[n - 1] | s[n - 2]) == s[n - 3]) return fun(s, n - 2);
    if ((s[n - 1] & s[n - 2]) == s[n - 3]) return fun(s, n - 2);
    if ((s[n - 1] ^ s[n - 2]) == s[n - 3]) return fun(s, n - 2);

    return 0;
}


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi s(n);

        for (auto& i : s)
        {
            cin >> i;
        }
        cout << fun(s, n - 1) << endl;

    }


    return 0;
}