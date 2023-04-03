#include <bits/stdc++.h>

using namespace std;

auto merge(const vector<int> &a, const vector<int> &b)
{
    int i = 0;
    int j = 0;
    vector<int> c;

    while (i != a.size() && j != b.size())
    {
        if (a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }

    while (i != a.size())
    {
        c.push_back(a[i]);
        i++;
    }
    while (j != b.size())
    {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

auto merge_sort(const vector<int> &arr)
{
    if (arr.size() == 1)
        return arr;

    int mid = arr.size() / 2;
    vector<int> a(mid);
    vector<int> b(arr.size() - mid);

    copy(arr.begin(), arr.begin() + mid, a.begin());
    copy(arr.begin() + mid, arr.end(), b.begin());

    vector<int> left = merge_sort(a);
    vector<int> right = merge_sort(b);

    return merge(left, right);
}

auto bubble_sort(vector<int> arr)
{
    int i, j ,n = arr.size();

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    //vector<int> ans = merge_sort(arr);
    vector<int> ans = bubble_sort(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }


    return 0;
}
