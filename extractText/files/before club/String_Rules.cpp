#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string ans;
    int i = 0;
    while (i < s.size())
    {
        if (isdigit(s[i]))
        {
            int num = s[i++] - '0';
        
            while (isdigit(s[i]))
            {
                num = num * 10 + (s[i++] - '0');
            
            }
            string sub;
            while (isalpha(s[i]))
            {
                sub += s[i++];
                
            }

            while (num--)
            {
                ans += sub;
            }
        }
        else
        {
            ans += s[i++];
        }
    }
    cout << ans;

    return 0;
}
