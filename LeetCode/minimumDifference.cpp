#include "my_hederfile.h"

using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &arr, int k)
    {

        int min_sum = 0;
        sort(arr.begin(), arr.end());
        int n = k;
        while (n < arr.size())
        {
            int sum = n-k;
            for (auto i = 0; i < n; i++)
            {
                sum -= arr[i];
                min_sum = min(min_sum, sum);
            }
        }
        return min_sum;
    }
};
int main()
{


    return 0;
}