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
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<long long> v(n);

        for (auto i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long ans = 0;
        long long left = 0, right = n - 1;
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            long long water = min(v[i], v[j]);
            if (water > ans)
            {
                ans = water;
                right = j;
                left = i;
            }
            if (v[i] > v[j]) j--;
            else i++;
        }

        cout << left << " " << right << endl;

    }

    return 0;
}