// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
typedef long long ll;
#define ln '\n'
#define loop(n) for(auto j = 0; j < n; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define div(n, k) (n % k == 0)
#define even(n) (n % 2 == 0)

// const int N = 1e5 + 1;

void solve()
{

}

int longestSubarrayWithSumK(vector<int> &a, long long k)
{
    // Write your code here

    int i = 0;
    int j = 0;
    long long sum = 0;
    int ans = 0;

    while (j < a.size())
    {
        sum += a[j++];

        while (sum > k)
        {
            sum -= a[i++];
        }

        if (sum == k)
        {
            ans = max(ans, j - i);
        }
    }
    return ans;
}

int main()
{
    fast_cin();
    int t = 1;
    // cin >> t;

    loop(t) solve();

    return 0;
}