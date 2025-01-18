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
        string s;
        cin >> s;

        vi v;

        int sum = 0;

        for (auto i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' and sum > 0)
            {
                v.push_back(sum);
                sum = 0;
            }
            if (s[i] == '1') sum++;
                
        }

        if (sum > 0) v.push_back(sum);

        sort(v.begin(), v.end(), greater<int>());

        int zara = 0;


        for (auto i = 0; i < v.size(); i++)
        {
            if (i % 2 == 0) zara += v[i];
        }

        cout << zara << endl;
    }
    

    return 0;
}