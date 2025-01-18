#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<string> v;

    while (!cin.eof())
    {
        string temp, s;
        getline(cin, temp);
        for (const auto &i : temp)
        {
            if (i != ' ')
            {
                s.push_back(i);
            }
        }
        v.push_back(s);
    }
    for (auto& i : v)
    {
        sort(i.begin(), i.end());
    }
    for (const auto &i : v)
    {
        cout << i << endl;
    }
    
    return 0;
}