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

const int N = 1e5 + 1;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        double profit = n * (double(20) / double(100));
        int ans = 100 / profit;

        if (double(ans) < double(100 / profit)) ans++;

        cout << ans << endl;

    }


    return 0;
}