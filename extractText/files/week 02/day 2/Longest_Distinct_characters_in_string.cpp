// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string &S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars(string &s)
{
    // your code here
    unordered_map<char, bool> m;

    int i, j, ans;
    i = j = ans = 0;

    while (j < s.size())
    {
        while (m.count(s[j]))
        {
            m.erase(s[i++]);
        }
        m[s[j++]];
        ans = max(ans, (int)m.size());
    }
    return ans;
}