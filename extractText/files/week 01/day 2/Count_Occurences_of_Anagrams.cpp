// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int search(string& t, string& s)
    {
        // code here
        unordered_map<char, int> m1, m2;
        for (auto& i : t)
        {
            m1[i]++;
        }

        int i = 0, j = 0, count = 0;

        while (j < s.size())
        {
            m2[s[j]]++;

            if (j - i + 1 == t.size())
            {
                if (m1 == m2) count++;
                
                if (m2.count(s[i]))
                {
                    if (m2[s[i]] > 1) m2[s[i]]--;
                    else m2.erase(s[i]);
                }
                i++;
            }
            j++;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends