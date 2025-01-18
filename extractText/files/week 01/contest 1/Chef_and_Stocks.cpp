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

        vi v(n);

        for (auto& i : v)
        {
            cin >> i;
        }

        int m = INT_MAX, idx;

        for (auto i = 0; i < v.size(); i++)
        {
            if (m > v[i])
            {
                m = v[i];
                idx = i;
            }
        }
        
        int profit = 0;
        
        for (auto i = 0; i < v.size(); i++)
        {
            if (i == idx) continue;
            profit += v[i];
        }
        cout << profit << endl;
    }


    return 0;
}