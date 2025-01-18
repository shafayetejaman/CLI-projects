#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int zara = 0, sum = 0;
        vector<int> v;

        for (auto i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' && sum > 0)
            {
                v.push_back(sum);
                sum = 0;
            }
            if (s[i] == '1')
                sum++;
        }
        if (sum > 0)
            v.push_back(sum);
        sort(v.begin(), v.end(), greater<>());

        for (auto i = 0; i < v.size(); i++)
        {
            if (i % 2 == 0)
                zara += v[i];
        }

        cout << zara << endl;
    }

    return 0;
}