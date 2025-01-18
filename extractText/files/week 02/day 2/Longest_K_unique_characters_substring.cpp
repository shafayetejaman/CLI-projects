// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here

        unordered_map<char, int> m;

        int i, j, ans;
        i = j = ans = 0;

        while (j < s.size())
        {
            m[s[j++]]++;

            while (m.size() > k)
            {
                if (m[s[i]] > 1) m[s[i]]--;
                else m.erase(s[i]);
                i++;
            }
            if (m.size() == k)
                ans = max(ans, j - i);
        }

        return (ans > 1) ? ans : -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
