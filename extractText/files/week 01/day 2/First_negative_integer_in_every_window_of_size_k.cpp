// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long arr[], long long n, long long k);

// Driver program to test above functions
int main()
{
    long long t, i;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long v[], long long n, long long k)
{
    long long i = 0;
    long long j = 0;
    queue<int> q;
    vector<long long> ans;

    while (j < n)
    {
        if (v[j] < 0) q.push(v[j]);

        if (j - i + 1 == k)
        {
            if (q.empty()) ans.push_back(0);
            else
            {
                ans.push_back(q.front());
                if (v[i] < 0)  q.pop();
            }
            i++;
        }
        j++;
    }
    return ans;
}
