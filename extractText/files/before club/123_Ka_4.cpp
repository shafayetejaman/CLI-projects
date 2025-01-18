#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

const int N = 1e5 + 1;

int main()
{
    int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 1; j <= n; j++)
        {
            if (i == 0) cout << j;
            else if (i == n - 1) cout << n;
            else
            {
                if (j == 1) cout << i + 1;
                else if (j == n) cout << n;
                else cout << " ";
            }
        }
        
        cout << endl;
    }

    return 0;
}