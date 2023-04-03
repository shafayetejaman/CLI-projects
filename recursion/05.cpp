#include "my_hederfile.h"

using namespace std;

// vector<string> per(string arr, string a)
// {
//     if (arr.empty())
//     {
//         vector<string> ans;
//         ans.push_back(a);
//         return ans;
//     }
//     char c = arr[0];
//     vector<string> l = per(arr.substr(1), a + c);
//     vector<string> r = per(arr.substr(1), a);
//     l.insert(l.end(), r.begin(), r.end());
//     return l;
// }

vector<string> per(string arr)
{
    vector<string> ans(1);
    for (auto i : arr)
    {
        int n = ans.size();
        for (auto j = 0; j < n; j++)
        {
            ans.push_back(ans[j] + i);
        }
    }
    return ans;
}
vector<vector<int>> per(vector<int> arr)
{
    vector<vector<int>> ans(1);
    for (auto i = 0; i < arr.size(); i++)
    {
        int n = ans.size();
        for (auto j = 0; j < n; j++)
        {
            vector<int> temp = ans[j];
            temp.push_back(arr[i]);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    // print(per(arr));

    // print(int('a'));

    for (auto &i : arr)
    {
        i *= 2;
    }
    print(arr);

    return 0;
}