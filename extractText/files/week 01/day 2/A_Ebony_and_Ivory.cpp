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

    for (auto i = 0; i <= c; i++)
    {
        for (auto j = 0; j <= c; j++)
        {
            if ((a * i + b * j) == c)
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}