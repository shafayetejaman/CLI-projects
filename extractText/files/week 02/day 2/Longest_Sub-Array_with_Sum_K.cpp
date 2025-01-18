// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int v[], int n, int k)
    {
        unordered_map<int, int> m;

        int j, ans;
        j = ans = 0;

        long long sum = 0;

        while (j < n)
        {
            sum += v[j];

            if (sum == k)
            {
                ans = max(ans, j + 1);
            }

            if (m.count(sum - k))
            {
                ans = max(ans, j - m[sum - k]);
            }

            if (!m.count(sum))
                m[sum] = j;

            j++; 
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    //code

    int t;cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0;i < n;i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;

    }

    return 0;
}
// } Driver Code Ends
