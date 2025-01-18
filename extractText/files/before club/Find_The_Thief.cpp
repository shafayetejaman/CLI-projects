#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> m;
        for (auto i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            m[j]++;
        }
        for (const auto &i : m)
        {
            if (i.second % 2 != 0)
            {
                cout << i.first << endl;
                break;
            }
        }
    }

    return 0;
}