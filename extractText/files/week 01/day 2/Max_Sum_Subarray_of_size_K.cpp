// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long maximumSumSubarray(int k, vector<int>& v, int n)
    {
        // code here 
        int i = 0;
        int j = 0;
        long sum = 0;
        long ans = INT_MIN;

        while (j < n)
        {
            sum += v[j];
            int win = j - i + 1;

            if (win < k) j++;

            else if (win == k)
            {
                ans = max(sum, ans);
                sum -= v[i++];
                j++;
            }
        }

        return ans;
    }

};

// } Driver Code Ends

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;;
        vector<int>Arr;
        for (int i = 0;i < N;++i)
        {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K, Arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends