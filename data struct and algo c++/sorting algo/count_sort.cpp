#include <bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &arr)
{
    int count[1000] = {0};
    int max = arr[0];
    for (auto i = 0; i < arr.size(); i++)
    {
        max = std::max(max, arr[i]);
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    vector<int> ans(arr.size());

    for (auto i : arr)
    {
        ans[--count[i]] = i;
    }
    arr = ans;
}

int main(void)
{
    vector<int> arr = {4, 2, 5, 6, 9, 12};
    count_sort(arr);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}