#include <bits/stdc++.h>

using namespace std;

void permutation(vector<int> &v, vector<vector<int>> &ans, int p)
{
    if (v.size() == p)
        return ans.push_back(v);

    for (int i = p; i < v.size(); i++)
    {
        swap(v[i], v[p]);
        permutation(v, ans, p + 1);
        swap(v[i], v[p]);
    }
}

int main(void)
{
    vector<int> v = {3, 2, 1};
    vector<vector<int>> ans;

    permutation(v, ans, 0);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}