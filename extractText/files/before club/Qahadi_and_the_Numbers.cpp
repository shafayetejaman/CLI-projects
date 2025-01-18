#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        for (auto i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            s.insert(j);
        }
        cout << n - s.size() << endl;
    }

    return 0;
}